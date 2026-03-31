class MyHashSet {
public:
    vector<int> map;
    MyHashSet() : map(1000001 , 0) {
        
    }
    
    void add(int key) {
        if(map[key] != 0){
            return;
        }
        map[key] = 1;
    }
    
    void remove(int key) {
        map[key] = 0;
    }
    
    bool contains(int key) {
        if(map[key] != 0){
            return true;
        }

        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */