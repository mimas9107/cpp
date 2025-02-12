#include <iostream>
#include <vector>

using namespace std;

// 藥盒的 18 格座標範圍，每個格子定義為 (x_min, y_min, x_max, y_max)
struct Box {
    int x_min, y_min, x_max, y_max;
};

// Edge Impulse 偵測的藥丸中心點座標
struct Pill {
    int x, y;
};

// 判斷藥丸是否落入某個藥盒格子
int findBoxForPill(const Pill& pill, const vector<Box>& pill_boxes) {
    for (int i = 0; i < pill_boxes.size(); i++) {
        if (pill.x >= pill_boxes[i].x_min && pill.x <= pill_boxes[i].x_max &&
            pill.y >= pill_boxes[i].y_min && pill.y <= pill_boxes[i].y_max) {
            return i + 1;  // 回傳格子編號 (從1開始)
        }
    }
    return -1;  // 沒有匹配的格子
}

int main() {
    // 定義 18 格藥盒的座標範圍 (這裡假設的範圍，根據實際影像調整)
    vector<Box> pill_boxes = {
        {0, 0, 50, 50}, {50, 0, 100, 50}, {100, 0, 150, 50},
        {0, 50, 50, 100}, {50, 50, 100, 100}, {100, 50, 150, 100},
        {0, 100, 50, 150}, {50, 100, 100, 150}, {100, 100, 150, 150},
        {0, 150, 50, 200}, {50, 150, 100, 200}, {100, 150, 150, 200},
        {0, 200, 50, 250}, {50, 200, 100, 250}, {100, 200, 150, 250},
        {0, 250, 50, 300}, {50, 250, 100, 300}, {100, 250, 150, 300}
    };

    // 偵測到的 5 顆藥丸中心點 (假設 Edge Impulse 模型輸出)
    vector<Pill> detected_pills = {
        {30, 30}, {120, 20}, {55, 70}, {10, 210}, {80, 260}
    };

    // 判斷每顆藥丸落在哪個格子
    for (int i = 0; i < detected_pills.size(); i++) {
        int box_id = findBoxForPill(detected_pills[i], pill_boxes);
        if (box_id != -1) {
            cout << "藥丸 " << i + 1 << " 位於藥盒格子 " << box_id << endl;
        } else {
            cout << "藥丸 " << i + 1 << " 不在任何格子內！" << endl;
        }
    }

    return 0;
}
