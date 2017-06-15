#include<iostream>
#include<vector>
#include<set>
#include<cassert>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2){
    std::set<int> s1 (nums1.begin(),nums1.end());
    
    std::set<int> ret;
    for(auto elem : nums2){
        if(s1.find(elem) != s1.end()){
            ret.insert(elem);
        }
    }

    std::vector<int>retVec (ret.begin(),ret.end());

    return retVec;
}

int main(){

    {    
        std::vector<int> v1 = {1,2,2,1};
        std::vector<int> v2 = {2,2};
        std::vector<int> ret = intersection(v1,v2);

        assert(ret.size() == 1);
        assert(ret[0] = 2);
    }

    {    
        std::vector<int> v1 = {};
        std::vector<int> v2 = {};
        std::vector<int> ret = intersection(v1,v2);

        assert(ret.size() == 0);
    }

    {    
        std::vector<int> v1 = {};
        std::vector<int> v2 = {3,3};
        std::vector<int> ret = intersection(v1,v2);

        assert(ret.size() == 0);
    }


    {    
        std::vector<int> v1 = {1,2,3,4,5};
        std::vector<int> v2 = {1,2,3,4,5};
        std::vector<int> ret = intersection(v1,v2);

        assert(ret.size() == 5);
    }
}
