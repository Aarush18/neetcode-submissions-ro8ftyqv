class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char ,int> freq;

        int maxFreq = 0 ;

        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i]]++;
            maxFreq = max(maxFreq , freq[s[i]]);
        }

        if(maxFreq > (s.size() + 1)/2 ){
            return "";
        }

        priority_queue<pair<int , char>>pq;

        for(auto& [ch , f] : freq){
            pq.push({f , ch});
        }

        string res = "";

        while(pq.size() >= 2){
            auto [f1 , c1] = pq.top(); pq.pop();
            auto [f2 , c2] = pq.top(); pq.pop();

            res+= c1;
            res+= c2;

            if(--f1 > 0) pq.push({f1 , c1});
            if(--f2 > 0) pq.push({f2 , c2});
        }

        if(!pq.empty()){
            auto [f , c] = pq.top();
            res+= c;

            if(--f > 0){
                return "";
            }
        }

        return res;
    }
};