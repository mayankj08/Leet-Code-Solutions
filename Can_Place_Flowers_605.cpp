#include <iostream>
#include <vector>
#include <iomanip>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {

    if(flowerbed.size() == 0 and n != 0)
        return false;

    if(n == 0){
        return true;
    }

    bool isLastFree;
    if(flowerbed[0] == 0){
        isLastFree = true;
    }
    else{
        isLastFree = false;
    }

    int accom = 0;

    bool isNextFree = false;
    bool isCurrFree = false; 

    if(flowerbed[0] == 0 and flowerbed.size() >1 and flowerbed[1] == 0){
        isLastFree = false;
        accom++;
    }

    if(accom >= n)
        return true;

    for(int i=1;i<flowerbed.size()-1;i++){

        if(flowerbed[i] == 0){
            isCurrFree = true;
        }
        else{
            isCurrFree = false;
        }

        if(flowerbed[i+1] == 0){
            isNextFree = true;
        }
        else{
            isNextFree = false;
        }

        //std::cout << isLastFree << " " <<isCurrFree << " " << isNextFree << std::endl;

        if(isLastFree == true and isNextFree == true and isCurrFree == true){
            accom ++;
            isLastFree = false;
        }
        else{
            isLastFree = isCurrFree;
        }

        if(accom >= n)
            return true;

    }

    if(flowerbed[flowerbed.size()-1] == 0){
        isCurrFree = true;
    }
    else{
        isCurrFree = false;
    }

    //std::cout << isLastFree << " " <<isCurrFree  << std::endl;
    if(isLastFree == true and isCurrFree == true){
        accom++;
    }

    if(accom >= n)
        return true;

    return false;

}

int main(){
    std::vector<int> inp = {0,0};
    std::cout << std::boolalpha << canPlaceFlowers(inp,1);
}
