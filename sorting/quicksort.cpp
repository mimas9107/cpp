#include <iostream>

using namespace std;

int swap(int &a, int &b){
    int tmp;
    tmp = a;
    a = b;
    b = tmp;
    return 0L;
}

void quicksort(int *array,int size, int left, int right){
    // for(int i=0; i<size; i++){
    //     cout << i << ", " << array[i] << '\n';
    // }
    if(left < right){
        int i = left+1;
        int j = right;
        
        int K = array[left];
    
        do
        {
            while(array[i] <= K){
                i = i + 1;
            }
            
            while(array[j] > K){
                j = j - 1;
            }
            cout << "==== "; 
            cout <<"i=" << i << ", j="<< j << ", K=" << K << '\n';
            for(int i=0; i<5; i++){
                // arr[i] = i;
                cout << array[i] << ", ";
            }
            cout << '\n';

            if(i < j){
                swap(array[i], array[j]);
            }
            for(int i=0; i<5; i++){
                // arr[i] = i;
                cout << array[i] << ", ";
            }
            cout << '\n';


        } while(i < j);
        swap(array[left], array[j]);
        quicksort(array,5, left, j-1);
        quicksort(array,5, j+1, right);

    }
    //return 0L;
}

int main()
{
    //int arr[10]={30, 24, 27, 16, 29, 33, 25, 18, 32, 35};
    //int arr[10]={10, 9, 8, 7, 6, 1, 2, 3, 5 , 4};
    int arr[5] = {-5,-4,-3,-2,-1};
    for(int i=0; i<5; i++){
        // arr[i] = i;
        cout << arr[i] << ", ";
    }
    cout << '\n';

    quicksort(arr,5, 0, 4);
    for(int i=0; i<5; i++){
        cout << arr[i] << ", ";
    }
    cout << '\n';
    // int m=99;
    // int n=55;
    // swap(m,n);
    // cout << "m= "<< m << ", n= " << n << '\n';
    




    return 0L;
}