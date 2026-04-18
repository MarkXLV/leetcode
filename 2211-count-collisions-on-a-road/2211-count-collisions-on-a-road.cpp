class Solution {

// If there are no vehicles on the left side or all vehicles on the left side are moving left, then flag is set to −1.
// If a collision occurs on the left and the vehicles eventually stop, then flag is set to 0.
// If there are consecutive vehicles on the left moving to the right, then flag stores the number of such vehicles.
public:
    int countCollisions(string directions) {
        int flag=-1;
        int ans=0;
        for(auto ch:directions)
        {
            if(ch=='L')
            {
                if(flag>=0)
                {
                    ans+=(flag+1);
                    flag=0;
                }
            }else if(ch=='S')
            {
                if(flag>0)
                {
                    ans+=flag;
                }
                flag=0;
            }else
            {
                if(flag>=0)
                {
                    flag++;
                }else
                {
                    flag=1;
                }
            }
        }
        return ans;
    }
};