#pragma once
#include <iostream>
#include <assert.h>
#define DEFAULT_CAPACITY 32;

template <typename T>
class DynamicArray
{
public:
	DynamicArray()
	{
		size = 0;
		capacity = DEFAULT_CAPACITY;
		arr = new T[capacity];
	}
	int GetSize()
	{
		return size;
	}

	// Get element at index i
	T Get(int pos)
	{
		assert(pos >= 0 && pos < size);
		return arr[pos];
	}

	void PushBack(T new_val)
	{
		// if size equals capacity, inscrease capacity by 2
		if (size == capacity)
			resize(2 * capacity);
		arr[size++] = new_val;
	}

	T PopBack()
	{
		assert(size != 0);
		T val = arr[size - 1];
		size--;
		// if size  = 1/4 *capacity, descrease capacity by 2
		if (size <= capacity / 4)
			resize(capacity / 2);
		return val;
	}

	// Insert element into index pos
	void Insert(int pos, T new_val)
	{
		assert(pos >= 0 && pos <= size); // if pos == size equivelant to PushBack
		if (size == capacity)
			resize(2 * capacity);
		size++;
		for (int i = size - 1; i > pos; i--)
			arr[i] = arr[i - 1];
		arr[pos] = new_val;
	}

	// Remove element at pos i
	void Remove(int pos)
	{
		assert(pos >= 0 && pos < size);
		size--;
		for (int i = pos; i < size; i++)
			arr[i] = arr[i + 1];
		if (size <= capacity / 4)
			resize(capacity / 2);
	}

	void Reverse()
	{
		for (int i = 0; i < size / 2; i++)
			std::swap(arr[i], arr[size - i - 1]);
	}

	void Print()
	{
		for (int i = 0; i < size; i++)
			std::cout << arr[i] << " ";
		std::cout << '\n';
	}

private:
	int size;
	int capacity;
	T *arr; // pointer to a dynamically-allocated array

	void resize(int new_capacity)
	{
		// Create newly_allocated array
		T *new_arr = new T[new_capacity];

		// Bring old values to new array
		for (int i = 0; i < size; i++)
			new_arr[i] = arr[i];

		// remove old array
		delete[] arr;

		// Replace with newly-allocated array
		arr = new_arr;
		capacity = new_capacity;
	}
};