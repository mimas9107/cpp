#include <iostream>
#include <cstdlib>
#include <ctime>

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
        this->root = NULL;
    }

    void showroot();
    void addnode(int);
    // void inorder(Node*);
    // void preorder(Node*);
    // void postorder(Node*);
};
void BinaryTree::showroot(){
    cout <<"root->data= " << this->root->data << '\n';
    return;
}
void BinaryTree::addnode(int item){

    Node *current;
    int flag=0;
    Node *newnode = new Node;
    newnode->data = item;
    newnode->left = NULL;
    newnode->right = NULL;

    if(this->root == NULL){
        this->root = newnode;
        //current = this->root;
    }else{
        //從root開始比對要插入的值.
        current = this->root;
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


int main(){

    BinaryTree mybintree;
    for(int i=1; i<21; i++){
        
        mybintree.addnode(1+(rand()%100));
        for(int j=0; j<i; j++){
            srand(j*32768);
        }
    }
    mybintree.showroot();
    return 0L;
}