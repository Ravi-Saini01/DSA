// 432. All O`one Data Structure

// Design a data structure to store the strings' count with the ability to return the strings with minimum and maximum counts.

// Implement the AllOne class:

// AllOne() Initializes the object of the data structure.
// inc(String key) Increments the count of the string key by 1. If key does not exist in the data structure, insert it with count 1.
// dec(String key) Decrements the count of the string key by 1. If the count of key is 0 after the decrement, remove it from the data structure. It is guaranteed that key exists in the data structure before the decrement.
// getMaxKey() Returns one of the keys with the maximal count. If no element exists, return an empty string "".
// getMinKey() Returns one of the keys with the minimum count. If no element exists, return an empty string "".
// Note that each function must run in O(1) average time complexity.

// Example 1:

// Input
// ["AllOne", "inc", "inc", "getMaxKey", "getMinKey", "inc", "getMaxKey", "getMinKey"]
// [[], ["hello"], ["hello"], [], [], ["leet"], [], []]
// Output
// [null, null, null, "hello", "hello", null, "hello", "leet"]

// Explanation
// AllOne allOne = new AllOne();
// allOne.inc("hello");
// allOne.inc("hello");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "hello"
// allOne.inc("leet");
// allOne.getMaxKey(); // return "hello"
// allOne.getMinKey(); // return "leet"

// Constraints:

// 1 <= key.length <= 10
// key consists of lowercase English letters.
// It is guaranteed that for each call to dec, key is existing in the data structure.
// At most 5 * 104 calls will be made to inc, dec, getMaxKey, and getMinKey.

class AllOne
{
private:
    // Doubly Linked List node to store count and a set of strings with that
    // count
    struct Node
    {
        int count;
        list<string> keys; // You should use an unordered_set<string> here
                           // because it will have Amortized O(1) time
                           // complexity for erase() function.
        Node *prev, *next;
        Node(int c) : count(c), prev(nullptr), next(nullptr) {}
    };

    // Hash map to store key -> count
    unordered_map<string, Node *> mp;

    // Head and tail pointers for the doubly linked list
    Node *head, *tail;

    // Add a new node with count `c` after node `prevNode`
    Node *addNodeAfter(Node *prevNode, int count)
    {
        Node *newNode = new Node(count);
        newNode->next = prevNode->next;
        newNode->prev = prevNode;
        if (prevNode->next)
        {
            prevNode->next->prev = newNode;
        }
        prevNode->next = newNode;
        if (tail == prevNode)
        {
            tail = newNode;
        }
        return newNode;
    }

    // Remove the node from the doubly linked list
    void removeNode(Node *node)
    {
        node->prev->next = node->next;
        if (node->next)
        {
            node->next->prev = node->prev;
        }
        if (tail == node)
        {
            tail = node->prev;
        }
        delete node;
    }

public:
    AllOne()
    {
        // Initialize head and tail dummy nodes for the doubly linked list
        head = new Node(0);
        tail = head;
    }

    void inc(string key)
    {
        if (mp.find(key) == mp.end())
        {
            // Key doesn't exist, add it to the list after the head with count 1
            if (head->next == nullptr || head->next->count != 1)
            {
                addNodeAfter(head, 1);
            }
            head->next->keys.push_front(key);
            mp[key] = head->next;
        }
        else
        {
            // Key exists, move it to the next count
            Node *curNode = mp[key];
            int curCount = curNode->count;
            if (curNode->next == nullptr ||
                curNode->next->count != curCount + 1)
            {
                addNodeAfter(curNode, curCount + 1);
            }
            curNode->next->keys.push_front(key);
            mp[key] = curNode->next;
            curNode->keys.remove(key);
            if (curNode->keys.empty())
            {
                removeNode(curNode);
            }
        }
    }

    void dec(string key)
    {
        Node *curNode = mp[key];
        int curCount = curNode->count;

        // Remove the key if count becomes zero
        curNode->keys.remove(key);
        if (curCount == 1)
        {
            mp.erase(key);
        }
        else
        {
            // Move it to the previous count
            if (curNode->prev == head || curNode->prev->count != curCount - 1)
            {
                addNodeAfter(curNode->prev, curCount - 1);
            }
            curNode->prev->keys.push_front(key);
            mp[key] = curNode->prev;
        }

        // Remove the current node if it has no more keys
        if (curNode->keys.empty())
        {
            removeNode(curNode);
        }
    }

    string getMaxKey() { return (tail == head) ? "" : tail->keys.front(); }

    string getMinKey()
    {
        return (head->next == nullptr) ? "" : head->next->keys.front();
    }
};
