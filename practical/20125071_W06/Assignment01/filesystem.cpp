#include "filesystem.h"

using namespace std;

CItem::CItem() : name("New Item"), size(0), hidden(0), readOnly(0){}

CItem::CItem(string Name) : name(Name), size(0), hidden(0), readOnly(0){}

CItem::CItem(string Name, int Size, bool isHidden, bool isReadOnly) : name(Name), size(Size), hidden(isHidden), readOnly(isReadOnly) {};

CItem::~CItem(){}

bool CItem::isHidden(){
    return hidden;
}

int CItem::getSize(){
    return size;
}

void CItem::print(bool hiddenItems){
    if (hiddenItems || !hidden){
        cout << name << "\n";
    }
}

bool CItem::isSameName(string Name){
    return name==Name;
}

void CItem::setHidden(bool isHidden){
    hidden=isHidden;
}

CFolder::CFolder(){}

CFolder::CFolder(string name) : CItem(name){}

void CFolder::add(CItem* item){
    subItems.push_back(item);
    size+=item->getSize();
}

void CFolder::print(bool hiddenItems){
    if (!hiddenItems && this->isHidden()) return;

    CItem::print(hiddenItems);
    int n=subItems.size();
    for (int i=0;i<n;++i){
        subItems[i]->print(hiddenItems);
    }
}

CItem* CFolder::removeByName(string name){
    for (int i=0;i<subItems.size();++i){
        if (subItems[i]->isSameName(name)){
            delete subItems[i];
            subItems.erase(subItems.begin()+i);
        }
        else subItems[i]->removeByName(name);
    }
    return this;
}

CItem* CFolder::findByName(string name){
    if (this->isSameName(name)) return this;
    int n=subItems.size();
    for (int i=0;i<n;++i){
        CItem *tmp = subItems[i]->findByName(name);
        if (tmp) return tmp;
    }
    return 0;
}

void CFolder::setHidden(bool hidden, bool applyChildren){
    this->CItem::setHidden(hidden);
    if (!applyChildren) return;
    int n=subItems.size();
    for (int i=0;i<n;++i){
        subItems[i]->setHidden(hidden);
    }
}

CFile::CFile(){};

CFile::CFile(string name, int size) : CItem(name,size,0,0){}

void CFile::print(bool hiddenItems){
    if (!hiddenItems && this->isHidden()) return;
    CItem::print(hiddenItems);
}

void CFile::setHidden(bool isHidden, bool applyChildren){
    CItem::setHidden(isHidden);
}

CItem* CFile::findByName(string name){
    return (this->isSameName(name)) ? this : 0;
}

CItem* CFile::removeByName(string name){
    return 0;
}