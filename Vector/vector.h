#pragma once

#include <iostream>
using namespace std;

template <typename ElemT>
class Vector
{
private:
	int size;

public:
	ElemT* components;

	Vector(int inputsize) :
		components(new ElemT[inputsize]),
		size(inputsize)
	{}

	~Vector()
	{
		delete components;
	}

	Vector(const Vector&) = delete;
	Vector& operator = (const Vector&) = delete;

	Vector<ElemT> VecSwap(Vector& original, Vector& destination);

	Vector<ElemT> VecCopy(const Vector& original, Vector& destination);

	void VecPrint();
};

template <typename ElemT>
Vector<ElemT> Vector<ElemT> :: VecSwap(Vector<ElemT>& original, Vector<ElemT>&  destination)
{
	ElemT* temp = original.components;
	destination.components = original.components;
	original.components = temp;

	return destination;
}


template <typename ElemT>
Vector<ElemT> Vector<ElemT> :: VecCopy(const Vector& original, Vector& destination)
{
	destination.components = new ElemT[original.size * sizeof(ElemT)];

	while (*original.components != '\0')
	{
		(*destination.components)++ = (*original.components)++;
	}
}


template <typename ElemT>
void  Vector<ElemT> :: VecPrint()
{
	size_t i = 0;
	while (components[i] != '\0')
	{
		cout << components[i] << endl;
		i++;
	}
}
