class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n=cars.size();
        vector<double>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            // while speed of current car is less than equal to cars on right it cannot intersect with them therefore we pop them
            while(!st.empty() and cars[i][1]<=cars[st.top()][1])
                st.pop();

            while(!st.empty())
            {
                double time=(double)(cars[st.top()][0]-cars[i][0])/(cars[i][1]-cars[st.top()][1]);
                if(ans[st.top()]==-1 || time<ans[st.top()])
                {
                    ans[i]=time;
                    break;
                }
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
};