
class Node{
    public:
        Node* links[26];
        string word;

        Node(){
            word = "";
            for(int i = 0 ; i < 26 ; i++){
                links[i] = nullptr;
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
    
};


class Solution {
private:
    Node* root;

    void solve(int i , int j ,vector<vector<char>>& board , vector<string>& output , Node* node){
        
        char ch = board[i][j];

        if(ch == '#' || !node->containsKey(ch))
            return;

        node = node->get(ch);

        if(node->word != ""){
            output.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int n = board.size();
        int m = board[0].size();

        if(i < n -1 ) solve(i + 1 , j , board  , output , node);
        if(j < m - 1)solve(i , j + 1 , board , output , node);
        if(i > 0)solve(i - 1 , j , board , output , node);
        if( j > 0) solve(i , j - 1 , board , output , node);

        board[i][j] = ch ;
    }
public:
     void insert(string word){
        Node* node = root;
        for(char ch : word){
            if(!node->containsKey(ch)){
                node->put(ch , new Node());
            }
            node = node->get(ch);
        }
        node->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        root = new Node();

        for(int i = 0 ; i < words.size(); i++){
            insert(words[i]);
        }

        vector<string> output;

        for(int i = 0 ; i < board.size(); i++){
            for(int j = 0 ; j < board[0].size() ; j++){
                solve(i , j , board  , output , root);
            }
        }

        return output;
    }
};
