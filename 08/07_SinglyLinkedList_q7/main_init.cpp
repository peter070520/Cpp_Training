#include "answer.h"
#include "utils.h"

const string CHECKED_FILENAME = "answer.h";
const int NO_IGNORED_LINES = 5;


int main() {
    codeCheck(CHECKED_FILENAME, NO_IGNORED_LINES);

    int arr[] = {2, 4, 6, 6, 3};
    int k = 3;
    LLNode* head = LLNode::createWithIterators(arr, arr + sizeof(arr) / sizeof(int));
    LLNode::printList(head);
    cout << "\n";
    LLNode* newhead = rotateLinkedList(head, k);
    LLNode::printList(newhead);
    return 0;

    /// END  <TEST CODE>


}