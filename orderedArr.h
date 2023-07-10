#pragma once
#include<iostream>
using namespace std;

template<class T>
class OrderedArray
{
private:

	T* array; //pointer to the array
	int lengthOfArr; //length of the array
	int maxSize; //capacity of the array
	int growSize; //integer for the amount the array will grow by
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
	//funcion to print the array
	void print()
	{
		for (int i = 0; i < lengthOfArr; i++)
		{
			cout << array[i] << " ";
		}
	}
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

};