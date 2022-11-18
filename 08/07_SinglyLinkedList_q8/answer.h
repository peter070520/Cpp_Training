#include <iostream>
#include <sstream>
using namespace std;



class LinkedList {
    public: 
        class Node;
    private:
        Node* head;
        Node* tail;
        int size;
    public: 
        class Node {
            private: 
                int value;
                Node* next;
                friend class LinkedList;
            public:
                Node() {
                    this->next = NULL;
                }
                Node(Node* node) {
                    this->value = node->value;
                    this->next = node->next;
                }
                Node(int value, Node* next = NULL) {
                    this->value = value;
                    this->next = next;
                }
        };
        LinkedList(): head(NULL), tail(NULL), size(0) {};
        ~LinkedList() {
            this->clear();
        }
        void clear() {
            Node* curNode = this->head;
            Node* next = NULL;
            while(curNode != NULL) {
                next = curNode->next;
                delete curNode;
                curNode = next;
            }
        }
        void add(int value) {
            Node* p = new Node(value);
            if(this->size == 0) {
                this->head = this->tail = p;
            } else {
                this->tail->next = p;
                this->tail = p;
            }
            this->size++;
        }
        string toString() {
            stringstream ss;
            ss << "[";
            Node* ptr = head;
            while (ptr != tail)
            {
                ss << ptr->value << ",";
                ptr = ptr->next;
            }

            if (this->size > 0)
                ss << ptr->value << "]";
            else
                ss << "]";
            return ss.str();
        }
        void partition(int k);
};

/// BEGIN  <STUDENT ANSWER>
void LinkedList::partition(int k) {
    //TODO
    
    
}
/// END  <STUDENT ANSWER>