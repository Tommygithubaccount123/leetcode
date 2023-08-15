class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n==0){return 0;}
        
        int big = nums[0];
        unordered_map<int,int> storage;
        for (auto num : nums){
            storage[num]++;
            big = max(big,num);
        }
        
        
        vector<int> lefts;
        for (auto elem : storage){
            if (storage.find(elem.first-1) == storage.end()){
                lefts.push_back(elem.first);
            }
        }
        
        int result = 1;
        int cur = 1;
        for (auto left : lefts){
            cur = 1;
            for (int i=left+1; i<big+1; i++){
                if (storage.find(i) != storage.end()){
                    cur++;
                } else {
                    break;
                }
            }
            result = max(result,cur);
        }
        return max(cur,result);
    }
};