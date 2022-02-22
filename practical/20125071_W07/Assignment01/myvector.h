#ifndef MYVECTOR_H
#define MYVECTOR_H_

#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

template <class T>
class MyVector {
private:
	int size;
	T* arr;

public:
	MyVector();
	MyVector(int n);
	MyVector(T* a, int n);
	MyVector(const MyVector& v);
	~MyVector();

	int getSize();
	T getItem(int index);
	void setItem(T value, int index);

	void add(T value);
	void addRange(T *a, int n);
	void clear();
	bool contains(T value);
	void toArray(T *a, int &n);
	bool equals(const MyVector &v);
	int indexOf(T value);
	int lastIndexOf(T value);
	void insert(T value, int idex);
	void remove(T value);
	void removeAt(int index);
	void reverse();
	string toString();

	void sortAsc();
	void sortDest();
};

class Fraction{
private:
	int num;
	int denom;
	int GCD(int a, int b);
	void normalize();

public:
	Fraction(int n, int d);
	Fraction(const Fraction &other);
	const Fraction& operator=(const Fraction &other);
	const Fraction& operator= (const int &val);
	bool operator==(const Fraction &other);
	bool operator!=(const Fraction &other);
	bool operator<(const Fraction &other);
	bool operator>(const Fraction &other);
	string toString();
	friend ostream& operator<<(ostream &out, const Fraction &f);
};

string to_string(Fraction f);

#endif // !MYVECTOR_H