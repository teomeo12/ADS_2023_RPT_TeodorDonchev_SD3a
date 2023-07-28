#pragma once
#include<iostream>
#include "orderedArr.h"
#include "lead.h"
#include <fstream>
#include <sstream>
#include <string>

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
	
	//overide the push function to insert a lead into the set of leads 
	void pushLead(const Lead& newElement) {
		OrderedArray<T>::pushLead(newElement);
	}
	//print the set
	void print();

	//overide the print function to print the set of leads
	void printLead();

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

	//oeprator | overloading for the set of leads
	MySet<Lead> operator | (Lead& other);

	//Destructor
	~MySet() { 
			//cout << "The set has been deleted!" << endl;
			//cout << "Myset destrucor" << endl;
	};
};
template<class T>
void MySet<T>::print()
{
	if (OrderedArray<T>::length() == 0)
		cout << "The Set is Empty!: ";
	else
		cout << "[";
		bool firstElement = true; //check if the element is the first element
		for (int i = 0; i < OrderedArray<T>::length(); i++)
		{
			if (firstElement) {
				cout << OrderedArray<T>::getElement(i);
				firstElement = false;
			}
			else
				cout <<", "<< OrderedArray<T>::getElement(i);
		
		}
		cout << "]" << endl;;
}
template<class T>
void MySet<T>::printLead()
{
	if (OrderedArray<T>::length() == 0)
		cout << "The Set is Empty!: ";
	
	for (int i = 0; i < OrderedArray<T>::length(); i++)
	{
		cout << OrderedArray<T>::getElement(i).toString() << endl;;

	}
}

template<class T>
MySet<Lead> MySet<T>:: operator | (Lead& other) {
	MySet<Lead> temp;
	//copy the elements of the first set to the temp set
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
		temp.pushLead(OrderedArray<T>::getElement(i));
	}
	//copy the elements of the second set to the temp set
	for (int i = 0; i < 20; i++) {
		temp.pushLead(other);
	}
	return temp;
}
template<class T>
MySet<T> operator-(const MySet<T>& otherSet) {
	MySet<T> differenceSet(*this); // Use the copy constructor to create a copy

	// Remove elements that also exist in the other set
	for (int i = 0; i < otherSet.length(); i++) {
		const T& element = otherSet.getElement(i);
		differenceSet.remove(element);
	}

	return differenceSet;
}

template<class T>
MySet<T> MySet<T>:: operator | ( MySet<T>& otherSet) {
	MySet<T> temp;
	//copy the elements of the first set to the temp set
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
	
		temp.push(OrderedArray<T>::getElement(i));
	}
	//copy the elements of the second set to the temp set
	for (int i = 0; i < otherSet.length(); i++) {
		temp.push(otherSet.getElement(i));
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

