class Solution {
public:

    string encode(vector<string>& strs) {
        int n=strs.size();
        string s="";
        for(string st:strs){
            s+=(to_string(st.size()))+"#"+st;
        }
        return s;
    }

    vector<string> decode(string s) {
        int n=s.size();
        int i=0;
        vector<string>res;
        while(i<n){
            int j=i;
            while(s[j]!='#'){
                j++;
            }

            int len= stoi(s.substr(i, j-i));
            string str = s.substr(j+1,len);
            
            res.push_back(str);
            i=j+1+len;
        }
        return res;
    }
};
