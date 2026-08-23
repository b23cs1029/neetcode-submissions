class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj(numCourses);
        vector<int> res;

        for(auto pre: prerequisites){
            indegree[pre[0]]++;
            adj[pre[1]].push_back(pre[0]);
        }
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
                res.push_back(i);
            }
        }
        int finish=0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            finish++;
            for(auto nei : adj[node]){
                indegree[nei]--;
                if(indegree[nei]==0){
                    q.push(nei);
                    res.push_back(nei);
                }
            }
        }
        if(finish==numCourses){
            return res;
        }
        else{
            return {};
        }
    }
};
