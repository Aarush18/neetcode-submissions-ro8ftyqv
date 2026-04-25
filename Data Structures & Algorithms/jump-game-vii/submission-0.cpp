class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        queue<int> q;
        q.push(0);

        int n = s.size();

        vector<bool> vis(n , false);

        vis[0] = true;

        int farthest = 0 ;

        while(!q.empty()){
            auto i = q.front(); q.pop();

            if(i == n - 1) return true;

            int start = max(farthest , i + minJump);
            int end = min(i + maxJump , n - 1);

            for(int j = start ; j <= end; j++){
                if(s[j] == '0' && !vis[j]){
                    vis[j] = true;
                    q.push(j);
                }
            }
            farthest = end + 1;
        }
        return false;
    }
};