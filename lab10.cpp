#include <iostream>
#include <cmath>
#include <cstring>

using namespace std;

class shape {              // үндсэн класс
public:
    float a;               // талын урт, радиус
    const char* name;      // дүрсний нэр

    shape() : a(0), name(nullptr) {}
    virtual ~shape() {}
};

class twod : public shape {   // 2D дүрсийн abstract класс
public:
    float xy[4][2];           // координатын цэгүүд

    virtual float area() = 0;        // талбай (цэвэр virtual)
    virtual float perimeter() = 0;   // периметр (цэвэр virtual)
    virtual void coordinate() = 0;   // координат тооцох (цэвэр virtual)

    void get_data();   // гараас утга авах
    void show_data();  // мэдээлэл хэвлэх
};

void twod::get_data() {
    cout << "coordinate: " << endl;
    cout << "x: ";
    cin >> xy[0][0];         // эхний цэгийн x
    cout << "y: ";
    cin >> xy[0][1];         // эхний цэгийн y
    cout << "side (a): ";
    cin >> a;                // талын урт / радиус
}

void twod::show_data() {
    cout << "_________" << endl
         << name << endl
         << "_________" << endl;

    cout << "coordinate: " << endl;

    if (strcmp(name, "triangle") == 0) {          // гурвалжин
        for (int i = 0; i < 3; ++i) {
            cout << "x" << i << ": " << xy[i][0] << endl;
            cout << "y" << i << ": " << xy[i][1] << endl;
        }
    } else if (strcmp(name, "square") == 0) {     // дөрвөлжин
        for (int i = 0; i < 4; ++i) {
            cout << "x" << i << ": " << xy[i][0] << endl;
            cout << "y" << i << ": " << xy[i][1] << endl;
        }
    } else {
        // circle гэх мэтэд координат тооцоогүй байгаа тул юу ч хэвлэхгүй байж болно
    }

    cout << "side (a): " << a << endl;
    cout << "area: " << area() << endl;
    cout << "perimeter: " << perimeter() << endl;
}
// circle
class circle : public twod {
public:
    circle() { name = "circle"; }

    float area() override;
    float perimeter() override;
    void coordinate() override;
};

float circle::perimeter() {
    return 2 * 3.14f * a;
}

float circle::area() {
    return 3.14f * a * a;
}

void circle::coordinate() {
    // Одоогоор координат тооцохгүй (хэрэгцээ гарвал энд бичиж болно)
}

// square
class square : public twod {
public:
    square() { name = "square"; }

    float area() override;
    float perimeter() override;
    void coordinate() override;
};

float square::perimeter() {
    return 4 * a;
}

float square::area() {
    return a * a;
}

void square::coordinate() {
    // xy[0] – эхний орой
    xy[1][0] = xy[0][0] + a;
    xy[1][1] = xy[0][1];

    xy[2][0] = xy[0][0] + a;
    xy[2][1] = xy[0][1] - a;

    xy[3][0] = xy[0][0];
    xy[3][1] = xy[0][1] - a;
}

// triangle 
class triangle : public twod {
public:
    triangle() { name = "triangle"; }

    float area() override;
    float perimeter() override;
    void coordinate() override;
};

float triangle::perimeter() {
    return 3 * a;
}

float triangle::area() {
    float h = sqrt(a * a - (a / 2) * (a / 2));  // тэнцүү талт гурвалжин
    return a * h / 2;
}

void triangle::coordinate() {
    float h = sqrt(a * a - (a / 2) * (a / 2));  // өндөр

    // xy[0] – дээд орой гэж үзье
    xy[1][0] = xy[0][0] + a / 2;
    xy[1][1] = xy[0][1] - h;

    xy[2][0] = xy[0][0] - a / 2;
    xy[2][1] = xy[0][1] - h;
}

// main 
int main() {
    int nCircle, nSquare, nTriangle;

    cout << "Heden toirog oruulah be? ";
    cin >> nCircle;

    cout << "Heden kvadrat oruulah be? ";
    cin >> nSquare;

    cout << "Heden gurvaljin oruulah be? ";
    cin >> nTriangle;

    int n = nCircle + nSquare + nTriangle;
    if (n <= 0) {
        cout << "Durs oldsongui.\n";
        return 0;
    }

    // Динамик массив (polymorphism ашиглана)
    twod** shapes = new twod*[n];

    int k = 0;
    for (int i = 0; i < nCircle;   ++i) shapes[k++] = new circle;
    for (int i = 0; i < nSquare;   ++i) shapes[k++] = new square;
    for (int i = 0; i < nTriangle; ++i) shapes[k++] = new triangle;

    // Мэдээлэл авах, координат тооцоод хэвлэх
    for (int i = 0; i < n; ++i) {
        cout << "\n[" << i << "] " << shapes[i]->name << '\n';
        shapes[i]->get_data();
        shapes[i]->coordinate();
        shapes[i]->show_data();
    }

    // Bubble sort – талбайгаар нь өсөхөөр эрэмбэлэх
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                twod* tmp   = shapes[j];
                shapes[j]   = shapes[j + 1];
                shapes[j+1] = tmp;
            }
        }
    }

    cout << "\n== Talbaigaar erembelsen (osohoor) ==\n";
    for (int i = 0; i < n; ++i) {
        shapes[i]->show_data();
    }

    // Санах ой цэвэрлэх
    for (int i = 0; i < n; ++i) {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}