#include "queue.h"

using namespace std;

void readFile(LinkedListQueue &q, string file){
    ifstream f;
    f.open(file);

    if (!f.is_open()){
        f.close();
        throw "Error! Can't open file!";
    }

    int cap;
    f >> cap;
    q.init(cap);

    int n;
    f >> n;
    for (int i=0;i<n;++i){
        int x;
        f >> x;
        q.enqueue(x);
    }

    f.close();
}

Node::Node(){
    val=0;
    next=0;
}

Node::Node(int x){
    val=x;
    next=0;
}

Node::Node(int x, Node *next){
    val=x;
    this->next=next;
}

Node::~Node(){
}

LinkedListQueue::LinkedListQueue(){
    head=tail=0;
    capacity=num=0;
}

void LinkedListQueue::init(int cap){
    head=tail=0;
    capacity=cap;
    num=0;
}

void LinkedListQueue::enqueue(int x){
    if (num==capacity){
        throw "Error! Queue is full!";
    }
    if (!tail){
        head = new Node(x);
        tail=head;
    }
    else{
        tail->next = new Node(x);
        tail=tail->next;
    }
    ++num;
}

int LinkedListQueue::dequeue(){
    if (!num){
        throw "Error! There's no element in queue!";
    }
    int ans=head->val;
    Node *tmp=head;
    head=head->next;
    delete tmp;
    --num;

    return ans;
}

int LinkedListQueue::peek(){
    return head->val;
}

bool LinkedListQueue::isEmpty(){
    return !num;
}

bool LinkedListQueue::isFull(){
    return num==capacity;
}

void LinkedListQueue::clear(){
    while (head){
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }

    tail=0;
    num=0;
}