 #pragma once
#include<iostream>
using namespace std;

template<class T>
class OrderedArray
{
private:

	T* array;		 //pointer to the array
	int lengthOfArr; //length of the array
	int maxSize;	 //capacity of the array
	int growSize;	 //integer for the amount the array will grow by
	T sum;			 //sum of two elements

public:

	OrderedArray();						  //default constructor
	OrderedArray(int size, int grow=1); //constructor with custom growSize
	void push(const T& newElement);       //insert an element in to an array 
	int length();						  //return the length of the array	
	int capacity();						  //return the capacity of the array
	int getGrowSize();					  //return the grow size of the array	
	T getElement(int index);			  //return the element at the given index
	void clear();						  //clear the array
	void print();						  //print the array
	T& sumOfTwoElements();		        //sum of the first and second elements
	bool operator==(const OrderedArray<T>& other); // function for the overloaded "==" operator
	bool operator!=(const OrderedArray<T>& other); // function for the overloaded "!=" operator
	bool operator>(const OrderedArray<T>& other);  // function for the overloaded ">" operator
	bool operator<(const OrderedArray<T>& other);  // function for the overloaded "<" operator
	bool operator>=(const OrderedArray<T>& other); // function for the overloaded ">=" operator
	bool operator<=(const OrderedArray<T>& other); // function for the overloaded "<=" operator

	~OrderedArray(); //destructor
};
template<class T>
OrderedArray<T>::OrderedArray()
{
	array = nullptr;
	lengthOfArr = 0;
	maxSize = 0;
	growSize = 1;
}

template<class T>
OrderedArray<T>::OrderedArray(int size, int grow)
{
	if (size <= 0)
		throw invalid_argument("The size of the array must be greater than 0");
	
	if (grow <= 0)
		throw invalid_argument("The grow size of the array must be greater than 0");
	

	array = new T[size];
	lengthOfArr = 0;
	maxSize = size;
	growSize = grow;
}

template<class T>
OrderedArray<T>::~OrderedArray()
{
	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
		cout<< "The array has been deleted" << endl;
	}
}

template<class T>
int OrderedArray<T>::capacity()
{
	return maxSize;
}



template<class T>
void OrderedArray<T>:: push(const T& newElement) {

	//if the array is full
	if (lengthOfArr >= maxSize)
	{
		//create a new array with the new size
		maxSize += growSize;
		T* newArr = new T[maxSize];

		//copy the elements from the old array 
		for (int i = 0; i < lengthOfArr; i++)
		{
			newArr[i] = array[i];
		}

		//delete the old array and pointer to the new array
		delete[] array;
		array = newArr;

	}

	//index to insert the new element
	int index = 0;
	for (int i = 0; i < lengthOfArr; i++)
	{
		if (newElement > array[i])
		{
			index++;
		}
	}
	//shift the elements to the right
	for (int i = 0; i < lengthOfArr - index; i++)
	{
		array[lengthOfArr - i] = array[lengthOfArr - i - 1];
	}

	//insert the new element
	array[index] = newElement;
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
T OrderedArray<T>::getElement(int index)
{
	if (index < 0 || index >= lengthOfArr)
		throw out_of_range("The index is out of range");
	return array[index];
}

template<class T>
void OrderedArray<T>::clear()
{
	
	if (array != nullptr)
	{
		delete[] array;
		array = nullptr;
	}
	lengthOfArr = 0;
	maxSize = 0;
	growSize = 1;
}

template<class T>
void OrderedArray<T>::print()
{
	cout << "[";
	for (int i = 0; i < lengthOfArr; i++)
	{
		cout << array[i] << ", ";
	}
	cout << "]" << endl;;
}

template<class T>
 T& OrderedArray<T>::sumOfTwoElements()
{
	return sum=array[0]+array[1];
}

 //overload == operator function
 template<class T>
 bool OrderedArray<T>::operator==(const OrderedArray<T>& other)
 {
	 if (lengthOfArr != other.lengthOfArr)
		 return false;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] != other.array[i])
			 return false;
	 }
	 return true;
 }

 //overload != operator function
 template<class T>
 bool OrderedArray<T>::operator!=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr != other.lengthOfArr)
		 return true;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] != other.array[i])
			 return true;
	 }
	 return false;
 }

 //overload > operator function
 template<class T>
 bool OrderedArray<T>::operator>(const OrderedArray<T>& other)
 {
	 if (lengthOfArr > other.lengthOfArr)
		 return true;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] > other.array[i])
			 return true;
	 }
	 return false;
 }

 //overload < operator function
 template<class T>
 bool OrderedArray<T>::operator<(const OrderedArray<T>& other)
 {
	 if (lengthOfArr < other.lengthOfArr)
		 return true;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] < other.array[i])
			 return true;
	 }
	 return false;
 }

 //overload >= operator function
 template<class T>
 bool OrderedArray<T>::operator>=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr >= other.lengthOfArr)
		 return true;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] >= other.array[i])
			 return true;
	 }
	 return false;
 }

 //overload <= operator function
 template<class T>
 bool OrderedArray<T>::operator<=(const OrderedArray<T>& other)
 {
	 if (lengthOfArr <= other.lengthOfArr)
		 return true;
	 for (int i = 0; i < lengthOfArr; i++)
	 {
		 if (array[i] <= other.array[i])
			 return true;
	 }
	 return false;
 }





