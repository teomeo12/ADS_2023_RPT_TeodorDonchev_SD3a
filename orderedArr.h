#pragma once
#include<iostream>
#include "lead.h"

template<class T>
class OrderedArray
{
private:

	T* array;									   // pointer to the array
	int lengthOfArr;							   // length of the array
	int maxSize;								   // capacity of the array
	int growSize;								   // integer for the amount the array will grow by

public:

	OrderedArray();								   // default constructor
	OrderedArray(int growSize);					   // constructor with custom growSize
	void push(const T& newElement);				   // insert an element in to an array 
	int length();								   // return the length of the array	
	int capacity();								   // return the capacity of the array
	int getGrowSize();							   // return the grow size of the array	
	T getElement(int index);					   // return the element at the given 
	bool remove(int index);						   // remove an element at the given index
	int search(const T& searchKey);				   // search for an element in the array
	void clear();								   // clear the array
	void print();								   // print the array
	T sumOfTwoElements();		                   // sum of the first and second elements
	bool operator==(const OrderedArray<T>& other); // function for the overloaded "==" operator
	bool operator!=(const OrderedArray<T>& other); // function for the overloaded "!=" operator
	bool operator>(const OrderedArray<T>& other);  // function for the overloaded ">" operator
	bool operator<(const OrderedArray<T>& other);  // function for the overloaded "<" operator
	bool operator>=(const OrderedArray<T>& other); // function for the overloaded ">=" operator
	bool operator<=(const OrderedArray<T>& other); // function for the overloaded "<=" operator
	~OrderedArray();							   // destructor
};
template<class T>
OrderedArray<T>::OrderedArray()
{
	array = new T[growSize=1];
	lengthOfArr = 0;
	maxSize = 0;
}

template<class T>
OrderedArray<T>::OrderedArray(int grow)
{
	if (grow <= 0)
		throw invalid_argument("The grow size of the array must be greater than 0");
	
	array = new T[grow];
	lengthOfArr = 0;
	maxSize = 0;
	growSize = grow;
}

template<class T>
OrderedArray<T>::~OrderedArray()
{
		delete[] array;
		array = nullptr;
		// control statement
		// cout<< "The array has been deleted!" << endl;
		// cout<<"OrderdArray destructor"<<endl;
}

template<class T>
int OrderedArray<T>::capacity()
{
	return maxSize;
}

// inserts a new element into the array in order.
// the new element is copied into the array.
template<class T>
void OrderedArray<T>:: push(const T& newElement) {
	
	// copy of the new element
	T copyOfnewElement = newElement;
	// check if the array is full
	if (lengthOfArr >= maxSize)
	{
		// create a new array with the new size
		maxSize += growSize;
		T* newArr = new T[maxSize];

		// copy the elements from the old array 
		for (int i = 0; i < lengthOfArr ; i++)
		{
			newArr[i] = array[i];
		}

		// delete the old array and pointer to the new array
		delete[] array;
		array = newArr;
		newArr = nullptr;
	}

	// index to insert the new element
	short index = 0;
	for (int i = 0; i < lengthOfArr; i++)
	{
		if (copyOfnewElement > array[i])
		{
			index++;
		}
	}
	// shift the elements to the right
	for (int i = lengthOfArr; i >  index; i--)
	{
		array[i] = array[ i - 1];
	}

	// insert the new element
	array[index] = copyOfnewElement;
	lengthOfArr++;
}

template<class T>
int OrderedArray<T>::length()
{
	return lengthOfArr;
}

template<class T>
int OrderedArray<T>::getGrowSize() {
	return growSize;
}

template<class T>
T OrderedArray<T>::getElement (int index)
{
	if (index < 0 || index >= lengthOfArr)
		throw out_of_range("The index is out of range");
	return array[index];
}

// searches for an element in the array using binary search
// returns the index of the element if found, or -1 if not found
template<class T>
int OrderedArray<T>::search(const T& searchKey) {
	//linear search
	/*for (int i = 0; i < lengthOfArr; i++) {
		if (array[i] == searchKey) {
			return i;
		}
	}
	return -1;*/

	//binary search
	int pStart = 0;
	int pEnd = lengthOfArr - 1;
	int pMid = 0;
	while (pStart <= pEnd) {
		pMid = (pStart + pEnd) / 2;
		if (array[pMid] == searchKey) {
			return pMid;
		}
		else if (array[pMid] > searchKey) {
			pEnd = pMid - 1;
		}
		else {
			pStart = pMid + 1;
		}
	}
	return -1;
}

