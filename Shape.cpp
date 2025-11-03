#include "Shape.h"

#include <string.h>  
#include <stddef.h>  // NULL

static int count=0;

shape::shape() {  // анхдагч байгуулагч
    a = 0;
    name = NULL;
    count++;
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
    count--;
}
static int setCount(int n) { count = n; }
static int getCount() { return count; }