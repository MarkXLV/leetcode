class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.rbegin(),piles.rend());
        int k=(int)piles.size()/3;
        int i=1;
        int sum=0;
        while(k--)
        {
            sum+=piles[i];
            i+=2;
        }
        return sum;
    }
};