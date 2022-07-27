class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> storage;
        for (auto i : magazine){
            if (storage.find(i) == storage.end()){
                storage[i] = 0;
            } else {
                storage[i] += 1;
            }
        }
        
        for (auto i : ransomNote){
            if (storage.find(i)!=storage.end()){
                if (storage[i] < 0){return false;}
                storage[i] -= 1;
            } else {
                return false;
            }
        }
        return true;
    }
};