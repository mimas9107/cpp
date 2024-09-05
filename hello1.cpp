#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
	if(argc != 1){
		for(int c=1; c<argc; c++)
		{
			cout << "arg" << c-1 << ": " << argv[c] << endl;

		}
	}else
	{
		cout << " ===== Hello world ===== " << endl;
		return 0L;
	}
	

return 0L;

}

