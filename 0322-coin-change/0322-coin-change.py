class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        dp = [amount+1 for i in range(amount+1)]

        coins.sort()
        dp[0] = 0
        for i in range(amount+1):
            for j in range(len(coins)):
                coin = coins[j]
                if coin == i:
                    dp[i] = 1
                elif coin < i:
                    dp[i] = min(dp[i], 1 + dp[i-coin])
                else:
                    break
        
        return dp[amount] if dp[amount] != amount+1 else -1

