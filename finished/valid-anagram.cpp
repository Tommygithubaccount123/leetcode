class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {return false;}
        
        unordered_map<char,int> storage;
        
        for (auto i : s){
            if (storage.find(i)==storage.end()){
                storage[i] = 1;
            } else {
                storage[i] += 1;
            }
        }
        
        for (auto i : t){
            if (storage.find(i)==storage.end()){
                return false;
            } else {
                storage[i] -= 1;
                if (storage[i] < 0){
                    return false;
                }
            }
        }
        
        unordered_map<char,int>::iterator it = storage.begin();
        while(it!=storage.end()){
            if (it->second!=0){
                return false;
            }
            it++;
        }
        return true;
    }
};