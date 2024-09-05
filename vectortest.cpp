#include <iostream>
#include <string>
#include <vector>

void passByRef(const std::vector<int> &arr){
    for(int i=0; i<arr.size(); i++){
        std::cout << arr[i] << std::endl;
    }
}

int main(int argc, char *argv[]){
    std::cout << "==== my vector container test01 ====" << std::endl;
    std::string name{"Justin"};
    std::cout << name << " has " << name.length() << " characters" << std::endl;

    std::vector<int> primes{2,3,5,7};
    primes.resize(6);
    std::cout << "primes has " << primes.size() << " elements" << std::endl;
    std::cout << "The first element is " << primes[0] << ", mem addr=" << &(primes[0]) << std::endl;
    std::cout << "The second element is " << primes[1] << ", mem addr=" << &(primes[1]) << std::endl;
    
    passByRef(primes);

    return 0L;
}