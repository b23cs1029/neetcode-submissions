class Solution {
public:
    vector<string> res;
    vector<string> store = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return res;
        dfs(0,"",digits);
        return res;
    }
    void dfs(int i, string curchar, string& digit){
        if(curchar.size()>=digit.size()){
            res.push_back(curchar);
            return;
        }
        string ch = store[digit[i]-'0'];
        for(char c:ch){
            dfs(i+1,curchar+c,digit);
        }

    }
};
