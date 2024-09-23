#include <iostream>
#include <vector>
using namespace std;
int main(){

    vector<vector<int>> v2d{{1,1,0},{0,1,1},{1,0,1}};
    // 用 int i , j 來索引 vector取值.
    for(int i=0; i<v2d.size(); i++){
        for(int j=0; j<v2d[i].size(); j++){
            cout << v2d[i][j] << " ";
        }
        cout << '\n';

    }
    cout << " ==== " << '\n';
    //用 ::iterator來操作 vector取值.
    for(vector<vector<int>>::iterator it1=v2d.begin(); it1 != v2d.end(); it1++){
        // 這邊 iterator為特殊性質指標, 故取其成員方法要用 "->"
        for(vector<int>::iterator it2=it1->begin(); it2 != it1->end(); it2++){
            cout << *it2 << " ";
        }
        cout << '\n';
    }

    // 插入新的vector元素在尾端
    cout << "====" << '\n';
    v2d.push_back({1,1,1});

    for(vector<vector<int>>::iterator it1=v2d.begin(); it1 != v2d.end(); it1++){
        for(vector<int>::iterator it2=it1->begin(); it2 != it1->end(); it2++){
            cout << *it2 << " ";
        }
        cout << '\n';
    }

    cout << "=====" << '\n';
    // 用 iterator指定位置插入新 vector元素:

    vector<vector<int>>::iterator it3 = v2d.begin();
    v2d.insert( it3+1, {1,2,4});

    for(vector<vector<int>>::iterator it1=v2d.begin(); it1 != v2d.end(); it1++){
        for(vector<int>::iterator it2=it1->begin(); it2 != it1->end(); it2++){
            cout << *it2 << " ";
        }
        cout << '\n';
    }

    cout << "=====" << '\n';
    // 將尾端刪除 用 pop_back()
    v2d.pop_back();
    for(vector<vector<int>>::iterator it1=v2d.begin(); it1 != v2d.end(); it1++){
        for(vector<int>::iterator it2=it1->begin(); it2 != it1->end(); it2++){
            cout << *it2 << " ";
        }
        cout << '\n';
    }
    
    cout<<"====="<<'\n';
    // 用 iterator指定位置刪除:
    vector<vector<int>>::iterator it4=v2d.begin();
    v2d.erase(it4+2);
    for(vector<vector<int>>::iterator it1=v2d.begin(); it1 != v2d.end(); it1++){
        for(vector<int>::iterator it2=it1->begin(); it2 != it1->end(); it2++){
            cout << *it2 << " ";
        }
        cout << '\n';
    }
    
    
    return 0L;


}

