#include "myvector.h"

using namespace std;

//Implementation of MyVector
template<class T>
MyVector<T>::MyVector(){
	size = 0;
	arr = 0;
}

template<class T>
MyVector<T>::MyVector(int n)
{
	size = n;
	arr = new T[n];
	for (int i = 0; i < n; ++i) arr[i] = 0;
}

template<class T>
MyVector<T>::MyVector(T* a, int n){
	size = n;
	arr = new T[n];
	for (int i = 0; i < n; ++i) arr[i] = a[i];
}

template<class T>
MyVector<T>::MyVector(const MyVector& v) {
	size = v.size;
	arr = new T[size];
	for (int i = 0; i < size; ++i) arr[i] = v.arr[i];
}

template<class T>
MyVector<T>::~MyVector(){
	if (arr) delete[] arr;
	size = 0;
	arr = 0;
}

template<class T>
int MyVector<T>::getSize(){
	return size;
}

template<class T>
T MyVector<T>::getItem(int index){
	if (index<0 || index>=size) {
		cout << "MyVector<T>::getItem: index is out of range.\n";
		exit(0);
	}
	return arr[index];
}

template<class T>
void MyVector<T>::setItem(T value, int index){
	if (index<0 || index>=size) {
		cout << "MyVector<T>::setItem(T,int): index is out of range.\n";
		exit(0);
	}
	arr[index]=value;
}

template<class T>
void MyVector<T>::add(T value){
	T *tmp=new T[size+1];
	for (int i=0;i<size;++i) tmp[i]=arr[i];
	tmp[size]=value;
	swap(tmp,arr);
	delete[] tmp;
	size++;
}

template<class T>
void MyVector<T>::addRange(T *a, int n){
	T *tmp=new T[size+n];
	for (int i=0;i<size;++i) tmp[i]=arr[i];
	for (int i=0;i<n;++i) tmp[i+size]=a[i];
	swap(tmp,arr);
	delete[] tmp;
	size+=n;
}

template<class T>
void MyVector<T>::clear(){
	delete[] arr;
	size=0;
	arr=0;
}

template<class T>
bool MyVector<T>::contains(T value){
	for (int i=0;i<size;++i){
		if (arr[i]==value) return 1;
	}
	return 0;
}

template<class T>
void MyVector<T>::toArray(T *a, int &n){
	for (int i=0;i<size;++i) a[i]=arr[i];
	n=size;
}

template<class T>
bool MyVector<T>::equals(const MyVector &v){
	if (v.size!=size) return 0;
	for (int i=0;i<size;++i){
		if (v.arr[i]!=arr[i]) return 0;
	}

	return 1;
}

template<class T>
int MyVector<T>::indexOf(T value){
	for (int i=0;i<size;++i){
		if (arr[i]==value) return i;
	}
	return -1;
}

template<class T>
int MyVector<T>::lastIndexOf(T value){
	for (int i=size-1;i>=0;--i){
		if (arr[i]==value) return i;
	}

	return -1;
}

template<class T>
void MyVector<T>::insert(T value, int index){
	if (index<0 || index>size){
		cout << "MyVector<T>::insert(T,int): index is out of range.\n";
		exit(0);
	}
	T *tmp=new T[size+1];
	for (int i=0;i<index;++i){
		tmp[i]=arr[i];
	}
	tmp[index]=value;
	for (int i=index;i<size;++i){
		tmp[i+1]=arr[i];
	}
	swap(arr,tmp);

	delete[] tmp;	
	size++;
}

template<class T>
void MyVector<T>::remove(T value){
	int count=0;
	for (int i=0;i<size;++i){
		if (arr[i]==value) ++count;
		else arr[i-count]=arr[i];
	}
	if (!count) return;
	size-=count;
	T *tmp=new T[size];
	for (int i=0;i<size;++i){
		tmp[i]=arr[i];
	}
	swap(tmp,arr);
	delete[] tmp;
}

template<class T>
void MyVector<T>::removeAt(int index){
	if (index<0 || index>=size) return;
	T *tmp=new T[size-1];
	for (int i=0;i<index;++i) tmp[i]=arr[i];
	for (int i=index;i<size-1;++i) tmp[i]=arr[i+1];

	swap(tmp,arr);
	delete[] tmp;
	size--;
}

template<class T>
void MyVector<T>::reverse(){
	for (int i=0;i<size/2;++i){
		swap(arr[i],arr[size-i-1]);
	}
}

template<class T>
string MyVector<T>::toString(){
	string ans="";
	if (!size) return ans;
	for (int i=0;i<size-1;++i) ans+=to_string(arr[i]) + ' ';
	return ans+to_string(arr[size-1]);
}

template<class T>
void MyVector<T>::sortAsc(){
	sort(arr,arr+size);
}

template<class T>
void MyVector<T>::sortDest(){
	sortAsc();
	reverse();
}

//Implemtation of Fraction
int Fraction::GCD(int a, int b){
	if (!a) return 1;
	while (b){
		int t=b;
		b=a%b;
		a=t;
	}
	return a;
}

