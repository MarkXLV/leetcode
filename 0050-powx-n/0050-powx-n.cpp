class Solution {
public:
    double myPow(double x, int n) {
        double res=1.0;
        // abs of -INT_MIN is not defines threfore we need to make it long long
        long long k=abs(1ll*n);
        for(int i=0;i<32;i++)
        {
            if((1<<i)&k)
            res=res*x;
            x=x*x;
        }
        return n>0?res:1.0/res;
    }
};