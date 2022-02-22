#include "savePrincess.h"

using namespace std;

void Prince::input(){
	cout << "Input the money of prince: ";
	cin >> money;

	cout << "Input the intellect of prince: ";
	cin >> intellect;

	cout << "Input the strength of prince: ";
	cin >> strength;
}

void Prince::output(){
	cout << "Money: " << money << "\n";
	cout << "Intellect: " << intellect << "\n";
	cout << "Strength: " << strength << "\n";
}

int Prince::getMoney(){
	return money;
}

int Prince::getIntellect() {
	return intellect;
}

int Prince::getStrength() {
	return strength;
}

void Prince::setMoney(int val) {
	money = val;
}

void Prince::setStrength(int val) {
	strength = val;
}

Gate::~Gate(){}

void BussinessGate::input(){
	cout << "Input the number of items: ";
	cin >> numItems;

	cout << "Input the price of each items: ";
	cin >> price;
}

bool BussinessGate::pass(Prince &prince){
	int money=prince.getMoney();
	if (money<numItems*price) return 0;
	prince.setMoney(money-=numItems*price);
	return 1;
}

void AcademicGate::input(){
	cout << "Input the intellect needed to pass: ";
	cin >> intellect;
}

bool AcademicGate::pass(Prince &prince){
	int pIntellect=prince.getIntellect();
	return (pIntellect>=intellect);
}

void PowerGate::input(){
	cout << "Input the strength needed to pass: ";
	cin >> strength;
}

bool PowerGate::pass(Prince &prince){
	int pStrength=prince.getStrength();
	if (pStrength<strength) return 0;
	prince.setStrength(pStrength-strength);

	return 1;
}

Castle::~Castle(){
	int n=gates.size();
	for (int i=0;i<n;++i){
		delete gates[i];
	}
}

void Castle::input(){
	int n;
	cout << "Input the number of gates: ";
	cin >> n;
	for (int i=0;i<n;++i){
		Gate *g=0;
		cout << "Input the kind of gate (1: BussinessGate, 2: AcademicGate, other: PowerGate): ";
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 1:
			g = new BussinessGate;
			break;

		case 2:
			g = new AcademicGate;
			break;
		
		default:
			g = new PowerGate;
			break;
		}

		g->input();
		gates.push_back(g);
		cout << "\n";
	}

	prince.input();
}

bool Castle::savePrincess(){
	int n=gates.size();
	for (int i=0;i<n;++i){
		if (!gates[i]->pass(prince)) return 0;
	}

	cout << "\nStatistic of prince after save princess:\n";
	prince.output();
	cout << "\n";

	return 1;
}