void Fraction::normalize(){
	int gcd=GCD(num,denom);
	num/=gcd;
	denom/=gcd;
	if (num*denom<0){
		num=-abs(num);
		denom=abs(denom);
	}
}

Fraction::Fraction(int n=0, int d=1){
	num=n;
	denom=d;
	normalize();
}

Fraction::Fraction(const Fraction &other){
	num=other.num;
	denom=other.denom;
}

const Fraction& Fraction::operator=(const Fraction &other){
	num=other.num;
	denom=other.denom;
	return *this;
}

const Fraction& Fraction::operator=(const int &val){
	num=val;
	denom=1;
	return *this;
}

bool Fraction::operator==(const Fraction &other){
	return (num==other.num && denom==other.denom);
}

bool Fraction::operator!=(const Fraction &other){
	return !operator==(other);
}

bool Fraction::operator<(const Fraction &other){
	return (num*other.denom < other.num*denom);
}

bool Fraction::operator>(const Fraction &other){
	return (num*other.denom > other.num*denom);
}

string Fraction::toString(){
	return (to_string(num)+'/'+to_string(denom));
}

string to_string(Fraction f){
	return f.toString();
}

ostream& operator<<(ostream &out, const Fraction &f){
	out << f.num << "/" << f.denom;
	return out;
}

