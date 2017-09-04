class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char,int> hashMap;
        
        for(auto &ch:s){
            if(hashMap.find(ch) == hashMap.end()){
                hashMap[ch] = 1;
            }
            else{
                ++ hashMap[ch];
            }
                
        }
        
        for(auto &ch:t){
            auto iter = hashMap.find(ch);
            if(iter == hashMap.end() or iter->second == 0){
                return false;
            }
            else{
                --hashMap[ch];
                
                if(hashMap[ch] == 0){
                    hashMap.erase(iter);
                }
            }
        }
        
        if(hashMap.empty())
            return true;
        else
            return false;
        
        return true;
        
    }
};
