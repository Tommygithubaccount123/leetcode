class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> storage;
        for (auto num : nums){
            storage[num]++;
        }
        
        int counter = 1;
        int missing;
        int duplicate;
        for (auto num : nums){
            if (storage.find(counter)==storage.end()){
                missing = counter;
            } else {
                if (storage[num] == 2){
                    duplicate = num;
                }
            }
            counter++;
        }
        
        return {duplicate, missing};
    }
};