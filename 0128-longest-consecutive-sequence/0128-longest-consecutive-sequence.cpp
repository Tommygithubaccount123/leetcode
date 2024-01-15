class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> storage(nums.begin(), nums.end());

        int result = 0;
        for (auto num : storage){
            int len = 1;
            if (storage.find(num-1) == storage.end()){
                int cur = num;
                while (storage.find(cur+1) != storage.end()){
                    len++;
                    cur++;
                }
            }
            result = max(result, len);
        }
        return result;

}

};