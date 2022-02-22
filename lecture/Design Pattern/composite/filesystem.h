#ifndef FILESYSTEM_H_
#define FILESYSTEM_H_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class CItem{
protected:
    string name;
    int size;

public:
    CItem();
    CItem(string Name);
    CItem(string Name, int size);
    virtual ~CItem();
    virtual void input();
    virtual int getSize();
    virtual void printSize();
};

class CFolder : public CItem{
private:
    vector<CItem*> subItems;

public:
    CFolder();
    CFolder(string name);
    void input();
    void add(CItem* item);
    void printSize();
};

class CFile: public CItem{
public:
    CFile();
    CFile(string name, int size);
    void input();
};

#endif