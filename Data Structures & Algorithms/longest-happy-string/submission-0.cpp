class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int , char>> pq;

        if(a > 0) pq.push({a , 'a'});
        if(b > 0) pq.push({b , 'b'});
        if(c > 0) pq.push({c , 'c'});

        string res = "";

        while(!pq.empty()){
            auto [f1 , c1] = pq.top(); pq.pop();

            int n = res.size();

            if(n >= 2 && res[n - 1] == c1 && res[n-2] == c1){   
                if(pq.empty()){
                    break;
                }
                auto [f2 , c2] = pq.top();
                pq.pop();

                res+= c2;
                if(--f2 > 0){
                    pq.push({f2 , c2});
                }

                pq.push({f1 , c1});
            }else{
                res+= c1;
                if(--f1 > 0){
                    pq.push({f1 , c1});
                }
            }
        }
        return res;
    }
};