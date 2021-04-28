#include <unordered_map>
#include <iostream>
using namespace std;

class Trie {
private:
    struct trieNode {
        unordered_map<char, trieNode*> map;
        bool isEndOfWord = false;
    };
    trieNode* root = new trieNode;

public:
    void insert(string word) {
        trieNode* ref = root;

        for (char c : word) {
            if (!ref->map[c])
                ref->map[c] = new trieNode;
            
            ref = ref->map[c];
        }
            
        ref->isEndOfWord = true;
    }
    
    bool search(string word) {
        trieNode* ref = root;

        for (char c : word) {
            if (!ref->map[c])
                return false;
            
            ref = ref->map[c];
        }
        
        return ref->isEndOfWord;
    }
    
    bool startsWith(string prefix) {
        trieNode* ref = root;

        for (char c : prefix) {
            if (!ref->map[c])
                return false;
            
            ref = ref->map[c];
        }
        
        return true;
    }
};

int main() {
    Trie trie;
    trie.insert("foo");
    trie.insert("bar");
    trie.insert("baz");

    cout << trie.search("foo") << endl;
    cout << trie.search("bar") << endl;
    cout << trie.search("baz") << endl;

    cout << trie.search("fo") << endl;
    cout << trie.search("ba") << endl;
    cout << trie.search("bats") << endl;

    cout << trie.startsWith("f") << endl;
    cout << trie.startsWith("fo") << endl;
    cout << trie.startsWith("foo") << endl;
    cout << trie.startsWith("food") << endl;
};
