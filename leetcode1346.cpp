// LeetCode #1346 Check If N and Its Double Exist
// 
// Given an array arr of integers, check if there exist two indices i and j such that :
//
//     i != j
//     0 <= i, j < arr.length
//     arr[i] == 2 * arr[j]
// Example 1:
//     Input: arr = [10,2,5,3]
//     Output: true
//     Explanation: For i = 0 and j = 2, arr[i] == 10 == 2 * 5 == 2 * arr[j]
// Example 2:
//     Input: arr = [3,1,7,11]
//     Output: false
//     Explanation: There is no i and j that satisfy the conditions.
// Constraints:
//     2 <= arr.length <= 500
//     -103 <= arr[i] <= 103


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        //ex1. arr = [10,2,5,3] return true
        //ex2. arr = [3,1,7,11] return false
        int cnt=0;
        int n=arr.size();

        // 用暴力法: 
        // 
        int i=0, j=n-1;
        for(i=0; i<n; i++){
            for(int k=i+1; k<n; k++ ){
                cnt++;
                cout << cnt << '\n';
                if ((arr.at(i) == 2*arr.at(k)) || (arr.at(k) == 2*arr.at(i))) {return true;}
                
            }
        }
        cout << cnt << '\n';
        return false;
    }
};

int main(){
    vector<int> arr{10,2,5,3}; // return true
    //vector<int> arr{3,1,7,11}; // return true
    
    Solution mysol;

    bool result = mysol.checkIfExist(arr);
    cout << result << '\n';

    return 0L;
}


// // Brute force method:
// // Time complexity: O(n^2) [ i=n, each i compare n-1 times => so, f(n)=n*(n-1)/2.=> O(n^2) ]
// // Space complexity: O(1)    [ no other additional memory space was required.]
 
// Think: 
// 1. 核心應該要同時考慮 當下 i是否為 j的 "2倍 或 1/2倍" => num[i] == 2*num[j] || 
// num[j] == 2*num[i] 只要一個成立就可以 return true.
 
// 2. 因為乘法代價也高, 應該可以改寫成
// num[i] == num[j]+num[j]  || num[j] == num[i]+num[i]
// 3. 避免用除法, 因為會碰到 truncation error可能不能預期; 硬要用要改用 取餘數判斷是否整除(mod 2==0); 
// 這邊用 index取值後交錯比較即可.
 
// 4. 要找一個優化的 i,j 遍歷方法
 