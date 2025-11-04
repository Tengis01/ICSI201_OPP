#ifndef PEOPLE_H
#define PEOPLE_H

#include <string>

class Person
{
private:
    std::string name;   
    std::string ssNum;
    int age;

public:
    Person(); // Анхдагч байгуулагч

    // Параметртэй байгуулагч
    Person(const std::string& name,
           const std::string& ssNum,
           int age);

    // Устгагч
    virtual ~Person();

    // Getter-үүд
    std::string getName() const;
    std::string getSSNum() const;
    int         getAge() const;

    // Setter-үүд
    void setName(const std::string& name);
    void setSSNum(const std::string& ssNum);
    void setAge(int age);
};

#endif // PEOPLE_H
