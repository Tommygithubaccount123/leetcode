class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int result = 0;
        
        int r = 0;
        int small = prices[0];
        
        while (r<n){
            if (prices[r] < small){
                small = prices[r];
            } else if (prices[r] - small > result){
                result = prices[r] - small;
            }
            r++;
        }
        return result;
    }
};