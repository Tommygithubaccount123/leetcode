class Solution {
public:
    int climbStairs(int n) {
        vector<int> storage = {1,2};
        if (n<=2){
            return storage[n-1];
        }
        for (int i=2; i<n; i++){
            storage.push_back(storage[i-2]+storage[i-1]);
        }
        return storage[n-1];
        
    }
};