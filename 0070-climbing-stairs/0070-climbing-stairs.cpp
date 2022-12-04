class Solution {
public:
    vector<int> storage = {1,2};
    int climbStairs(int n){
        if (n == 1){return 1;}
        if (n == 2){return 2;}
        for (int i=2; i<n; i++){
            storage.push_back(storage[i-2] + storage[i-1]);
        }
        return storage[storage.size()-1];
    }
};