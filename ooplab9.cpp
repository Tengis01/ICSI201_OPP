#include <iostream>
#include <string>
#include <vector>

using namespace std;


class Person {
private:
    string Name;      
    string SSNum;     
    int Age;          

public:
    Person(string name = "", string ss = "", int age = 0)
        : Name(name), SSNum(ss), Age(age) {}

        virtual ~Person() {}
    
        // Getter functions - utgiig butsaana
        string getName() const { return Name; }
        string getSSNum() const { return SSNum; }
        int getAge() const { return Age; }
        
        // Setter functions - utga onoohod ashiglana
        void setName(string name) { Name = name; }
        void setSSNum(string ss) { SSNum = ss; }
        void setAge(int age) { Age = age; }
        
        // Virtual print - daraah klassuudad override hiine
        virtual void printBasicInfo() const {
            cout << "Name: " << Name
            << ", SSNum: " << SSNum
            << ", Age: " << Age;
        }
    };



    /*
 * Spouse class:
 *  - Person-оос өвлөсөн (нэр, нас гэх мэт) + AnniversaryDate талбартай.
 *  - Employee-тэй 0..1 харьцаатай байдлаар ашиглана (нэг ажилтанд 0 эсвэл 1 эхнэр/нөхөр).
 */
class Spouse : public Person {
private:
    string AnniversaryDate;  

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

    // Override print
    void printBasicInfo() const override {
        Person::printBasicInfo();
        cout << ", Anniversary: " << AnniversaryDate;
    }
};




/*
 * Child class:
 *  - Person-оос өвлөөд FavoriteToy гэдэг нэмэлт талбартай.
 *  - Employee-тэй 0..n харьцаатай нэг ажилтан олон хүүхэдтэй байж болно.
 */
class Child : public Person {
private:
    string FavoriteToy;

public:
    Child(string name = "", string ss = "", int age = 0, string toy = "")
        : Person(name, ss, age), FavoriteToy(toy) {}

    string getFavoriteToy() const { return FavoriteToy; }
    void setFavoriteToy(const string& toy) { FavoriteToy = toy; }

    void printBasicInfo() const override {
        Person::printBasicInfo();
        cout << ", Favorite toy: " << FavoriteToy;
    }
};

// Employee класс дотор Employee* заагч ашиглах тул урьдчилж зарласан
class Employee;




/*
 * Division class:
 *  - Нэг хэлтэс олон ажилтантай (1..n) байна гэсэн харьцааг илэрхийлнэ.
 */
class Division {
private:
    string DivisionName;
    // 1..n Employee
    vector<Employee*> employees;

public:
    Division(const string& name = "Default Division")
        : DivisionName(name) {
        // Anh uusgeh ued heltesiin ner default-aar "Default Division"
        cout << "[Info] Division uuslee: " << DivisionName << endl;
    }

    Division(const string& name = "") : DivisionName(name) {}

    string getDivisionName() const { return DivisionName; }
    void setDivisionName(const string& name) { DivisionName = name; }

    // Employee нэмэх (1..n харьцаа Division талаас)
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }

    void print() const {
        cout << "Division: " << DivisionName;
    }
};



/*
 * JobDescription class:
 *  - Ажилтны гүйцэтгэх үүрэг, албан тушаалын тодорхойлолт.
 *  - Employee-тэй 1..n харьцаатай: нэг ажилтан олон үүрэгтэй байж болно.
 */
class JobDescription {
private:
    string Description;

public:
    JobDescription(const string& desc = "") : Description(desc) {}

    string getDescription() const { return Description; }
    void setDescription(const string& d) { Description = d; }

    void print() const {
        cout << Description;
    }
};



class Employee : public Person {
private:
    string CompanyID;
    string Title;
    string StartDate;

    Division* division;                         // 1 (заавал)
    vector<JobDescription*> jobs;               // 1..n
    Spouse* spouse;                             // 0..1
    vector<Child*> children;                    // 0..n

    static int count;                           // нийт Employee тоо

public:
    // Employee байгуулагч - заавал Division, 1 JobDescription өгнө
    Employee(string name = "Unknown",
             string ss = "000000",
             int age = 0,
             const string& companyID = "C000",
             const string& title = "Employee",
             const string& startDate = "2020-01-01",
             Division* div = nullptr,
             JobDescription* firstJob = nullptr)
        : Person(name, ss, age),
          CompanyID(companyID),
          Title(title),
          StartDate(startDate),
          spouse(nullptr) {

        // Hoolbogdoh Division baihgui bol default uusgene
        if (div == nullptr) {
            division = new Division("Default Division");
        } else {
            division = div;
        }

        // Hoolbogdoh JobDescription baihgui bol default uusgene
        if (firstJob == nullptr) {
            firstJob = new JobDescription("Default Job");
        }

        // Job-oo nemne
        this->addJob(firstJob);

        // Division-d ene ajiltniig nemne
        division->addEmployee(this);

        ++count;
    }

