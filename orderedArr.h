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

public:

	OrderedArray();						  //default constructor
	OrderedArray(int size, int grow=1); //constructor with custom growSize
	void push(const T& newElement);       //insert an element in to an array 
	int length();						  //return the length of the array	
	void clear();						  //clear the array
	void print();						  //print the array
	~OrderedArray(); //destructor
};
template<class T>
OrderedArray<T>::OrderedArray()
{
	array = nullptr;
	lengthOfArr = 0;
	maxSize = 0;
	growSize = 0;
}

template<class T>
OrderedArray<T>::OrderedArray(int size, int grow)
{
	if (size <= 0)
		throw invalid_argument("The size of the array must be greater than 0");
	
	if (grow <= 0)
		throw logic_error("The grow size of the array must be greater than 0");
	

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
	}
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
	for (int i = 0; i < lengthOfArr; i++)
	{
		cout << array[i] <<" ";
	}
}