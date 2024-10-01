#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // int i = m-1; // 2
        // int j = n-1; // 2
        // int k = m+n-1; // 5
        
        // [2,5,6] n=3
        //  0 1 2 3 4 5
        // [1,2,3,0,0,0] m=3
        
        for(int i = m+n-1; i>-1; i--){
            if(m==0){
                break;
            }
            if(n==0){
                nums1.at(i)=nums1.at(n-1);
                n=n-1;
            }
            if(nums2.at(n-1) > nums1.at(m-1)){
                nums1.at(i) = nums2.at(n-1);
                n=n-1;
            }else{
                nums1.at(i) = nums1.at(m-1);
                m=m-1;
            }
            
        }
        

    }    
};

int main(){ //nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
    vector<int> a1{1,2,3,0,0,0}, a2{2,5,6};
    int m=3, n=3;
    Solution mysol;
    mysol.merge(a1, m, a2, n);

    for(int i=0; i<m+n; i++){
        cout << a1.at(i) << " ";
    } cout << '\n';

    return 0L;
}