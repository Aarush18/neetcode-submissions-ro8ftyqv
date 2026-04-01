class FreqStack {
public:
    unordered_map<int , int>freqMap;
    unordered_map<int , vector<int>> groupMap;
    int maxFreq = 0 ;
    FreqStack() {
        
    }
    
    void push(int val) {
        freqMap[val]++;
        auto f = freqMap[val];
        groupMap[f].push_back(val);
        maxFreq = max(maxFreq , f);
    }
    
    int pop() {
        auto x = groupMap[maxFreq].back();

        freqMap[x]--;

        groupMap[maxFreq].pop_back();

        if(groupMap[maxFreq].size() == 0){
            groupMap.erase(maxFreq);
            maxFreq--;
        }

        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */