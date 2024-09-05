#include <iostream>
using namespace std;

int insertion_sort(int arr[], int n_size){
    int i,j, key;
    for(i=1; i!=n_size; i++){
        key = arr[i];
        j = i-1;
        while((j>=0) && (arr[j]>key)){
            arr[j+1] = arr[j];
            j=j-1;
        }
        arr[j+1]=key;

    }

return 0L;
}


int main(){

    int list[] = {64, 32, 16, 8, 4, 2, 1};
    int length = sizeof(list)/sizeof(list[0]);
    insertion_sort(list,sizeof(list)/sizeof(list[0]));

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