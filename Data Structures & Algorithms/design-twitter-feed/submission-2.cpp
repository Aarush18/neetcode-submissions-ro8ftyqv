class Twitter {
public:
    int timeStamps = 0 ;
    Twitter() {
        
    }

    unordered_map<int , vector<pair<int , int>>> tweets;
    unordered_map<int , unordered_set<int>> followMap;
    
    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({timeStamps++ , tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {   
        vector<int> res;
        priority_queue<tuple<int , int , int ,int>> pq;


        followMap[userId].insert(userId);

        for(auto followee : followMap[userId]){
            if(!tweets[followee].empty()){
                auto idx = tweets[followee].size() - 1;
                auto [time , tweet] = tweets[followee][idx];

                pq.push({time , tweet , followee , idx});
            }
        }

        while(!pq.empty() && res.size() < 10){
            auto [time , tweet , user , idx] = pq.top(); pq.pop();

            res.push_back(tweet);

            if(idx > 0){
                auto[newTimeStamp , newTweet] = tweets[user][idx -1];
                pq.push({newTimeStamp , newTweet , user , idx - 1});
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
