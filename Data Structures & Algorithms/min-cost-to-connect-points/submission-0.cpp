class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        unordered_map<int, vector<pair<int,int>>> adj;
        int N = points.size();
        for(int i=0;i<N;i++){
            int x1=points[i][0];
            int y1=points[i][1];
            for(int j=i+1;j<N;j++){
                int x2=points[j][0];
                int y2=points[j][1];
                int dist = abs(x1-x2)+abs(y1-y2);
                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }

        unordered_set<int> visit;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;

        minH.push({0,0});
        int res=0;
        while(visit.size()<N){
            auto curr = minH.top();
            minH.pop();
            int d=curr.first;
            int i=curr.second;
            if(visit.count(i)){
                continue;
            }
            res+=d;
            visit.insert(i);

            for( auto nei : adj[i]){
                int neiD=nei.first;
                int neiI=nei.second;
                if(!visit.count(neiI)){
                    minH.push({neiD,neiI});
                }
            }
        }
        return res;
    }
};
