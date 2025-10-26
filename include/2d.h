#ifndef __2D__
#define __2D__

#include "Shape.h"                          //shape.h header file холбож өгнө
class twod: public shape{                   //shape ээс удамшсан 2Dshape класс тодорхойлолт
    public:                                 //public хандалтын түвшинтэй
        // --- АНХДАГЧ байгуулагч
        twod();
        // --- ПАРАМЕТРТ байгуулагч: ЭХ КЛАССЫН параметрт байгуулагчийг дуудна
        twod(const char* n, float side);

        virtual float area()=0;             //ингэснээр удамшсан функцууд даин тодорхойлолт хийж болно
        virtual float perimeter()=0;
        float xy[4][2];                     //координатын цэгүүдийг хадгалах хувьсагч
        void get_data(void);                //гараас утга оноох функц
        void show_data(void);               //мэдээлэл дэлгэцэлж харуулах функц
        virtual void coordinate()=0;        //координатын цэгүүдийг олох функц
};
#endif 