class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int>ans(n,0);
        stack<int>st;
        st.push(heights[n-1]);
        ans[n-1] = 0;
        for(int i= n-2; i>=0; i--){
            while(st.size()>0 && heights[i] > st.top()){
                st.pop();
                ans[i]++ ;
            }
            if(st.size() != 0)  ans[i]++;
            st.push(heights[i]);
        }

        return ans;
    }

};