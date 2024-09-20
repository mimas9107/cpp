#include <iostream>
#include <list>
// 士兵隊伍訓練
using namespace std;

int main(){

    int T, n;
    list<int> a;
    list<int>::iterator it;
    cin >> T;
    while(T--){
        cin >> n;
        a.clear();

        int k=2; // 先delete 喊2的士兵
        for(int i=1; i<=n; i++){
            a.push_back(i); // 存入士兵編號
        }
        while(a.size()>3){
            int cnt = 1;
            for(it=a.begin(); it!=a.end(); ){
                if(cnt++%k == 0){ // delete 喊k的士兵
                    it=a.erase(it); // it指向下一位的位址
                }else{
                    it++; // 指向下一位的位址
                }
            }
            k = (k==2?3:2);
        }
        for(it=a.begin(); it!=a.end(); it++){
            if(it!=a.begin()) { 
                cout << " ";
                cout << *it;
            }
        }
        cout << '\n';

    }
    
    return 0L;
}
