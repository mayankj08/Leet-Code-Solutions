#include <iostream>
#include <vector>

using namespace std;

class Solution {

    public:

        bool canGetSum(const vector<int>& nums,int desiredSum,int ind,int currSum) {

            std::cout << "index = " << ind << " " << "currSum = " << currSum << " " <<  std::endl;

            if(currSum == desiredSum){
                return true;
            }

            if(ind >= nums.size()){
                return false;
            } 

            bool ret;
            currSum = currSum - nums[ind];
            ret = canGetSum(nums,desiredSum,ind+1,currSum);
            if(ret == true)
                return true;

            currSum = currSum + nums[ind];
            ret = canGetSum(nums,desiredSum,ind+1,currSum);
            if(ret == true)
                return true;

        }

        bool canPartition(vector<int>& nums) {
            // Find sum of all the numbers in nums
            int sum = 0;
            for(auto num : nums){
                sum += num;
            }

            // if sum is odd then for sure we can't 
            // divide input array into two arrays so that
            // sum of both the new arrays are same
            if(sum % 2 != 0){
                return false;
            }

            // We need sum of new array to be half of sum of 
            // whole array
            sum = sum/2;

            // Also, in case sum if even number then too not in every
            // case we can divide input array into array so that sum
            // of both the new divided arrays are same

            // Let's get a bit vector with all elements 
            // being 1. 1 implies we are including that element
            // as part of our sum

            int currSum = 0;
            for(auto num : nums){
                currSum += num;
            }
            return canGetSum(nums,sum+100,0,currSum);


        }

};

int main(){

    Solution sol;

    vector<int> nums = {1,5,11,5};

    std::cout << std::boolalpha 
        << sol.canPartition(nums)
        << std::endl ;

    return 0;

}
