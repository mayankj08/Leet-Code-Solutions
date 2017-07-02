#include<cassert>
#include<iostream>
#include<cmath>

bool judgeSquareSum(int c){
	int sqrRoot = std::sqrt(c);

	for(int i=0;i<=sqrRoot;i++){
		auto temp = c-(i*i);
		int tempRoot = std::sqrt(temp);
		if(tempRoot*tempRoot == temp){
			//std::cout << "a is:" << i << " b is:" << tempRoot << "\n"; 
			return true;
		}
	}

	return false;
}

bool bruteForce(int c){
	for(int i=0;i<=c;i++){
		for(int j=0;j<=c;j++){
			if(i*i + j*j == c) return true;
		}
	}
	return false;
}


int main(){
	/*for(int i=0;i<10000;i++){
		std::cout << i << " " << bruteForce(i) << " " << judgeSquareSum(i) <<"\n";
		assert(bruteForce(i) == judgeSquareSum(i));
	}*/

	assert(judgeSquareSum(2147483645) == false);
}

