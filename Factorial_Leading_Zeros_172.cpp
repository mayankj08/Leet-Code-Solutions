#include<cassert>
#include<climits>

int trailingZeroes(int n){
    int numZeros = 0;

    for(long long i=5;n/i>0;i=i*5){
        numZeros = numZeros + n/i;
    }   
    return numZeros;
}

int main(){
    assert(trailingZeroes(5) == 1);
    assert(trailingZeroes(101) == 24);
    assert(trailingZeroes(1000) == 249);
    assert(trailingZeroes(0) == 0);
    assert(trailingZeroes(-10) == 0);
    assert(trailingZeroes(1808548329) == 452137076);
    trailingZeroes(INT_MAX);
}
