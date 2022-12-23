#include "OYVector.h"
template<class T>
OYVector<T>::OYVector(int cap) {
	size = 0;
	capacity = cap;
	arr = new T [capacity];
}

template<class T>
OYVector<T>::~OYVector() {
	delete[] arr;
}
template<class T>
int OYVector<T>::Size() {
	return size;
}
template<class T>
int OYVector<T>::Capacity() {
	return capacity;
}

template<class T>
OYVector<T>::OYVector(T*p,int n) {
	
	for (size_t i = 0; i < n; i++)
	{
		p = new int(i);
		arr[i] = p;
	}
	delete p;
}
template<class T>
OYVector<T>::OYVector(const OYVector<T>& n) {
	if (this != &n) {
		size = n->size;
		capacity = n->capacity;
		arr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = n->arr[i];
		}
	}
}

template<class T>
OYVector<T>& OYVector<T>:: operator=(const OYVector<T>& other) {
	if (this != &other) {
		delete[] arr;
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (int i = 0; i < other.size; i++) {
			arr[i] = other.arr[i];
		}
	}
	return *this;
}
template<class T>
OYVector<T>& OYVector<T>:: operator=(const OYVector<T>&& other) {
	if (this != &other) {
		delete[] arr;
		size = other.size;
		capacity = other.capacity;
		arr = new T[capacity];
		for (int i = 0; i < other.size; i++) {
			arr[i] = other.arr[i];
		}
		other.arr = nullptr;
	}
	return *this;
}
template<class T>
T& OYVector<T>::operator[](int index) {
	try {
		if (index > size - 1) {
			throw "error";
		}
	}
	catch (...) {
		cout << "An error has occured, index out of range." << endl;
		exit(-1);
	}
	return arr[index];
}
template<class T>
int OYVector<T>::push_back(T elem) {
	if (size < capacity) {
		arr[size++] = elem;
	}
	else {
		T* temp_arr = new T[capacity];
		for (int i = 0; i < size; i++) {
			temp_arr[i] = arr[i];
		}
		delete[] arr;
		capacity *= 2;
		arr = new T[capacity];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = temp_arr[i];
		}
		arr[size++] = elem;
		delete[] temp_arr;
	}
	return size-1;
}
template<class T>
T OYVector<T>::pop_back() {

	T* temp_arr = new T[capacity];
	for (int i = 0; i < size; i++) {
		temp_arr[i] = arr[i];
	}
	delete[] arr;
	if (capacity == size) {
		capacity /= 2;
	}
	arr = new T[capacity];
	for (size_t i = 0; i < size - 1; i++)
	{
		arr[i] = temp_arr[i];
	}
	delete[] temp_arr;
	size--;
	return arr[size - 1];
}
template<class T>
void OYVector<T>:: erase(T* it) {

	bool check = false;

	for (size_t i = 0; i < size - 1; i++)
	{
		if (*it == arr[i]) {
			arr[i] = arr[i + 1];
			check = true;
		}
	}
	try {
		if (check == false) {
			throw "error";
		}
	}
	catch (...) {
		cout << "The Element Is Not Exist !!" << endl;
		exit(-1);
	}
	this->pop_back();
}
template<class T>
void OYVector<T>::erase(T* it1,T* it2) {

	bool check = false;
	int counter = 0;
	int x;
	for (size_t i = 0; i < size ; i++)
	{
		x = i;
		if (it1 == &arr[i]) {
			
			for (size_t j = x; j < size; j++)
			{
				counter++;
				if (it2 == &arr[j]) {

					for (size_t z = j; z < size; z++)
					{
						arr[x] = arr[z + 1];
						x++;
						check = true;
					}
					
				}
				if (check) {
					break;
				}
			}
			if (check) {
				break;
			}
		}
	}
	
	for (size_t i = 0; i < counter; i++)
	{
		this->pop_back();
	}
	try {
		if (check == false) {
			throw "error";
		}
	}
	catch (...) {
		cout << "The Element Is Not Exist !!" << endl;
		exit(-1);
	}
}
template<class T>
T* OYVector<T>:: begin() {
	T* begin = &arr[0];
	return begin;
}
template<class T>
T* OYVector<T>::end() {
	T* end = &arr[size];
	return end;
}
template<class T>
T  OYVector<T>::operator++() {
	auto it = this->begin();
	static int i = 1;
	try {
		if (i >= size) {
			throw "error";
		}
	}
	catch (...) {
		cout << "Out of range" << endl;
		exit(-1);
	}
	it = arr[i];
	i++;
	return *it;
}
template<class T>
T  OYVector<T>::operator+(int n) {
	auto it = this->begin();
	static int j = 1;
	for (size_t i = 0; i < n; i++)
	{
		j++;
	}
	try {
		if (j >= size) {
			throw "error";
		}
	}
	catch (...) {
		cout << "Out of range" << endl;
		exit(-1);
	}
	it = arr[j];
	return *it;
}
template<class T>
void OYVector<T>::clear() {
	delete[] arr;
	capacity = 2;
	size = 0;
	arr = new T[capacity];
}
template<class T>
void OYVector<T>::insert(T*& it, T e) {

	if (size >= capacity) {
		capacity *= 2;
	}
	T* temp_arr = new T[capacity];
	T* temp_arr2 = new T[capacity];
	for (int i = 0; i < size; i++) {
		temp_arr[i] = arr[i];
		temp_arr2[i] = arr[i];
		if (it == &arr[i]) {
			it = &temp_arr2[i];
		}
	}
	delete[] arr;
	bool check = false;
	for (int i = 0; i < size; i++)
	{
		if (it == &temp_arr2[i]) {
			temp_arr2[i] = e;
			for (int j = i; j < size; j++) {
				temp_arr2[j + 1] = temp_arr[j];
				check = true;
			}
			break;
		}
		if (check) {
			break;
		}
	}
	arr = new T[capacity];
	size++;
	for (int i = 0; i < size; i++) {
		arr[i] = temp_arr2[i];
		if (*it == temp_arr2[i]) {
			it = &arr[i];
		}
	}
	delete[]temp_arr;
	delete[]temp_arr2;
}
template<class T>
bool OYVector<T>:: operator==(const OYVector<T>& a) {

	if (size != a.size) {
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] != a.arr[i]) {
			return false;
		}
	}
	return true;
}
template<class T>
bool OYVector<T>:: operator<(const OYVector<T>& a) {

	
	if (size >= a.size) {
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] < a.arr[i]) {
				return true;
			}
		}
	}
	else {
		for (size_t i = 0; i < a.size; i++)
		{
			if (arr[i] < a.arr[i]) {
				return true;
			}
		}
	}
	
	return false;
}
template<class T>
int OYVector<T>::resize() {
	T* temp_arr = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		temp_arr[i] = arr[i];
	}
	delete[] arr;
	capacity *= 2;
	arr = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = temp_arr[i];
	}
	delete[] temp_arr;
	return capacity;
}
template<class T>
bool OYVector<T>::empty() {
	if (size == 0) {
		return true;
	}
	else {
		return false;
	}
}
template<class T>
ostream& operator << (ostream& out, OYVector<T>& other) {
	for (size_t i = 0; i < other.size; i++)
	{
		out << other.arr[i] << endl;
	}
	return out;
}