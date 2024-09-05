#include <iostream>

using namespace std;

class robot{
public:
	char* name;
	
	robot(char* name){
		this->name = name;
		return;		
	}
	int say(){
		cout << "hello sir! I'm " << this->name << '\n';
		return 0L;
	}
    int info(){
        cout << "this= " << this << '\n';
        return 0L; 
    }
};

int main(int argc, char* argv[]){
    robot robot01("Bob");
    robot01.say();
    robot01.info();
return 0L;
}