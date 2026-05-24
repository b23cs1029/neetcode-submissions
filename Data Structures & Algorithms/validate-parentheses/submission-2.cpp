class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char>st;
        unordered_map<char,char>opentoclose = {
            {')','('},{'}','{'},{']','['}
        };
        for(char c:s){
            if(opentoclose.contains(c)){
                if(!st.empty()&&st.top()==opentoclose[c]){
                    st.pop();
                }
                else return false;
            }
            else{
                st.push(c);
            }
        }
        return st.empty();

    }
};
