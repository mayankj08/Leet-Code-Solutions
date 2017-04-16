/*
 * Compile it as : g++ -std=c++11 Fizz_Buzz_412.cpp
 */

#include <iostream>
#include <vector>
#include <string>

class Solution {
	public:
        std::vector<std::string> fizzBuzz(int n) {
			std::vector<std::string> out;
			
			for(long i=1;i<=n;i++){

				bool isMultipleOfThree = (i%3==0);
				bool isMultipleOfFive = (i%5==0);

				if(isMultipleOfThree and isMultipleOfFive){
					out.push_back("FizzBuzz");
				}
				else if(isMultipleOfThree){
					out.push_back("Fizz");
				}
				else if(isMultipleOfFive){
					out.push_back("Buzz");
				}
				else{
					out.push_back(std::to_string(i));
				}
			}

			return out;
		}
};

int main(){

	int n;
	std::cin >> n;
	Solution sol;

	std::vector<std::string> out = sol.fizzBuzz(n);

    // Now print the output
    for(auto str : out){
        std::cout << str << "\n";
    }

	return 0;
}
