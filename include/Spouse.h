#ifndef SPOUSE_H
#define SPOUSE_H

#include <string>
#include "people.h"

class Spouse : public Person
{
private:
    std::string anniversaryDate;

public:
    Spouse();

    Spouse(const std::string& name,
           const std::string& ssNum,
           int age,
           const std::string& anniversaryDate);

    virtual ~Spouse();

    // Getter
    std::string getAnniversaryDate() const;

    // Setter
    void setAnniversaryDate(const std::string& anniversaryDate);
};

#endif 
