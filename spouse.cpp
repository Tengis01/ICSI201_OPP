#include "include/spouse.h"

Spouse::Spouse()
    : Person(), anniversaryDate("2000-01-01")
{
}

Spouse::Spouse(const std::string& name,
               const std::string& ssNum,
               int age,
               const std::string& anniversaryDate)
    : Person(name, ssNum, age),   // суурь классын байгуулагч
      anniversaryDate(anniversaryDate)
{
}

Spouse::~Spouse(){
}

// Getter
std::string Spouse::getAnniversaryDate() const
{
    return anniversaryDate;
}
// Setter
void Spouse::setAnniversaryDate(const std::string& anniversaryDate)
{
    this->anniversaryDate = anniversaryDate;
}
