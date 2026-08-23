class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        vector<vector<int>> adj(n+1);
        for(auto e: edges){
            int  u=e[0]; int v=e[1];
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            vector<bool> visit(n+1,false);
            if(dfs(u,-1,adj,visit)){
                return {u,v};
            }
        }
        return {};
    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool> &visit ){
        if(visit[node]) return true;
        visit[node]=true;
        for(int nei : adj[node]){
            if(nei==parent){
                continue;
            }
            if(dfs(nei,node,adj,visit)){
                return true;
            }
        }
        return false;
    }
};
