class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n=arr.size();
        vector<int>count(n+1,0);
        for(auto x:arr)
        {
            count[min(x,n)]++;
        }
        int ans=1;
        for(int num=2;num<=n;num++)
        {
            ans=min(ans+count[num],num);
        }
        return ans;
    }
};