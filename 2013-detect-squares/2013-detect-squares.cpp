class DetectSquares {
public:
    // store frequncy of points[x][y] 
    unordered_map<int,unordered_map<int,int>>points; 
    unordered_map<int,vector<int>>pointx;
    DetectSquares() {

    }
    
    void add(vector<int> point) {
        int x=point[0],y=point[1];
        points[x][y]++;
        pointx[x].push_back(y);
    }
    
    int count(vector<int> point) {
        int ans=0;
        int x=point[0],y=point[1];
        if(pointx.find(x)==pointx.end())return 0;
        for(auto y2:pointx[x])
        {
            int distance=abs(y-y2);
            if(distance==0)continue;
            ans+=points[x-distance][y]*points[x-distance][y2];
            ans+=points[x+distance][y]*points[x+distance][y2];
        }
        return ans;
    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */