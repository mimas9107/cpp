#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) {
        // find 1st max
        int n=nums.size();
        int max=-1;
        for(int i=0; i<n; i++){
            if(nums.at(i) > max){
                max=nums.at(i);
            }
        }
        return max;

    }
    
};

int main(){
    vector<int> arr{2,2,3,1};
    //(1) [2],2,3,1 => 1,2,3,[2]
    //(2) 1,[2],3,2 => 1,[2],3,2
    //(3) 1,2,[3],2 => 1,2,2,[3]
    Solution mysol;
    int res=mysol.thirdMax(arr);
    cout << res << '\n';

    return 0;
}