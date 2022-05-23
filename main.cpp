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

    OrgChart organization;
    organization.add_root("CEO")
            .add_sub("CEO", "CTO")      // Now the CTO is subordinate to the CEO
            .add_sub("CEO", "CFO")         // Now the CFO is subordinate to the CEO
            .add_sub("CEO", "COO")         // Now the COO is subordinate to the CEO
            .add_sub("CTO", "VP_SW") // Now the VP Software is subordinate to the CTO
            .add_sub("COO", "VP_BI");      // Now the VP_BI is subordinate to the COO


       cout <<  " \n------------ \n " ;
    for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
        cout << (*it) << " " ;
    }  // prints: CEO CTO VP_SW CFO COO VP_BI
    cout <<  "\n ------|------ \n " ;


}
