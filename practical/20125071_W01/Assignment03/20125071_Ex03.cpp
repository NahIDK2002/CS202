#include "queue.h"

using namespace std;

int main(){
    try{
        LinkedListQueue q;
        readFile(q,"input.txt");
        cout << "Try push when queue is full: ";
        try{
            q.enqueue(0);
            
        }
        catch (const char *msg){
            cout << msg << "\n\n";
        }

        cout << "Peek: " << q.peek() << "\n";
        cout << "Dequeue: " << q.dequeue() << "\n";
        cout << "Peek after dequeue: " << q.peek() << "\n";
        cout << "isEmpty: " << q.isEmpty() << "\n";

        cout << "Push 1 element\n";
        q.enqueue(2);

        cout << "isEmpty: " << q.isEmpty() << "\n";
        cout << "isFull: " << q.isFull() << "\n";

        q.clear();
        cout << "After clear: isEmpty: " << q.isEmpty() << "\n";
        cout << "             isFull:  " << q.isFull() << "\n";
        cout << "             dequeue: ";
        
        try{
            q.dequeue();
        }
        catch(const char* &msg){
            cout << msg << '\n';
        }     
    }
    catch (const char* &msg){
        cout << msg;
    }

    return 0;
}