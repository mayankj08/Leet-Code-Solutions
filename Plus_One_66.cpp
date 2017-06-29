#include<vector>
#include<cassert>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	auto iter = digits.end();
	int toAdd = 1;

	while(iter != digits.begin()){
		iter--;
		auto sum = *iter + toAdd;
		*iter = sum%10;
		toAdd = sum/10;
	}

	if(toAdd != 0){
		digits.insert(iter,toAdd);
	}

	return digits;
}

int main(){

	vector<int> vec = {5,9,9};

	auto res = plusOne(vec);
	assert(res.size() ==4);

	return 0;
}
