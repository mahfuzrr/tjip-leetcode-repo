/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    unordered_map <Node*, Node*> cache;
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        if(cache.find(head) != cache.end()) return cache[head];
        Node* nw = new Node(head->val);
        cache[head] = nw;
        nw->next = copyRandomList(head->next);
        nw->random = copyRandomList(head->random);
        return nw;
    }
};
