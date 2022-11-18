#include <iostream>
using namespace std;



class LLNode {
public:
    int val;
    LLNode* next;
    LLNode();
    LLNode(int val, LLNode* next);
    template <typename InputIterator>
    static LLNode* createWithIterators(InputIterator first, InputIterator last);
    static void printList(LLNode* head);
    void clear();
};

LLNode::LLNode() : val(0), next(nullptr) {}

LLNode::LLNode(int val, LLNode* next = nullptr) : val(val), next(next) {}

template <typename InputIterator>
LLNode* LLNode::createWithIterators(InputIterator first, InputIterator last) {
    LLNode* trav = nullptr;
    LLNode* head = nullptr;
    while (first != last) {
        if (trav == nullptr) {
            head = new LLNode(*first);
            trav = head;
        }
        else {
            trav->next = new LLNode(*first);
            trav = trav->next;
        }
        first = first + 1;
    }
    return head;
}

void LLNode::printList(LLNode* head) {
    cout << "[";
    LLNode* trav = head;
    while (trav != nullptr) {
        cout << trav->val;
        trav = trav->next;
        if (trav != nullptr) cout << ", ";
    }
    cout << "]";
}

void LLNode::clear() {
    LLNode* pre = this;
    LLNode* trav = this;
    while (trav != nullptr) {
        trav = trav->next;
        delete pre;
        pre = trav;
    }
}

/// BEGIN  <STUDENT ANSWER>
LLNode* reverseLinkedList(LLNode* head)
{
    // STUDENT ANSWER
    
}
/// END  <STUDENT ANSWER>