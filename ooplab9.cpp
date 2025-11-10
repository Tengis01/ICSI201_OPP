#include <iostream>
#include <string>
using namespace std;


// Parent class: Person

class Person {
private:
    string Name;      // Huniin ner
    string SSNum;     // Niigmiin daatgaliin dugaar
    int Age;          // Nas

public:
    // Constructor - shine object uusgeh ued duudagdana
    Person(string name = "", string ss = "", int age = 0)
        : Name(name), SSNum(ss), Age(age) {}

    // Getter functions - utgiig butsaana
    string getName() const { return Name; }
    string getSSNum() const { return SSNum; }
    int getAge() const { return Age; }

    // Setter functions - utga onoohod ashiglana
    void setName(string name) { Name = name; }
    void setSSNum(string ss) { SSNum = ss; }
    void setAge(int age) { Age = age; }
};


// Derived class: Spouse (Person-oos udamshina)

class Spouse : public Person {
private:
    string AnniversaryDate;  // Gerleltin oi (ognoo helbertei string)

public:
    // Constructor - Person-iin constructor-g duudaj utguud onoono
    Spouse(string name = "", string ss = "", int age = 0, string anniv = "")
        : Person(name, ss, age), AnniversaryDate(anniv) {}

    // Getter - AnniversaryDate utgiig butsaana
    string getAnniversaryDate() const {
        return AnniversaryDate;
    }

    // Setter - AnniversaryDate-d shine utga onoohod ashiglana
    void setAnniversaryDate(string date) {
        AnniversaryDate = date;
    }
};


// Turshiltin main() function

int main() {
    // Spouse object uusgej utguud onooh
    Spouse s("Enkhbayar", "A12345", 20, "2023-06-15");

    // Utguudiig hevleh
    cout << "Name: " << s.getName() << endl;
    cout << "SSNum: " << s.getSSNum() << endl;
    cout << "Age: " << s.getAge() << endl;
    cout << "Anniversary Date: " << s.getAnniversaryDate() << endl;

    return 0;
}
