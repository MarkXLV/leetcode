class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        unordered_map<int,int>one,two;
        int n=A.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]=i>=1?ans[i-1]:0;
            if(A[i]==B[i])
            {
                ans[i]++;
            }else
            {
                if(one[B[i]])
                    ans[i]++;
                if(two[A[i]])
                    ans[i]++;
            }
            one[A[i]]++;
            two[B[i]]++;
        }
        return ans;
    }
};