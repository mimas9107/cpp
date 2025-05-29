#include <iostream>
#include <map>
#include <string>

using namespace std;

int main(){

    map<string, int> mymaps ;
    mymaps.insert(pair<string,int>("hello",67));

    cout << mymaps["hello"] << '\n';

    return 0L;
}