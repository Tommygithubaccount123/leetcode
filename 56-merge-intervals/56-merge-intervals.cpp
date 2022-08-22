class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()==1){return intervals;}
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        result.push_back(intervals[0]);
        int result_index = 0;
        
        for (int i=1; i<intervals.size(); i++){
            if (result[result_index][1] < intervals[i][0]){
                result.push_back(intervals[i]);
                result_index += 1;
            } else {
                result[result_index][1] = max(result[result_index][1], intervals[i][1]);
            }
        }
        return result;
    }
};