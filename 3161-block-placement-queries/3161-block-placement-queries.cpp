int seg[4*100000];
void update(int node,int start,int end,int idx,int val)
{
    if(start==end)
    {
        seg[node]=val;
        return;
    }
    int mid=(start+end)/2;
    if(idx<=mid)
    {
        update(2*node+1,start,mid,idx,val);
    }
    else
    {
        update(2*node+2,mid+1,end,idx,val);
    }
    seg[node]=max(seg[2*node+1],seg[2*node+2]);
}
int find_max(int node,int start,int end,int l,int r)
{
    if(l>end || r<start)
    {
        return 0;
    }
    if(l<=start && r>=end)
    {
        return seg[node];
    }
    int mid=(start+end)/2;
    return max(find_max(2*node+1,start,mid,l,r),find_max(2*node+2,mid+1,end,l,r));
}

set<int>idx;
class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        memset(seg,0,sizeof(seg));

        idx.clear();
        idx.insert(0);

        vector<bool> res;

        for(auto &q : queries)
        {
            if(q[0] == 1)
            {
                int x = q[1];

                auto upper = idx.upper_bound(x);

                if(upper != idx.end())
                {
                    int nxt = *upper;

                    update(0,0,100000,nxt,nxt-x);
                }

                auto lower = upper;
                --lower;

                int prev = *lower;

                update(0,0,100000,x,x-prev);

                idx.insert(x);
            }
            else
            {
                int x  = q[1];
                int sz = q[2];

                auto it = idx.upper_bound(x);
                --it;

                int lastObstacle = *it;

                int bestGap = max(
                    find_max(0,0,100000,0,x),
                    x - lastObstacle
                );

                res.push_back(bestGap >= sz);
            }
        }

        return res;
    }
};