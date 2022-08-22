class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        
        for (int i=0; i<intervals.size(); i++){
            if (i + 1 == intervals.size()){
                result.push_back(intervals[i]);
                break;
            }
            if (intervals[i][1] < intervals[i+1][0]){
                result.push_back(intervals[i]);
                continue;
            }
            
            vector<int> merge = intervals[i];
            while (i+1 < intervals.size() && merge[1] >= intervals[i+1][0]){
                merge[0] = min(merge[0], intervals[i+1][0]);
                merge[1] = max(merge[1], intervals[i+1][1]);
                i += 1;
            }
            result.push_back(merge);
        }
        return result;
    }
};