class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int n=arr.size();
        int ans=1;
        int curr=1;
        for(int i=0;i<n-1;i++)
        {
            if(i%2==0)
            {
                if(arr[i]<arr[i+1])
                {
                    curr++;
                }else
                {
                    curr=1;
                }
            }else
            {
                if(arr[i]>arr[i+1])
                {
                    curr++;
                }else
                {
                    curr=1;
                }
            }
            ans=max(ans,curr);
        }

        curr=1;
        for(int i=0;i<n-1;i++)
        {
            if((i+1)%2==0)
            {
                if(arr[i]<arr[i+1])
                {
                    curr++;
                }else
                {
                    curr=1;
                }
            }else
            {
                if(arr[i]>arr[i+1])
                {
                    curr++;
                }else
                {
                    curr=1;
                }
            }
            ans=max(ans,curr);
        }
        return ans;
    }
};