#include "filesystem.h"

using namespace std;

CItem::CItem() : name("New Item"), size(0){}

CItem::CItem(string Name) : name(Name), size(0){}

CItem::CItem(string Name, int Size) : name(Name), size(Size){}

CItem::~CItem(){}

void CItem::input(){
    cout << "Name of the item: ";
    fflush(stdin);
    getline(cin,name);
}

int CItem::getSize(){
    return size;
}

void CItem::printSize(){
    cout << "The size of item " << name << ": " << size << "\n";
}

CFolder::CFolder(){}

CFolder::CFolder(string name) : CItem(name){}

void CFolder::input(){
    CItem::input();
    int choice=0;
    CItem *item=0;
    do {
        cout << "You are at folder " << name << "\n";
        cout << "1: add Folder, 2: add File, 0: stop\nPlease input your choice: " ;
        cin >> choice;
        switch (choice)
        {
            case 1:
                item=new CFolder();
                item->input();
                add(item);
                break;

            case 2:
                item= new CFile();
                item->input();
                add(item);
                break;
            
            default:
                break;
        }
    } while (choice);
}

void CFolder::add(CItem* item){
    subItems.push_back(item);
    size+=item->getSize();
}

void CFolder::printSize(){
    CItem::printSize();
    int n=subItems.size();
    for (int i=0;i<n;++i){
        subItems[i]->printSize();
    }
}

CFile::CFile(){};

void CFile::input(){
    CItem::input();
    cout << "The size of the item: ";
    cin >> size;
}

CFile::CFile(string name, int size) : CItem(name,size){}
