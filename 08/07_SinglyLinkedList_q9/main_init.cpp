#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;

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

int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);
    
    Polynomial *poly = new Polynomial();
    poly->insertTerm(6.0, 2);
    poly->insertTerm(4.0, 5);
    poly->insertTerm(4.0, 3);
    poly->insertTerm(6.0, 5);
    poly->insertTerm(-1.0, 0);
    poly->insertTerm(-6.0, 6);
    poly->insertTerm(6.0, 6);
    poly->print();
    return 0;
}




