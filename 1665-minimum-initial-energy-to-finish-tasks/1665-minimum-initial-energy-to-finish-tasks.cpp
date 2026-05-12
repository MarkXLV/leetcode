class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(),tasks.end(),[&](const vector<int>&a,const vector<int>&b)
        {
            return a[1]-a[0]>b[1]-b[0];
        });
        int ans=0;
        int res=0;
        for(auto x:tasks)
        {
            int a=x[0];
            int b=x[1];
            // cout<<a<<' '<<b<<endl;
            if(ans<b)
            {
                res+=(b-ans);
                ans+=(b-ans);
            }
            ans-=a;
        }
        return res;
    }
};