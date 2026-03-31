class Node {
public:
    Node* links[26];
    bool flag;

    Node() {
        flag = false;
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

    void setEnd() {
        flag = true;
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
        node->setEnd();
    }

    void dfs(int i, int j,
             vector<vector<char>>& board,
             vector<string>& output,
             Node* node,
             string& currWord) {

        int n = board.size();
        int m = board[0].size();

        // boundary check
        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        char ch = board[i][j];

        // visited or not in trie
        if(ch == '#' || !node->containsKey(ch))
            return;

        node = node->get(ch);
        currWord.push_back(ch);

        // word found
        if(node->flag) {
            output.push_back(currWord);
            node->flag = false;  // avoid duplicates
        }

        // mark visited
        board[i][j] = '#';

        dfs(i+1, j, board, output, node, currWord);
        dfs(i-1, j, board, output, node, currWord);
        dfs(i, j+1, board, output, node, currWord);
        dfs(i, j-1, board, output, node, currWord);

        // backtrack
        board[i][j] = ch;
        currWord.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        root = new Node();

        // build trie
        for(string word : words) {
            insertWord(word);
        }

        vector<string> output;
        int n = board.size();
        int m = board[0].size();

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(root->containsKey(board[i][j])) {
                    string currWord = "";
                    dfs(i, j, board, output, root, currWord);
                }
            }
        }

        return output;
    }
};
