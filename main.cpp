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

    OrgChart org;
    OrgChart org_empty;
    OrgChart org_double_names;
    /* create normal tree */

    org.add_root("dana");
    org.add_root("shir");
    org.add_sub("shir", "tal");

    org.add_sub("shir", "sapir");
    org.add_sub("sapir", "dan");
    org.add_sub("dan", "ziv");
    org.add_sub("tal", "avi");
    org.add_sub("tal", "yossi");
    org.add_sub("shir", "ido");
    org.add_sub("ziv", "shaked");
    org.add_sub("ziv", "ofer");


    /* create tree with 1 name*/
  org_double_names.add_root("adi");
    for (size_t i = 0; i < 11; i++)
    {
      org_double_names.add_sub("adi", "adi");
    }


    std::vector<std::string> v = {"shir", "tal", "sapir", "ido", "avi", "yossi", "dan", "ziv", "shaked", "ofer"};
    size_t i = 0;
    for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){
//        CHECK_EQ(*it, v.at(i++));
        cout << (*it)  << " vec " << v.at(i++) <<endl;

    }

    cout <<  " ------------- "  <<endl;

    for(auto it = org_double_names.begin_level_order(); it != org_double_names.end_level_order(); ++it){
        bool  b = (*it == "adi");
        cout << b << ", ";
    }
    cout <<  "\n ------------- "  <<endl;

    std::vector<int> nums = {4, 3, 5, 3, 3, 5, 3, 3, 6, 4};
    int j = 0;
    for(auto it = org.begin_level_order(); it != org.end_level_order(); ++it){

        cout << (*it) << " ->" <<  it->size() << " vec " << nums.at((size_t)j)<<endl;
        j++;
    }


}
