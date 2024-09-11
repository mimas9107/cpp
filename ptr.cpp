#include <iostream>
#include <cstring>
using namespace std;

int mystrlen(char *mystr){
    if(*mystr=='\0'){
        return 0;
    }
    char *ptr;
    int i=0;
    
    while( *(mystr+i) != '\0' ){
        ptr = mystr+i; // Debug中讀取 ptr+i看 ptr變化. 
        i=i+1;
    }    
    //cout << i << '\n';
    
    return i;
}
int main(){

    int a=100, *p;
    p = &a;

    int &b=a;

    cout << a << '\n';
    cout << p << '\n';
    cout << *p << '\n';
    cout << b << '\n';
    cout << &b << '\n';

    string s="c++";
    string *ps;
    ps = &s;
    *ps="123";
    cout << s << '\n';
    cout << ps << '\n';
    cout << *ps << '\n';

    char src[]="hi";
    char dest[]="jane!$#";
    char *src2 = new char[16];
    strcpy(src2, "world hello");
    cout << src[0]<< src[1] << src[2] << src[3] << src[5] << src[9] << src[15] << src[16] <<src[17] << '\n'; // 這句很嚴重. 超過 src的索引卻存取到 dest的記憶體位置.
    // 直接用 []超過邊界去存取, compiler不會報錯, 代表需要自己掌握與檢查.
    // 或是改用 std::string 來建這個變數(物件), 可以使用 at()超出邊界會被檢查到, 但犧牲效能.
    
    cout << sizeof(src) << '\n';
    cout << src << ", len=" << mystrlen(src) << '\n'; 
    cout << dest << ", len=" << mystrlen(dest) << '\n';
    cout << src2 << ", len=" << mystrlen(src2) << '\n';
    delete src2;
    
    return 0L;
}