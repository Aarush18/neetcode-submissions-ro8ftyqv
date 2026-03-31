class Solution {
public:
    bool isValid(string s) {
        int n = s.size();

        stack<char> st;

        int cnt = 0;

        for(int i = 0; i < n ; i++){
            if(s[i] == '(' || s[i] == '{' || s[i] == '['){
                st.push(s[i]);
                cnt++;
            }
             else if(!st.empty() &&
                (s[i] == ')' && st.top() == '(' ||
                 s[i] == '}' && st.top() == '{' ||
                 s[i] == ']' && st.top() == '[')){
                st.pop();
                cnt--;
            }else{

            return false;
            }
        }
        if( cnt == 0 ){
            return true;
        }
        return false;
    }
};
