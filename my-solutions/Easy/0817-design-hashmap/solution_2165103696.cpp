class MyHashMap {
private:
    struct Node {
        int key;
        int value;
        Node* next;

        Node(int k, int v) : key(k), value(v), next(nullptr) {}
    };

    vector<Node*> buckets;
    int capacity;
    int size;

    double loadFactor = 0.75;

    int getIndex(int key) {
        return key % capacity;
    }

    void resize() {
        int oldCapacity = capacity;
        capacity *= 2;

        vector<Node*> newBuckets(capacity, nullptr);

        for (int i = 0; i < oldCapacity; i++) {
            Node* curr = buckets[i];

            while (curr != nullptr) {
                Node* next = curr->next;

                int newIndex = curr->key % capacity;

                curr->next = newBuckets[newIndex];
                newBuckets[newIndex] = curr;

                curr = next;
            }
        }

        buckets = move(newBuckets);
    }

public:
    MyHashMap() {
        capacity = 16;
        size = 0;
        buckets.resize(capacity, nullptr);
    }

    void put(int key, int value) {
        int index = getIndex(key);

        Node* curr = buckets[index];

        // Key already exists → update value
        while (curr != nullptr) {
            if (curr->key == key) {
                curr->value = value;
                return;
            }
            curr = curr->next;
        }

        // Insert new key-value pair
        Node* newNode = new Node(key, value);
        newNode->next = buckets[index];
        buckets[index] = newNode;

        size++;

        // Resize if load factor becomes too high
        if ((double)size / capacity > loadFactor) {
            resize();
        }
    }

    int get(int key) {
        int index = getIndex(key);

        Node* curr = buckets[index];

        while (curr != nullptr) {
            if (curr->key == key) {
                return curr->value;
            }

            curr = curr->next;
        }

        return -1;
    }

    void remove(int key) {
        int index = getIndex(key);

        Node* curr = buckets[index];
        Node* prev = nullptr;

        while (curr != nullptr) {

            if (curr->key == key) {

                // Removing head
                if (prev == nullptr) {
                    buckets[index] = curr->next;
                }
                // Removing middle/tail
                else {
                    prev->next = curr->next;
                }

                delete curr;
                size--;
                return;
            }

            prev = curr;
            curr = curr->next;
        }
    }

    ~MyHashMap() {
        for (int i = 0; i < capacity; i++) {
            Node* curr = buckets[i];

            while (curr != nullptr) {
                Node* next = curr->next;
                delete curr;
                curr = next;
            }
        }
    }
};