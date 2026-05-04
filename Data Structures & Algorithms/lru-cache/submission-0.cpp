struct Node {
    int data;
    int key;
    Node* prev;
    Node* next;

    Node(int k, int val) : key(k), data(val), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    unordered_map<int, Node*> table;
    Node* head = new Node(0, 0);
    Node* tail = new Node(0, 0);

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head->prev = tail;
        tail->next = head;
    }

    void updateNodePosition(Node* node) {
        Node* prev = node->prev;
        Node* next = node->next;

        if (next) {
            next->prev = prev;
        }

        if (prev) {
            prev->next = next;
        }
    }

    void pushNodeToFront(Node* node) {
        head->prev->next = node;
        node->prev = head->prev;

        node->next = head;
        head->prev = node;
    }

    void updateNodeAccess(int key) {
        if (table.find(key) == table.end()) {
            return;
        }

        Node* node = table[key];
        updateNodePosition(node);
        pushNodeToFront(node);
    }
    
    int get(int key) {
        if (table.find(key) == table.end()) {
            return -1;
        }

        updateNodeAccess(key);

        return table[key]->data;
    }
    
    void put(int key, int value) {
        if (table.find(key) != table.end()) {
            table[key]->data = value;
            updateNodeAccess(key);
            return;
        }

        Node* node = new Node(key, value);

        if (!capacity) {
            Node* lruNode = tail->next;
            tail->next = lruNode->next;
            tail->next->prev = tail;
            table.erase(lruNode->key);
            delete lruNode;
        }

        table[key] = node;
        pushNodeToFront(node);
        capacity = max(0, capacity-1);
    }
};
