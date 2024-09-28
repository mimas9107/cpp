#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int p1 = 0;
        int p2 = n-1;
        int pcurr = 0, pnext = pcurr+1; 
        
        for(int i=0; i<n; i++){
            pcurr = i;
            pnext = i+1;
            if(pcurr < n-1 && nums.at(pcurr) == nums.at(pnext)){
                cout << "*" << nums.at(i) << '\n';
                i++;
            }
        }
        return pcurr;
    }
};

int main(){

    vector<int> arr{0,0,1,1,1,2,2,3,3,4};
    Solution mysol;
    int result;
    result = mysol.removeDuplicates(arr);

    cout << "result= " << result << '\n';


    return 0L;
}