class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        int a; int b;
        stack<int>st;
        for(int i=0;i<n;i++){
            if(tokens[i]=="+"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a+b);
            }
            else if(tokens[i]=="-"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b-a);
            }
            else if(tokens[i]=="*"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(a*b);
            }
            else if(tokens[i]=="/"){
                a=st.top();
                st.pop();
                b=st.top();
                st.pop();
                st.push(b/a);
            }

            else{
                st.push(stoi(tokens[i]));
                // int num = 0;
                // for (char c : tokens[i]) {
                //     num = num * 10 + (c - '0');
                // }
                // st.push(num);
            }
        }
        return st.top();

    }
};
