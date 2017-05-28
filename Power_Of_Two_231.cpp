/* 
 * Compile with flage -std=c++11
 *
 * Logic :
 * Given number is power of two if 
 * all the bits except first bit are 0
 * and the first bit should be 1
 */

#include <iostream>

bool isPowerOfTwo(int n){
    // Get left most binary digit
    do{
        if(n == 1){
            return true;
        }

        if ((n&0b1) == 0b0){
            n = (n>>1);
        }
        else{
            return false;;
        }
    }while(n);
    return false;
}

int main(){
    int n;
    while(1){
        std::cin >> n;
        std::cout << std::boolalpha << isPowerOfTwo(n) << '\n';
    }
}
