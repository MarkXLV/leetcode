class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> res;
        for(auto x:asteroids)
        {
            if(x>0)
            {
                res.push_back(x);
            }else
            {
                if(res.size()==0 or res.back()<0)
                {
                    res.push_back(x);
                }else
                {
                    while(res.size()>0 and res.back()>0 and abs(res.back())<abs(x))
                    {
                        res.pop_back();
                    }
                    if(res.size()>0 and res.back()>0 and abs(res.back())==abs(x))
                    {
                        res.pop_back();
                        continue;
                    }
                    if(res.size()==0 or res.back()<0)
                    {
                        res.push_back(x);
                    }
                    
                }
            }
        }
        return res;
    }
};