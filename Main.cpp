#include "circle.h"                         //circle.h file холбож байна
#include "triangle.h"                       //triangle.h file холбож байна
#include "square.h"                         //square.h file холбож байна
#include<iostream>                          //iostream сан холбож байна
#include<string.h>

using namespace std;

main(){
    twod *shapes[3];                        //2dshape хэлбэрийн 3 хаяган хувьсагч авах массив зарлалт
    shapes[0]=new circle;                   //эхний объектед circle хэлбэрийн санах ой нөөцлөж байна.
    shapes[0]->name=new char[7];            //нэрэнд нь 7 хэмжээтэй санах ой нөөцөлж байна.
    strcpy(shapes[0]->name,"circle");       //нөөцөлсөн санах ой доо circle утгыг хуулж байна
    shapes[1]=new triangle;                 //эхний объектед circle хэлбэрийн санах ой нөөцлөж байна.
    shapes[1]->name=new char[9];            //нэрэнд нь 9 хэмжээтэй санах ой нөөцөлж байна
    strcpy(shapes[1]->name,"triangle");     //нөөцөлсөн санах ой доо triangle утгыг хуулж байна
    shapes[2]=new square;                   //эхний объектед circle хэлбэрийн санах ой нөөцлөж байна.
    shapes[2]->name=new char[7];            //нэрэнд нь 7 хэмжээтэй санах ой нөөцөлж байна
    strcpy(shapes[2]->name,"square");       //нөөцөлсөн санах ой доо square утгыг хуулж байна

    for(int i=0;i<3;i++){                   //давталт гүйлгэж бүх объектийн гишүүн өгөгдлүүдэд утга оруулна
        shapes[i]->get_data();
        shapes[i]->coordinate();            //мэдээллийг харуулахаас өмнө coordinate функцийг дуудаж ажиллуулж байна
        shapes[i]->show_data();             //мэдээллийг хэвлэж харуулна
    }
}
