class Solution {
    unordered_map<int,vector<int>> premap;
    unordered_set<int>visiting;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //cycle detection
        for(int i=0;i<numCourses;i++){
            premap[i]={};
        }
        for(auto& pre: prerequisites){
            premap[pre[0]].push_back(pre[1]);
        }
        for(int c=0;c<numCourses;c++){
            if(!dfs(c)){
                return false;
            }
        }
        return true;
    }

    bool dfs(int crs){
        if(visiting.count(crs)){
            return false;
        }
        if(premap[crs].empty()){
            return true;
        }

        visiting.insert(crs);
        for(int adj : premap[crs]){
            if(!dfs(adj)){
                return false;
            }
        }
        visiting.erase(crs);
        premap[crs].clear();
        return true;
    }
};
