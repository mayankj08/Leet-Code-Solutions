#include <vector>
#include <algorithm>
#include <iostream>

/*
 *  Logic:
 *      We want to find min of max so sorting the number
 *      and selecting second number from sorted list should
 *      be the required number
 *  Compile with -std=c++11
 */

int arrayPairSum(std::vector<int>& nums){
    std::sort(nums.begin(), nums.end());

    auto len = nums.size();
    int sum=0;
    for(int i=0;i<len;i=i+2){
        sum += nums[i];
    }
    return sum;
}

int main(){
    std::vector<int> nums{1,4,3,2};
    std::cout << arrayPairSum(nums) << '\n';

}
