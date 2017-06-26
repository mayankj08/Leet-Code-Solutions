#include<iostream>
#include<vector>
#include<climits>
#include<cassert>

int maximumProduct(std::vector<int>& nums) {
	std::sort(nums.begin(),nums.end());

	int size = nums.size();

	if(nums[0] >= 0){
		return (nums[size-1] * nums[size-2] * nums[size-3]);
	}
	else if(nums[0] < 0 and nums[1] >= 0){
		return(nums[size-1] * nums[size-2] * nums[size-3]);
	}
	else if(nums[0] < 0 and nums[1] < 0){
		auto prod1 = nums[0]*nums[1]*nums[size-1];
		auto prod2 = nums[size-1] * nums[size-2] * nums[size-3];
		if(prod1 > prod2){
			return prod1;
		}
		else{
			return prod2;
		}

	}

	return -1;

	
}

int main(){
	{
		std::vector<int> nums = {1,2,3};
		auto out = maximumProduct(nums);
		assert(out == 6);
	}

	{
		std::vector<int> nums = {0,2,3,6};
		auto out = maximumProduct(nums);
		assert(out == 36);
	}

	{
		std::vector<int> nums = {-1,2,3,4};
		auto out = maximumProduct(nums);
		assert(out == 24);
	}

	{
		std::vector<int> nums = {-2,-3,-5,4};
		auto out = maximumProduct(nums);
		assert(out == 60);
	}
	{
		std::vector<int> nums = {-1,-2,-3,4,5,6};
		auto out = maximumProduct(nums);
		assert(out == 120);
	}
	{
		std::vector<int> nums = {-1,-2,-3,-4};
		auto out = maximumProduct(nums);
		assert(out == -6);
	}
	{
		std::vector<int> nums = {-1,2,3,4};
		auto out = maximumProduct(nums);
		assert(out == 24);
	}
	{
		std::vector<int> nums = {-1,-2,-3,0};
		auto out = maximumProduct(nums);
		assert(out == 0);
	}

	return 0;
}
