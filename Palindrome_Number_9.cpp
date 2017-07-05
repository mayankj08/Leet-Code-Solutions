#include<string>
#include<cassert>
#include<iostream>

using namespace std;

bool isPalindrome(int x,bool debug=false) {

    if(x<0)
        return false;

	string xStr = to_string(x);
	int len = xStr.length();

	for(int i=0;i<len/2;i++){
        if(debug){
            std::cout << "i:" << i << " len-i-i:" << len-1-i << '\n';
        }
		if(xStr[i] != xStr[len-1-i])
			return false;
	}

	return true;

}

int main(){
	assert(isPalindrome(1) == true);
	assert(isPalindrome(0) == true);
	assert(isPalindrome(100) == false);
	assert(isPalindrome(1001,true) == true);
	assert(isPalindrome(101) == true);
	assert(isPalindrome(11) == true);
	assert(isPalindrome(-11) == false);
	assert(isPalindrome(-121) == false);
	assert(isPalindrome(-1213) == false);
	assert(isPalindrome(-0) == true);
	assert(isPalindrome(3443) == true);
	assert(isPalindrome(34) == false);
	assert(isPalindrome(344534) == false);

}
