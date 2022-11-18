#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;


int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int arr[] = {13, 88, 60, 7, 192};
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = reverseLinkedList(head);
    LLNode::printList(newhead);
    newhead->clear();
    return 0;

    /// END  <TEST CODE>


}