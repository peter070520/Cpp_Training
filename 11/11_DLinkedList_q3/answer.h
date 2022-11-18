#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;


template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
    class Iterator ;
protected:
    Node* head;
    Node* tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0){};
    ~DLinkedList(){};
    void    add(const T &e);
    void    add(int index, const T &e);
    int     size();
    bool    empty();
    T       get(int index);
    void    set(int index, const T &e);
    int     indexOf(const T &item);
    bool    contains(const T &item);
    T       removeAt(int index);
    bool    removeItem(const T &item);
    void    clear();
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
        Node *previous;
        friend class DLinkedList<T>;
        
        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();
        
        // Prefix ++ overload
        Iterator &operator++();
        
        // Postfix ++ overload
        Iterator operator++(int);
    };
    
    string toString()
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

};

template <class T>
void DLinkedList<T>::add(const T &e)
{
    Node *pNew = new Node(e);

    if (this->count == 0)
    {
        this->head = pNew;
        this->tail = pNew;
    }
    else
    {
        this->tail->next = pNew;
        pNew->previous = this->tail;
        this->tail = pNew;
    }

    this->count++;
}

template <class T>
void DLinkedList<T>::add(int index, const T &e)
{
    if ((index < 0) || (index > count))
        throw std::out_of_range("Index is out of range");

    if (index == this->count)
        return this->add(e);

    Node *pNew = new Node(e);
    if (index == 0)
    {
        pNew->next = this->head;
        this->head->previous = pNew;
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
        pNew->previous = pre;
        pre->next->previous = pNew;
        pre->next = pNew;
    }

    this->count++;
}

template <class T>
int DLinkedList<T>::size()
{
    return this->count;
}

template <class T>
bool DLinkedList<T>::contains(const T &item)
{
    return indexOf(item) != -1;
}

template <class T>
bool DLinkedList<T>::empty()
{
    return this->count == 0;
}

template <class T>
T DLinkedList<T>::get(int index)
{
    if ((index < 0) || (index > count - 1))
        throw std::out_of_range("The index is out of range!");

    if (index < this->size() / 2)
    {
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
    else
    {
        Node *temp = this->tail;
        int cursor = this->size() - 1;
        while (temp != NULL)
        {
            if (cursor == index)
                break;

            temp = temp->previous;
            cursor--;
        }

        return temp->data;
    }
}

template <class T>
int DLinkedList<T>::indexOf(const T &item)
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
void DLinkedList<T>::set(int index, const T &e)
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
void DLinkedList<T>::clear()
{
    while (this->count > 0)
    {
        this->removeAt(0);
    }
}


template <class T>
T DLinkedList<T>::removeAt(int index)
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
        if (this->head == NULL)
            this->tail = NULL;
        else
            this->head->previous = NULL;

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
    if (pre->next == NULL)
        this->tail = pre;
    else
        del->next->previous = pre;

    del->next = NULL;
    delete del;

    this->count--;
    return delData;
}

template <class T>
bool DLinkedList<T>::removeItem(const T &item)
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
    del->previous = NULL;

    if (del == this->tail)
        this->tail = pre;
    else
        pre->next->previous = pre;

    delete del;
    this->count--;

    return true;
}

	/// BEGIN  <STUDENT ANSWER>
/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin) 
{

}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    
}

template <class T> 
void DLinkedList<T>::Iterator::set(const T &e)
{
    
}

template<class T>
T& DLinkedList<T>::Iterator::operator*() 
{
    
}

template<class T>
void DLinkedList<T>::Iterator::remove() 
{
    /*
    * TODO: delete Node in pList which Node* current point to. 
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator) 
{
    
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++() 
{
    
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int) 
{
    
}

