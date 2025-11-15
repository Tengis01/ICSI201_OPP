#include <iostream>
#include <stdexcept> // std::out_of_range, std::invalid_argument-ийг ашиглана

// T төрлийн дурын өгөгдөл хадгалах GeneralList загвар класс
template <typename T>
class GeneralList {
private:
    T* data;         // Өгөгдөл хадгалах динамик массив (Хувийн гишүүн)
    int count;       // Жагсаалтын одоогийн элементүүдийн тоо (length)
    int capacity;    // Массивын нийт багтаамж (capacity)

    // Массивын багтаамжийг өргөтгөх хувийн туслах функц
    void expandCapacity() {
        // Багтаамжийг 2 дахин нэмэгдүүлнэ
        int newCapacity = capacity * 2;
        if (newCapacity == 0) {
            // Эхний удаа дуудагдах үед (capacity = 0 байвал)
            newCapacity = 4; 
        }

        // Шинэ багтаамжтай түр массив үүсгэнэ
        T* newData = new T[newCapacity];
        
        // Хуучин өгөгдлүүдийг шинэ рүү хуулна
        for (int i = 0; i < count; ++i) {
            newData[i] = data[i];
        }

        // Хуучин массивын санах ойг суллана (NULL check хийхгүй байж болно)
        if (data != nullptr) {
            delete[] data;
        }

        // data-г шинэ массив руу заана, багтаамжийг шинэчилнэ
        data = newData;
        capacity = newCapacity;
    }

public:
    // 1. Конструктор (Анхны байгуулагч)
    GeneralList() : count(0), capacity(0), data(nullptr) {}

    // 2. Деструктор (Устгагч) - Санах ойг суллах
    ~GeneralList() {
        delete[] data;
    }
    
    // 3. Хуулбарлахыг хориглох (Deep Copy ашиглахгүй бол)
    GeneralList(const GeneralList&) = delete;
    GeneralList& operator=(const GeneralList&) = delete;

    // -----------------------------------------------------
    // Хүсэлтэд дурдсан функцууд
    // -----------------------------------------------------

    /**
     * @brief Жагсаалтын сүүлд элемент нэмнэ.
     * @param t Нэмэх элемент
     */
    void add(T t) {
        // Багтаамж дүүрсэн эсэхийг шалгана
        if (count == capacity) {
            expandCapacity();
        }
        // Сүүлд нь элементийг нэмээд, тоог нэгээр нэмэгдүүлнэ
        data[count] = t;
        count++;
    }

    /**
     * @brief index-дүгээрт элементийг оруулна.
     * @param t Оруулах элемент
     * @param index Оруулах байрлал (0 <= index <= length())
     */
    void insert(T t, int index) {
        if (index < 0 || index > count) {
            // "index > count" нь "add"-тэй адил сүүлд нэмэх боломжийг хаахгүй,
            // зөвхөн оруулах байрлал (индекс) хүрээ хязгаарт багтаж буйг шалгана.
            throw std::out_of_range("Insert index is out of bounds (0 <= index <= length).");
        }

        // Багтаамж дүүрсэн бол өргөтгөнө
        if (count == capacity) {
            expandCapacity();
        }

        // index-ээс хойших элементүүдийг нэг байрлалаар хойшлуулна
        for (int i = count; i > index; --i) {
            data[i] = data[i - 1];
        }

        // index-т шинэ элементийг оруулна
        data[index] = t;
        count++;
    }

    /**
     * @brief i-р элементийн утгыг буцаана.
     * @param index Авах элементийн байрлал
     * @return i-р элементийн утга
     */
    T get(int index) const {
        if (index < 0 || index >= count) {
            throw std::out_of_range("Get index is out of bounds (0 <= index < length).");
        }
        return data[index];
    }

    /**
     * @brief i-р элементийг устгана.
     * @param index Устгах элементийн байрлал
     */
    void deleteElement(int index) { // "delete" нь C++-ийн түлхүүр үг тул "deleteElement" гэж нэрлэв
        if (index < 0 || index >= count) {
            throw std::out_of_range("Delete index is out of bounds (0 <= index < length).");
        }

        // index-ээс хойш байгаа элементүүдийг нэг байрлалаар урагшлуулж, устгалтыг хийнэ
        for (int i = index; i < count - 1; ++i) {
            data[i] = data[i + 1];
        }

        count--; // Элементийн тоог нэгээр багасгана
        // *Жич: Устгагдсан элементийн санах ойг "delete" хийх шаардлагагүй, учир нь
        // энэ нь T* төрлийн массивын доторх утга юм.
    }

    /**
     * @brief Жагсаалтын уртыг буцаана.
     * @return Элементийн тоо
     */
    int length() const {
        return count;
    }
};

// -----------------------------------------------------
// Хэрэгжилтийг шалгах код (main функц)
// -----------------------------------------------------

int main() {
    // 1. Integer төрлийн жагсаалт
    std::cout << "--- Integer GeneralList Test ---" << std::endl;
    GeneralList<int> intList;

    intList.add(10); // [10]
    intList.add(20); // [10, 20]
    intList.add(30); // [10, 20, 30]
    std::cout << "Length after add: " << intList.length() << std::endl; // Output: 3

    intList.insert(15, 1); // [10, 15, 20, 30]
    std::cout << "Element at index 1: " << intList.get(1) << std::endl; // Output: 15

    try {
        intList.deleteElement(3); // 30-г устгана: [10, 15, 20]
        std::cout << "Element at index 2 after delete: " << intList.get(2) << std::endl; // Output: 20
        intList.deleteElement(0); // 10-г устгана: [15, 20]
        std::cout << "Element at index 0 after delete: " << intList.get(0) << std::endl; // Output: 15

    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    
    std::cout << "Final Length: " << intList.length() << std::endl; // Output: 2

    // 2. String төрлийн жагсаалт
    std::cout << "\n--- String GeneralList Test ---" << std::endl;
    GeneralList<std::string> stringList;

    stringList.add("Apple");
    stringList.add("Banana");
    stringList.insert("Cherry", 1); // [Apple, Cherry, Banana]
    
    std::cout << "Length: " << stringList.length() << std::endl; // Output: 3
    std::cout << "Item at index 2: " << stringList.get(2) << std::endl; // Output: Banana

    try {
        stringList.deleteElement(0); // Apple-г устгана: [Cherry, Banana]
        std::cout << "Item at index 0 after delete: " << stringList.get(0) << std::endl; // Output: Cherry
        
        // Хүрээ хязгаараас хэтэрсэн index-ийн туршилт
        // stringList.get(5); 
    } catch (const std::out_of_range& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}