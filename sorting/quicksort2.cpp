#include <iostream>

using namespace std;

int myswap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return 0L;
}

int partition(int r[], int low, int high){
    int i=low, j=high, pivot=r[low];
    while(i<j){
        while(i<j && r[j]>pivot){
            j--;
        }
        if(i<j){
            myswap(r[i++], r[j]);
        }
        while(i<j && r[i]<=pivot){
            i++;
        }
        if(i<j){
            myswap(r[i],r[j--]);
        }
    }
    return i;
}
void quicksort(int r[], int low, int high){
    if(low<high){
        int mid = partition(r, low, high);
        quicksort(r, low, mid-1);
        quicksort(r, mid+1, high);
    }
}


int partition2(int r[], int low, int high){

    int i=low, j=high, pivot=r[low], tmpj, tmpi;
    while(i<j){
        tmpj=r[j]; tmpi=r[i];
        while(i<j && r[j]>pivot){ 
            tmpj=r[j];
            j--;
        }
        while(i<j && r[i]<=pivot){
            tmpi=r[i]; // debug watch 用
            i++;
        }
        if(i<j){
            
            myswap(r[i++], r[j--]);
        }
    }
    if(r[i]>pivot){
        myswap(r[j-1], r[low]);
        return i-1;
    }
    myswap(r[i], r[low]);
    return i;
}

void quicksort2(int r[], int low, int high){
    if(low<high){
        int mid = partition2(r, low, high);
        
        quicksort2(r, low, mid-1);
        quicksort2(r, mid+1, high);
    }
}

int main()
{
    //int arr[]={30, 24, 5, 58, 18, 36, 12, 42, 39};
    int arr[]={10, 9, 8, 7, 6, 1, 2, 3, 5 , 4};
    int len=sizeof(arr)/sizeof(arr[0]);
    
    for(int i=0; i<len; i++){
        // arr[i] = i;
        cout << arr[i] << " ";
    }
    cout << '\n';

    quicksort2(arr, 0, len-1);
    for(int i=0; i<len; i++){
        cout << arr[i] << " ";
    }
    cout << '\n';
    
    




    return 0L;
}