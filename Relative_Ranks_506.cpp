#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
struct ath{
    int pos;
    int score;
};

struct {
    bool operator()(ath a, ath b) const
    {
        return a.score > b.score;
    }   
} customLess;

std::vector<std::string> findRelativeRanks(std::vector<int>& nums) {
    std::vector<ath> aths;
    aths.resize(nums.size());
    for(int i=0;i<nums.size();i++){
        aths[i].pos = i;
        aths[i].score = nums[i];
    }
    
    std::sort(aths.begin(),aths.end(),customLess);

    std::vector<std::string> ret;
    ret.resize(nums.size());

    for(int i=0;i<nums.size();i++){

        if(i==0){
            ret[aths[i].pos] = "Gold Medal";
        }
        else if(i==1){
            ret[aths[i].pos] = "Silver Medal";
        }
        else if(i==2){
            ret[aths[i].pos] = "Bronze Medal";
        }
        else{
            ret[aths[i].pos] = std::to_string(i+1);
        }
    }

    return ret;
}

int main(){
    
    std::vector<int> vec = {5,4,3,2,1};
    auto ret = findRelativeRanks(vec);    
    for(int i=0;i<ret.size();i++){
        std::cout<< ret[i] << '\n';    
    }

    return 0;
}
