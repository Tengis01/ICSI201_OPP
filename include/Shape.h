#ifndef __SHAPE__
#define __SHAPE__

class shape {
public:

    static int count; // Бүх үүссэн объектын тоог тоолох static хувьсагч

    float a;          // тал/радиус
    char* name;       // дүрсний нэр

    //  АНХДАГЧ байгуулагч
    shape();

    // ПАРАМЕТРТ байгуулагч 
    shape(const char* n, float side);

    // УСТГАГЧ 
    virtual ~shape();// Объект устахад хасагдана
};

#endif
