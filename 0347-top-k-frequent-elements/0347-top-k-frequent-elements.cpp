class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> storage;
        for (auto num : nums){
            storage[num]++;
        }
        priority_queue<pair<int,int>> order;
        for (auto elem : storage){
            pair<int,int> p = {elem.second, elem.first};
            order.push(p);
        }
        
        vector<int> result;
        for (int i=0; i<k; i++){
            pair<int,int> top = order.top();
            order.pop();
            result.push_back(top.second);
        }
        return result;
    }
};