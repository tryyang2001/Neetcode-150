#include <unordered_map>
using namespace std;

class Node {
public:
    int key;
    int val;
    Node* prev;
    Node* next;
    
    Node(int key, int value) {
        this->key = key;
        this->val = value;
        this->prev = NULL;
        this->next = NULL;
    }
};

class LRUCache {
private:
    int capacity;
    unordered_map<int, Node*> cache;
    Node* head;
    Node* tail;
    
    void remove(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
    }
    
    void add(Node* node) {
        Node* prev = tail->prev;
        prev->next = node;
        node->prev = prev;
        node->next = tail;
        tail->prev = node;
    }
    
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (cache.find(key) == cache.end()) {
            return -1;
        } else {
            remove(cache[key]);
            add(cache[key]);
            return cache[key]->val;
        }
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            remove(cache[key]);
        }
        cache[key] = new Node(key, value);
        add(cache[key]);
        if (cache.size() > this->capacity) {
            Node* lru = head->next;
            remove(lru);
            cache.erase(lru->key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */