#include <iostream>
#include <vector>
using namespace std;

int main(){
    system("chcp 65001");
    // 這邊用 [] 索引陣列取值要很小心, c/c++ 不會檢查邊界, 
    // 要自己控制邊界檢查. 允許的話盡量用 vector容器.
    int *arr = new int[10];
    int length=0;
    for(int i=0; i<10; i++){
        arr[i] = i+1;
        length++;
        
    }
    for(int n=0; n<length; n++){
        cout << arr[n] << " ";
    } 
    cout << '\n';    
     

    // kill 0th position of array:    
    cout << "==== " << " 刪除第1個元素 " << " ====" << '\n';
    for(int m=1;m<length; m++){
        arr[m-1]=arr[m];
        if(m == length-1){
            arr[m]=-99;
        }
    }
    for(int n=0; n<length; n++){
        cout << arr[n] << " ";
    } 
    cout << '\n';





    delete[] arr;
    return 0L;
}