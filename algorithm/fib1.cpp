#include <iostream>
#include <vector>
using namespace std;


int main(){
	long n=0, res=0;

	cout << "fibinacci Nth term: " ;
	cin >> n;
	cout << '\n';
	if(n == 0){ 
	   res=0; 
	
	} else if(n==1 || n==2){
		res=1;
	}
	else{
	   		   
	   long num1=0;
	   long num2=1;
	   long num3=num2+num1;
	   
	   long i=2;
	   while(i<n){
	      num1=num2;
	      num2=num3;	      
	      num3=num2+num1;
              i++;		      
	   }
	   
   	   res=num3;	   
	}

	cout << "ans= " << res << '\n'; 


return 0L;
}
