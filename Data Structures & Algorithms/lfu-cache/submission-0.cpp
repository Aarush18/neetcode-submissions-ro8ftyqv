class LFUCache {
public:
    int cap ;
    int size ;
    int minFreq;
    unordered_map<int , list<vector<int>>::iterator>mp;
    unordered_map<int , list<vector<int>>>freq;

    LFUCache(int capacity) {
        cap = capacity;
        size = 0 ;
        minFreq = 0;
    }

    void makeFrequentlyUsed(int key){
        
        auto &vec = *(mp[key]);

        auto val = vec[1];
        auto f = vec[2];

        freq[f].erase(mp[key]);

        if(freq[f].empty()){
            freq.erase(f);
            if(f == minFreq){
                minFreq++;
            }
        }

        f++;
        freq[f].push_front(vector<int>({key , val , f}));
        mp[key] = freq[f].begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }

        auto &vec = *(mp[key]);

        auto val = vec[1];

        makeFrequentlyUsed(key);

        return val;
    }
    
    void put(int key, int value) {
        if(cap == 0){
            return;
        }

        if(mp.find(key) != mp.end()){
            auto& vec = *(mp[key]);
            vec[1] = value;

            makeFrequentlyUsed(key);
        }else if(size < cap){
            size++;
            minFreq = 1;
            freq[1].push_front(vector<int>({key , value , 1}));
            mp[key] = freq[1].begin();
        }else{
            auto& list_ref = freq[minFreq];
            auto node_to_delete = list_ref.back()[0];

            list_ref.pop_back();
            mp.erase(node_to_delete);

            if(list_ref.empty()){
                freq.erase(minFreq);
            }
            minFreq = 1;
            freq[1].push_front(vector<int>({key , value , 1}));
            mp[key] = freq[1].begin();
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */