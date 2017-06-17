#include<iostream>
#include<cassert>
#include<set>
#include<algorithm>

int nthUglyNumber(int n){

    int count = 1;
    unsigned long long currUgly = 1;
    std::set<unsigned long long> nextCandidates;

    while(count<n) {

        nextCandidates.insert(currUgly*2);
        nextCandidates.insert(currUgly*3);
        nextCandidates.insert(currUgly*5);

        // find minimum of all the numbers in nextCandidates
        auto iter = std::min_element(nextCandidates.begin(),nextCandidates.end());

        currUgly = *iter;
        nextCandidates.erase(iter);

        //std::cout << "Curr Count:" << count << '\n';
        count ++;
    }
    //std::cout << "Curr Ugly as returned is:" << currUgly << std::endl; 
    return currUgly;
}

int main(){
    assert(nthUglyNumber(1) == 1);
    assert(nthUglyNumber(3) == 3);
    assert(nthUglyNumber(5) == 5);
    assert(nthUglyNumber(6) == 6);
    assert(nthUglyNumber(7) == 8);
    assert(nthUglyNumber(10) == 12);

    std::cout << nthUglyNumber(150);
}
