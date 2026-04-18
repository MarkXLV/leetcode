class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int>mp;
        if(hand.size()%groupSize!=0)return false;
        for(auto x:hand)mp[x]++;
        for(auto [k,f]:mp)
        {
            while(mp[k]>0)
            {
                for(int i=k;i<groupSize+k;i++)
                {
                    mp[i]--;
                    if(mp[i]<0)return false;
                }
            }
        }
        return true;
    }
};