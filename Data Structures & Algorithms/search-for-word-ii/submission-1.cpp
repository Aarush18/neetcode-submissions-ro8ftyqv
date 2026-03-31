class Node {
public:
    Node* links[26];
    string word;   // store full word at end

    Node() {
        word = "";
        for(int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
    }

    bool containsKey(char ch) {
        return links[ch - 'a'] != nullptr;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }
};

class Solution {
private:
    Node* root;

    void insertWord(string word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->containsKey(ch)) {
                node->put(ch, new Node());
            }
            node = node->get(ch);
        }

        node->word = word;  // store full word
    }

    void dfs(int i, int j,
             vector<vector<char>>& board,
             vector<string>& output,
             Node* node) {

        char ch = board[i][j];

        if(ch == '#' || !node->containsKey(ch))
            return;

        node = node->get(ch);

        // word found
        if(node->word != "") {
            output.push_back(node->word);
            node->word = "";  // prevent duplicate
        }

        board[i][j] = '#';

        int n = board.size();
        int m = board[0].size();

        if(i > 0) dfs(i-1, j, board, output, node);
        if(j > 0) dfs(i, j-1, board, output, node);
        if(i < n-1) dfs(i+1, j, board, output, node);
        if(j < m-1) dfs(i, j+1, board, output, node);

        board[i][j] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new Node();

        // Build Trie
        for(string word : words) {
            insertWord(word);
        }

        vector<string> output;

        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(i, j, board, output, root);
            }
        }

        return output;
    }
};
