#include <iostream>
/* 用單向鏈結串列實作 佇裂 */
using namespace std;
class Node{
public:
    int data;
    Node *next;
};

class queue{
public:
    Node *tail;
    Node *head;
    int MAX_ITEMS;
    int n_len;

    queue(int MAX_LEN){
        this->head = NULL;
        this->tail = NULL;
        this->MAX_ITEMS = MAX_LEN;
        this->n_len = 0;
        return;
    }

    void enqueue(int item){        
        Node *current = new Node;
        current->data = item;
        current->next = NULL;
        
        if(this->head == NULL && this->n_len == 0){
            this->head = current;
            
            this->tail = current;
            this->n_len = this->n_len + 1;
            return;
        }
        
        if(this->n_len < this->MAX_ITEMS){
           
            this->tail->next = current;
            this->n_len = this->n_len + 1;

            this->tail = current;

        }else{
            cout << "\u001B[31m Warning! QUEUE is full! u must POP out the head!" << '\n';
            cout << "The value=[ " << current->data << " ] will be discard!\u001B[37m" << '\n';
            delete current;
            
        }
        return;
    }

    void dequeue(){
        Node *tmp;
        tmp = this->head;
        if(this->n_len > 0){
            
            // this->head = this->head->next;
            this->head = tmp->next;
            this->n_len = this->n_len -1;  
        }else{

            cout << " Warning! QUEUE is empty! LEN=[ " << this->n_len << " ]" << '\n';
            return;
        }
        delete tmp;
        return;
    }

    void printqueue(){
        if(this->n_len < 1){
            cout << "\u001B[33m Warning! QUEUE is empty! \u001B[37m" << '\n';
            return;
        }

        cout << "===== QUEUE LEN=[ " << this->n_len << " ]====="  << '\n';
        int i=0;
        Node *current;
        cout << "head= " << this->head << ", data= " << head->data << ", head.next= " << head->next << '\n';

        current = this->head;
        while(current != NULL){

            cout << i << ", addr= "<< &current->data << " , data= " << current->data << " , next= " << current->next << '\n';

            current = current->next;
            i=i+1;
        }

        cout << "tail= " << this->tail << ", data= " << tail->data << ", tail.next= " << tail->next << '\n';
        return;
    }
};


int main(){
    queue myqueue(10);
    myqueue.enqueue(1);
    myqueue.enqueue(2);
    myqueue.enqueue(3);
    myqueue.enqueue(4);
    myqueue.enqueue(5);
    myqueue.enqueue(6);
    myqueue.enqueue(7);
    myqueue.enqueue(8);
    myqueue.enqueue(9);
    myqueue.enqueue(10);
    myqueue.printqueue();

    myqueue.dequeue();
    myqueue.printqueue();

    myqueue.enqueue(98);
    myqueue.enqueue(77);
    myqueue.printqueue();
    
    for(int i=0; i<10; i++){
        cout << "\u001B[32m [ " << i << " ] \u001B[37m" << '\n';
        myqueue.dequeue();
        myqueue.printqueue();
    }
    

    return 0L;
}