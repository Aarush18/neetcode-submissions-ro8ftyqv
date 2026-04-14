class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> st(deadends.begin() , deadends.end());

        queue<string> q;
        q.push("0000");

        if(st.count("0000")){
            return -1;
        }

        st.insert("0000");

        int level = 0 ;

        while(!q.empty()){
            int size = q.size();

            for(int i = 0 ; i < size; i++){
                auto curr = q.front();
                q.pop();

                if(curr == target){
                    return level;
                }

                for(int i = 0 ; i < 4 ; i++){
                    char ch = curr[i];  

                    int inc = ch == '9' ? '0' : ch + 1;
                    int dec = ch == '0' ? '9' : ch - 1;

                    auto temp = curr;
                    temp[i] = inc;

                    if(!st.count(temp)){
                        q.push(temp);
                        st.insert(temp);
                    }

                    temp = curr;
                    temp[i] = dec;

                    if(!st.count(temp)){
                        q.push(temp);
                        st.insert(temp);
                    }
                    
                    curr[i] = ch;
                }
            }
            level++;
        }
        return -1;
    }

};