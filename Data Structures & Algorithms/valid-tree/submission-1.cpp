class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<bool> visit(n,false);
        for(auto e : edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        if(!dfs(0,-1,adj,visit)){
            return false;
        }
        
        for(int i=0;i<n;i++){
            if(!visit[i]){
                return false;
            }
        }
        return true;

    }

    bool dfs(int node, int parent, vector<vector<int>>& adj, vector<bool>& visit){
        visit[node]=true;
        for(int nei :adj[node]){
            if(nei==parent){
                continue;
            }
            if(visit[nei]){
                return false;
            }
            if(!dfs(nei, node, adj, visit)) return false;
        }
        return true;
    }
};
