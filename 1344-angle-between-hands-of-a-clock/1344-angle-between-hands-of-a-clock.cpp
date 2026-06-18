class Solution {
public:
    double angleClock(int hour, int minutes) {
        // 5 min -> 30*
        // 1 min -> 6*
        if(hour==12)hour=0;
        double first=minutes*6.0;
        double second=hour*30.0;
        double advance= minutes*0.5;
        second=second+advance;
        double ans=max(second,first)-min(second,first);
        return min(ans,360-ans);

    }
};