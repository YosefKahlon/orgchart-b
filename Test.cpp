////
//// Created by 97252 on 5/18/2022.
////
//
//
//#include "doctest.h"
//#include "sources/OrgChart.hpp"
//#include "iostream"
//#include "stack"
//using namespace ariel;
//
//
//TEST_CASE ("Test 1 ") {
//
//    OrgChart organization;
//
//            CHECK_NOTHROW(organization.add_root("CEO"));
//            CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));// Now the CTO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));// Now the CFO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CEO", "COO"));// Now the COO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));// Now the VP Software is subordinate to the CTO
//            CHECK_NOTHROW(organization.add_sub("COO", "VP_BI")); // Now the VP_BI is subordinate to the COO
//
//    //root is not exist
//            CHECK_THROWS(organization.add_sub("unknown", "CTO"));
//            CHECK_THROWS(organization.add_sub("unknown2", "CFO"));
//            CHECK_THROWS(organization.add_sub("unknown3", "VP_BI"));
//
//    //VP_BI is child of COO
//            CHECK_THROWS(organization.add_sub("CEO", "CTO"));// Now the CTO is subordinate to the CEO
//            CHECK_THROWS(organization.add_sub("CEO", "CFO"));// Now the CFO is subordinate to the CEO
//            CHECK_THROWS(organization.add_sub("CEO", "COO"));//
//
//
//}
//
//TEST_CASE ("Test 2 ") {
//
//    OrgChart organization;
//
//            CHECK_NOTHROW(organization.add_root("CEO"));
//            CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));// Now the CTO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));// Now the CFO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CEO", "COO"));// Now the COO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW"));// Now the VP Software is subordinate to the CTO
//            CHECK_NOTHROW(organization.add_sub("COO", "VP_BI")); // Now the VP_BI is subordinate to the COO
//
//    std::vector<string> level{"CEO", "CTO", "CFO", "COO", "VP_SW", "VP_BI"};
//    std::vector<string> pre{"CEO", "CTO", "VP_SW", "CFO", "COO ","VP_BI"};
//
//
//    std::stack<std::string> stack;
//
//
//    size_t i=0;
//    for (auto it = organization.begin_level_order(); it != organization.end_level_order(); ++it) {
//        CHECK_EQ((*it) , level.at(i++));
//
//
//    }
//
//    i = 0;
//    for (auto element: organization) { // this should work like level order
//                CHECK_EQ((element) , level.at(i++));
//                stack.push(element);
//    }
//
//
//    for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it) {
//                CHECK_EQ((*it), stack.top());
//                stack.pop();
//    }
//
//    i=0;
//    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
//
//                CHECK_EQ((*it), pre.at(i++));
//
//    }
//
//
//    }
//
//    TEST_CASE("Test 3 "){
//
//    OrgChart organization;
//
//            CHECK_NOTHROW(organization.add_root("A"));
//            CHECK_NOTHROW(organization.add_sub("A", "BB"));// Now the CTO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("A", "CCC"));// Now the CFO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("A", "DDDD"));// Now the COO is subordinate to the CEO
//            CHECK_NOTHROW(organization.add_sub("BB", "EEEEE"));// Now the VP Software is subordinate to the CTO
//            CHECK_NOTHROW(organization.add_sub("CCC", "FFFFFF")); // Now the VP_BI is subordinate to the COO
//
//            int i = 0;
//    for (auto it = organization.begin_preorder(); it != organization.end_preorder(); ++it) {
//                CHECK_EQ((*it).size(), i++ );
//
//    }
//
//
//}