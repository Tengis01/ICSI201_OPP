#ifndef __SHAPE__
#define __SHAPE__

class shape {
public:
    // Бүх үүссэн объектын тоог тоолох static хувьсагч
    static int count;

    // Бүх үүссэн объектын тоог буцаах функц
    static int count_ret();

    float a;          // тал/радиус
    char* name;       // дүрсний нэр

    // АНХДАГЧ байгуулагч
    shape();

    // ПАРАМЕТРТ байгуулагч
    shape(const char* n, float side);

    // УСТГАГЧ
    virtual ~shape(); // Объект устахад хасагдана

    static int setcount(int new_count) { return count = new_count; }
    static int getcount() { return count; }
};

#endif
