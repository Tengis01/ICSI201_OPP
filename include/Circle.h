#ifndef __CIRCLE__
#define __CIRCLE__

#include "2d.h"

class circle:public twod{
   public:
   // --- АНХДАГЧ байгуулагч
    circle();
    // --- ПАРАМЕТРТ байгуулагч: ЭХ КЛАССЫН параметрт байгуулагчийг дуудаж байна
    circle(float r);

   float area();                 //талбай олох функц
   float perimeter();            //периметр олох функц
   void coordinate();            //координатын цэгүүдийг олох функц
};

#endif 
