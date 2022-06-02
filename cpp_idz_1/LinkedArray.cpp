#include "LinkedArray.h"
#include <iostream>

DinamicArrayIntNumber::DinamicArrayIntNumber() {
    arr = new int[defaultSize];
    int size = defaultSize;
    int reserve = 0;
}
DinamicArrayIntNumber::DinamicArrayIntNumber(int size, int reserve) {
    this->size = size;
    this->reserve = reserve;
    arr = new int[size + reserve];
    for (int i = 0; i < size; i++) {
        arr[i] = 0;
    }
}
DinamicArrayIntNumber::DinamicArrayIntNumber(int size, int n, int reserve) {
    this->size = size;
    this->reserve = reserve;
    arr = new int[size + reserve];
    for (int i = 0; i < size; i++) {
        arr[i] = n;
    }
}
DinamicArrayIntNumber::DinamicArrayIntNumber(const DinamicArrayIntNumber& dinamic) {
    size = dinamic.size;
    reserve = dinamic.reserve;
    arr = new int[size + reserve];
    for (int i = 0; i < dinamic.size; ++i) {
        arr[i] = dinamic.arr[i];
    }
}
DinamicArrayIntNumber::DinamicArrayIntNumber(DinamicArrayIntNumber&& dinamic)
    : arr(dinamic.arr), size(dinamic.size), reserve(dinamic.reserve)
{
    dinamic.arr = nullptr;
}
DinamicArrayIntNumber::~DinamicArrayIntNumber()
{
    delete[] arr;
}
int DinamicArrayIntNumber::getSizeOfArray() const {
    return size;
}
int DinamicArrayIntNumber::getElementOfArray(const int i) const {
    if (i >= size) {
        throw std::exception("Ошибка");
    }
    return arr[i];
}
void DinamicArrayIntNumber::resize(const int newSize) {
    int* newArray = new int[newSize];
    if (size >= newSize)
    {
        reserve = reserve + size - newSize;
        for (int i = 0; i < newSize; i++) {
            newArray[i] = arr[i];
        }
        delete[] arr;
        size = newSize;
        arr = newArray;
    }
    if (size < newSize)
    {
        int i = 0;
        for (; i < size; i++) {
            newArray[i] = arr[i];
        }
        for (; i < newSize; i++) {
            newArray[i] = 0;
        }
        delete[] arr;
        size = newSize;
        arr = newArray;
        if (newSize - size < reserve)
        {
            size = newSize;
            reserve = reserve - (newSize - size);
        }
    }
}

void DinamicArrayIntNumber::createReserveSize(const int n)
{
    int sizeN = size + n;
    reserve = n;
    int* dopArr = new int[sizeN];
    for (int i = 0; i < size; i++)
    {
        dopArr[i] = arr[i];
    }
    delete[] arr;
    arr = dopArr;
    dopArr = nullptr;
}
int DinamicArrayIntNumber::capacity() const
{
    return reserve;
}
bool DinamicArrayIntNumber::isEmpty()
{
    return size == 0;
}
void DinamicArrayIntNumber::pushBack(const int x)
{
    if (reserve == 0)
    {
        throw std::exception("За размером следи!");
    }
    reserve--;
    arr[size] = x;
    size++;
}
void DinamicArrayIntNumber::popBack()
{
    if (isEmpty())
    {
        throw std::exception("За размером следи!");
    }
    size--;
    reserve++;
}

DinamicArrayIntNumber& DinamicArrayIntNumber::operator=(const DinamicArrayIntNumber& diname) {
    if (&diname != this && *this != diname)
    {
        delete[] arr;
        size = diname.size;
        reserve = diname.reserve;
        arr = new int[size];
        for (int i = 0; i < size; i++) {
            arr[i] = diname.arr[i];
        }
        return *this;
    }
    return *this;
}
DinamicArrayIntNumber& DinamicArrayIntNumber::operator=(DinamicArrayIntNumber&& dinamic)
{
    if (&dinamic != this && *this != dinamic)
    {
        delete[] arr;
        size = dinamic.size;
        reserve = dinamic.reserve;
        arr = dinamic.arr;
        dinamic.arr = nullptr;
        return *this;
    }
    delete[] dinamic.arr;
    return *this;
}
int& DinamicArrayIntNumber::operator[](const int index) const {
    if (index >= getSizeOfArray())
        throw std::exception("Здесь запривачено, гнида");
    return arr[index];
}
bool operator== (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2) {
    if (d1.size != d2.size || d1.reserve != d2.reserve) {
        return false;
    }
    for (int i = 0; i < d1.size; i++) {
        if (d1.arr[i] != d2.arr[i]) {
            return false;
        }
    }
    return true;
}

bool operator != (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    return !(d1 == d2);
}

bool operator> (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    const int minSize = std::min(d1.size, d2.size);
    for (int i = 0; i < minSize; i++) {
        if (d1.arr[i] > d2.arr[i]) {
            return true;
        }
        else if (d1.arr[i] < d2.arr[i])
        {
            return false;
        }
    }
    return minSize != d1.size;
}

bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    const int minSize = std::min(d1.size, d2.size);
    for (int i = 0; i < minSize; i++) {
        if (d1.arr[i] > d2.arr[i])
        {
            return true;
        }
        else if (d1.arr[i] < d2.arr[i])
        {
            return false;
        }
    }
    if (minSize == d2.size) {
        return true;
    }

    return false;
}

bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    const int minSize = std::min(d1.size, d2.size);
    for (int i = 0; i < minSize; i++) {
        if (d1.arr[i] < d2.arr[i]) {
            return true;
        }
        else if (d1.arr[i] > d2.arr[i])
        {
            return false;
        }
    }
    return minSize != d1.size;
}

bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2)
{
    const int minSize = std::min(d1.size, d2.size);
    for (int i = 0; i < minSize; i++) {
        if (d1.arr[i] < d2.arr[i]) {
            return true;
        }
        else if (d1.arr[i] > d2.arr[i])
        {
            return false;
        }
    }
    if (minSize == d1.size) {
        return true;
    }

    return false;
}

DinamicArrayIntNumber operator+(const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2) {
    DinamicArrayIntNumber result = DinamicArrayIntNumber(d1.size + d2.size, d1.capacity() + d2.capacity());
    for (int i = 0; i < d1.size; i++) {
        result.arr[i] = d1.arr[i];
    }
    for (int j = d1.size; j < (d1.size + d2.size); j++) {
        result.arr[j] = d2.arr[j - d1.size];
    }
    return result;
}

std::ostream& operator<< (std::ostream& out, const DinamicArrayIntNumber& dinamic)
{
    out << "DinamicArrayIntNumber(";
    for (int i = 0; i < dinamic.getSizeOfArray(); i++) {
        out << dinamic.arr[i];
        if( i != dinamic.getSizeOfArray() -1)
        out << ", ";
    }
    out << ")";

    return out;
}

std::istream& operator>> (std::istream& in, DinamicArrayIntNumber& dinamic)
{
    for (int i = 0; i < dinamic.getSizeOfArray(); i++) {
        in >> dinamic.arr[i];
    }
    return in;
}