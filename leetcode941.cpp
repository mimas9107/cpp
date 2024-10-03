// Leetcode #941 Valid Mountain Array
// Given an array of integers arr, return true if and only if it is a valid mountain array.
//
// Recall that arr is a mountain array if and only if:
//
//     arr.length >= 3
//     There exists some i with 0 < i < arr.length - 1 such that:
//         arr[0] < arr[1] < ... < arr[i - 1] < arr[i] 
//         arr[i] > arr[i + 1] > ... > arr[arr.length - 1]
// Example 1:
// Input: arr = [2,1]
// Output: false

// Example 2:
// Input: arr = [3,5,5]
// Output: false

// Example 3:
// Input: arr = [0,3,2,1]
// Output: true

// Constraints:
//     1 <= arr.length <= 104
//     0 <= arr[i] <= 104
 



#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        // [0,3,2,1] Output: true
        // arr = [3,5,5] Output: false
        
        int n=arr.size();
        
        int max=-1,L_max=-1;
        int idx_max=0,idx_L_max=0;
        
        int R_max=-1;
        int idx_R_max=n-1;
        
        // find the max value, and it's index
        for(int i=0; i<n; i++){
            if(max<arr.at(i)){
                max = arr.at(i); 
                idx_max = i;     
            }
        }
        // Strip out the edge condition [max,...] or [...,max]
        if((idx_max == n-1) || (idx_max == 0)){
            return false;            
        }
        if((arr.at(0) == arr.at(1)) || arr.at(n-1)==arr.at(n-2)){
            return false;
        }
        
        if((idx_max < n-1) && (idx_max > 0) ){
            
            // Left side 0~idx_max-1
            for(int i=0; i<idx_max; i++){
                if(L_max<arr.at(i)){
                    L_max=arr.at(i);
                    idx_L_max = i;
                }else{
                    // violate increasing
                    return false;
                }
            }
            // check left partition:
            if( (L_max<max) && (idx_L_max<idx_max) ){
                //Right side idx_max~n-1
                for(int i=n-1; i>idx_max; i--){
                    if(R_max<arr.at(i)){
                        R_max=arr.at(i);
                        idx_R_max = i;
                    }else{
                        // violate strictly decreasing
                        return false;
                    }
                }
                //check right partition:
                if( (R_max<max) && (idx_R_max>idx_max) ){
                    
                    cout << "L_max="<< L_max << ",index=" << idx_L_max << '\n';
                    cout << "* max="<< max << ",index=" << idx_max << '\n';
                    cout << "R_max="<< R_max << ",index=" << idx_R_max << '\n';

                    return true;
                }else{
                    return false;
                }
                
                
            }else{
                // left partition something wrong! [increasing?]
                return false;
            }
        }
        // all conditions above were checked fail, return false
        return false;
    }
};

int main(){

    //vector<int> arr{1,7,9,5,4,1,2}; // expect false 
    //vector<int> arr{4,4,3,2,1}; // expect false
    //vector<int> arr{0,3,2,1}; // expect true
    //vector<int> arr{6,7,7,8,6}; // expect false
    vector<int> arr{0,8,11,14,26,27,29,31,38,39,41,44,45,51,52,51,50,49,48,47,46,45,44,42,41,40,39,38,37,36,35,34,33,32,31,30,28,27,26,25,24,23,22,20,19,18,17,16,14,12,11,10,9,8,6,5,4,3,2,0}; // expect true

    bool result;

    Solution mysol;

    result = mysol.validMountainArray(arr);

    cout << result << '\n';

    return 0L;


}