class Solution {
public:
    bool checkValidString(string s) {
        int leftmin=0;int leftmax=0;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
               leftmin++;
               leftmax++; 
            }else if(s[i]==')')
            {
                if(leftmin>0)leftmin--;
                leftmax--;
            }else
            {
                if(leftmin>0)leftmin--;
                leftmax++;
            }
            if(leftmax<0)return false;
        }
        return leftmin==0;
    }
};