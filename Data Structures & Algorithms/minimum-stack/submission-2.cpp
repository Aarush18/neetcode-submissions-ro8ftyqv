class MinStack {
public:
    stack<long long> st;
    long long mini;
    long long x;

    MinStack() {
        mini = 1e9;
    }
    
    void push(int val) {
        if(st.empty()){
            st.push(val);
            mini = val;
        }
        else{
            if(val < mini){
                st.push(2LL *val - mini);
                mini = val;
            }else{
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.empty()){
            return;
        }
        x = st.top();
        st.pop();

        if(x < mini){
            mini = 2*mini - x;
        }
    }
    
    int top() {
        if(st.empty()){
            return -1;
        }

        x = st.top();

        if(x < mini){
            return mini;
        }
        return x;
    }
    
    int getMin() {
        return mini;
    }
};
