#include "2d.h"
#include <iostream>
#include <string.h>

using namespace std;

twod::twod() : shape() {
    // xy-ыг 0 болгоё
    for (int i = 0; i < 4; ++i) { xy[i][0] = 0; xy[i][1] = 0; }
}

twod::twod(const char* n, float side) : shape(n, side) {
    for (int i = 0; i < 4; ++i) { xy[i][0] = 0; xy[i][1] = 0; }
}
void twod::get_data(void) {
    cout << "coordinate: " << endl;
    cout << "x: "; cin >> this->xy[0][0];                           // xy[0][0] буюу х цэгийг гараас оруулна
    cout << "y: "; cin >> this->xy[0][1];                           // xy[0][1] буюу у цэгийг гараас оруулна
    cout << "side: "; cin >> this->a;                               // //талын уртыг гараас оруулна
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
            }else if (strcmp(name,"circle")==0){                       //нэр нь дугуй байвал төвийн координатыг хэвлэж харуулна
            cout<<"x: "<<xy[0][0]<<endl;
            cout<<"y: "<<xy[0][1]<<endl;
        }
            cout << "side: " << this->a << endl;
            cout << "area: " << this->area() << endl;
            cout << "perimeter: " << this->perimeter() << endl;
}