// returns true if removal is successful, false if the index is out of range
// decreases the length of the array by 1
template<class T>
bool OrderedArray<T>::remove(int index) {
	if (index < 0 || index > lengthOfArr) 
	{
		throw out_of_range("The index is out of range");
		return false;
	}
	for (int i = index + 1; i < lengthOfArr; i++) {
		array[i - 1] = array[i];
	}
	lengthOfArr --;
	return true;
}

template<class T>
void OrderedArray<T>::clear()
{
	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
	// reset the variables
	lengthOfArr = 0;
	maxSize = 0;
	growSize = 1;
}

template<class T>
void OrderedArray<T>::print()
{
	if (lengthOfArr == 0) 
	{
		cout << "The Array is Empty!";
	}
	else 
	{
		cout << "Printing the array: ";
		cout << "[";
		bool firstElement = true;
		for (int i = 0; i < lengthOfArr; i++)
		{
			if (firstElement)
			{
				cout << array[i];
				firstElement = false;
			}
			else
				cout << ", " << array[i];
		}
		cout << "]" << endl;
	}	
}

// returnt the sum of the first and second element in the array
template<class T>
 T OrderedArray<T>::sumOfTwoElements()
{
	 T sum = 0;
	return sum=array[0]+array[1];
}

 template<class T>
 bool OrderedArray<T>::operator==(const OrderedArray<T>& other)
 {
	 if (lengthOfArr != other.lengthOfArr) 
	 {
		 return false;
	 }
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] != other.array[i])
			 return false;
	 }
	 return true;
 }

 template<class T>
 bool OrderedArray<T>::operator!=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr != other.lengthOfArr) 
	 {
		 return true;
	 }
	 else 
	 {
		 for (int i = 0; i < lengthOfArr; i++)
		 {
			 if (array[i] != other.array[i])
				 return true;
		 }
	 }
	
	 return false;
 }

 template<class T>
 bool OrderedArray<T>::operator>(const OrderedArray<T>& other)
 {
	 if (lengthOfArr > other.lengthOfArr) 
	 {
		 return true;
	 }
	 else if (lengthOfArr < other.lengthOfArr)
	 {
		 return false;
	 }
	 else 
	 {
		 for (int i = 0; i < lengthOfArr; i++)
		 {
			 if (array[i] > other.array[i])
				 return true;
			 else if (array[i] < other.array[i])
				 return false;
		 }
		 return false;
	 }
 }

 template<class T>
 bool OrderedArray<T>::operator>=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr > other.lengthOfArr) 
	 {
		 return true;
	 }
	 else if (lengthOfArr < other.lengthOfArr) 
	 {
		 return false;
	 }
	 else
	 {
		 for (int i = 0; i < lengthOfArr; i++)
		 {
			 if (array[i] > other.array[i])
				 return true;
			 else if (array[i] < other.array[i])
				 return false;
		 }
		 return true;
	 }
 }

 template<class T>
 bool OrderedArray<T>::operator<(const OrderedArray<T>& other)
 {
	 if (lengthOfArr < other.lengthOfArr) 
	 {
		 return true;
	 }
	 else if (lengthOfArr > other.lengthOfArr)
	 {
		 return false;
	 }
	 else 
	 {
		 for (int i = 0; i < lengthOfArr; i++)
		 {
			 if (array[i] < other.array[i])
				 return true;
			 else if (array[i]>other.array[i]) {
				 return false;
			 }
		 }
		 // The arrays are equal
		 return false;
	 } 
 }

 template<class T>
 bool OrderedArray<T>::operator<=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr < other.lengthOfArr) 
	 {
		 return true;
	 }
	 else if (lengthOfArr > other.lengthOfArr) 
	 {
		 return false;
	 }
	 else
	 {
		 for (int i = 0; i < lengthOfArr; i++)
		 {
			 if (array[i] < other.array[i])
				 return true;
			 else if (array[i] > other.array[i])
				 return false;
		 }
		 // The arrays are equal
		 return true;
	 }
 }
 

 





