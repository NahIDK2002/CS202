#include "list.h"

int main(){
    LinkedList list;
    list.add(1);
    list.add(2);
    list.add(3);

    try{
        list.add(4);
    }
    catch (const char* msg){
        cout << msg;
    }

    try{
        list.add(2,5);
    }
    catch (const char* msg){
        cout << msg;
    }

    cout << list.toString() << "\n";
    
    try{
        cout << list.get(2) << "\n";
    }
    catch (const char* msg){
        cout << msg;
    }

    cout << list.toString() << "\n";

    try{
        cout << list.remove(1) << "\n";
    }
    catch (const char* msg){
        cout << msg;
    }
    cout << list.toString() << "\n";

    try{
        list.set(0,2);
    }
    catch (const char* msg){
        cout << msg;
    }

    cout << list.toString() << "\n";
    cout << list.size() << "\n";

    List* newList1=list.clone();
    cout << newList1->toString() << "\n";

    try{
        List* newList2=list.subList(2,3);
        cout << newList2->toString() << "\n";
    }
    catch (const char* msg){
        cout << msg;
    }

    list.clear();
    cout << list.toString() << "\n";

    return 0;
}