    ~Employee() override {}

    // static getter - нийт Employee тоог буцаана
    static int getCount() { return count; }

    // Гишүүн функцүүд
    string getCompanyID() const { return CompanyID; }
    string getTitle() const { return Title; }
    string getStartDate() const { return StartDate; }

    void setCompanyID(const string& id) { CompanyID = id; }
    void setTitle(const string& t) { Title = t; }
    void setStartDate(const string& d) { StartDate = d; }

    void setDivision(Division* div) {
        division = div;
        if (division) {
            division->addEmployee(this);
        }
    }

    // 0..1 Spouse
    void setSpouse(Spouse* s) {
        spouse = s;
    }

    bool hasSpouse() const {
        return spouse != nullptr;
    }

    // 0..n Child
    void addChild(Child* c) {
        children.push_back(c);      // push_back ашиглаж байна
    }

    const vector<Child*>& getChildren() const {
        return children;
    }

    // 1..n JobDescription
    void addJob(JobDescription* job) {
        this->jobs.push_back(job);  
    }

    const vector<JobDescription*>& getJobs() const {
        return jobs;
    }

    // Бүх мэдээллээ хэвлэх
    void printAllInfo() const {
        cout << "================ Employee ================\n";
        Person::printBasicInfo();
        cout << "\nCompanyID: " << CompanyID
             << ", Title: " << Title
             << ", Start date: " << StartDate << "\n";

        cout << "Division: ";
        if (division) cout << division->getDivisionName();
        else cout << "None";
        cout << "\n";

        cout << "Job descriptions (" << jobs.size() << "): ";
        for (size_t i = 0; i < jobs.size(); ++i) {
            jobs[i]->print();
            if (i + 1 < jobs.size()) cout << ", ";
        }
        cout << "\n";

        if (spouse) {
            cout << "Spouse: ";
            spouse->printBasicInfo();
            cout << "\n";
        } else {
            cout << "Spouse: (none)\n";
        }

        cout << "Children (" << children.size() << "):\n";
        for (const Child* ch : children) {
            cout << "  - ";
            ch->printBasicInfo();
            cout << "\n";
        }
    }
};

// Static гишүүн хувьсагчийн анхны утгад шилжүүллээ.
int Employee::count = 0;



int main() {
    // Division-ууд
    Division it("IT Division");
    Division hr("HR Division");

    // JobDescription-ууд
    JobDescription dev("Developer");
    JobDescription lead("Team Lead");
    JobDescription hrSpec("HR Specialist");

    // Employee-ууд (дор хаяж 1 JobDescription, 1 Division)
    Employee e1("Bold", "UK95122136", 30, "C001", "Developer", "2020-01-10", &it, &dev);
    Employee e2("Sarnai", "JK97072137", 28, "C002", "Team Lead", "2019-05-20", &it, &lead);
    Employee e3("Naran", "BD90022138", 35, "C003", "HR Specialist", "2018-03-15", &hr, &hrSpec);

    // e2-д нэмж job өгье (1..n)
    e2.addJob(&dev); // нэг хүн хэд хэдэн үүрэгтэй байж болно

    // Spouse-ууд (0..1)
    Spouse s1("Tungalag", "SP98017021", 27, "2016-06-15");
    Spouse s3("Bilegt", "PU92040621", 33, "2012-09-10");

    e1.setSpouse(&s1);  // e1 – гэр бүлтэй
    // e2 – ганц бие (spouse оноогоогүй)
    e3.setSpouse(&s3);  // e3 – гэр бүлтэй

    // Children (0..n)
    Child c1("Temuulen", "TA20031816", 5, "Car");
    Child c2("Uuganbayr", "UB22052116", 3, "Lego");
    Child c3("Solongo", "SO18101816", 7, "Doll");

    e1.addChild(&c1);         // e1 – 2 huuhedtei
    e1.addChild(&c2);

    e3.addChild(&c3);         // e3 – 1 huuhedtei
    // e2 – huuhedgui

    // Бүх Employee-уудыг vector-т хадгалаад хэвлэх
    vector<Employee*> employees;
    employees.push_back(&e1);
    employees.push_back(&e2);
    employees.push_back(&e3);

    cout << "Total employees: " << Employee::getCount() << "\n\n";

    for (Employee* e : employees) {
        e->printAllInfo();
        cout << "\n";
    }


    Employee e1("Bold", "UK95122136", 30, "C001", "Developer", "2020-01-10", nullptr, &dev);

    // 2. Employee uusgeh ued Division zaasan (IT Division ashiglagdana)
    Employee e2("Sarnai", "JK97072137", 28, "C002", "Team Lead", "2019-05-20", &it, nullptr);

    cout << "\nTotal employees: " << Employee::getCount() << "\n\n";

    e1.printAllInfo();
    cout << "\n";
    e2.printAllInfo();
    cout << "\n";

    return 0;
}
