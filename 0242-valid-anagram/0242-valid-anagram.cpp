class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() > t.size()){return false;}
        unordered_map<char, int> storage;
        for (auto chara : s){
            storage[chara]++;
        }
        for (auto chara : t){
            if (storage.find(chara) == storage.end()){return false;}
            storage[chara]--;
            if (storage[chara] < 0){return false;}
        }
        
        return true;
    }
};