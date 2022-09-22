class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {        
        if (intervals.size() == 1){return intervals;}
        
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end());
        int resultIndex = 0;
        result.push_back(intervals[0]);
        for (int i=1; i<intervals.size(); i++){
            if (result[resultIndex][1] >= intervals[i][0]){
                result[resultIndex][1] = max(result[resultIndex][1], intervals[i][1]);
            } else {
                result.push_back(intervals[i]);
                resultIndex += 1;
            }
        }
        return result;
    }
};