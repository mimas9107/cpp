#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int idx = 1;
        if(nums.size() == 0){
            return 0;
        }
        for(int i=1; i<n; i++){
            if(nums.at(i) != nums.at(i-1)){
                
                nums.at(idx) = nums.at(i);
                idx=idx+1;
            }
        }
        return idx;
    }

    void printout(vector<int> &nums){
        for(vector<int>::iterator it=nums.begin(); it!=nums.end(); it++){
            cout << *it << " ";
        }
        cout << '\n';
    }
};

int main(){
    //vector<int> arr{1,1,2};
    vector<int> arr{0,0,1,1,1,2,2,3,3,4};
    Solution mysol;
    int result;
    result = mysol.removeDuplicates(arr);

    cout << "result= " << result << '\n';
    cout << "the array= ";
    mysol.printout(arr);


    return 0L;
}