#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int idx=n-1;
        for(int i=n-1; i>-1; i--){
            if( val == nums.at(i)){
                // cout << i << '\n';
                
                nums.at(i) = nums.at(idx);
                idx=idx-1;
                
                
            }
            
        }
        printout(nums);
        return idx+1 ;
    }
    void printout(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin(); it != nums.end(); it++){
            cout << *it << " ";
        }
        cout << '\n';
    }
};

int main(){
    // 3,2,2,3 val=3 => output=2 [2,2,_,_]
    // 0,1,2,2,3,0,4,2 val=2 => output=5 [0,1,4,0,3,_,_,_]
    // vector<int> arr{3,2,2,3}; 
    // int val=3;
    vector<int> arr{0,1,2,2,3,0,4,2};
    int val=2;

    int result;
    Solution mysol;
    result = mysol.removeElement(arr, val);

    cout << "result= " << result << '\n';


    return 0L;
}