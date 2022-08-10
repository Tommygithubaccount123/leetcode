class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>> storage;
        for (int i=0; i<points.size(); i++){
            int x = points[i][0];
            int y = points[i][1];
            int distance = (x*x + y*y);
            vector<int> group = {distance};
            for (auto j : points[i]){
                group.push_back(j);
            }
            storage.push(group);
            if (storage.size() > k){
                storage.pop();
            }
        }
        vector<vector<int>> result;
        while (!storage.empty()){
            vector<int> popped = storage.top();
            storage.pop();
            popped = {popped[1],popped[2]};
            result.push_back(popped);
        }
        return result;
    }
    
};