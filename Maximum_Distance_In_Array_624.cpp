#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cassert>

int maxDistance(std::vector<std::vector<int>>& arrays){
    
    int numOfArrays = arrays.size();
    std::vector<int> maxValues ;
    std::vector<int> minValues ;

    for(int i=0;i<numOfArrays;i++){
        maxValues.push_back(*std::max_element(arrays[i].begin(),arrays[i].end()));
        minValues.push_back(*std::min_element(arrays[i].begin(),arrays[i].end()));
    }

    int maxDistance = INT_MIN;
    for(int i=0;i<numOfArrays;i++){
        for(int j=0;j<numOfArrays;j++){

            if(i==j)
                continue;

            if(maxValues[i]-minValues[j] > maxDistance){
                maxDistance = maxValues[i]-minValues[j];
            }
        }
    }
    return maxDistance;
}

int main(){
    std::vector<std::vector<int>> inp = {{1,2,100},
                                         {4,5},
                                         {1,2,3}};

    assert(maxDistance(inp) == 99);
}
