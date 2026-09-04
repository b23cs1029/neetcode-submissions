class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       int inf=INT_MAX;

       vector<int> dist(n, inf);
       dist[k-1]=0;
    for(int i=0;i<n-1;i++){
        for(auto t:times){
            int u=t[0]-1; int v=t[1]-1; int w=t[2];
            if(dist[u]!=inf && dist[u]+w<dist[v]){
                dist[v]=dist[u]+w;
            }
        }
    } 

       int res= *max_element(dist.begin(),dist.end());
       return res==inf?-1:res;
    }
};
