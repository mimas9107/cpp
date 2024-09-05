#include <iostream>
using namespace std;

int bubble_sort(int list[], int n_size){
    int i,j,temp;
    for(i=0; i<n_size-1; i++){
        for(j=0; j<n_size-1-i; j++){
            if(list[j] > list[j+1]){
                temp = list[j+1];
                list[j+1] = list[j];
                list[j] = temp;
            }
        }
        cout << "[i= "<< i << "] ";
        for(int i=0; i<n_size; i++){
            if(i == n_size-1){
                cout << list[i] << "\n";
            }
            else{
                cout << list[i] << ", ";
            }
        
        }   
    }



    return 0L;
}

int main(){

    int list[] = {15, 8, 20, 31, 47, 55,6};
    int length = sizeof(list)/sizeof(list[0]);
    bubble_sort(list,sizeof(list)/sizeof(list[0]));

    for(int i=0; i<length; i++){
        if(i == length-1){
            cout << list[i] << "\n";
        }
        else{
            cout << list[i] << ", ";
        }
        
    }

    return 0L;
}