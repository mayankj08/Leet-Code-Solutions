#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<functional>
#include<numeric>

using std::vector;
using std::accumulate;
using std::bit_xor;

int singleNumber(vector<int>& nums){
    return accumulate(nums.begin(),nums.end(),0,std::bit_xor<int>() );
}

int main(){
    
    {
        vector<int> v1 = {1,1,2,2,3,4,4};
        assert(singleNumber(v1)==3);
    } 
    {
        vector<int> v1 = {1,1,2,2,3,3,4};
        assert(singleNumber(v1)==4);
    }

    return 0;
}
