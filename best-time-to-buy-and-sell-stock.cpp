class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int small = INT_MAX;
        int val = 0;
        for (int i=0; i<prices.size(); i++){
            small = min(small, prices[i]);
            val = max(val, prices[i]-small);
        }
        return val;
    }
};