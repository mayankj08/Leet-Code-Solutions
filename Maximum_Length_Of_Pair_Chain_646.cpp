#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;

bool compare(std::vector<int> p1,std::vector<int> p2){
    if(p2[1] > p1[1]){
        return true;
    }
    return false;
}

int findLongestChain(vector<vector<int>>& pairs) {
    std::sort(pairs.begin(),pairs.end(),compare);
    
    int maxLen = 0;
    
    long lastBig = LONG_MIN;
    for(auto pair : pairs){
        if(lastBig < pair[0]){
            maxLen++;
            lastBig = pair[1];   
        }
    }
    return maxLen;
}

int main(){
    std::vector<std::vector<int>> v1 = {{INT_MIN,2},{9,10},{8,12},{7,8} };
    std::cout << findLongestChain(v1) << '\n';
}
