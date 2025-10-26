#ifndef __TRIANGLE__
#define __TRIANGLE__

#include "2d.h"

class triangle:public twod{
   public:
   
   triangle(); // АНХДАГЧ байгуулагч
   triangle(float a_); // ПАРАМЕТРТ байгуулагч

   float area();                 //талбай олох функц
   float perimeter();            //периметр олох функц
   void coordinate();            //координатын цэгүүдийг олох функц
};
#endif 
