#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 16;

void printVector(vector<int> vec) {
    cout << "[";
    for (auto i = 0u; i < vec.size(); i++) {
        if (i > 0u) cout << ", ";
        cout << vec[i];
    }
    cout << "]";
}
int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int arr1[] = {2, 9};
    int arr2[] = {0, 5};
    LLNode* head1 = LLNode::createWithIterators(arr1, arr1 + sizeof(arr1) / sizeof(int));
    LLNode* head2 = LLNode::createWithIterators(arr2, arr2 + sizeof(arr2) / sizeof(int));
    LLNode* newhead = addLinkedList(head1, head2);
    LLNode::printList(newhead);
    head1->clear();
    head2->clear();
    newhead->clear();
    return 0;

    /// END  <TEST CODE>


}