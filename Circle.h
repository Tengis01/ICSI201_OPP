#include "2d.h"                  //2d.h header file холбож байна
#ifndef __circle__
#define __circle__

class circle:public twod{        //2dshape классаас удамшина
   float area();                 //талбай олох функц
   float perimeter();            //периметр олох функц
   void coordinate();            //координатын цэгүүдийг олох функц
};

#endif 
