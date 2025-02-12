#include <iostream>
#include <vector>
#include <map>
#include <cmath>

using namespace std;

#define CONFIDENCE_THRESHOLD 95.0  // 可信度閾值

// 藥盒的 18 格座標範圍
struct Box {
    int x_min, y_min, x_max, y_max;
};

// Edge Impulse 偵測的藥丸座標與分類
struct Pill {
    int x, y;
    int type;      // 偵測的藥丸類別 (可能錯誤)
    double conf;   // 可信度 (0~100%)
};

// 判斷藥丸是否落入某個藥盒格子
int findBoxForPill(const Pill& pill, const vector<Box>& pill_boxes) {
    for (int i = 0; i < pill_boxes.size(); i++) {
        if (pill.x >= pill_boxes[i].x_min && pill.x <= pill_boxes[i].x_max &&
            pill.y >= pill_boxes[i].y_min && pill.y <= pill_boxes[i].y_max) {
            return i + 1; // 回傳格子編號 (從1開始)
        }
    }
    return -1; // 沒有匹配的格子
}

// 計算兩個點之間的歐幾里得距離
double calcDistance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

// 追蹤每顆藥丸的分類與位置
class PillTypeTracker {
public:
    int last_x, last_y; // 追蹤藥丸的座標
    map<int, int> type_vote;  // 追蹤多次推論後的分類
    map<int, int> box_vote;   // 追蹤格子落點
    int id; // 唯一識別碼

    PillTypeTracker(int id, int x, int y) : id(id), last_x(x), last_y(y) {}

    void record(int type, int box_id) {
        if (type != -1) {
            type_vote[type]++;
        }
        if (box_id != -1) {
            box_vote[box_id]++;
        }
        last_x = (last_x + x) / 2;
        last_y = (last_y + y) / 2;
    }

    // 選擇出現次數最多的類別
    int getFinalType() {
        int max_count = 0, best_type = -1;
        for (const auto& entry : type_vote) {
            if (entry.second > max_count) {
                max_count = entry.second;
                best_type = entry.first;
            }
        }
        return best_type;
    }

    // 選擇最常出現的格子
    int getFinalBox() {
        int max_count = 0, best_box = -1;
        for (const auto& entry : box_vote) {
            if (entry.second > max_count) {
                max_count = entry.second;
                best_box = entry.first;
            }
        }
        return best_box;
    }
};

// 管理所有藥丸的追蹤器
class PillManager {
private:
    vector<PillTypeTracker> pills;
    int next_id = 1;  // 藥丸的唯一 ID

public:
    void update(const vector<Pill>& detected_pills, const vector<Box>& pill_boxes) {
        for (const auto& detected_pill : detected_pills) {
            // 只接收可信度 ≥ 95% 的推論結果
            if (detected_pill.conf < CONFIDENCE_THRESHOLD) continue;

            bool matched = false;

            // 檢查是否有相近的藥丸
            for (auto& pill_tracker : pills) {
                if (calcDistance(pill_tracker.last_x, pill_tracker.last_y, detected_pill.x, detected_pill.y) < 15) {
                    pill_tracker.record(detected_pill.type, findBoxForPill(detected_pill, pill_boxes));
                    matched = true;
                    break;
                }
            }

            // 若沒有找到相近的藥丸，則新增一個追蹤器
            if (!matched && pills.size() < 10) {
                PillTypeTracker new_pill(next_id++, detected_pill.x, detected_pill.y);
                new_pill.record(detected_pill.type, findBoxForPill(detected_pill, pill_boxes));
                pills.push_back(new_pill);
            }
        }
    }

    void printResults() {
        for (const auto& pill_tracker : pills) {
            cout << "藥丸 " << pill_tracker.id << " 最終類別: " << pill_tracker.getFinalType()
                 << "，落入藥盒格子: " << pill_tracker.getFinalBox() << endl;
        }
    }
};

int main() {
    // 定義 18 格藥盒的座標範圍
    vector<Box> pill_boxes = {
        {0, 0, 50, 50}, {50, 0, 100, 50}, {100, 0, 150, 50},
        {0, 50, 50, 100}, {50, 50, 100, 100}, {100, 50, 150, 100},
        {0, 100, 50, 150}, {50, 100, 100, 150}, {100, 100, 150, 150},
        {0, 150, 50, 200}, {50, 150, 100, 200}, {100, 150, 150, 200},
        {0, 200, 50, 250}, {50, 200, 100, 250}, {100, 200, 150, 250},
        {0, 250, 50, 300}, {50, 250, 100, 300}, {100, 250, 150, 300}
    };

    PillManager pill_manager;

    // 模擬多次推論 (假設 10 次)
    vector<vector<Pill>> detected_pills_series = {
        {{30, 30, 1, 96.5}, {120, 20, 2, 94.2}, {55, 70, 3, 97.8}, {10, 210, 4, 99.0}, {80, 260, 5, 98.3}},
        {{32, 32, 1, 97.1}, {118, 22, 2, 95.6}, {57, 72, 3, 98.4}, {12, 208, 4, 99.2}, {78, 258, 5, 96.8}},
        {{28, 29, 1, 94.0}, {122, 19, 2, 96.5}, {54, 68, 3, 98.7}, {9, 212, 4, 99.4}, {81, 261, 5, 97.2}, {90, 100, 6, 92.3}},
        {{29, 31, 1, 98.0}, {121, 21, 2, 97.2}, {56, 69, 3, 98.9}, {11, 209, 4, 99.5}, {79, 259, 5, 98.1}},
    };

    // 進行多次推論並統計結果
    for (int t = 0; t < detected_pills_series.size(); t++) {
        pill_manager.update(detected_pills_series[t], pill_boxes);
    }

    // 最終結果
    pill_manager.printResults();

    return 0;
}
