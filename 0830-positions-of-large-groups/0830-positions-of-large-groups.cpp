class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        int ptr1 = 0;
        int ptr2 = 0;
        int n = s.size();
        while (ptr2 < n) {
            while (ptr2 < n && s[ptr1] == s[ptr2])
                ptr2++;

            if (ptr2 - ptr1 > 2) {
                vector<int> temp(2, 0);
                temp[0] = ptr1;
                temp[1] = ptr2 - 1;
                ans.push_back(temp);
            }

            ptr1 = ptr2;
        }

        return ans;
    }
};