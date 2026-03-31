class LRUCache {
public:
    int n ;
    LRUCache(int capacity) {
        n = capacity;
    }

    list<int> dll;
    unordered_map<int , pair<list<int>::iterator , int>>mp; // key , {add , val};

    void makeRecentlyUsed(int key){
    
        dll.erase(mp[key].first);

        dll.push_front(key);        

        mp[key].first = dll.begin();
    }
    
    int get(int key) {
        if(mp.find(key) == mp.end()){
            return -1;
        }
        makeRecentlyUsed(key);

        return mp[key].second;
    }
    
    void put(int key, int value) {
        if(mp.find(key) != mp.end()){
            mp[key].second = value;
            makeRecentlyUsed(key);
        }else{
            dll.push_front(key);
            mp[key] = {dll.begin() , value};
            n--;
        }if(n < 0){
            int node_to_delete = dll.back();
            mp.erase(node_to_delete);

            dll.pop_back();
            n++;
        }
    }
};
