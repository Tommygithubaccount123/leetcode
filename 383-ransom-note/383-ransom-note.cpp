class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> storage;
        for (auto i : magazine){
            storage[i]++;
        }
        
        for (auto i : ransomNote){
            if (storage.find(i)!=storage.end()){
                if (storage[i] < 1){return false;}
                storage[i] -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};