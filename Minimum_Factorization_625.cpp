#include<iostream>
#include<vector>
#include<cassert>
#include<algorithm>
#include<string>

int smallestFactorization(int a){
    std::vector<int> digits;

    if(a==1)
        return 1;
    else if(a==0)
        return 0;

    for(int i=9;i>1;i--){
        while(1){
            //std::cout << a << '\n';
            if(a%i == 0){
                a = a/i;
                digits.push_back(i);
            }
            else{
                break;
            }
        }

    }

    std::string out;

    if(a == 1){
        for(int i=digits.size()-1;i>=0;i--){
            out = out + std::to_string(digits[i]);
        }
    }
    else{
        return 0;
    }

    
    int ret;
    
    try{
        ret = std::stoi(out);
    }
    catch(const std::invalid_argument& ia){
        return 0;
    }
    catch (const std::out_of_range& oor){
        return 0;
    }

    return ret;
}

int main(){
    assert(smallestFactorization(48) == 68);
    assert(smallestFactorization(15) == 35);
    assert(smallestFactorization(111) == 0);
    assert(smallestFactorization(0) == 0);
    assert(smallestFactorization(1) == 1);
    assert(smallestFactorization(2) == 2);
    assert(smallestFactorization(25) == 55);
}
