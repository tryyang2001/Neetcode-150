#include <unordered_map>
#include <string>
#include <map>
using namespace std;

class TimeMap {
private: 
    unordered_map<string, map<int, string>> time_map;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        time_map[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if (time_map.find(key) != time_map.end()) {
            if (time_map[key].find(timestamp) != time_map[key].end()) {
                return time_map[key].find(timestamp)->second;
            } else {
                auto it = time_map[key].lower_bound(timestamp);
                if (it == time_map[key].begin()) {
                    return "";
                } else if (it == time_map[key].end()) {
                    return time_map[key].rbegin()->second;
                } else {
                    return prev(it)->second;
                }
            }
        } else {
            return "";
        }
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */