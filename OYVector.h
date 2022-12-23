#pragma once
#include <iostream>
using namespace std;
template<class T>
class OYVector
{
private:
	typedef T* iterator;
	int size;
	int capacity;
	T* arr;
public:

	OYVector(int cap = 2);
	OYVector(iterator p, int n);
	OYVector(const OYVector<T>& n); 
	~OYVector();
	OYVector& operator=(const OYVector<T>& other);
	OYVector& operator=(const OYVector<T>&& other);
	T& operator[](int index);
	int push_back(T elem);
	T pop_back();
	void erase(iterator i);
	void erase(iterator it1, iterator it2);
	iterator begin();
	iterator end();
	int Size();
	T operator++();
	T operator+(int n);
	void clear();
	int Capacity();
	void insert(iterator& it, T e);
	bool operator==(const OYVector<T>& a);
	bool operator< (const OYVector<T>& a);
	int resize();
	bool empty();
	template<class C>
	friend ostream& operator << (ostream& out, OYVector<C> & other);

};

