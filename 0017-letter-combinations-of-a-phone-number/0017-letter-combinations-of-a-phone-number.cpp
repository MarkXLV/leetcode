class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        map<int,string>mp;
        int x=0;
        for(int i=2;i<8;)
        {
            char c=x+'a';
            mp[i]+=c;
            x++;
            if(x%3==0)i++;
        }
        mp[7]+='s';
        mp[8]="tuv";
        mp[9]="wxyz";

        vector<string> res;
        if(digits=="")return res;
        function<void(int,string)>fun=[&](int idx,string str)
        {
            // cout<<str+'-'<<endl;
            if(idx==digits.size())
            {
                res.push_back(str);
                return;
            }
            for(int i=0;i<mp[digits[idx]-'0'].size();i++)
            {
                // cout<<i<<' '<<idx;
                fun(idx+1,str+mp[digits[idx]-'0'][i]);
            }
        };
        fun(0,"");
        return res;
    }

};