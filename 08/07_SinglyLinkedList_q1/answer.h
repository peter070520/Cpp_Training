#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
class SLinkedList {
public:
    class Node; // Forward declaration
protected:
    Node* head;
    Node* tail;
    int count;
public:
    SLinkedList(): head(NULL), tail(NULL), count(0) {};
    ~SLinkedList() { };
    void    add(const T& e);
    void    add(int index, const T& e);
    int     size();
    string  toString() {
        stringstream ss;
        ss << "[";
        Node* ptr = head;
        while(ptr != tail){
            ss << ptr->data << ",";
            ptr = ptr->next;
        }
        
        if(count > 0)
            ss << ptr->data << "]";
        else 
            ss << "]";
        return ss.str();
    }
public:
    class Node {
    private:
        T data;
        Node* next;
        friend class SLinkedList<T>;
    public:
        Node() {
            next = 0;
        }
        Node(Node* next) {
            this->next = next;
        }
        Node(T data, Node* next = NULL) {
            this->data = data;
            this->next = next;
        }
    };
};
template <class T>
void SLinkedList<T>::add(const T& e) {
    /* Insert an element into the end of the list. */
    //TODO
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    /* Insert an element into the list at given index. */
    //TODO
}

template<class T>
int SLinkedList<T>::size() {
    /* Return the length (size) of list */ 
    //TODO
}
