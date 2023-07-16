class MyLinkedList {
private:
    class Node {
    public:
        int value;
        Node* next;
        Node(int _value, Node* _next) {
            value = _value;
            next = _next;
        }
        ~Node() {
            cout << "destroyed " << value << "\n";
        }
    };
    int len;
    Node* head = nullptr; // DUMMY HEAD

public:
    MyLinkedList() {
        len = 0;
        head = new Node(0, nullptr);
    }

    ~MyLinkedList() {
        auto curr = head;
        for (int i = 0; i <= len; i++) {
            auto toBeRemoved = curr;
            curr = curr -> next;
            delete(toBeRemoved);
        }
    }
    
    int get(int index) {
        if (index < 0 || index >= len) return -1;
        auto curr = head -> next;
        while(index--) {
            curr = curr -> next;
        }
        return curr -> value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > len) return;
        auto curr = head;
        while(index--) {
            curr = curr -> next;
        }
        auto nxt = curr -> next;
        curr -> next = new Node(val, nullptr);
        curr -> next -> next = nxt;
        len++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= len) return;
        auto curr = head;
        while(index--) {
            curr = curr -> next;
        }
        auto toBeRemoved = curr -> next;
        curr -> next = curr -> next -> next;
        delete(toBeRemoved);
        len--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
