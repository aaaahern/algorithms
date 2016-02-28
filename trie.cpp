#include<iostream>
#include<string>

using namespace std;

struct Node {
    char key;
    int value;
    Node* next;
    Node* child;
    Node(char c) : key(c), value(0), next(nullptr), child(nullptr) {}
};

class Trie {
private:
    Node* root;
    
    void _DFS_print(Node* node, string& s) {
        if (node == nullptr) {
            cout << s << endl;
            return;
        }
        
        s.push_back(node->key);
        _DFS_print(node->child, s);
        s.pop_back();
        
        while (node->next != nullptr) {
            node = node->next;
            s.push_back(node->key);
            _DFS_print(node->child, s);
            s.pop_back();
        }
    }
    
public:
    Trie() : root(new Node(' ')) {}
    
    void insert(string s) {
        Node* node = root;
        Node* parent = root;
        int i = 0;
        int e = s.size();
        
        while (i < e) {
            if (node->child != nullptr) {
                parent = node;
                node = node->child;
                while (node->key != s[i] && node->next != nullptr)
                    node = node->next;
                if (node->key == s[i]) {
                    i++;
                    continue;
                }
                else break; //no s[i] child
            }
            else break; //no children
        }
        
        node = parent;
        
        while (i < e) {
            if (node->child == nullptr) {
                node->child = new Node(s[i]);
                node = node->child;
                i++;
            }
            else {
                node = node->child;
                if (node->key > s[i]) { //add node at the head
                    parent->child = new Node(s[i]);
                    parent->child->next = node;
                    node = parent->child;
                    i++;
                    continue;
                }
                //find the position
                while (node->next != nullptr && node->next->key < s[i]) {
                    node = node->next;
                }
                Node* newNode = new Node(s[i]);
                newNode->next = node->next;
                node->next = newNode;
                node = newNode;
                i++;
            }
        }
    }
    
    bool find(string s) {
        Node* node = root;
        for (char c : s) {
            node = node->child;
            while (node != nullptr && node->key != c)
                node = node->next;
            if (node == nullptr)
                return false;
        }
        return true;
    }
    
    
    //print all words in lexicographically order
    void print() {
        string s;
        if (root->child != nullptr)
            _DFS_print(root->child, s);
    }
    
    
};

int main(int argc, char** args) {
	Trie test;
	test.insert("apple");
	cout << test.find("apple") << endl;
	return 0;
}
