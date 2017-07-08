#include<iostream>
#include<vector>
#include<cassert>

using namespace std;

int findMaxConsecutiveOnes(vector<int>& nums) {
	int maxOnes = 0;
	int currCount = 0;
	for(auto elems : nums){
		if(elems == 0){
			if(maxOnes < currCount){
				maxOnes = currCount;
				currCount = 0;
			}
			else{
				currCount = 0;
			}
		}
		else{
			currCount++;
		}
	}

	if(maxOnes < currCount){
		maxOnes = currCount;
	}

	return maxOnes;
}

int main(){
	{
		vector<int> v = {1,1,1,1};
		assert(findMaxConsecutiveOnes(v) == 4);
	}

	{
		vector<int> v = {0,1,1,0,1,1,1};
		assert(findMaxConsecutiveOnes(v) == 3);
	}

	{
		vector<int> v = {0,0,0,0,0,0,0};
		assert(findMaxConsecutiveOnes(v) == 0);
	}

	{
		vector<int> v = {1,1,0,1};
		assert(findMaxConsecutiveOnes(v) == 2);
	}

}
