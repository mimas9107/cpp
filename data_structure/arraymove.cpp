// Leetcode #1089 Duplicate Zeros [Easy]
// Given a fixed-length integer array arr, duplicate each occurrence of zero, 
// shifting the remaining elements to the right.
//
// Note that elements beyond the length of the original array are not written. 
// Do the above modifications to the input array in place and do not return anything.

// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]

// Example 2:

// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]


#include <iostream>
#include <vector>

using namespace std;
void printarray(vector<int> &array){
    for(vector<int>::iterator it=array.begin(); it !=array.end(); it++){
            // print out array
            cout << *it << " ";
        }cout << '\n';
}
int main(){
    vector<int> arr{-1,0,3,7,5,0,4,2}; //except ans={-1,0,0,3,7,5,0,0}
    vector<int> res;
    int n = arr.size();
           
    printarray(arr);
    // 沿著原陣列開始掃描
    for(int i=0; i<n; i++){
        if(arr.at(i) != 0){
            // 碰到 arr[i] != 0 就複製arr[i]到 res尾端.
            res.push_back(arr.at(i));
        }
        if(arr.at(i) == 0) {
            // 碰到 arr[i] == 0 就複製兩次arr[i]到 res尾端.
            res.push_back(arr.at(i));
            res.push_back(arr.at(i));
            // 此時 res陣列長度應該會比原陣列長度 +1, 但不管它.
        }
        
    }
    // 將 res陣列值複製到 arr中, 索引上限指到 n-1, 後面的不管它.
    for(int i = 0; i<n; i++){
        arr.at(i) = res.at(i);
    }
    printarray(res);
    printarray(arr);
    return 0L;


    // Time complexity: O(n)
    // Space comlexity: O(n) => 有用到額外陣列空間處理解答
}