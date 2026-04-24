#include <bits/stdc++.h>
using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isEnd;

    TrieNode() {
        isEnd = false;
        for (int i = 0; i < 26; i++) children[i] = NULL;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx])
                node->children[idx] = new TrieNode();

            node = node->children[idx];
        }

        node->isEnd = true;
    }

    bool search(string word) {
        TrieNode* node = root;

        for (char c : word) {
            int idx = c - 'a';

            if (!node->children[idx])
                return false;

            node = node->children[idx];
        }

        return node->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* node = root;

        for (char c : prefix) {
            int idx = c - 'a';

            if (!node->children[idx])
                return false;

            node = node->children[idx];
        }

        return true;
    }
};

int main() {
    Trie trie;

    trie.insert("apple");
    trie.insert("app");

    cout << trie.search("apple") << endl;   // 1 (true)
    cout << trie.search("app") << endl;     // 1 (true)
    cout << trie.search("appl") << endl;    // 0 (false)

    cout << trie.startsWith("ap") << endl;  // 1 (true)

    return 0;
}