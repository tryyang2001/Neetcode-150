#include <string>
#include <unordered_set>
#include <set>
using namespace std;
class Trie {
public:
    unordered_set<string> word_set;
    set<string> words;
    Trie() {
        
    }
    
    void insert(string word) {
        word_set.insert(word);
        words.insert(word);
    }
    
    bool search(string word) {
        if (word_set.find(word) != word_set.end()) {
            return true;
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        if (words.lower_bound(prefix) != words.end()) {
            int i = 0;
            int j = 0;
            string str = *words.lower_bound(prefix);
            while (i < str.size() && j < prefix.size()) {
                if (str[i] == prefix[j]) {
                    i++;
                    j++;
                } else {
                    if (str[i] > prefix[j]) {
                        return false;
                    }
                    return true;
                }
            }
            return true;
        }
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */