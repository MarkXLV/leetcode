class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        heights.push_back(0); // Append 0 to handle remaining bars
        int max_area = 0;

        for (int i = 0; i < heights.size(); ++i) {
            while (!st.empty() && heights[i] < heights[st.top()]) {
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                max_area = max(max_area, height * width);
            }
            st.push(i);
        }

        return max_area;
    }
};