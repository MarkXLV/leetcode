class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dis=1;
        int n=seats.size();
        int i=0;
        int j=n-1;
        while(i<n and seats[i]==0)i++;
        while(j>=0 and seats[j]==0)j--;
        dis=max(dis,i);
        dis=max(dis,n-1-j);
        int cn=0;
        for(i;i<=j;i++)
        {
            if(seats[i]==0)
            {
                cn++;
            }else
            {
                cn=0;
            }
            dis=max(dis,(cn+1)/2);
        }
        return dis;
    }
};