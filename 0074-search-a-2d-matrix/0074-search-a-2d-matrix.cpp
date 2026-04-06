class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size();int m=matrix[0].size();
        int low=0;int high=n-1;
        int idx=0;
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(matrix[mid][0]<=target)
            {
                low=mid+1;
                idx=mid;
            }else
            {
                high=mid-1;
            }
        }

        low=0;high=m-1;
        while(low<=high)
        {
            int mid=(low+high)/2;
            // cout<<low<<' '<<high<<' '<<mid<<endl;
            if(matrix[idx][mid]==target)
            {
                return true;
            }
            else if(matrix[idx][mid]<target)
            {
                low=mid+1;
            }else
            {
                high=mid-1;
            }
        }
        return false;


    }
};