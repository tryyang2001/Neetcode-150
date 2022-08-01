#include <unordered_map>
#include <vector>
#include <unordered_set>
using namespace std;

class Twitter {
public:
    unordered_map<int, unordered_set<int>> follower;
    vector<pair<int, int>> posts;
    
    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {
        posts.push_back({userId, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        int count = 10;
        vector<int> ans;
        for (int i = posts.size() - 1; i >= 0; i--) {
            if (count == 0) {
                break;
            }
            if (posts[i].first == userId || follower[userId].find(posts[i].first) != follower[userId].end()) {
                ans.push_back(posts[i].second);
                count--;
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        follower[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        follower[followerId].erase(followeeId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */