class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        heights.push_back(0);
        int ans=0;
        for(int i=0;i<heights.size();i++)
        {
            while(!st.empty() and heights[i]<heights[st.top()])
            {
                // calculate area of rectangle for the st.top() since we received next smallest to the right , 
                // while in stack we maintain next smaller to left
                int height=heights[st.top()];
                st.pop();
                int width=st.empty()?i:i-st.top()-1;
                ans=max(ans,width*height);
            }
            st.push(i);
        }
        return ans;
    }
};