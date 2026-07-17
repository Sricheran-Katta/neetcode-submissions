class Twitter {
private:
    int time = 0;
    unordered_map<int, vector<pair<int, int>>> tweets;
    unordered_map<int, unordered_set<int>> followers;
public:
    Twitter() {
        time = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({time++, tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int, int>> maxHeap;
        int count = 0;
        for(int i = tweets[userId].size() - 1; i >= 0 && count < 10; count++, i--){
            maxHeap.push(tweets[userId][i]);
        }
        for(int follower : followers[userId]){
            int count = 0;
            for(int i = tweets[follower].size() - 1; i >= 0 && count < 10; count++, i--){
                maxHeap.push(tweets[follower][i]);
            }
        }
        vector<int> ans;
        for(int i = 0; i < 10; i++){
            if(!maxHeap.empty()){
                ans.push_back(maxHeap.top().second);
                maxHeap.pop();
            }
        }
        return ans;
    }
    
    void follow(int followerId, int followeeId) {
        if(followerId != followeeId){
            followers[followerId].insert(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
        followers[followerId].erase(followeeId);
    }
};
