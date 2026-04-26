class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n=capital.size();
        vector<int>index(n);
        iota(index.begin(),index.end(),0);

        // sorting indexs based on capital 
        sort(index.begin(),index.end(),[&](const int &a,const int &b)
        {
            return capital[a]<capital[b];
        });

        priority_queue<int,vector<int>>maxprofit;
        // try to pick maxprofit k times;
        int idx=0;
        for(int i=0;i<k;i++)
        {
            // push affordables profit into the max heap and pick the most profit
            while(idx<n)
            {
                int x=index[idx];
                if(capital[x]<=w)
                    maxprofit.push(profits[x]);
                else
                    break;
                idx++;
            }

            if(maxprofit.empty())
               return w;

            w+=maxprofit.top();maxprofit.pop();
        }

        return w;

    }
};