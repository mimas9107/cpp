#include <iostream>
using namespace std;

int sequential(int list[], int n_size, int target_key){
    int i;
    for(i=0; i<n_size; i++){
        if( list[i] == target_key){
            return i;
        }
    }
    return -1;
}

#define COMPARE(x,y)((x<y)? -1 : (x==y)? 0 : 1)
int binary_search(int list[], int left, int right, int target_key){
    int middle;
    if(left <= right){
        middle = (left+right)/2;

        switch(COMPARE(list[middle],target_key)){
            case -1:
               return binary_search(list, middle+1, right, target_key);
            case 0:
               return middle;
            case 1:
               return binary_search(list, left, middle-1, target_key);
        }
    }
    return -1;
}

int main(){

    int list[]{54,2,40,22,17,22,60,35};

    cout << "sequential searching. Key=22. it's index is: " << sequential(list, 8, 22) << '\n';

    int list2[]={9,1,2,4,8,16,32,64,128};
    cout << binary_search(list2, 0, 7, 2) << '\n';


    return 0L;
}