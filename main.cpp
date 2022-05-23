#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;

#include "sources/OrgChart.hpp"
using namespace ariel;

int main() {
    class Person {
    public:
        string name;
        int age;

        Person(string Name, int Age) : name(Name), age(Age) {}

        bool operator==(Person &p1) {
            return this->name == p1.name;
        }
    };
    //instantiate People
    Person Great_GrandFather("Great_GrandFather", 85);
    Person Grandfather("GrandFather", 65);
    Person Father("Father", 45);
    Person Uncle("Uncle", 43);
    Person Aunt("Aunt", 43);
    Person Son("Son", 20);
    Person Daughter("Daughter", 18);
    Person Cousin("Cousin", 15);

    OrgChart chart1;

    chart1.add_root(Aunt.name);
    chart1.add_root(Great_GrandFather.name);

    chart1.add_sub(Great_GrandFather.name, Grandfather.name);
    chart1.add_sub(Grandfather.name, Father.name);
    chart1.add_sub(Grandfather.name, Uncle.name);
    chart1.add_sub(Grandfather.name, Aunt.name);

    chart1.add_sub(Father.name, Son.name);
    chart1.add_sub(Father.name, Daughter.name);
    chart1.add_sub(Uncle.name, Cousin.name);

    // test level order
    vector<string> lvl_order;
    for (auto it = chart1.begin_level_order(); it != chart1.end_level_order(); ++it) {
        lvl_order.push_back(*it);
    }

    bool b1 =lvl_order.at(0)== Great_GrandFather.name;
    cout << b1 << endl;
    bool b2 = lvl_order.at(1)== Grandfather.name;
    cout << b2 << endl;
    bool b3 = lvl_order.at(2)== Father.name;
    cout << b3 << endl;
    bool b4 =lvl_order.at(3) == Uncle.name;//
    cout << b4 << endl;
    cout << lvl_order.at(3) <<endl;
    bool b5 =lvl_order.at(4)== Aunt.name;//
    cout << b5 << endl;
    cout << lvl_order.at(4) <<endl;;
    bool b6 =lvl_order.at(5)== Son.name;
    cout << b6 << endl;
    bool b7 =lvl_order.at(6)== Daughter.name;
    cout << b7 << endl;
    bool b8 =lvl_order.at(7)== Cousin.name;
    cout << b8 << endl;





}
