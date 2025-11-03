#ifndef __SHAPE__
#define __SHAPE__

class shape {
public:
    float a;          // тал/радиус
    char* name;       // дүрсний нэр

    static int count; // Бүх үүссэн объектын тоог тоолох static хувьсагч

    //  АНХДАГЧ байгуулагч
    shape(); // Объект үүсэх бүрт нэмэгдэнэ

    // ПАРАМЕТРТ байгуулагч 
    shape(const char* n, float side);

    // УСТГАГЧ 
    virtual ~shape(); // Объект устахад хасагдана

    // Static гишүүн функцүүд — утга оноох, авах
    static void setCount(int n) {count=n; }
    static int getCount() {return count; }
};

#endif
