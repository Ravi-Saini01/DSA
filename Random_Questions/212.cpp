// 212. Word Search II

// Given an m x n board of characters and a list of strings words, return all words on the board.

// Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.

// Example 1:

// Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
// Output: ["eat","oath"]
// Example 2:

// Input: board = [["a","b"],["c","d"]], words = ["abcb"]
// Output: []

// Constraints:

// m == board.length
// n == board[i].length
// 1 <= m, n <= 12
// board[i][j] is a lowercase English letter.
// 1 <= words.length <= 3 * 104
// 1 <= words[i].length <= 10
// words[i] consists of lowercase English letters.
// All the strings of words are unique.

class Solution
{
public:
    vector<string> result;
    int r, c;
    vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    struct trieNode
    {
        bool endOfWord;
        trieNode *children[26];
        string word;
    };

    trieNode *getNode()
    {
        trieNode *temp = new trieNode();
        temp->endOfWord = false;
        for (int i = 0; i < 26; i++)
        {
            temp->children[i] = NULL;
        }
        temp->word = "";
        return temp;
    }

    void insert(trieNode *root, string str)
    {
        trieNode *pCrawl = root;
        for (char ch : str)
        {
            if (pCrawl->children[ch - 'a'] == NULL)
            {
                pCrawl->children[ch - 'a'] = getNode();
            }
            pCrawl = pCrawl->children[ch - 'a'];
        }
        pCrawl->endOfWord = true;
        pCrawl->word = str;
    }

    void DFS(vector<vector<char>> &board, int i, int j, trieNode *root)
    {
        if (i < 0 || i >= r || j < 0 || j >= c || board[i][j] == '$' ||
            root->children[board[i][j] - 'a'] == NULL)
        {
            return;
        }
        root = root->children[board[i][j] - 'a'];
        if (root->endOfWord == true)
        {
            result.push_back(root->word);
            root->endOfWord = false;
        }
        char temp = board[i][j];

        board[i][j] = '$';
        for (pair<int, int> p : directions)
        {
            int new_i = i + p.first;
            int new_j = j + p.second;
            DFS(board, new_i, new_j, root);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>> &board,
                             vector<string> &words)
    {
        r = board.size();
        c = board[0].size();

        trieNode *root = getNode();
        for (string str : words)
        {
            insert(root, str);
        }

        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                char ch = board[i][j];
                if (root->children[ch - 'a'] != NULL)
                {
                    DFS(board, i, j, root);
                }
            }
        }
        return result;
    }
};
// TC-->O(O(M∗N∗3^l)
