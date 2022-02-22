#include "filesystem.h"

using namespace std;

int main(){
    CFolder C("C");
    CFolder System("System");
    CFolder Windows("Windows");
    CFile a_txt("a.txt",123);
    CFile b_doc("b.doc",456);

    System.add(&a_txt);
    Windows.add(&b_doc);
    C.add(&System);
    C.add(&Windows);

    cout << "Content of folder C -> " << endl;
    bool isPrintHiddenItems=0;
    C.print(isPrintHiddenItems);

    CItem* p=C.removeByName("System");
    cout << "Content of folder C after removing folder System -> " << endl;
    C.print(0);

    p=C.findByName("b.doc");
    if (p!=NULL){
        cout << "b.doc is found in folder C" << endl;
    }
    else{
        cout << "b.doc is not found" << endl;
    }

    p=C.findByName("a.txt");
    if (p!=NULL){
        cout << "a.txt is found" << endl;
    }
    else{
        cout << "a.txt is not found" << endl;
    }

    p=C.findByName("Windows");
    bool isHidden;
    bool isAlsoApplyToChildren;

    if (p!=NULL){
        cout << "Folder Windows is folder. Content of folder Windows ->" << endl;
        isHidden = 1; isAlsoApplyToChildren=0;

        p->setHidden(isHidden,isAlsoApplyToChildren);
        p->print(0);

        isHidden=1; isAlsoApplyToChildren=1;
        p->setHidden(isHidden,isAlsoApplyToChildren);
        p->print(0);
    }
    else{
        cout << "Folder Windows is not found" << endl;
    }

    return 0;
}