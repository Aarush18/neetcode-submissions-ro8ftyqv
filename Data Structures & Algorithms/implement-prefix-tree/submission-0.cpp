class Node {
    public:
    Node* links[26];
    bool flag;
    Node(){
        flag = false;  
        for(int i = 0 ; i < 26 ; i++){
            links[i] = NULL;
        }
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != NULL;
    }

    void put(char ch , Node* node){
        links[ch - 'a'] = node;
    }

    void setEnd(){
        flag = true;
    }

    bool isEnd(){
        return flag;
    }

    Node* get(char ch){
        return links[ch - 'a'];
    }

};

class PrefixTree {
private:
    Node* root ;
public:
    PrefixTree() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        for(int i = 0 ; i < word.length() ; i++){
            if(!node->containsKey(word[i])){
                node->put(word[i] , new Node());
            }
            node = node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;

        for(auto ch : word){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return node->isEnd();
    }
    
    bool startsWith(string prefix) {
        Node * node = root;

        for(auto ch : prefix){
            if(!node->containsKey(ch)){
                return false;
            }
            node = node->get(ch);
        }
        return true;
    }
};
