#include "triangle.h"               //triangle.h header file холбож байна
#include <math.h>
float triangle::perimeter(){        //периметр функц тодорхойлолт
    return 3*a;                     //периметрийг олон буцааж байна
}
float triangle::area(){             //талбай олох функцийн тодорхойлолт
    float h=sqrt(a*a-a/2*a/2);      //гурвалжны өндөрийг олж байна
    return a*h/2;                   //талбайг олон буцааж байна
}
void triangle::coordinate(){        //координатын цэгийг олох функц тодорхойлолт
    float h=sqrt(a*a-a/2*a/2);
    xy[1][0]=xy[0][0]+a/2;          //х у цэгүүдийг олж байна
    xy[1][1]=xy[0][1]-h;
    xy[2][0]=xy[0][0]-a/2;
    xy[2][1]=xy[0][1]-h;
}
