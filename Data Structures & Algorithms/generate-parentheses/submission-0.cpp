class Solution {
public:
    vector<string>res;
    vector<string> generateParenthesis(int n) {
        string stack;
        backtrack(0,0,n,stack);
        return res;
    }

    void backtrack(int openN, int closedN, int n, string& stack){
        if(openN==closedN && openN==n){
            res.push_back(stack);
            return;
        }

        if(openN<n){
            stack+='(';
            backtrack(openN+1,closedN,n,stack);
            stack.pop_back();
        }
        if(closedN<openN){
            stack+=')';
            backtrack(openN,closedN+1,n,stack);
            stack.pop_back();
        }
    }
};
