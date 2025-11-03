#include "Shape.h"

#include <string.h>  
#include <stddef.h>  // NULL

shape::shape() {  // анхдагч байгуулагч
    a = 0;
    name = NULL;
}

shape::shape(const char* n, float side) {  // параметрт байгуулагч
    a = side;
    if (n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    } else {
        name = NULL;
    }
}

shape::~shape() { // устгагч
    if (name) {
        delete[] name;
        name = NULL;
    }
}

int shape::count=0; // Статик хувьсагчийг анхдагч утгаар 0 болгоно