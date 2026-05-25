class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int>q;
        int n=s.size();
        if(s[n-1]!='0')return false;
        q.push(0);
        int considered=0;
        while(!q.empty())
        {
            int x=q.front();
            q.pop();
            if(x+minJump<=n-1 && x+maxJump>=n-1)return true;
            for(int k=max(considered+1,x+minJump);k<=min(x+maxJump,n-1);k++)
            {
                if(s[k]=='0')
                    q.push(k);

                if(k==n-1)
                    return true;
            }
            considered=x+maxJump;
        }
        return false;
    }
};