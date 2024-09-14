#include <iostream>
using namespace std;
void merge(int A[], int low, int mid, int high){
    int *B = new int[high-low+1]; // 開一個輔助陣列;
    int i=low, j=mid+1, k=0;

    while(i<=mid && j<=high){ // 從小到大存放到輔助陣列中
        if(A[i]<=A[j]){
            B[k++] = A[i++];

        }else{
            B[k++] = A[j++];
            
        }
    }
    while(i<=mid){ // 陣列中剩下的元素放到陣列中
        B[k++] = A[i++];

    }
    while(j<=high){
        B[k++] = A[j++];
    }
    for(i=low,k=0; i<=high; i++)
    {
        A[i]=B[k++];
    
    }
delete[] B;
}

void MergeSort(int A[], int low, int high){
    if(low<high){
        int mid=(low+high)/2; // 取中間點
        MergeSort(A, low, mid); // A[low : mid] 中的元素合併排序
        MergeSort(A, mid+1, high); // A[mid+1 : high]中的元素合併排序
        merge(A, low, mid, high); // 合併
    }

}

int main(){
    int l[] = {4, 9, 15, 24, 30, 2, 6, 18, 20, 59, 27};
    int len=sizeof(l)/sizeof(l[0]);
    cout << "original array: ";
    for(int i=0; i<len; i++){
        cout << l[i] << " ";
    }
    cout << '\n';
    MergeSort(l, 0, len-1);

    cout << "sorted array: ";
    for(int i=0; i<len; i++){
        cout << l[i] << " ";
    }
    cout << '\n';

    return 0L;
}