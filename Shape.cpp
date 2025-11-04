#include "Shape.h"

#include <string.h>  
#include <stddef.h>  // NULL

int shape::count = 0; //static huvisagchid garaanii utga

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
    count++;
}

shape::~shape() { // устгагч
    if (name) {
        delete[] name;
        name = NULL;
    }
    count--;
}
int shape::count_ret(){
    return count;
}