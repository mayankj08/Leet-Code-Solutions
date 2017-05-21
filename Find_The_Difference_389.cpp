#include<iostream>
#include<unordered_map>
#include<string>

char findTheDifference(std::string s,std::string t){
    // Iterate over s and fill map
    std::unordered_map<char,int> sMap;
    for(int i=0;i<s.size();i++){
        auto iter = sMap.find(s[i]);
        if(iter == sMap.end()){ // Means elem is not foudn in sMap
            sMap[s[i]] = 1;
        }
        else{
             iter->second++;
        }
    } 

    // Now iterate over t and find elem in sMap
    for(int i=0;i<t.size();i++){
        auto iter = sMap.find(t[i]);
        if(iter == sMap.end() or iter->second == 0){
            return t[i];
        }
        else{
            iter->second--;
        }
    } 
    return '\0';
}


int main(){
    std::string s = "aa";
    std::string t = "aab";
    std::cout << findTheDifference(s,t) << '\n';
}
