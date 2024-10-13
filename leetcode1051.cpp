#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int n = heights.size();
        vector<int> expected;
        for(vector<int>::iterator it=heights.begin(); it != heights.end(); it++){
            expected.push_back(*it);
        }
        sort(expected.begin(),expected.begin()+n);
        int cnt=0;
        for(int i=0; i<n; i++){
            if(heights.at(i) != expected.at(i)){
                cnt++;
            }
        }
        return cnt;      
    }
};

int main(){

    vector<int> arr{1,1,4,2,1,3};
    Solution mysol;
    mysol.heightChecker(arr);
    return 0;
}