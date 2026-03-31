class Node{
    public:
    Node* links[26];
    bool flag ;

    Node(){
        flag = false;
        for(int i = 0 ; i < 26 ; i++){
            links[i] = NULL;
        }
    }

    bool containsKey(char ch){
        return links[ch - 'a'] != nullptr;
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

    bool helper(int ind , string word , Node* node){
        if(ind == word.size()){
            return node->flag;
        }

        char ch = word[ind];

        if(ch != '.'){
            if(!node->containsKey(ch)){
                return false;
            }
            return helper(ind + 1 , word , node->get(ch));
        }else{
            for(int i = 0 ; i < 26 ; i++){
                if(node->links[i] != nullptr){
                    if(helper(ind + 1 , word , node->links[i]) == true){
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
        return root->helper(0 , word , root);
    }
};
