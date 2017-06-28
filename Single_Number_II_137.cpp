#include<iostream>
#include<vector>
#include<cassert>
#include<map>

int singleNumber(std::vector<int>& nums) {
    std::map<int,int> dict;

    for(auto elem:nums){
        if(dict.find(elem) != dict.end()){
            dict[elem] = dict[elem]+1;
        }
        else{
            dict[elem] = 1;
        }
    }

    for(auto elem : dict){
        if(elem.second == 1)
            return elem.first;
    }
}

int main(){
    
    {
        std::vector<int> vec = {1,1,1,3};
        assert(singleNumber(vec) == 3);
    }

    {
        std::vector<int> vec = {1,1,3,1};
        assert(singleNumber(vec) == 3);
    }

    {
        std::vector<int> vec = {1,1,2,2,2,3,1};
        assert(singleNumber(vec) == 3);
    }

}
