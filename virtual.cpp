/*
Virtual Function is a function in base class, which is overrided in the derived class, and which tells the compiler to perform Late Binding on this function.

Virtual Keyword is used to make a member function of the base class Virtual.

We can call private function of derived class from the base class pointer with the help of virtual keyword. 

vptr is vpointer which points to the virtual function of that object.
vtable is table containing address of virtual functions of each class.

To accomplich late binding, Compiler creates VTABLEs, for each class with virtual function

If a function is declared as virtual in the base class, it will be virtual in all its derived classes.

Refer: http://shaharmike.com/cpp/vtable-part2/
*/
#include<iostream>

using namespace std;

class Base {
public:
	void show() {
		cout<<"Base Class\n";
	}
};

class BaseWithVirtual {
public:
	virtual void show() {
		cout<<"Base Class Virtual\n";
	}
};

class Derived: public Base {
public:
	void show() {
		cout<<"Derived Class\n";
	}
};

class DerivedFromVirtual: public BaseWithVirtual {
private:
	void show() {
		cout<<"Derived Class with Base having virtual keyword for function overriden\n";
	}
};

int main(){

	Base *b;
	BaseWithVirtual *bVirtual;
	Derived d;
	DerivedFromVirtual dVirtual;

	b = &d;
	bVirtual = &dVirtual;

	b->show();
	bVirtual ->show();
	cout<<"---------------\n";

	return 0;

}

/*
OUTPUT:

Base Class
Derived Class with Base having virtual keyword for function overriden

*/