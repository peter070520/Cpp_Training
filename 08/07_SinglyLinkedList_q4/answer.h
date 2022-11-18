#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;

template <class T>
class SLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration

protected:
    Node *head;
    Node *tail;
    int count;

public:
    SLinkedList() : head(NULL), tail(NULL), count(0){};
    ~SLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &removeItem);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();

    SLinkedList(const SLinkedList &list)
    {
        this->count = 0;
        this->head = NULL;
        this->tail = NULL;
    }

    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }

public:
    class Node
    {
    private:
        T data;
        Node *next;
        friend class SLinkedList<T>;

    public:
        Node()
        {
            next = 0;
        }
        Node(Node *next)
        {
            this->next = next;
        }
        Node(T data, Node *next = NULL)
        {
            this->data = data;
            this->next = next;
        }
    };

    class Iterator
    {
    private:
        SLinkedList<T>* pList;
        Node* current;
        int index;

    public:
        Iterator(SLinkedList<T> *pList = 0, bool begin = true);
        Iterator &operator=(const Iterator &iterator);
        void remove();
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
};


template <class T>
SLinkedList<T>::~SLinkedList()
{
    this->clear();
}

template <class T>
void SLinkedList<T>::add(const T& e)
{
    Node *pNew = new Node(e);

    if (this->count == 0)
    {
        this->head = this->tail = pNew;
    }
    else
    {
        this->tail->next = pNew;
        this->tail = pNew;
    }

    this->count++;
}

template <class T>
void SLinkedList<T>::add(int index, const T& e)
{
    if ((index < 0) || (index > count))
        throw std::out_of_range("Index is out of range");

    if (index == this->count)
        return this->add(e);

    Node *pNew = new Node(e);
    if (index == 0)
    {
        pNew->next = this->head;
        this->head = pNew;
    }
    else
    {
        Node *pre = head;
        int cursor = 0;
        while (pre != NULL)
        {
            if (cursor == index - 1)
                break;
            pre = pre->next;
            cursor++;
        }

        pNew->next = pre->next;
        pre->next = pNew;
    }

    this->count++;
}

template <class T>
T SLinkedList<T>::removeAt(int index)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("Index is out of range");

    Node *pre = this->head;
    int cursor = 0;

    if (index == 0)
    {
        Node *temp = this->head;
        T delData = this->head->data;
        this->head = this->head->next;
        delete temp;
        this->count--;
        return delData;
    }

    while (pre != NULL)
    {
        if (cursor == index - 1)
            break;

        pre = pre->next;
        cursor++;
    }

    Node *del = pre->next;
    T delData = del->data;
    pre->next = del->next;
    del->next = NULL;
    if (pre->next == NULL) {
        this->tail = pre;
    }
    delete del;

    this->count--;
    return delData;
}

template <class T>
bool SLinkedList<T>::removeItem(const T& item)
{
    if (this->count == 0)
        return false;

    if (this->head->data == item)
    {
        this->removeAt(0);
        return true;
    }

    bool found = false;
    Node *pre = this->head;
    while (pre != this->tail)
    {
        if (pre->next->data == item)
        {
            found = true;
            break;
        }
        pre = pre->next;
    }

    if (!found)
        return false;

    Node *del = pre->next;
    pre->next = del->next;
    del->next = NULL;

    if (del == this->tail)
    {
        tail = pre;
    }

    delete del;
    this->count--;

    return true;
}

template <class T>
bool SLinkedList<T>::empty()
{
    return count == 0;
}

template <class T>
int SLinkedList<T>::size()
{
    return count;
}

template <class T>
void SLinkedList<T>::clear()
{
    while (this->count > 0)
    {
        this->removeAt(0);
    }
}

template <class T>
T SLinkedList<T>::get(int index)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");

    Node *temp = this->head;
    int cursor = 0;
    while (temp != NULL)
    {
        if (cursor == index)
            break;

        temp = temp->next;
        cursor++;
    }

    return temp->data;
}

template <class T>
void SLinkedList<T>::set(int index, const T& e)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");

    Node *temp = this->head;
    int cursor = 0;
    while (temp != NULL)
    {
        if (cursor == index)
        {
            temp->data = e;
            return;
        }

        temp = temp->next;
        cursor++;
    }
}

template <class T>
int SLinkedList<T>::indexOf(const T& item)
{
    Node *temp = this->head;
    int cursor = 0;
    while (temp != NULL)
    {
        if (temp->data == item)
            return cursor;

        temp = temp->next;
        cursor++;
    }

    return -1;
}
template <class T>
bool SLinkedList<T>::contains(const T& item)
{
    return indexOf(item) != -1;
}

template <class T>
string SLinkedList<T>::toString()
{
    stringstream ss;
    ss << "[";
    Node *ptr = head;
    while (ptr != tail)
    {
        ss << ptr->data << ",";
        ptr = ptr->next;
    }

    if (count > 0)
        ss << ptr->data << "]";
    else
        ss << "]";
    return ss.str();
}

/// BEGIN  <STUDENT ANSWER>
template <class T>
SLinkedList<T>::Iterator::Iterator(SLinkedList<T>* pList, bool begin)
{
    /*
        Constructor of iterator
        * Set pList to pList
        * begin = true: 
        * * Set current (index = 0) to pList's head if pList is not NULL
        * * Otherwise set to NULL (index = -1)
        * begin = false: 
        * * Always set current to NULL
        * * Set index to pList's size if pList is not NULL, otherwise 0
    */
}

template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator=(const Iterator& iterator)
{
    /*
        Assignment operator
        * Set this current, index, pList to iterator corresponding elements.
    */
}

template <class T>
void SLinkedList<T>::Iterator::remove()
{
    /*
        Remove a node which is pointed by current
        * After remove current points to the previous node of this position (or node with index - 1)
        * If remove at front, current points to previous "node" of head (current = NULL, index = -1)
        * Exception: throw std::out_of_range("Segmentation fault!") if remove when current is NULL
    */
}

template <class T>
void SLinkedList<T>::Iterator::set(const T& e)
{
    /*
        Set the new value for current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
T& SLinkedList<T>::Iterator::operator*()
{
    /*
        Get data stored in current node
        * Exception: throw std::out_of_range("Segmentation fault!") if current is NULL
    */
}

template <class T>
bool SLinkedList<T>::Iterator::operator!=(const Iterator& iterator)
{
    /*
        Operator not equals
        * Returns false if two iterators points the same node and index
    */
}
// Prefix ++ overload
template <class T>
typename SLinkedList<T>::Iterator& SLinkedList<T>::Iterator::operator++()
{
    /*
        Prefix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}
// Postfix ++ overload
template <class T>
typename SLinkedList<T>::Iterator SLinkedList<T>::Iterator::operator++(int)
{
    /*
        Postfix ++ overload
        * Set current to the next node
        * If iterator corresponds to the previous "node" of head, set it to head
        * Exception: throw std::out_of_range("Segmentation fault!") if iterator corresponds to the end
    */
}

/// END  <STUDENT ANSWER>