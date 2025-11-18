#include <iostream>
#include <cmath> 
#include <cstring> // strcmp
#include <stdexcept> // out_of_range
using namespace std;

// Base class: бүх дүрсний үндсэн класс
class shape {
public:
    float a;          // талын урт / радиус
    const char* name; // дүрсний нэр

    shape() : a(0), name(nullptr) {}
    virtual ~shape() {}
};

// 2D дүрсийн abstract class
class twod : public shape {
public:
    float xy[4][2];  // дүрсний оройнуудын координат

    virtual float area() = 0;        // Талбайг буцаах виртуал функц
    virtual float perimeter() = 0;   // Периметрийг буцаах виртуал функц
    virtual void coordinate() = 0;   // Оройнуудын координатыг тооцох виртуал функц

    // Объектын өгөгдлийг дэлгэцэнд хэвлэх
    void show_data() {
        cout << "_________\n" << name << "\n_________\n";
        cout << "Coordinates:\n";
        if (strcmp(name, "triangle") == 0) {
            for (int i = 0; i < 3; i++)
                cout << "x" << i << ": " << xy[i][0] << " y" << i << ": " << xy[i][1] << "\n";
        }
        else if (strcmp(name, "square") == 0) {
            for (int i = 0; i < 4; i++)
                cout << "x" << i << ": " << xy[i][0] << " y" << i << ": " << xy[i][1] << "\n";
        }
        cout << "side/radius: " << a << "\n";
        cout << "area: " << area() << "\n";
        cout << "perimeter: " << perimeter() << "\n";
    }
};

// Circle class
class circle : public twod {
public:
    circle() { name = "circle"; }

    float area() override { return 3.14f * a * a; }
    float perimeter() override { return 2 * 3.14f * a; }
    void coordinate() override { 
        // circle-д одоогоор xy ашиглахгүй 
    }
};

// Square class
class square : public twod {
public:
    square() { name = "square"; }

    float area() override { return a * a; }
    float perimeter() override { return 4 * a; }

    void coordinate() override {
        xy[1][0] = xy[0][0] + a; xy[1][1] = xy[0][1];
        xy[2][0] = xy[0][0] + a; xy[2][1] = xy[0][1] - a;
        xy[3][0] = xy[0][0];     xy[3][1] = xy[0][1] - a;
    }
};

// Triangle class
class triangle : public twod {
public:
    triangle() { name = "triangle"; }

    float area() override {
        float h = sqrt(a * a - (a / 2) * (a / 2));
        return a * h / 2;
    }

    float perimeter() override { return 3 * a; }

    void coordinate() override {
        float h = sqrt(a * a - (a / 2) * (a / 2));
        xy[1][0] = xy[0][0] + a / 2; xy[1][1] = xy[0][1] - h;
        xy[2][0] = xy[0][0] - a / 2; xy[2][1] = xy[0][1] - h;
    }
};

template<typename T>
class GeneralList {
private:
    T* data;      // Объект хадгалах динамик массив
    int count;    // Одоогийн элементүүдийн тоо
    int capacity; // Массивын багтаамж

    // Багтаамжийг өргөтгөх функц
    void expandCapacity() {
        int newCap = (capacity == 0 ? 4 : capacity * 2);
        T* newData = new T[newCap];
        for (int i = 0; i < count; i++) newData[i] = data[i];
        delete[] data;
        data = newData;
        capacity = newCap;
    }

public:
    GeneralList() : data(nullptr), count(0), capacity(0) {}

    ~GeneralList() { delete[] data; }

    // Жагсаалтын сүүлд объект нэмэх
    void add(T t) {
        if (count == capacity) expandCapacity();
        data[count++] = t;
    }

    // Жагсаалтын дунд оруулах функц
    void insert(T t, int index) {
        if (index < 0 || index > count) throw out_of_range("Index out of bounds");
        if (count == capacity) expandCapacity();
        for (int i = count; i > index; i--) data[i] = data[i - 1];
        data[index] = t;
        count++;
    }

    // i-р элементийг авах
    T& get(int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of bounds");
        return data[index];
    }

    // i-р элементийг устгах
    void deleteElement(int index) {
        if (index < 0 || index >= count) throw out_of_range("Index out of bounds");
        for (int i = index; i < count - 1; i++) data[i] = data[i + 1];
        count--;
    }

    // Жагсаалтын уртыг буцаах
    int length() const { return count; }
};

int main() {
    GeneralList<twod*> shapes;

    // 27 объект үүсгэх: 9 circle, 9 square, 9 triangle
    circle c1,c2,c3,c4,c5,c6,c7,c8,c9;
    square s1,s2,s3,s4,s5,s6,s7,s8,s9;
    triangle t1,t2,t3,t4,t5,t6,t7,t8,t9;

    // Object-уудыг жагсаалтад нэмэх
    shapes.add(&c1); shapes.add(&c2); shapes.add(&c3); shapes.add(&c4); shapes.add(&c5);
    shapes.add(&c6); shapes.add(&c7); shapes.add(&c8); shapes.add(&c9);

    shapes.add(&s1); shapes.add(&s2); shapes.add(&s3); shapes.add(&s4); shapes.add(&s5);
    shapes.add(&s6); shapes.add(&s7); shapes.add(&s8); shapes.add(&s9);

    shapes.add(&t1); shapes.add(&t2); shapes.add(&t3); shapes.add(&t4); shapes.add(&t5);
    shapes.add(&t6); shapes.add(&t7); shapes.add(&t8); shapes.add(&t9);

    // Санамсаргүйгийн оронд гараар тал/радиус оноох
    for (int i = 0; i < shapes.length(); i++) {
        shapes.get(i)->a = i % 10 + 1;   // 1-10 утгууд
        shapes.get(i)->xy[0][0] = i;     // x координат
        shapes.get(i)->xy[0][1] = i;     // y координат
        shapes.get(i)->coordinate();
    }

    // Bubble sort: талбайгаар өсөхөөр эрэмбэлэх
    for (int i = 0; i < shapes.length() - 1; i++) {
        for (int j = 0; j < shapes.length() - i - 1; j++) {
            if (shapes.get(j)->area() > shapes.get(j + 1)->area()) {
                twod* tmp = shapes.get(j);
                shapes.get(j) = shapes.get(j + 1);
                shapes.get(j + 1) = tmp;
            }
        }
    }

    // Эрэмбэлэгдсэн объектуудыг дэлгэцэнд хэвлэх
    for (int i = 0; i < shapes.length(); i++) {
        cout << "\n[" << i << "] " << shapes.get(i)->name << "\n";
        shapes.get(i)->show_data();
    }

    // Жагсаалтын дунд оруулах / устгах жишээ
    cout << "\nJagsaaltiin dund oruulah/ustgah jishee\n";
    circle c10;
    c10.a = 7;

    try {
        shapes.insert(&c10, 5); // 5-р индекс дээр circle нэмэх
        cout << "Element amjilttai nemlee (index 5).\n";
    } catch (const out_of_range& e) {
        cout << "Nemehed aldaa garlaa: " << e.what() << "\n";
    }

    try {
        shapes.deleteElement(2); // 2-р индексийг устгах
        cout << "Element amjilttai ustgalaa (index 2).\n";
    } catch (const out_of_range& e) {
        cout << "Ustgahad aldaa garlaa: " << e.what() << "\n";
    }
    return 0;
}
