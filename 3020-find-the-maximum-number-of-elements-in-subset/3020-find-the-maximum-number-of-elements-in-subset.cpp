class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<int,int>mp;
        unordered_map<int,bool>vis;
        int cn1=0;
        for(auto x:nums)
        {
            mp[x]++;
            vis[x]=false;
            if(x==1)cn1++;
        }
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        function<int(int)>calculate=[&](int num)
        {
            __int128 k=num;
            int ans=0;
            while(mp[k]>1 && !vis[k])
            {
                ans+=2;
                vis[k]=true;
                k=k*k;            
            }
            vis[k]=true;
            if(mp[k]!=1)
            {
                return ans-1;
            }else
                return ans+1;
        };
        int res=1;
        for(int i=0;i<n;i++)
        {
            if(mp[nums[i]]>1 && nums[i]!=1 && !vis[nums[i]])
            {
                int tans=calculate(nums[i]);
                // cout<<nums[i]<<tans<<endl;
                res=max(res,tans);
            }
            vis[nums[i]]=true;
        }
        if(cn1%2==0)cn1--;
        return max(cn1,res);
    }
};