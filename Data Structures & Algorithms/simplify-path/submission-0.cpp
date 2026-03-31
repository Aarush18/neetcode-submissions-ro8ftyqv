class Solution {
public:
    string simplifyPath(string path) {
        
        stringstream ss(path);

        string token = "" ;

        stack<string> st;

        while(getline(ss , token , '/')){
            if(token == "." || token == ""){
                continue;
            }

            if(token != ".."){
                st.push(token);
            }else if(!st.empty()){
                st.pop();
            }
        }

        if(st.empty()){
            return "/";
        }

        string res = "";

        while(!st.empty()){
            res = "/" + st.top() + res;
            st.pop();
        }

        return res;
    }
};