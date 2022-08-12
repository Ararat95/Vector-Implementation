#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector
{
public:
    Vector ();
    Vector (int);
    Vector (int, int);
    Vector (const Vector&);
    Vector (Vector&&);
    ~Vector ();
    Vector& operator = (const Vector&);
    Vector operator + (const Vector&);
    Vector& operator += (const Vector&);
    int operator ++ ();
    const int operator ++ (int);
    int& operator [] (size_t);
    friend std::ostream& operator << (std::ostream&, const Vector&);
    int operator << (const int&);


public:
    void push_back (int);
    void pop_back ();
    void print ();
    int size ();
    void insert (int,int);
    std::string find_by_value (int);
    void remove_by_value (int);
    

private:
    int _size;
    int _capacity;
    int* _arr;
    int* _index;

};

#endif