#ifndef ILIST_H
#define ILIST_H
#include <string>
using namespace std;

template <class T>
class IList
{
public:
    virtual void add(const T& e) = 0;
    virtual void add(int index, const T& e) = 0;
    virtual T removeAt(int index) = 0;
    virtual bool removeItem(const T& item) = 0;
    virtual bool empty() = 0;
    virtual int size() = 0;
    virtual void clear() = 0;
    virtual T get(int index) = 0;
    virtual void set(int index, const T& e) = 0;
    virtual int indexOf(const T& item) = 0;
    virtual bool contains(const T& item) = 0;
    virtual string toString() = 0;
};
#endif /* ILIST_H */
