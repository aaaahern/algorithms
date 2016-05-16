//208 https://leetcode.com/problems/implement-trie-prefix-tree/
// Notice that a word in trie should end with a special character

class TrieNode {
public:
    // Initialize your data structure here.
    vector<TrieNode*> children;
    char c;
    TrieNode(char a) {
        c = a;
    }
    TrieNode* getChild(char a) {
        for (TrieNode* child : children) {
            if (child->c == a) return child;
        }
        return nullptr;
    }
};

class Trie {
public:
    Trie() {
        root = new TrieNode('/');
    }
    
    // Inserts a word into the trie.
    void insert(string word) {
        if (word.size() == 0) return;
        int i = 0;
        TrieNode* node = root;
        for (; i < word.size(); i++) {
            TrieNode* next = node->getChild(word[i]);
            if (next) {
                node = next;
            }
            else {
                break;
            }
        }
        for (; i < word.size(); i++) {
            node->children.push_back(new TrieNode(word[i]));
            node = node->getChild(word[i]);
        }
        node->children.push_back(new TrieNode('\0'));
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* node = root;
        for (int i = 0; i < word.size(); i++) {
            TrieNode* next = node->getChild(word[i]);
            if (next) {
                node = next;
            }
            else return false;
        }
        if (node->getChild('\0'))
            return true;
        else return false;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for (int i = 0; i < prefix.size(); i++) {
            TrieNode* next = node->getChild(prefix[i]);
            if (next) {
                node = next;
            }
            else return false;
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");
