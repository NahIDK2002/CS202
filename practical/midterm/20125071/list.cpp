#include "list.h"

Node::Node(){
    data=0;
    next=0;
}

Node::Node (int x){
    data=x;
    next=0;
}

Node::Node(int x, Node *n){
    data=x;
    next=n;
}

List::~List(){}

LinkedList::LinkedList(){
    head=0;
    tail=0;
}

LinkedList::~LinkedList(){
    while (head){
        Node *tmp=head->next;;
        delete head;
        head=tmp;
    }
    head=tail=0;
}

void LinkedList::add(int x){
    if (!tail){
        head=new Node(x);
        tail=head;
    }
    else{
        tail->next=new Node(x);
        tail=tail->next;
    }
}

void LinkedList::add(int index, int x){
    int n=size();
    if (index<0 || index>=n) {
        throw "Index is out of range";
    }
    if (index==0){
        Node *newHead= new Node(x,head);
        head=newHead;
    }
    else if (index==n){
        tail->next = new Node(x);
        tail=tail->next;
    }
    else{
        int i=1; Node *cur=head;
        while (i<index)
        {
            ++i;
            cur=cur->next;
        }
        Node *next=cur->next;
        cur->next=new Node(x,next);
    }
}

void LinkedList::clear(){
    while (head){
        Node *tmp=head;
        head=head->next;
        delete tmp;
    }
    head=tail=0;
}

List* LinkedList::clone(){
    static LinkedList newList;

    Node *cur=head;
    while (cur){
        if (newList.head){
            newList.tail->next=new Node(cur->data);
            newList.tail=newList.tail->next;
        }
        else{
            newList.head=new Node(cur->data);
            newList.tail=newList.head;
        }
        cur=cur->next;
    }

    return &newList;
}

int LinkedList::get(int index){
    int n=size();
    if (index<0 || index>=n){
        throw "Index is out of range!\n";
    }
    if (index==0){
        return head->data;
    }
    else if (index==n-1){
        return tail->data;
    }
    else{
        Node *cur=head;
        while (index--){
            cur=cur->next;
        }

        return cur->data;
    }
}

int LinkedList::remove(int index){
    int n=size();
    if (index<0 || index>=n){
        throw "Index is out of range!\n";
    }

    int removeVal=0;
    if (index==0){
        removeVal=head->data;
        Node *newHead=head->next;
        delete head;
        head=newHead;
    }
    else{
        Node *prev=head;
        for (int i=1;i<index;++i){
            prev=prev->next;
        }

        removeVal=prev->next->data;
        Node *next=prev->next->next;
        delete prev->next;
        prev->next=next;
        if (index==n-1) tail=prev;
    }

    return removeVal;
}

void LinkedList::set(int index, int element){
    int n=size();
    if (index<0 || index>=n){
        throw "Index is out of range!\n";
    }
    if (index==0){
        head->data=element;
    }
    else if (index==n-1){
        tail->data=element;
    }
    else{
        Node *cur=head;
        for (int i=0;i<index;++i){
            cur=cur->next;
        }
        cur->data=element;
    }
}

int LinkedList::size(){
    Node *tmp=head;
    int count=0;
    while (tmp){
        count++;
        tmp=tmp->next;
    }

    return count;
}

List* LinkedList::subList(int fromIndex, int toIndex){
    int n=size();
    if (fromIndex<0 || fromIndex>=n){
        throw "fromIndex is out of range!\n";
    }
    if (toIndex<0 || toIndex>n){
        throw "toIndex is out of range!\n";
    }

    static LinkedList newList;
    if (fromIndex==toIndex) return &newList;
    
    Node *cur=head;
    for (int i=0;i<fromIndex;++i){
        cur=cur->next;
    }

    newList.head = new Node(cur->data);
    newList.tail=newList.head;
    for (int i=fromIndex+1;i<toIndex;++i){
        cur=cur->next;
        newList.tail->next=new Node(cur->data);
        newList.tail=newList.tail->next;
    }

    return &newList;
}

string LinkedList::toString(){
    string list="";
    if (!head) return list;
    list = to_string(head->data);
    Node *cur=head->next;
    while (cur){
        list+=' ' + to_string(cur->data);
        cur=cur->next;
    }

    return list;
}