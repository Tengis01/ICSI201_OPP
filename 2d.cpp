#include "2d.h"
#include <iostream>
#include<string.h>

using namespace std;

void twod::get_data(void){                                          //get data функц тодорхойлолт
            cout<<"coordinate: "<<endl;
            cout<<"x: ";
            cin>>xy[0][0];                                          //xy[0][0] буюу х цэгийг гараас оруулна
            cout<<"y: ";
            cin>>xy[0][1];                                          //xy[0][1] буюу у цэгийг гараас оруулна
            cout<<"side: ";
            cin>>a;                                                 //талын уртыг гараас оруулна
};
void twod::show_data(void){                                         //мэдээлэл дэлгэцэлж харуулах функц тодорхойлолт
            cout<<"_________"<<endl<<name<<endl<<"_________"<<endl;
            cout<<"coordinate: "<<endl;
            if(strcmp(name,"triangle")==0){                         //нэр нь гурвалжин байвал 3 цэгийн координатыг л хэвлэж харуулна
                for(int i=0;i<3;i++){
                cout<<"x"<<i<<": ";
                cout<<xy[i][0]<<endl;
                cout<<"y"<<i<<": ";
                cout<<xy[i][1]<<endl;
                }
            }else if(strcmp(name,"square")==0){                     //нэр нь дөрвөлжин байвал 4 цэгийн мэдээллийг хэвлэж харуулна
                for(int i=0;i<4;i++){
                cout<<"x: ";
                cout<<xy[i][0]<<endl;
                cout<<"y: ";
                cout<<xy[i][1]<<endl;
                }
            }
            cout<<"side: ";
            cout<<a<<endl;
            cout<<"area: ";
            cout<< area()<<endl;
            cout<<"perimeter: ";
            cout<< perimeter()<<endl;
        }
