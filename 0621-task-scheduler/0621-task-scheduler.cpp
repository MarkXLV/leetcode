class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        // maths .
        // A--A--A
        // AB-AB-AB
        map<char,int>mp;
        int mx=0;
        for(auto x:tasks)
        {
            mp[x]++;
            mx=max(mx,mp[x]);
        }
        int num_max=0;
        for(const auto&[c,f]:mp)
        {
            if(f==mx)
            {
                num_max++;
            }
        }
        return max((int)tasks.size(),(n+1)*(mx-1)+num_max);
    }
};