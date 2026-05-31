class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long k=mass;
        for(auto x:asteroids)
        {
            if(x<=k)
            {
                k+=x;
            }else
            {
                return false;
            }
        }
        return true;
    }
};