#include "include/people.h"

Person::Person()
    : name("Default"), ssNum("AA000000"), age(0)
{
}

Person::Person(const std::string& name,
               const std::string& ssNum,
               int age)
    : name(name), ssNum(ssNum), age(age)
{
}

Person::~Person()
{
}

// Getter-үүд
std::string Person::getName() const{
    return name;
}

std::string Person::getSSNum() const{
    return ssNum;
}

int Person::getAge() const{
    return age;
}

// Setter-үүд
void Person::setName(const std::string& name){
    this->name = name;
}

void Person::setSSNum(const std::string& ssNum){
    this->ssNum = ssNum;
}

void Person::setAge(int age){
    this->age = age;
}
