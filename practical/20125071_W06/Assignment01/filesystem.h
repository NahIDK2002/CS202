#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CItem{
private:
    bool hidden;
    bool readOnly;
    string name;

protected:
    int size;

public:
    CItem();
    CItem(string Name);
    CItem(string Name, int Size, bool isHidden, bool isReadOnly);
    virtual ~CItem();
    virtual void setHidden(bool isHidden);
    virtual void setHidden(bool isHidden, bool applyChildren)=0;
    virtual bool isHidden();
    virtual bool isSameName(string Name);
    virtual int getSize();
    virtual void print(bool hiddenItems);
    virtual CItem* removeByName(string name)=0;
    virtual CItem* findByName(string name) = 0;
};

class CFolder : public CItem{
private:
    vector<CItem*> subItems;

public:
    CFolder();
    CFolder(string name);
    CFolder(const CFolder &other);
    const CFolder& operator= (const CItem &other);
    void add(CItem* item);
    void print(bool hiddenItems);
    CItem* removeByName(string name);
    CItem* findByName(string name);
    void setHidden(bool hidden, bool applyChildren);
};

class CFile: public CItem{
public:
    CFile();
    CFile(string name, int size);
    void print(bool hiddenItems);
    void setHidden(bool isHidden, bool applyChildren);
    CItem* removeByName(string name);
    CItem* findByName(string name);
};

#endif