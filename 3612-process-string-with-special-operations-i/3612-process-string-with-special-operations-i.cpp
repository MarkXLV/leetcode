class Solution {
public:
    string processStr(string str) {
        string s="";
        for(auto x:str)
        {
            if(x=='*')
                s=s.substr(0,s.size()-1);
            else if(x=='#')
                s=s+s;
            else if(x=='%')
                reverse(s.begin(),s.end());
            else
                s+=x;
        }
        return s;
    }
};