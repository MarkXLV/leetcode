class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int dis=1;
        int n=seats.size();
        int last=0;
        int i=0;
        int j=n-1;
        while(i<n and seats[i]==0)i++;
        while(j>=0 and seats[j]==0)j--;
        dis=max(dis,i);
        dis=max(dis,n-(j)-1);
        last=i;
        for(i;i<=j;i++)
        {
            if(seats[i]==1 and i!=last)
            {
                dis=max(dis,(i-last)/2);
            }
            if(seats[i]==1)
            {
                last=i;
            }
        }
        return dis;
    }
};