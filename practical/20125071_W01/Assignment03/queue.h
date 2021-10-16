#ifndef QUEUE_H_
#define QUEUE_H_

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Node{
    public:
        int val;
        Node *next;
        Node();
        Node(int x);
        Node(int x, Node *next);
        ~Node();
};

class LinkedListQueue{
    private:
        Node *head;
        Node *tail;
        int capacity;
        int num;

    public:
        LinkedListQueue();
        void init(int cap);
        void enqueue(int x);
        int dequeue();
        int peek();
        bool isEmpty();
        bool isFull();
        void clear();
};

void readFile(LinkedListQueue &q, string file);

#endif