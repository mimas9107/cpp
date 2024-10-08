#include <iostream>
#include <cstdlib>
#include <ctime>
#include <queue>

using namespace std;

// 定義 二元樹-節點基礎類別:
class Node{
public:
    int data;
    Node *left;
    Node *right;
};
// 定義 二元樹類別:
class BinaryTree{
private:
         int level;
    Node *root;
    bool isLeaf(Node *ptr){
        if(ptr->left == NULL && ptr->right == NULL){
            return true;
        }else{
            return false;
        }
    }
    
public:
    BinaryTree(){
        root = NULL;
    }

    Node* getroot();
    void addnode(int);
    void inorder(Node*);
    void preorder(Node*);
    void postorder(Node*);
    void leveltraverse(Node*);
    Node* search(Node*,int);
};
Node* BinaryTree::getroot(){
    
    return this->root;
}
void BinaryTree::addnode(int item){

    Node *current;
    int flag=0;
    Node *newnode = new Node;
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;

    if(root == NULL){
        root = newnode;
        current = newnode;
    }else{
        //從root開始比對要插入的值.
        current = root;
        while(!flag){
            if(item < current->data){
                // 往左子樹：
                if(current->left == NULL){
                    current->left = newnode;
                    flag = 1;
                }else{
                    current = current->left;
                }
            }else{
                // 往右子樹：
                if(current->right == NULL){
                    current->right = newnode;
                    flag = 1;
                }else{
                    current = current->right;
                }
            }
        }//while

    }
    cout << "&= " << current << ", d= "<< current->data <<", l="<< current->left <<", r=" << current->right << '\n';
}
void BinaryTree::inorder(Node *ptr){
    // 中序走訪 LDR
    if(ptr){ // 若 ptr不為 NULL就繼續走往下走. 
        inorder(ptr->left);            // 往L遞迴
        cout << ptr->data << "->"; //L遞迴是NULL回來根, 印根的資料
        inorder(ptr->right);           // 往R遞迴
    }
}
void BinaryTree::preorder(Node *ptr){
    // 前序走訪 NLR
    if(ptr){ // 若 ptr不為 NULL就繼續走往下走.
        cout << ptr->data << "->"; //印根的資料
        preorder(ptr->left);           // 往L遞迴
        preorder(ptr->right);          // 往R遞迴
    }
}
void BinaryTree::postorder(Node *ptr){
    // 後序走訪 LRN
    if(ptr){
        postorder(ptr->left);          // 往L遞迴
        postorder(ptr->right);         // 往R遞迴
        cout << ptr->data << "->"; //印根的資料
    }
}
void BinaryTree::leveltraverse(Node *ptr){
    // 層狀走訪
    if(!ptr){
        return;
    }
    queue<Node*> Q;
    Q.push(ptr);

    while(!Q.empty()){

        ptr=Q.front();
        Q.pop();
        cout<<ptr->data<< "->";
        if(ptr->left){
            Q.push(ptr->left);
        }
        if(ptr->right){
            Q.push(ptr->right);
        }
    }
    return;
}
Node* BinaryTree::search(Node *ptr, int data){
    while(1){
        if(ptr == NULL){return NULL;} // 沒找到 data, 回傳 NULL.
        if(ptr->data == data){ 
            return ptr; // 找到 data, 回傳這個節點指標;
        }else if(ptr->data > data){
            ptr = ptr->left; // data比節點值小, 走左邊繼續找.
        }else{
            ptr = ptr->right; // data比節點值大, 走右邊繼續找.
        }
    }
}

int main(){
    srand(time(NULL));
    BinaryTree mybintree;
    // 依序建立二元樹 {13,12,41,8,23,59,6,55,19}
    mybintree.addnode(13);
    mybintree.addnode(12);
    mybintree.addnode(41);
    mybintree.addnode(8);
    mybintree.addnode(23);
    mybintree.addnode(59);
    mybintree.addnode(6);
    mybintree.addnode(55);
    mybintree.addnode(19);
    
    // Traversal : 
    // inorder
    mybintree.inorder(mybintree.getroot()); 
    cout << '\n';
    // preorder
    mybintree.preorder(mybintree.getroot()); 
    cout << '\n';
    // postorder
    mybintree.postorder(mybintree.getroot()); 
    cout << '\n';
    // level 
    mybintree.leveltraverse(mybintree.getroot());
    cout << '\n';

    //search data
    int finddata{0};
    Node *findptr{NULL};
    cout << "=====" << '\n';
    cout << "Please input a data to search in the tree: ";
    cin >> finddata;
    findptr = mybintree.search(mybintree.getroot(), finddata);
    if( findptr != NULL){
        cout << " There are [ " << finddata << "] in the tree!" << '\n';
        mybintree.inorder(findptr);
        cout << '\n';
    }

    return 0L;
}