#include <iostream>
#include <vector>
#include <map>

using namespace std;

// 藥盒的 18 格座標範圍
struct Box {
    int x_min, y_min, x_max, y_max;
};

// Edge Impulse 偵測的藥丸座標與分類
struct Pill {
    int x, y;
    int type;  // 偵測的藥丸類別 (可能錯誤)
};

// 追蹤每顆藥丸的分類與位置
class PillTypeTracker {
public:
    map<int, int> type_vote;  // 追蹤多次推論後的分類
    map<int, int> box_vote;   // 追蹤格子落點

    void record(int type, int box_id) {
        if (type != -1) {
            type_vote[type]++;
        }
        if (box_id != -1) {
            box_vote[box_id]++;
        }
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

    // 追蹤 5 顆藥丸
    vector<PillTypeTracker> pill_trackers(5);

    // 模擬多次推論 (假設 10 次)
    int num_iterations = 10;
    vector<vector<Pill>> detected_pills_series = {
        {{30, 30, 1}, {120, 20, 2}, {55, 70, 3}, {10, 210, 4}, {80, 260, 5}},
        {{32, 32, 1}, {118, 22, 2}, {57, 72, 3}, {12, 208, 4}, {78, 258, 5}},
        {{28, 29, 1}, {122, 19, 2}, {54, 68, 3}, {9, 212, 4}, {81, 261, 5}},
        {{29, 31, 1}, {121, 21, 2}, {56, 69, 3}, {11, 209, 4}, {79, 259, 5}},
        {{30, 30, 1}, {120, 20, 2}, {55, 70, 3}, {10, 210, 4}, {80, 260, 5}},
        {{31, 29, 1}, {119, 23, 2}, {53, 67, 3}, {8, 213, 2}, {82, 262, 5}}, // 錯誤分類：藥丸 4 被分類為 2
        {{30, 28, 1}, {120, 24, 2}, {52, 66, 3}, {7, 214, 4}, {83, 263, 5}},
        {{29, 32, 1}, {121, 19, 2}, {58, 73, 3}, {13, 207, 4}, {77, 5, 5}},  // 錯誤分類
        {{30, 31, 1}, {120, 21, 2}, {55, 71, 3}, {10, 211, 4}, {80, 260, 5}},
        {{30, 30, 1}, {120, 20, 2}, {55, 70, 3}, {10, 210, 4}}
    };

    // 進行多次推論並統計結果
    for (int t = 0; t < num_iterations; t++) {
        vector<Pill> detected_pills = detected_pills_series.at(t);
               
        for (int i = 0; i < detected_pills.size(); i++) {
            int box_id = findBoxForPill(detected_pills[i], pill_boxes);
            pill_trackers[i].record(detected_pills[i].type, box_id);
        }
    }

    // 最終分類與格子判定
    for (int i = 0; i < pill_trackers.size(); i++) {
        cout << "藥丸 " << i + 1 << " 最終類別: " << pill_trackers[i].getFinalType()
             << "，落入藥盒格子: " << pill_trackers[i].getFinalBox() << endl;
    }

    return 0;
}
