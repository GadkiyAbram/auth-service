//
// Created by aleksandr on 02.06.24.
//

#include "Pointer.h"

#include <iostream>
#include <ostream>

using namespace std;

void Pointer::pointerInt() {
    // Declare and initialize pointer
    int *p_number{};    // will initialize with nullptr
    // *p_number will store only addresses of the variables that have the type int

    double *p_fractional_number{};
    // *p_fractional_number will store only addresses of the variables that have the type double

    // Explicitly initialize with nullptr
    int *a_pointer{nullptr};
    int a = 333;
    a_pointer = &a;

    cout << "Number a: " << a << "\n" << endl;
    cout << "Address a: " << &a << "\n" << endl;
    cout << "Number a: " << *a_pointer << "\n" << endl; // Dereferencing a pointer, looking what's inside the address
    cout << "Pointer a: " << a_pointer << "\n" << endl;
    cout << "Number a: " << &a_pointer << "\n" << endl;
}

void Pointer::pointerChar() {
    constexpr int integer = 2;
    const int *p_int = &integer;

    char *p_message{"Hello there"};

    cout << "number is " << p_int << "\n" << endl;
    cout << "The message address is " << *p_message << "\n" << endl;
}
