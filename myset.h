#pragma once
#include<iostream>
#include "orderedArr.h"
#include "lead.h"

using namespace std;

template <class T>
class MySet : public OrderedArray<T> {
public:
	// Default constructor
	//MySet() : OrderedArray<T>() {};
	// 
	// Constructor with custom grow size inherited from parent class
	MySet(int grow_size = 10) : OrderedArray<T>(grow_size) {};

	// Override the push function to insert an element into the set
	void push(const T& newElement) {
		if (OrderedArray<T>::search(newElement) < 0) {
			OrderedArray<T>::push(newElement);
		}
	}
	
	// Comparison function to compare two Lead objects based on their phone numbers
	static bool compareLeads(const Lead& lead1, const Lead& lead2) {
		return lead1.phoneAsId < lead2.phoneAsId;
	}
	
	//overide the push function to insert a lead into the set of leads 
	void pushLead( Lead& newElement) {
		if (OrderedArray<T>::search(newElement.getPhoneAsId(), compareLeads) < 0) {
			OrderedArray<T>::push(newElement.getPhoneAsId());
		}
	}
	//print the set
	void print();

	//get the length of the set
	int length() {
		return OrderedArray<T>::length();
	}

	//get the element at the given index
	T getElement(int index) {
		return OrderedArray<T>::getElement(index);
	}

	//operator | overloading
	MySet<T> operator | ( MySet<T>& other); 

	//operator & overloading
	MySet<T> operator & (MySet<T>& other);

	//Destructor
	~MySet() { 
		
			cout << "The set has been deleted!" << endl;
			cout << "Myset destrucor" << endl;
		
	};

};
template<class T>
void MySet<T>::print()
{
	if (OrderedArray<T>::length() == 0)
		cout << "The Set is Empty!: ";
	cout << "[";
	for (int i = 0; i < OrderedArray<T>::length(); i++)
	{
		cout << OrderedArray<T>::getElement(i)<<", ";
		
	}
	cout << "]" << endl;;
}

template<class T>
MySet<T> MySet<T>:: operator | ( MySet<T>& other) {
	MySet<T> temp;
	//copy the elements of the first set to the temp set
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
		temp.push(OrderedArray<T>::getElement(i));
	}
	//copy the elements of the second set to the temp set
	for (int i = 0; i < other.length(); i++) {
		temp.push(other.getElement(i));
	}
	return temp;
}

template<class T>
MySet<T> MySet<T>:: operator & (MySet<T>& otherSet) {
	MySet<T> tempSet;
	
	for (int i = 0; i < length(); i++) {
		const T& element = getElement(i);

		//  if the element exists in the other set push it to the temp set
		for (int j = 0; j < otherSet.length(); j++) {
			if (element == otherSet.getElement(j)) {
				tempSet.push(element);
			}
		
		}
	}

	/*for (int i = 0; i < OrderedArray<T>::length(); i++) {
		T element = OrderedArray<T>::getElement(i);
		if (otherSet.search(element) >= 0) {
			tempSet.push(element);
		}
	}*/

	return tempSet;
}




