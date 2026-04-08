class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        vector<pair<int,int>>y_cor;
        long long total_area=0;
        for(auto x:squares)
        {
            y_cor.push_back({x[1],x[2]});
            y_cor.push_back({x[1]+x[2],-1*x[2]});
            total_area+=1ll*x[2]*x[2];
        }
        sort(y_cor.begin(),y_cor.end());
        long long prev_y=0;
        long long curr_length=0;
        long long area=0;
        for(auto x:y_cor)
        {
            auto[y,length] = x;
            long long delta_y = y - prev_y;
            long long curr_area=1ll*delta_y*curr_length;
            if(area+curr_area>=(total_area)/2.0)
            {
                return prev_y+(total_area-2.0*area)/(2.0*curr_length);
            }
            area+=curr_area;
            curr_length+=length;
            prev_y=y;
        }
        return 0;
    }
};