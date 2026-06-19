class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int ans=0;
        int k=0;
        int n=gain.size();
        for(int i=0;i<n;i++)
        {
            k+=gain[i];
            ans=max(ans,k);
        }
        return ans;
    }
};