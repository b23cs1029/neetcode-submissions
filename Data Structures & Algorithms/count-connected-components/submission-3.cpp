class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n,0);
        int res=0;
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        for(int i=0;i<n;i++){
            if(!visit[i]){
                dfs(i,adj,visit);
                res++;
            }
        }
        return res;
        
    }
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visit){
        visit[node]=true;
        for(int nei :adj[node]){
            if(!visit[nei]){
                dfs(nei,adj,visit);
            }
        }
    }

};
