class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> currentpartion;
        backtrack(s,0,currentpartion,res);
        return res;
    }
    void backtrack(string &s,int start,vector<string> &currentpartion,vector<vector<string>> &res)
    {
        if(start==s.size())
        {
            res.push_back(currentpartion);
            return;
        }
        for(int end=start;end<s.size();end++)
        {
            if(ispal(s,start,end))
            {
                currentpartion.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1,currentpartion,res);
                currentpartion.pop_back();
            }
        }
    }
    bool ispal(string &s,int i,int j)
    {
        while(i<=j and s[i]==s[j])
        {
            i++;
            j--;
        }
        if(i>=j)return true;
        return false;
    }
};