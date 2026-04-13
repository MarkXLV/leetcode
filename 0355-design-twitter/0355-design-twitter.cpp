class Twitter {
private:
    int timeStamp;
    unordered_map<int, unordered_set<int>> followers;
    unordered_map<int, vector<pair<int, int>>> tweets; // userId -> [(time, tweetId)]

public:
    Twitter() : timeStamp(0) {}

    void postTweet(int userId, int tweetId) {
        tweets[userId].emplace_back(timeStamp++, tweetId);
    }

    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> recentTweets;
        for (auto& tweet : tweets[userId]) {
            recentTweets.push(tweet);
        }
        for (auto& f : followers[userId]) {
            for (auto& tweet : tweets[f]) {
                recentTweets.push(tweet);
            }
        }
        vector<int> result;
        int count = 0;
        while (!recentTweets.empty() && count < 10) {
            result.push_back(recentTweets.top().second);
            recentTweets.pop();
            count++;
        }
        return result;
    }

    void follow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followers[followerId].insert(followeeId);
        }
    }

    void unfollow(int followerId, int followeeId) {
        if (followers[followerId].find(followeeId) != followers[followerId].end()) {
            followers[followerId].erase(followeeId);
        }
    }
};