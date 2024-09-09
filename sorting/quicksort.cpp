#include <iostream>

using namespace std;

int swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return 0L;
}

int quicksort(int *array,int size, int left, int right){
    // for(int i=0; i<size; i++){
    //     cout << i << ", " << array[i] << '\n';
    // }
    
        int i = left +1;
        int j = right;
        int K = array[left];
    if(left < right){
        do
        {
            while(array[i] < K){
                i = i + 1;
            }
            while(array[j] > K){
                j = j - 1;
            }
            if(i < j){
                swap(array[i], array[j]);
            }

        } while(i < j);
        swap(array[left], array[j]);
        quicksort(array,10, left, j-1);
        quicksort(array,10, j+1, right);

    }
    return 0L;
}

int main()
{
    int arr[10]={30, 24, 27, 16, 29, 33, 25, 18, 32, 35};
    for(int i=0; i<10; i++){
        // arr[i] = i;
        cout << arr[i] << ", ";
    }
    cout << '\n';

    quicksort(arr,10, 1, 10);
    for(int i=0; i<10; i++){
        cout << arr[i] << ", ";
    }
    cout << '\n';
    // int m=99;
    // int n=55;
    // swap(m,n);
    // cout << "m= "<< m << ", n= " << n << '\n';
    




    return 0L;
}