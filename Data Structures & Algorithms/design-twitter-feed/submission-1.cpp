class Twitter {
public:
    unordered_map<int, vector<pair<int,int>>> tweets;
    unordered_map<int , unordered_set<int>>followMap;

    int timestamp = 0;
    Twitter() {

    }
    
    void postTweet(int userId , int tweetId) {
        tweets[userId].push_back({timestamp++ , tweetId });
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<int> res ;
        priority_queue<tuple<int , int , int , int>>pq;
        followMap[userId].insert(userId); // a user can view its tweet as well


        // dekh hame 4 values chaiye to put in the priority_queue => {timestamp , tweetId , userId , idx }
        for(int followee : followMap[userId]){
            if(!tweets[followee].empty()){
            auto idx = tweets[followee].size() - 1;
            auto [time , tweetId] = tweets[followee][idx];
            pq.push({time , tweetId , followee , idx});
            }
        }

        while(!pq.empty() &&  res.size() < 10){
            auto [timestamp , tweetId , user , idx] = pq.top(); pq.pop();
            res.push_back(tweetId);

            if(idx > 0){
                auto [newTimestamp , newTweetId] = tweets[user][idx - 1];
                pq.push({newTimestamp , newTweetId , user , idx - 1});
            }
        }
        return res;
    }
    
    void follow(int followerId, int followeeId) {
       followMap[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
       if(followerId != followeeId){
            followMap[followerId].erase(followeeId);
        }
    }
};
