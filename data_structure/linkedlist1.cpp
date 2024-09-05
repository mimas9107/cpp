#include <iostream>

class Node{
public:
    int value;
    Node *next;
};

using namespace std;

int main(){

    Node *head = new Node();
    cout << "input head(1st Node) value= "; 
    cin >> head->value;
    head->next = NULL;

    /// 建立後續節點.
    Node *current = head; 
    for(int i=1; i<5; i++){
        current->next = new Node(); /// 建立下一個節點, 並把節點的位置給 head->next;
        current = current->next; /// 移動到現在節點, 準備作資料存取.
        cout << "input next Node value= ";
        cin >> current->value; 
        current->next = NULL;
    }

    /// 尋訪節點.
    current = head; /// 移動回 head節點.

    while(current != NULL){
        cout << "value= " << current->value << ", value's addr= " << &current->value << ", next addr= " << current->next << endl;
        current = current->next;
    }
    return 0L;
}