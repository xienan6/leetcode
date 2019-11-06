// Source : https://leetcode.com/problems/design-twitter/
// Author : Nan
// Date   : 2019-11-06
// Runtime: 64 ms

/*
* Use two hash and a variable to simulate time.
*
* Time complexity O(-), Space complexity O(-)
*/

class Twitter {
public:
    /** Initialize your data structure here. */
    Twitter() {
        time = 0;
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        follow(userId, userId);
        tweets[userId].insert({time++, tweetId});
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        vector<int> res;
        map<int, int> top10;
        for (auto id : friends[userId]) {
            for (auto a : tweets[id]) {
                top10.insert({a.first, a.second});
                if (top10.size() > 10) top10.erase(top10.begin());
            }
        }
        for (auto a : top10) {
            res.insert(res.begin(), a.second);
        }
        return res;
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        friends[followerId].insert(followeeId);
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            friends[followerId].erase(followeeId);
        }
    }
private:
    int time;
    unordered_map<int, unordered_set<int>> friends;
    unordered_map<int, map<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */