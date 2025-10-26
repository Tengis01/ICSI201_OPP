#include "Square.h"                 //square.h header file холбож байна

square::square() : twod("square", 0) {} // АНХДАГЧ байгуулагч тодорхойлолт
square::square(float a_) : twod("square", a_) {} // ПАРАМЕТРТ байгуулагч тодорхойлолт

    float square::perimeter(){      //периметр функц тодорхойлолт
        return 4*a;                 //периметрийг олон буцааж байна
    }
    float square::area(){           //талбай олох функцийн тодорхойлолт
        return a*a;                 //талбайг олон буцааж байна
    }
    void square::coordinate(){      //координатын цэгүүдийг олох функц тодорхойлолт
        xy[1][0]=xy[0][0]+a;        //х у цэгүүдийг олж байна
        xy[1][1]=xy[0][1];
        xy[2][0]=xy[0][0]+a;
        xy[2][1]=xy[0][1]-a;
        xy[3][0]=xy[0][0];
        xy[3][1]=xy[0][1]-a;
    }
