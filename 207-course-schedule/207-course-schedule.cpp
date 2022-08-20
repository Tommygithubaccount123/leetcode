class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses,0);
        vector<int> edges[numCourses]; //adjacency list
        
        for (auto pairs : prerequisites){
            edges[pairs[1]].push_back(pairs[0]);
        }
        
        for (int i=0; i<numCourses; i++){
            if (cycle(i, visited, edges)){
                return false;
            }
        }
        return true;
    }
    
    bool cycle(int index, vector<int>& vis, vector<int> edgeList[]){
        if (vis[index]==1){
            return true;
        }
        if (vis[index]==0){
            vis[index] = 1;
            for (auto edge : edgeList[index]){
                if (cycle(edge, vis, edgeList)){
                    return true;
                }
            }
        }
        vis[index] = 2;
        return false;
    }
};