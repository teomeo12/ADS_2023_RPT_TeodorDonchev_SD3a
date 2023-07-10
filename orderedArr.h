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
	//constructor with custom growSize
	OrderedArray(int size, int grow = 1)
	{
		array = new T[size];
		maxSize = size;
		growSize = grow;
		lengthOfArr = 0;
	}
	//default constructor
	OrderedArray()
	{
		array = new T[1];
		maxSize = 1;
		growSize = 1;
		lengthOfArr = 0;
	}
	//destructor
	~OrderedArray() {
		if (array != nullptr)
		{
			delete[] array;
			array = nullptr;
		}
	}
	//print the array
	void print()
	{
		for (int i = 0; i < lengthOfArr; i++)
		{
			cout << array[i] << " ";
		}
	}
	//clear the array
	void clear()
	{
		if (array != nullptr)
		{
			delete[] array;
			array = nullptr;
		}
		lengthOfArr = 0;
		maxSize = 1;
		growSize = 1;
		array = new T[1];
	}

	// get the number of elements in the array
	int length()
	{
		return lengthOfArr;
	}

	//insert an element in to an array
	void push(const T& newElement) {
	
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
};