#pragma once

#include <iostream>

class DinamicArrayIntNumber {
private:
    int* arr;
    int size;
    int reserve;
public:
    static constexpr int defaultSize = 10;

    DinamicArrayIntNumber();
    DinamicArrayIntNumber(int size, int reserve);
    DinamicArrayIntNumber(int size, int n, int reserve);
    DinamicArrayIntNumber(const DinamicArrayIntNumber& dinamic);
    DinamicArrayIntNumber(DinamicArrayIntNumber&& dinamic);
    ~DinamicArrayIntNumber();

    int getSizeOfArray() const;
    int getElementOfArray(const int i) const;
    void resize(int newSize);

    void createReserveSize(int n);

    int capacity() const;
    bool isEmpty();

    void pushBack(int x);
    void popBack();

    DinamicArrayIntNumber& operator=(const DinamicArrayIntNumber& dinamic);
    DinamicArrayIntNumber& operator=(DinamicArrayIntNumber&& dinamic);

    int& operator[](const int index) const;

    friend bool operator== (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator!= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator> (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator<= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend bool operator< (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);
    friend bool operator>= (const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend DinamicArrayIntNumber operator+(const DinamicArrayIntNumber& d1, const DinamicArrayIntNumber& d2);

    friend std::ostream& operator<<(std::ostream& out, const DinamicArrayIntNumber& d1);
    friend std::istream& operator>>(std::istream& in, DinamicArrayIntNumber& d1);
};