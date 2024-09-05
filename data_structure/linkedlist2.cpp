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
            cout << "value= " << current->value << ", value's addr= " << &current->value << ", next addr= " << current->next << '\n';
            current = current->next;
        }
    }

    void insert_begin(int value){
        Node *new_Node = new Node();
        new_Node->value = value;
        new_Node->next = list;
        list = new_Node;

    }

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

};



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
    
    return 0L;
}