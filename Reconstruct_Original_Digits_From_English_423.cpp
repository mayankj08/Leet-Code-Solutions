#include<iostream>
#include<string>
#include<map>

/* 0 : zero
 * 1 : one
 * 2 : two
 * 3 : three
 * 4 : four
 * 5 : five
 * 6 : six
 * 7 : seven
 * 8 : eight
 * 9 : nine
 *
 * z : zero
 * (total o - u - w)  : one
 * w : two 
 * r - u : three
 * u : four
 * remaining f five
 * x : six
 * v : remaining seven
 * t : remaining eight
 * n : remaining ninne
 */


std::string originalDigits(std::string str){
    std::string out = "";
    
    std::map<char,int> count;

    for(auto ch : str){
        auto iter = count.find(ch);
        if(iter == count.end()){
            count[ch] = 1;
        }
        else{
            count[ch] = count[ch]+1;
        }
    }

    // Look for zero
    int zeroCount = count['z'];
    for(int i=0;i<zeroCount;i++){
        out += "0";
    }

    count['z'] = count['z'] - zeroCount;
    count['e'] = count['e'] - zeroCount;
    count['r'] = count['r'] - zeroCount;
    count['o'] = count['o'] - zeroCount;

    // one
    int oneCount = count['o'] - count['u'] - count['w'];
    for(int i=0;i<oneCount;i++){
        out += "1";
    }

    count['o'] = count['o'] - oneCount;
    count['n'] = count['n'] - oneCount;
    count['e'] = count['e'] - oneCount;

    // two
    int twoCount = count['w'];
    for(int i=0;i<twoCount;i++){
        out += "2";
    }

    count['t'] = count['t'] - twoCount;
    count['w'] = count['w'] - twoCount;
    count['o'] = count['o'] - twoCount;

    // three
    int threeCount = count['r'] - count['u'];
    for(int i=0;i<threeCount;i++){
        out += "3";
    }

    count['t'] = count['t'] - threeCount;
    count['h'] = count['h'] - threeCount;
    count['r'] = count['r'] - threeCount;
    count['e'] = count['e'] - threeCount;
    count['e'] = count['e'] - threeCount;

    // four
    int fourCount = count['u'];
    for(int i=0;i<fourCount;i++){
        out += "4";
    }

    count['f'] = count['f'] - fourCount;
    count['o'] = count['o'] - fourCount;
    count['u'] = count['u'] - fourCount;
    count['r'] = count['r'] - fourCount;

    // five
    int fiveCount = count['f'];
    for(int i=0;i<fiveCount;i++){
        out += "5";
    }

    count['f'] = count['f'] - fiveCount;
    count['i'] = count['i'] - fiveCount;
    count['v'] = count['v'] - fiveCount;
    count['e'] = count['e'] - fiveCount;

    // six
    int sixCount = count['x'];
    for(int i=0;i<sixCount;i++){
        out += "6";
    }

    count['s'] = count['s'] - sixCount;
    count['i'] = count['i'] - sixCount;
    count['x'] = count['x'] - sixCount;

    // seven
    int sevenCount = count['v'];
    for(int i=0;i<sevenCount;i++){
        out += "7";
    }

    count['s'] = count['s'] - sevenCount;
    count['e'] = count['e'] - sevenCount;
    count['v'] = count['v'] - sevenCount;
    count['e'] = count['e'] - sevenCount;
    count['n'] = count['n'] - sevenCount;

    // eight
    int eightCount = count['t'];
    for(int i=0;i<eightCount;i++){
        out += "8";
    }

    count['e'] = count['e'] - eightCount;
    count['i'] = count['i'] - eightCount;
    count['g'] = count['g'] - eightCount;
    count['h'] = count['h'] - eightCount;
    count['t'] = count['t'] - eightCount;

    // nine
    int nineCount = count['n']/2;
    for(int i=0;i<nineCount;i++){
        out += "9";
    }

    count['n'] = count['n'] - nineCount;
    count['i'] = count['i'] - nineCount;
    count['n'] = count['n'] - nineCount;
    count['e'] = count['e'] - nineCount;

    return out;
}

int main(){
    std::string str = "fviefuro";
    std::cout << originalDigits(str);
}
