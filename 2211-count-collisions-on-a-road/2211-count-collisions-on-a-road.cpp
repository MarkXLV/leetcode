class Solution {
public:
    int countCollisions(string directions) {
        int ans=0;
        stack<char>st;
        int n=directions.size();
        for(int i=0;i<n;i++)
        {
            if(directions[i]=='L')
            {
                int cn=0;
                if(!st.empty())
                {
                    if(st.top()=='R')
                    {
                        int cn=0;
                        while(!st.empty() and st.top()=='R')
                        {
                            if(cn==0)cn+=2;
                            else cn++;
                            st.pop();
                        }
                        if(cn>0)st.push('S');
                        ans+=cn;
                    }else
                    {
                        ans++;
                    }
                }
                
            }else if(directions[i]=='S')
            {
                while(!st.empty() and st.top()=='R')
                {
                    ans++;
                    st.pop();
                }
                st.push('S');
            }else
            {
                st.push('R');
            }
        }
        
        return ans;
    }
};