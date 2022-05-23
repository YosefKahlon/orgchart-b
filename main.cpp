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




    OrgChart chart2;
   (chart2.add_root("Owner"));
   (chart2.add_root("New_Owner"));

   (chart2.add_sub("New_Owner" , "General_Manager"));
   (chart2.add_sub("New_Owner" , "Share_Holders"));
   (chart2.add_sub("New_Owner" , "Head_of_operations"));
   (chart2.add_sub("General_Manager" , "Head_Coach"));
   (chart2.add_sub("General_Manager" , "Assistant_Coach"));
   (chart2.add_sub("Head_of_operations" , "Team_Doctor"));
   (chart2.add_sub("Head_of_operations" , "Head_Scout"));
   (chart2.add_sub("Share_Holders" , "Sub_Share_Holder1"));
   (chart2.add_sub("Share_Holders" , "Sub_Share_Holder2"));

   (chart2.add_sub("Head_Coach" , "Captain"));
   (chart2.add_sub("Team_Doctor" , "Team_Physiotherapist"));

    vector<string> pre_order;
    for (auto it = chart2.begin_preorder(); it != chart2.end_preorder(); ++it) {
        pre_order.push_back(*it);
    }
//
//    bool a = (pre_order.at(0), "Stan_Kronke");
//    bool a1 = (pre_order.at(1), "General_Manager");
//    bool a2 = (pre_order.at(2), "Head_Coach");
//    bool a3 = (pre_order.at(3), "Captain");
//    bool a0 = (pre_order.at(4), "Assistant_Coach");
//    bool a4 = (pre_order.at(5), "Water_Boy");
//    bool a5 = (pre_order.at(6), "Share_Holders");
//    bool a6 = (pre_order.at(7), "Sub_Share_Holder1");
//    bool a7 = (pre_order.at(8), "Sub_Share_Holder2");
//    bool a8 = (pre_order.at(9), "Head_of_operations");
//    bool a9 = (pre_order.at(10), "Team_Doctor");
//    bool a10 = (pre_order.at(11), "Team_Physiotherapist");
//    bool a11 = (pre_order.at(12), "Head_Scout");


}
