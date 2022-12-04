class Solution {
public:
    vector<int> storage = {1,2};
    int climbStairs(int n){
        if (n == 1){return 1;}
        if (n == 2){return 2;}
        while (n > 2){
            storage.push_back(storage[storage.size()-1]+storage[storage.size()-2]);
            n--;
        }
        return storage[storage.size()-1];
    }
};