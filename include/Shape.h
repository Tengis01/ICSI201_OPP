#ifndef __SHAPE__
#define __SHAPE__

class shape {
public:
    float a;          // тал/радиус
    char* name;       // дүрсний нэр

    //  АНХДАГЧ байгуулагч
    shape();

    // ПАРАМЕТРТ байгуулагч 
    shape(const char* n, float side);

    // УСТГАГЧ 
    virtual ~shape();
};

#endif
