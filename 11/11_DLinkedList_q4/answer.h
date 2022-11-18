#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
using namespace std;


template <class T>
class DLinkedList {
public:
    class Node; // Forward declaration
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
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

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


	/// BEGIN  <STUDENT ANSWER>
template <class T>
T DLinkedList<T>::removeAt(int index)
{
    /* Remove element at index and return removed value */
}

template <class T>
bool DLinkedList<T>::removeItem(const T& item)
{
    /* Remove the first apperance of item in list and return true, otherwise return false */
    
}

template<class T>
void DLinkedList<T>::clear(){
    /* Remove all elements in list */
}
