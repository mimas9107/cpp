#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        for(int i = m+n-1; i>-1; i--){
            if(n==0){
                break;
            }
            if(m==0){
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

    for(vector<int>::iterator it=a1.begin(); it != a1.end(); it++){
        cout << *it << " ";
    }
    cout << '\n';
    return 0L;
}