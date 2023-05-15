class Solution {
public:
    vector<int> dp = {0,1};
    int fib(int n) {
        if (n < dp.size()){
            return dp[n];
        }
        dp.push_back(fib(n-1) + fib(n-2));
        return dp[n];
    }
};