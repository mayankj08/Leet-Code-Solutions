#include<string>
#include<iostream>

using namespace std;

int countSubstrings(string s){
    
    auto isPalindrome = [](std::string s){
        int len = s.length();
        for(int i=0;i<len/2;i++){
            if(s[i] != s[len-i-1])
                return false;
        }
        return true;
    };

    auto st = s.begin();
    auto end = s.begin()+1;
    int res = 0;
    while(1){
        
        string str(st,end);
        std::cout << str << " " << isPalindrome(str) << '\n';
        if(isPalindrome(str)){
            res++;
        }
        end++;
        if(end == s.end()){
            st++;
            if(st != s.end())
                end = st+1;
        }       

 
        if(st == s.end())
            break;
    }
    return res;
}

int main(){
    std::cout << countSubstrings("aaa") << '\n';
    std::cout << countSubstrings("abc") << '\n';
    std::cout << countSubstrings("abba") << '\n';
}
