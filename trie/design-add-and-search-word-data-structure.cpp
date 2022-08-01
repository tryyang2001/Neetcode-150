#include <unordered_map>
#include <string>
using namespace std;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool isEnd = false;
    
    TrieNode() {
        
    }
};

class WordDictionary {
public: 
    TrieNode* root;
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* curr = root;
        for (auto& c : word) {
            if (curr->children.find(c) == curr->children.end()) {
                curr->children.insert({c, new TrieNode()});
            }
            curr = curr->children[c];
        }
        curr->isEnd = true;
    }
    
    bool dfs(string word, int i, TrieNode* curr) {
        if (i == word.size()) {
            return curr->isEnd;
        }
        if (curr->children.find(word[i]) != curr->children.end()) {
            return dfs(word, i + 1, curr->children[curr->children.find(word[i])->first]);
        }
        if (word[i] == '.') {
            for (auto& child : curr->children) {
                if (dfs(word, i + 1, child.second)) {
                    return true;
                }
            }
        }
        return false;
    }
    
    bool search(string word) {
        TrieNode* curr = root;
        return dfs(word, 0, root);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */