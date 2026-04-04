class Solution {
public:
    double myPow(double x, int n) {
        double ans=1.0;
        long long k=1ll*n;
        bool pos=true;
        if(n<0)
        {
            k=-1ll*n;
            pos=false;
        }
        for(int i=0;i<32;i++)
        {
            if((1<<i)&k)
                ans*=x;
            x=x*x;
        }
        if(pos)
        return ans;
        else
        return 1.0/ans;
    }
};