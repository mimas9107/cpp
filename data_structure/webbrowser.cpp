#include <iostream>
#include <string>
#include <stack>

// STL 函式庫應用 堆疊結構模擬瀏覽器 向前、向後運作：

using namespace std;

int main(){
    stack<string> backward_stack;
    stack<string> forward_stack;

    
    string c;
    string cur="http://www.acm.org";

    while(cin>>c && c!="QUIT"){
        if(c=="VISIT"){ // VISIT command
            backward_stack.push(cur);
            cin >> cur;
            cout << cur << '\n';
            while(forward_stack.empty() != true){
                forward_stack.pop();

            }
            
        }else if(c=="BACK"){ // BACK command
            if(backward_stack.empty()){
                cout << "Ignored" << '\n';
            }else{
                forward_stack.push(cur);
                cur = backward_stack.top();
                backward_stack.pop();
                cout << cur << '\n';
            }

        } else { // FORWARD command
            if(forward_stack.empty()){
                cout << "Ignored" << '\n';

            }else{
                backward_stack.push(cur);
                cur = forward_stack.top();
                forward_stack.pop();
                cout << cur << '\n';
            }
        }
    }
    return 0L;
}