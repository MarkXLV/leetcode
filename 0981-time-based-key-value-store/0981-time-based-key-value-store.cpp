class TimeMap {
public:
    unordered_map<string,unordered_map<int,string>>mp;
    unordered_map<string,vector<int>>timemap;
    TimeMap() {
        mp.clear();
        timemap.clear();
    }
    
    void set(string key, string value, int timestamp) {
        timemap[key].push_back(timestamp);
        mp[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        int idx=upper_bound(timemap[key].begin(),timemap[key].end(),timestamp)-timemap[key].begin();
        int time=0;

        if(idx-1>=0)
            time=timemap[key][idx-1];

        return mp[key][time];
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */