#include <iostream>
#include <sstream>
#include <string>
#include <assert.h>
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
    bool    empty();
    T       get(int index);
    void    set(int index, const T& e);
    int     indexOf(const T& item);
    bool    contains(const T& item);
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

template<class T>
void SLinkedList<T>::add(const T& e) {
    Node* pNew = new Node(e);

    if (this->count == 0) {
        this->head = this->tail = pNew;
    }
    else {
        this->tail->next = pNew;
        this->tail = pNew;
    }

    this->count++;
}

template<class T>
void SLinkedList<T>::add(int index, const T& e) {
    if((index < 0) || (index > count))
        throw std::out_of_range("Index is out of range");
    
    if (index == this->count)
        return this->add(e);
    
    Node* pNew = new Node(e);
    if (index == 0) {
        pNew->next = this->head;
        this->head = pNew;
    }
    else {
        Node* pre = head;
        int i = 0;
        while (pre != NULL) {
            if (i == index - 1) break;
            pre = pre->next;
            i++;
        }

        pNew->next = pre->next;
        pre->next = pNew;
    }

    this->count++;
}

template<class T>
int SLinkedList<T>::size() {
    return this->count;
}



	/// BEGIN  <STUDENT ANSWER>
template<class T>
T SLinkedList<T>::get(int index) {
    /* Give the data of the element at given index in the list. */
    //TODO
}

template <class T>
void SLinkedList<T>::set(int index, const T& e) {
    /* Assign new value for element at given index in the list */
    //TODO

}

template<class T>
bool SLinkedList<T>::empty() {
    /* Check if the list is empty or not. */
    //TODO
    
}

template<class T>
int SLinkedList<T>::indexOf(const T& item) {
    /* Return the first index wheter item appears in list, otherwise return -1 */
    //TODO

}

template<class T>
bool SLinkedList<T>::contains(const T& item) {
    /* Check if item appears in the list */
    //TODO
    
}



