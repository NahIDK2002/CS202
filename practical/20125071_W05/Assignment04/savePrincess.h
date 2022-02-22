#ifndef SAVEPRINCESS_H_
#define SAVEPRINCESS_H_

#include <iostream>
#include <vector>

using namespace std;

class Prince {
private:
	int money;
	int intellect;
	int strength;

public:
	void input();
	void output();
	int getMoney();
	int getIntellect();
	int getStrength();
	void setMoney(int val);
	void setStrength(int val);
};

class Gate {
public:
	virtual void input() = 0;
	virtual bool pass(Prince& prince) = 0;
	virtual ~Gate();
};

class BussinessGate : public Gate{
private:
	int numItems;
	int price;

public:
	void input();
	bool pass(Prince &prince);
};

class AcademicGate : public Gate{
private:
	int intellect;

public:
	void input();
	bool pass(Prince &prince);
};

class PowerGate : public Gate{
private:
	int strength;

public:
	void input();
	bool pass(Prince &prince);
};

class Castle{
private:
	vector<Gate*> gates;
	Prince prince;

public:
	~Castle();
	void input();
	bool savePrincess();
};


#endif // !SAVEPRINCESS_H_
