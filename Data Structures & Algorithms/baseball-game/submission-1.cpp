class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        vector<int> res;

        for(int i =0 ; i < operations.size(); i++){
            if(operations[i] == "+"){
              if(!st.empty()){
                auto x = st.top(); st.pop();
                auto y = st.top();

                st.push(x);
                st.push(x + y);
                res.push_back(x + y);
              }
            }else if(operations[i] == "C"){
                if(!st.empty()){
                    st.pop();
                    res.pop_back();
                }

            }else if(operations[i] == "D"){
                if(!st.empty()){
                    auto x = st.top();
                    res.push_back(x*2);
                    st.push(x*2);
                }
            }else{
                st.push(stoi(operations[i]));
                res.push_back(stoi(operations[i]));
            }
        }

        return accumulate(res.begin() , res.end() , 0);
    }
};