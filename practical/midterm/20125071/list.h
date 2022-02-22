#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <string>

using namespace std;

class List{
public:
    virtual ~List();
    virtual void add(int x)=0;
    virtual void add(int index, int x)=0;
    virtual void clear()=0;
    virtual List* clone ()=0;
    virtual int get(int index)=0;
    virtual int remove(int index)=0;
    virtual void set(int index, int element)=0;
    virtual int size()=0;
    virtual List* subList(int fromIndex, int toIndex)=0;
    virtual string toString()=0;
};

struct Node
{
    int data;
    Node *next;
    Node();
    Node(int x);
    Node(int x, Node *n);
};

class LinkedList: public List{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    ~LinkedList();
    void add(int x);
    void add(int index, int x);
    void clear();
    List* clone();
    int get(int index);
    int remove(int index);
    void set(int index, int element);
    int size();
    List* subList(int fromIndex, int toIndex);
    string toString();
};


#endif