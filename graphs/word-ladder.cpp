#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
  
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        bool isInside = false;
        for (auto& word : wordList) {
            if (word == endWord) {
                isInside = true;
            }
        }
        if (!isInside) {
            return 0;
        }
        unordered_map<string, unordered_set<string>> adj;
        //adjacency list using word as key and other words differ by 1
        //O(n^2 * m)
        for (auto& str : wordList) {
            int matches = 0;
            for (int i = 0; i < beginWord.size(); i++) {
                if (beginWord[i] == str[i]) {
                    matches++;
                }
            }
            if (beginWord.size() - matches <= 1) {
                adj[beginWord].insert(str);
            }
        }
        for (int i = 0; i < wordList.size(); i++) {
            for (int j = i + 1; j < wordList.size(); j++) {
                int matches = 0;
                for (int k = 0; k < wordList[i].size(); k++) {
                    if (wordList[i][k] == wordList[j][k]) {
                        matches++;
                    }
                }
                if (wordList[i].size() - matches <= 1) {
                    adj[wordList[i]].insert(wordList[j]);
                    adj[wordList[j]].insert(wordList[i]);
                }
            }
        }
        //adjacency list using word pattern, O(n * m^2)

        //do BFS to find min jump to reach endWord
        queue<string> frontier;
        frontier.push(beginWord);
        unordered_set<string> visited;
        unordered_map<string, string> parent;
        parent[beginWord] = beginWord;
        while (!frontier.empty()) {
            string curr = frontier.front();
            frontier.pop();
            for (auto& str : adj[curr]) {
                if (str == endWord) {
                    int count = 1;
                    parent[str] = curr;
                    curr = str;
                    while (parent[curr] != curr) {
                        count++;
                        curr = parent[curr];
                    }
                    return count;
                }
                if (visited.find(str) != visited.end()) {
                    continue;
                }
                frontier.push(str);
                visited.insert(str);
                parent[str] = curr;
            }
        }
        return 0;
    }
};