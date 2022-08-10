class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> storage;
        for (int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = x*x + y*y;
            storage.push({distance, x, y});
            if (storage.size() > k){
                storage.pop();
            }
        }
        vector<vector<int>> result;
        while (!storage.empty()){
            vector<int> popped = storage.top();
            storage.pop();
            result.push_back({popped[1], popped[2]});
        }
        return result;
    }
    
};