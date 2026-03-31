class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        unordered_map<char , int> indegree(words.size());
        unordered_map<char , vector<char>> adj(words.size());

        for(auto& word : words){
            for(auto ch : word){
                indegree[ch] = 0;
            }
        }

        for(int i = 0 ; i < words.size() - 1;  i++){
            auto word1 = words[i];
            auto word2 = words[i + 1];

            if(word1.size() > word2.size() && word1.substr(0 , word2.size()) == word2){
                return "";
            }

            for(int j = 0 ; j < min(word1.size() , word2.size()) ; j++){
                if(word1[j] != word2[j]){
                    adj[word1[j]].push_back(word2[j]);
                    indegree[word2[j]]++;
                    break;
                }
            }
        }

        queue<char> q;

        for(auto& [ch , degree] : indegree){
            if(degree == 0){
                q.push(ch);
            }
        }

        string res = "";

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            res+= node;

            for(auto it : adj[node]){
                indegree[it]--;
                if(indegree[it] == 0){
                    q.push(it);
                }
            }
        }

        if(res.size() == indegree.size()){
            return res;
        }

        return "";
    }
};
