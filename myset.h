#pragma once
#include<iostream>
#include "lead.h"
#include <fstream>
#include <sstream>
#include <string>

template <class T>
class MySet : public OrderedArray<T> {
public:
	
	MySet(int grow_size = 10) : OrderedArray<T>(grow_size) {};   // constructor with custom grow size inherited from parent class
	void push(const T& newElement);								 // override the push function to insert an element into the set
	void print();												 // print the set
	void printLead();										     // overide the print function to print the set of leads
	int length();												 // return the length of the set
	T getElement(int index);									 // get the element at the given index
	MySet<T> operator | ( MySet<T>& other);						 // operator | overloading
	MySet<T> operator & (MySet<T>& other);						 // operator & overloading
	MySet<T> operator - (MySet<T>& other);						 // operator - overloading
	~MySet()											         // destructor
	{ 
			//cout << "The set has been deleted!" << endl;
			//cout << "Myset destrucor" << endl;
	};
};

template<class T>
void MySet<T>::push(const T& newElement) {
	// check if the element is already in the set and if not add it to the set
	if (OrderedArray<T>::search(newElement) == -1) 
	{
		OrderedArray<T>::push(newElement);
	}
	else 
	{
		//cout<<"The element"<< newElement<<" is already in the set!" << endl;
	}
}

template<class T>
void MySet<T>::print()
{
	if (OrderedArray<T>::length() == 0) {
		cout << "The Set is Empty! "<<endl;
	}	
	else 
	{
		cout << "Printing the Set: ";
		cout << "[";
		bool firstElement = true; //check if the element is the first element
		for (int i = 0; i < OrderedArray<T>::length(); i++)
		{
			if (firstElement) {
				cout << OrderedArray<T>::getElement(i);
				firstElement = false;
			}
			else
				cout << ", " << OrderedArray<T>::getElement(i);

		}
		cout << "]" << endl;
	}
		
}

template<class T>
void MySet<T>::printLead()
{
	if (OrderedArray<T>::length() == 0)
	{
		cout << "The Set is Empty! " << endl;

	}
		
	for (int i = 0; i < OrderedArray<T>::length(); i++)
	{
		cout << OrderedArray<T>::getElement(i).toString() << endl;;

	}
}

template<class T>
int MySet<T>::length() {
	return OrderedArray<T>::length();
}

template<class T>
T MySet<T>::getElement(int index) {
	return OrderedArray<T>::getElement(index);
}

template<class T>
MySet<T> MySet<T>:: operator | ( MySet<T>& otherSet) {
	MySet<T> temp;
	// copy the elements of the first set to the temp set
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
	
		temp.push(OrderedArray<T>::getElement(i));
	}
	// copy the elements of the second set to the temp set
	for (int i = 0; i < otherSet.length(); i++) {
		temp.push(otherSet.getElement(i));
	}
	return temp;
}

template<class T>
MySet<T> MySet<T>:: operator & (MySet<T>& otherSet) {
	MySet<T> tempSet;
	
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
		T element = OrderedArray<T>::getElement(i);
		if (otherSet.search(element) >= 0)
		{
			tempSet.push(element);
		}
	}

	return tempSet;
}

template<class T>
MySet<T> MySet<T>:: operator - (MySet<T>& otherSet) {
	MySet<T> tempSet;

	// copy the elements of the first set to the temp set
	for (int i = 0; i < OrderedArray<T>::length(); i++) {
		tempSet.push(OrderedArray<T>::getElement(i));
	}

	// removing the elements of the second set from the temp set
	for (int i = 0; i < otherSet.length(); i++) {
		T element = otherSet.getElement(i);  // get the element of the second set
		int index = tempSet.search(element); // search for the element in the temp set
		while (index != -1) {
			tempSet.remove(index);			 // remove the element from the temp set
			index = tempSet.search(element); // search for the element in the temp set
		}		
	}
	return tempSet;
}

// read the return leads from the csv file
MySet<Lead> readLeadsFromCSV(const string& filename) {
	MySet<Lead> leads;
	ifstream inputfile;
	if (inputfile.fail())
	{
		cout << "Error opening file" << endl;
		exit(1);
	}
	inputfile.open(filename);
	string line;
	// read the file line by line and create a lead from extracted data
	while (getline(inputfile, line)) {
		string leadStr;
		string phoneStr;
		stringstream inputString(line);
		
		// get the lead name from the line
		size_t lastCommaPos = line.rfind(",");
		leadStr = line.substr(0, lastCommaPos);
        //cout << "lead: " << leadStr << endl;

		// get the phone number and convert it to long
		size_t delimeter = line.find_last_of("(");
		string prefixAndNumber = line.substr(delimeter);
		phoneStr = prefixAndNumber.substr(1, 3) + prefixAndNumber.substr(5);
		//cout << "phoneNumber: " << phoneStr << endl;
		phoneStr.erase(3, 2);
		long phoneNumber = stol(phoneStr);

		// create a new lead and push it to the set
		Lead newLead(leadStr, phoneNumber);
		leads.push(newLead);
		//cout << "L: " << lead << " P: " << phoneNumber << endl;
	}

	inputfile.close();
	return leads;
}

// write the common leads to the csv file
void writeLeadsToCSV(MySet<Lead>& leadSet, const string& leadsFile) {

	ofstream outputfile;
	outputfile.open(leadsFile);
	if (outputfile.is_open())
	{
		// rite each lead to the csv file
		for (int i = 0; i < leadSet.length(); i++) {
			Lead lead = leadSet.getElement(i);
			outputfile << "ID " << lead.phoneAsId << ", " << "Lead " << lead.leadDetails << endl;
		}

		outputfile.close();
		cout << "->> Leads successfully written to ->> " << leadsFile << endl;
	}
	else 
	{
		cout << "Error: Unable to open " << leadsFile << " for writing." << endl;
	}
}