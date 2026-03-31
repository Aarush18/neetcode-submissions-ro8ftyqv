class Node {
public:
    bool flag;
    Node* links[26];
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

    Node* get(char ch){
        return links[ch - 'a'];
    }

    void setEnd(){
        flag = true;
    }

    bool helper(string word , int index , Node* node){
        if(index == word.size()){
            return node->flag;
        }

        char ch = word[index];

        if(ch != '.'){
            if(!node->containsKey(ch)){
                return false;
            }
            return helper(word , index + 1 , node->get(ch));
        }
        else{
            for(int i = 0 ; i < 26 ; i++){
                if(node->links[i] != NULL){
                    if(helper(word , index + 1 , node->links[i])){
                        return true;
                    }
                }
            }
            return false;
        }
    }

};

class WordDictionary {
private:
    Node* root ;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node * node = root;
        return node->helper(word , 0 , node);
    }
};
