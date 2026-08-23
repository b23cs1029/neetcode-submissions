class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        if(find(wordList.begin(),wordList.end(),endWord)==wordList.end() || beginWord == endWord){
            return 0;
        }
        int n= wordList.size();
        int m=wordList[0].size();
        vector<vector<int>> adj(n);
        unordered_map<string,int> mp;
        for(int i=0;i<n;i++){
            mp[wordList[i]]=i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int cnt=0;
                for(int k=0;k<m;k++){
                    if(wordList[i][k]!=wordList[j][k]){
                        cnt++;
                    }
                }
                if(cnt==1){//c
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        queue<int> q;
        int res=1;
        vector<bool>visit(n,false);

        for(int i=0;i<m;i++){
            for(char c='a';c<='z';c++){
                if(c==beginWord[i]) continue;
                //must explain
               string word = beginWord.substr(0, i) + c + beginWord.substr(i + 1);
                if(mp.find(word)!=mp.end() && visit[mp[word]]==false){
                    q.push(mp[word]);
                    visit[mp[word]]=true;
                }
            }
        }

        while(!q.empty()){
            res++;
            int len = q.size();
            for(int i=0;i<len;i++){
                int node=q.front();
                q.pop();
                if(mp[endWord]==node){
                    return res;
                }
                for(int nei:adj[node]){
                    if(visit[nei]==false){
                        q.push(nei);
                        visit[nei]=true;
                    }
                }
            }
        }

        return 0;

    }
};
