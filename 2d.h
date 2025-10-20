#include "shape.h"                          //shape.h header file холбож өгнө
#ifndef __2d__
#define __2d__

class twod: public shape{                   //shape ээс удамшсан 2Dshape класс тодорхойлолт
    public:                                 //public хандалтын түвшинтэй
        virtual float area()=0;             //ингэснээр удамшсан функцууд даин тодорхойлолт хийж болно
        virtual float perimeter()=0;
        float xy[4][2];                     //координатын цэгүүдийг хадгалах хувьсагч
        void get_data(void);                //гараас утга оноох функц
        void show_data(void);               //мэдээлэл дэлгэцэлж харуулах функц
        virtual void coordinate()=0;        //координатын цэгүүдийг олох функц
};
#endif 
