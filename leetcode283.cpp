// Leetcode #283 Move zeros
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
// Note that you must do this in-place without making a copy of the array.
// Example 1:
//
// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Example 2:
//
// Input: nums = [0]
// Output: [0]
//
// Constraints:
//
//     1 <= nums.length <= 104
//     -231 <= nums[i] <= 231 - 1
// 
// Follow up: Could you minimize the total number of operations done?

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 1st: runtime=456ms beats 5.04% => 只要 L碰到 0後面都要移動 1次.
        // Time complexity: O(N)
        // Space complexity: O(1)
        // 
        int n=nums.size();
        int L=0,R=n-1;

        while(L<=R){            
            if(nums.at(L)==0){
                // num[L]為0 則 L+1~R 都要往左移動1位置.
                // 保留 L+1~R 的原資訊不要覆蓋, 只有最後對 num[R]覆蓋為0, 然後 R往左-1.                
                for(int j=L+1; j<R+1; j++){
                    nums.at(j-1) = nums.at(j);
                }
                nums.at(R)=0;
                R--;
            }else{
                L++;
            }
        }
    }
};


int main(){
    vector<int> arr{0,1,0,3,12}; //expect [1,3,12,0,0]
    // vector<int> arr{0};  // expect [0]
    // vector<int> arr{0,0,1}; // expect [1,0,0]


    Solution mysol;
    mysol.moveZeroes(arr);

    for(vector<int>::iterator it=arr.begin(); it != arr.end(); it++){
        cout << *it << " ";
    }cout << '\n';

    return 0L;
}