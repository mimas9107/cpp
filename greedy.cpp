#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    // 貨物重量列表：
    int wi[] = {4,10,7,11,3,5,14,2,1,9,6,8};
    
    int len=sizeof(wi)/sizeof(wi[0]);
    cout << "貨物個數: " << len << '\n';
    cout << "貨物重量: ";
    for(int i=0; i< len; i++){
        cout << *(wi+i) << " ";
    }
    cout << '\n';

    sort(wi,wi+len);
    cout << "排序後貨物重量: ";
    for(int i=0; i< len; i++){
        cout << *(wi+i) << " ";
    }
    cout << '\n';
    double tmp=0.0;
    double c=30.0;
    int ans = 0;
    cout << "船可載重: " << c << '\n';
    for(int i=0; i< len; i++){

        tmp = tmp + wi[i];
        if(tmp <= c){
            ans++;
        }else{
            break;
        }
    }
    cout << "最後裝了幾個貨物: " << ans << '\n';
    return 0L;
}