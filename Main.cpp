#include "include/circle.h"
#include "include/triangle.h"
#include "include/square.h"
#include <iostream>
#include <string.h>
using namespace std;

int main() {
    int nCircle, nSquare, nTriangle; // объектын тоог хадгалах хувьсагчид
    cout << "Heden toirog oruulah be? ";   cin >> nCircle; 
    cout << "Heden kvadrat oruulah be? ";   cin >> nSquare;
    cout << "Heden gurvaljin oruulah be? "; cin >> nTriangle;

    int n = nCircle + nSquare + nTriangle;   // ← нийт объектын тоо
    if (n <= 0) { cout << "Durs oldsongui.\n"; return 0; } // ямар ч объект үүсгэхгүй бол дуусгана

    // Динамик массив үүсгэх яагаад гэвэл хэрэглэгчээс оруулсан тоогоор объект үүсгэх учраас
    twod** shapes = new twod*[n];

    // Объектуудыг үүсгэх (нэрийг байгуулагч дотроос автоматаар онооно)
    int k = 0;
    for (int i = 0; i < nCircle;   ++i) shapes[k++] = new circle; 
    for (int i = 0; i < nSquare;   ++i) shapes[k++] = new square;
    for (int i = 0; i < nTriangle; ++i) shapes[k++] = new triangle;

    // Гараас өгөгдөл авч, координатыг тооцоод харуулъя
    for (int i = 0; i < n; ++i) {
        cout << "\n[" << i << "] " << shapes[i]->name << '\n';
        shapes[i]->get_data();
        shapes[i]->coordinate();
        shapes[i]->show_data();
    }

    // Үүссэн объектын тоог хэвлэхҮүссэн объектын тоог хэвлэх
    cout << "\nNiit uusgesen object: " << shape::getCount() << endl;

    // Хэрэглэгч ямар арга замаар эрэмбэлхээ сонгох
    int c;
    do{
        cout<<"ymr eremblelt songoh ve?\n1. talbaigaar\n2. perimetereer.\n==> ";
        cin>>c;
        if(c==1){
            // BUBBLE SORT: талбайгаар нь (өсөхөөр) эрэмбэлэх
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (shapes[j]->area() > shapes[j + 1]->area()) {
                        twod* tmp = shapes[j];
                        shapes[j]   = shapes[j + 1];
                        shapes[j+1] = tmp;
                    }
                }
            }

            cout << "\n== Talbaigaar erembelsen (osohoor) ==\n";
            for (int i = 0; i < n; ++i) {
                shapes[i]->show_data();
            }
        }
        if(c==2){
            // BUBBLE SORT: Периметрээр (өсөхөөр) эрэмбэлэх
            for (int i = 0; i < n - 1; ++i) {
                for (int j = 0; j < n - i - 1; ++j) {
                    if (shapes[j]->perimeter() > shapes[j + 1]->perimeter()) {
                        twod* tmp = shapes[j];
                        shapes[j] = shapes[j + 1];
                        shapes[j + 1] = tmp;
                    }
                }
            }

            cout << "\n== Perimeter-eer erembelsen (osohoor) ==\n";
            for (int i = 0; i < n; ++i) {
                shapes[i]->show_data();
            }
        }
        cout << "\ndahin erembleh uu? (1-Tiim / 0-Ugui): ";
        cin >> c;
    }while (c==1);

    // Санах ой цэвэрлэх
    for (int i = 0; i < n; ++i) delete shapes[i];
    delete[] shapes;

    return 0;
}