int main() {
	MyVector<int> v1;
	MyVector<Fraction> v2(2);
	int a[5] = { 4,3,1,7,3 };
	MyVector<int> v3(a, 5);
	MyVector<Fraction> v4(v2);

	//constructor
	cout << "\nConstructor:\n";
	cout << "v1: " << v1.toString() << "\n";
	cout << "v2: " << v2.toString() << "\n";
	cout << "v3: " << v3.toString() << "\n";
	cout << "v4: " << v4.toString() << "\n";
	

	//getSize()
	cout << "\ngetSize():\n";
	cout << "v1: " << v1.getSize() << "\n";
	cout << "v2: " << v2.getSize() << "\n";
	cout << "v3: " << v3.getSize() << "\n";
	cout << "v4: " << v4.getSize() << "\n";

	//getItem()
	cout << "\ngetItem():\n";
	// cout << "v1: " << v1.getItem(0) << "\n";		//out or range
	cout << "v2: " << v2.getItem(1) << "\n";
	cout << "v3: " << v3.getItem(4) << "\n";
	cout << "v4: " << v4.getItem(0) << "\n";

	//setItem()
	cout << "\nsetItem():\n";
	// v1.setItem(1,1);		// out of range
	v3.setItem(6,2);
	Fraction f(1,-2);
	v4.setItem(f,1);
	cout << "v3: " << v3.toString() << "\n";
	cout << "v4: " << v4.toString() << "\n";

	//add()
	cout << "\nadd():\n";
	v1.add(2);
	v2.add(Fraction(1,5));
	cout << "v1: " << v1.toString() << "\n";
	cout << "v2: " << v2.toString() << "\n";

	//addRange()
	cout << "\naddRange():\n";
	v1.addRange(a,5);
	cout << "v1: " << v1.toString() << "\n";

	//clear();
	cout << "\nclear():\n";
	cout << "v3 (before): " << v3.toString() << "\n";
	v3.clear();
	cout << "v3 (after): " << v3.toString() << "\n";

	//contains():
	cout << "\ncontains():\n";
	cout << "v3.contains(): " << v3.contains(1) << "\n";
	cout << "v1: " << v1.toString() << "\n";
	cout << "v1.contains(2): " << v1.contains(2) << "\n";
	cout << "v1.contains(10): " << v1.contains(10) << "\n";
	cout << "v2: " << v2.toString() << "\n";
	cout << "v2.contains(Fraction(2,10): " << v2.contains(Fraction(2,10)) << "\n";

	//toArray():
	cout << "\ntoArray():\n";
	int aInt[6], nInt, nFraction;
	v1.toArray(aInt,nInt);
	cout << "aInt: ";
	for (int i=0;i<nInt;++i) cout << aInt[i] << " ";
	cout << "\n";
	Fraction aFraction[3];
	v2.toArray(aFraction,nFraction);	
	cout << "aFraction: ";
	for (int i=0;i<nFraction;++i) cout << aFraction[i] << " ";
	cout << "\n";

	//equals();
	cout << "\nequals():\n";
	cout << "v1==v3: " << v1.equals(v3) << "\n";
	v1.clear();
	cout << "v1==v3 (after v1.clear()): " << v1.equals(v3) << "\n";
	MyVector<Fraction> v5(v2);
	cout << "v2==v5: " << v2.equals(v5) << "\n";

	//indexOf()
	cout << "\nindexOf():\n";
	MyVector<int> v6(a,5);
	cout << "v6: " << v6.toString() << "\n";
	cout << "v6.indexOf(7): "<< v6.indexOf(7) << "\n";
	cout << "v6.indexOf(3): " << v6.indexOf(3) << "\n";
	cout << "v6.indexOf(8): " << v6.indexOf(8) << "\n";
	cout << "v2: " << v2.toString() << "\n";
	cout << "v2.indexOf(Fraction(0,1)): " << v2.indexOf(Fraction(0,1)) << "\n";
	cout << "v2.indexOf(Fraction(2,3)): " << v2.indexOf(Fraction(2,3)) << "\n";

	//lastIndexOf()
	cout << "\nlastIndexOf():\n";
	cout << "v6: " << v6.toString() << "\n";
	cout << "v6.lastIndexOf(3): " << v6.lastIndexOf(3) << "\n";
	cout << "v6.lastIndexOf(8): " << v6.lastIndexOf(8) << "\n";
	cout << "v2: " << v2.toString() << "\n";
	cout << "v2.lastIndexOf(Fraction(0,1)): " << v2.lastIndexOf(Fraction(0,1)) << "\n";
	cout << "v2.lastIndexOf(Fraction(2,3)): " << v2.lastIndexOf(Fraction(2,3)) << "\n";

	//insert()
	cout << "\ninsert():\n";
	cout << "v6 (before): " << v6.toString() << "\n";
	v6.insert(2,3);
	cout << "v6 (after v6.insert(2,3)): " << v6.toString() << "\n";
	// v6.insert(1,12); //out of range
	cout << "v2 (before): " << v2.toString() << "\n";
	v2.insert(Fraction(2,3),0);
	cout << "v2 (after v2.insert(Fraction(2,3),0)): " << v2.toString() << "\n";
	// v2.insert(Fraction(3,2),-1); //out of range

	//remove()
	cout << "\nremove():\n";
	cout << "v6 (before): " <<  v6.toString() << "\n";
	v6.remove(3);
	cout << "v6 (after v6.remove(3)): " << v6.toString() << "\n";
	v6.remove(10);
	cout << "v6 (after v6.remove(10)): " << v6.toString() << "\n";
	cout << "v2 (before): " << v2.toString() << "\n";
	v2.remove(Fraction(0,1));
	cout << "v2 (after v2.remove(Fraction(0,1)): " << v2.toString() << "\n";

	//removeAt()
	cout << "\nremove():\n";
	cout << "v6 (before): " <<  v6.toString() << "\n";
	v6.removeAt(2);
	cout << "v6 (after v6.removeAt(2)): " << v6.toString() << "\n";
	v6.removeAt(10);
	cout << "v6 (after v6.removeAt(10)): " << v6.toString() << "\n";
	cout << "v4 (before): " << v4.toString() << "\n";
	v4.removeAt(1);
	cout << "v4 (after v4.removeAt(1): " << v4.toString() << "\n";
	v4.removeAt(5);
	cout << "v4 (after v4.removeAt(5)): " << v4.toString() << "\n";

	//reverse();
	cout << "\nreverse():\n";
	cout << "v2 (before): " << v2.toString() << "\n";
	v2.reverse();
	cout << "v2.reverse(): " << v2.toString() << "\n";

	cout << "v4 (before): " << v4.toString() << "\n";
	v4.reverse();
	cout << "v4.reverse(): " << v4.toString() << "\n";

	cout << "v5 (before): " << v5.toString() << "\n";
	v5.reverse();
	cout << "v5.reverse(): " << v5.toString() << "\n";

	cout << "v6 (before): " << v6.toString() << "\n";
	v6.reverse();
	cout << "v6.reverse(): " << v6.toString() << "\n";

	//sortAsc()
	cout << "\nsortAsc():\n";
	cout << "v2 (before): " << v2.toString() << "\n";
	v2.sortAsc();
	cout << "v2.sortAsc(): " << v2.toString() << "\n";

	cout << "v4 (before): " << v4.toString() << "\n";
	v4.sortAsc();
	cout << "v4.sortAsc(): " << v4.toString() << "\n";

	cout << "v5 (before): " << v5.toString() << "\n";
	v5.sortAsc();
	cout << "v5.sortAsc(): " << v5.toString() << "\n";

	cout << "v6 (before): " << v6.toString() << "\n";
	v6.sortAsc();
	cout << "v6.sortAsc(): " << v6.toString() << "\n";

	//sortDest()
	cout << "\nsortDest():\n";
	cout << "v2 (before): " << v2.toString() << "\n";
	v2.sortDest();
	cout << "v2.sortDest(): " << v2.toString() << "\n";

	cout << "v4 (before): " << v4.toString() << "\n";
	v4.sortDest();
	cout << "v4.sortDest(): " << v4.toString() << "\n";

	cout << "v5 (before): " << v5.toString() << "\n";
	v5.sortDest();
	cout << "v5.sortDest(): " << v5.toString() << "\n";

	cout << "v6 (before): " << v6.toString() << "\n";
	v6.sortDest();
	cout << "v6.sortDest(): " << v6.toString() << "\n";

	return 0;
}