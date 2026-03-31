class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> st;

        for(int i = 0 ; i < tokens.size() ; i++){
            if(tokens[i] == "+"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();
                st.push(to_string(x + y));
            }
            else if(tokens[i] == "-"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();

                st.push(to_string(y - x));                
            }
            else if(tokens[i] == "/"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();

                st.push(to_string(y / x));            
            }
            else if(tokens[i] == "*"){
                int x = stoi(st.top());
                st.pop();
                int y = stoi(st.top());
                st.pop();

                st.push(to_string(x * y));
            }else{
            st.push(tokens[i]);
            }
        }

        return stoi(st.top());
    }
};
