#include <iostream>
using namespace std;
template <class T>
class Set {
private:
    int size;
    int capacity;
    T* arr;
public:
    Set(int cap = 2) {
        size = 0;
        capacity = cap;
        arr = new T[capacity];
    }
    
    int push_back(T elem) {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == elem) {
                return 0;
            }
        }
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
        return size - 1;
    }
    void display() {
        for (size_t i = 0; i< size; i++)
        {
            cout << arr[i] << endl;
        }
    }
    T pop_back() {

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
    void erase(T elem) {

        bool check = false;

        for (size_t i = 0; i < size - 1; i++)
        {
            if (arr[i]==elem) {
                for (size_t j = i; j < size - 1; j++) {
                    arr[j] = arr[j + 1];
                }
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
    int Size() {
        return size;
    }
    bool isExist(T item) {
        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] == item) {
                return true;
            }
        }
        return false;
    }
    bool operator==(const Set<T>& a) {

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
    bool operator!=(const Set<T>& a) {

        if (size != a.size) {
            return true;
        }

        for (size_t i = 0; i < size; i++)
        {
            if (arr[i] != a.arr[i]) {
                return true;
            }
        }
        return false;
    }
    /*T* ptr()
    {
        delete[] arr;
        capacity = 2;
        size = 0;
        T* ptr = new T[capacity];
        return ptr;
    }*/
};

int main()
{
    Set<int>s;
    cout << "add elements" << endl;
    s.push_back(5);
    s.push_back(6);
    s.push_back(7);
    s.push_back(8);
    s.push_back(8);
    cout << "display elements" << endl;
    s.display();
    cout << "delete element" << endl;
    s.erase(5);
    s.display();
    cout << "the number of items" << endl;
    cout << s.Size() << endl;
    cout << "if element is exist" << endl;
    cout << s.isExist(11) << endl;
    

}