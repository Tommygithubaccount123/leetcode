class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> storage;
        for (auto num : nums){
            storage[num]++;
        }
        
        int result = 0;
        for (auto num : nums){
            if (storage.find(num-1) == storage.end()){
                int len = 0;
                int next = num;
                while (storage.find(next) != storage.end()){
                        len++;
                        next++;
                }
                result = max(result, len);
            }
        }
        return result;
    }
};