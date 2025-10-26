#ifndef __SQUARE__
#define __SQUARE__

#include "2d.h"

class square:public twod{
   public:
   square();
   square(float a);

   float area();                 //талбай олох функц
   float perimeter();            //периметр олох функц
   void coordinate();            //координатын цэгүүдийг олох функц
}; 
#endif
