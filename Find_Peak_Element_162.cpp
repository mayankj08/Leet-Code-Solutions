#include<iostream>
#include<vector>
#include<climits>

int findPeakElement(std::vector<int>& nums){
    int prev = INT_MIN;
    int sz = nums.size();    

    if((nums[0] == INT_MIN and sz == 1) or (nums[0] == INT_MIN and nums[0] > nums[1])){
        return 0;
    }

    for(int i=0;i<sz;i++){
        if(i == sz-1){
            if(prev < nums[i]){
                return i;
            }
        }
        else if(prev < nums[i] and nums[i+1] < nums[i])
            return i;        

        prev = nums[i];
    }
    return -1;
}

int main(){
    std::vector<int> inp = {-2147483648,-2147483647};
    std::cout << findPeakElement(inp) << '\n';
}
