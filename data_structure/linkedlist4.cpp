#include <iostream>
using namespace std;
class Node{
public:
    int value;
    Node *next;
};
class Link_list{
public:
    int count;
    Node *list;
    // 建構子()
    Link_list(int count){
        if(count >= 1){
            Node *head = new Node();
            cout << "input head(1st Node) value= "; 
            cin >> head->value;
            head->next = NULL;
            /// 建立後續節點.
            Node *current = head; 
            for(int i=1; i<count; i++){
                current->next = new Node(); /// 建立下一個節點, 並把節點的位置給 head->next;
                current = current->next;    /// 移動到現在節點, 準備作資料存取.
                cout << "input next Node value= ";
                cin >> current->value; 
                current->next = NULL;
            }
            list = head;
        }else
        {
            list=NULL;
        }
    }
    // 列印list
    void printlist()
    {   
        if(list == NULL){
            cout << "list = NULL " << '\n';
            return;
        }
        /// 尋訪節點.
        Node *current = list; /// 移動回 head節點.
        
        while(current != NULL)
        {
            // cout << "value= " << current->value << ", value's addr= " << &current->value << ", next addr= " << current->next << '\n';
            cout << current->value << " ";
            current = current->next;
        }
        cout << '\n';
    }
    // 在開頭插入
    void insert_begin(int value){
        Node *new_Node = new Node();
        new_Node->value = value;
        new_Node->next = list;
        list = new_Node;

    }
    // 在尾端插入
    void insert_end(int value){
        Node *new_Node = new Node();
        new_Node->value = value;
        new_Node->next = NULL;

        Node *current = list;
        while(true)
        {   /// 跑一次 list取得 最後一個 Node位置;
            if(current->next == NULL){break;}
            current = current->next;
        }
        
        current->next = new_Node;
        
    }
    // 在指定數值後插入
    void insert(int find, int value){
        Node *new_Node = new Node();
        new_Node->value = value;
        new_Node->next = NULL;
        
        Node *current = list;
        /// 從頭走一遍 list, 當下的 current->value是目標值就跳出.
        while(current != NULL){
            if(current->value == find){
                break;
            }
            current = current->next;
        }
        /// 當下的 next 指定給要插入的 new_Node->next
        /// 新插入的 new_Node位置 指定給 current->next完成插入.
        
        new_Node->next = current->next;
        current->next = new_Node;
        return;
    }
    // 反轉 圖解資料結構使用C++書上範例:
    Node* reverse(Node*);
    
    // 反轉2 Geeksforgeeks.org範例:
    Node* reverse2(Node*);
    // 移除指定數值
    void removal(int);
};

Node* Link_list::reverse(Node* ptr){
    Node *p,*q,*r;
    p = ptr;
    q = NULL;
    while(p!=NULL){
        r = q;
        q = p;
        p = p->next;
        q->next=r;
    }
    return q;
}

Node* Link_list::reverse2(Node* ptr){
    Node *curr = ptr, *prev = NULL, *Store_next;
    while(curr!=NULL){
        // Store the current's next 將目前的 next存起來,
        Store_next = curr->next;
        // reverse 目前的 next指向前一個即完成反轉.
        curr->next = prev;
        // 目前節點存成 previous準備前往下一個節點.
        prev = curr;
        // current move to stored next 移動往保存的 next節點. 
        curr = Store_next;

    // 直到目前節點為 NULL為止.    
    }
    // prev即為此反轉串列的頭.
    return prev;
}

void Link_list::removal(int find){
    // 參考 https://alrightchiu.github.io/SecondRound/linked-list-xin-zeng-zi-liao-shan-chu-zi-liao-fan-zhuan.html#delete
    Node *current = list;
    Node *prev = NULL;
    
    // Traversal走一次串列直到 current->value 等於尋找的值, 此時會得到 prev 及 current確切位置.
    while(current != NULL && current->value != find){ 
        prev = current;
        current = current->next;
    }
    // traversal走到尾都沒找到 value:
    if(current == NULL){
        cout << "There is no value=" << find << " in the list." << '\n';
    }else if(current == list){
        // ＊分開考慮 若是刪除開頭第一個, 就相當於 current 等於 list 
        list = current->next;    // 直接將 當下節點的next給 list就好. 
        delete current;          // 當下節點記憶體空間可以釋放了.
        current=NULL;            // current指標清空, 避免 bug.
        }
    else{
        // ＊不是開頭的情況, 將 prev->next 指向 current->next 就跳過 current了.
        prev->next = current->next;    // 本方法的核心.
        delete current;                // 當下節點記憶體空間可以釋放了.
        current=NULL;                  // current指標清空, 避免 bug.
    }

    return;
}

int main(){
   
    int n;
    cout << "counts of the Nodes= ";
    cin >> n;

    Link_list mylist1(n);
    mylist1.printlist();

    cout << "================" << '\n';
    int m=-1;
    cout << "please input the value and insert begin: ";
    cin >> m;
    mylist1.insert_begin(m);
    mylist1.printlist();

    cout << "================" << '\n';
    
    cout << "please input the value and insert end: ";
    cin >> m;
    mylist1.insert_end(m);
    mylist1.printlist();

    cout << "================" << '\n';
    int target;
    cout << "please input the target value and insert after the value: ";
    cin >> target >> m;
    mylist1.insert(target,m);
    mylist1.printlist();
    
    cout << "================" << '\n';
    
    cout << "Reverse the list" << '\n';
    
    mylist1.list = mylist1.reverse(mylist1.list);
    mylist1.printlist();

    cout << "================" << '\n';
    cout << "Reverse the list 2" << '\n';
    
    mylist1.list = mylist1.reverse2(mylist1.list);
    mylist1.printlist();

    cout << "================" << '\n';
    
    cout << "please input the target value to delete: ";
    cin >> target;
    mylist1.removal(target);
    mylist1.printlist();

    return 0L;
}