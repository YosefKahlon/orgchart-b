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




    cout <<"\n----------- catch exception ---------\n";

    OrgChart orgChart;
    try {
        orgChart.add_sub("no root", "test");

    } catch (exception& e) {
        cout << e.what() << endl;
    }


    cout <<"\n-----------inti OrgChart ---------\n";

    orgChart.add_root("root").
            add_sub("root", "child_a").
            add_sub("root", "child_b").
            add_sub("root", "child_c").
            add_sub("root","child_d").
            add_sub("root","child_e").
            add_sub("root","child_f");


    cout<< orgChart <<endl;

    cout <<"\n-----------revers iterator---------\n";


    /**
     *                         root
     *                          |
     *       ----   --------  -------   ------   ------
     *     |      |         |         |        |       |
     *  child_a, child_b, child_c, child_d, child_e, child_f
     *
     *
     */



    for(auto it = orgChart.begin_reverse_order() ; it != orgChart.reverse_order(); ++it){
        cout << (*it) <<", ";
}

    cout << endl;

    cout <<"\n--------- add child for child of root --------\n";

    orgChart.add_sub("child_a", "child_a_a");
    orgChart.add_sub("child_a", "child_a_b");
    orgChart.add_sub("child_f", "child_f_a");
    orgChart.add_sub("child_f", "child_f_b");

    cout<<orgChart <<endl;


    cout <<"\n--------- level order  --------\n";

    /**
 *                         root
 *                          |
 *       ----   --------  -------   ------   ------
 *     |      |         |         |        |       |
 *  child_a, child_b, child_c, child_d, child_e, child_f
 *    |                                            |
 *  ----------  -------                   -------    --------
 *            |                                    |
 *  child_a_a, child_a_b                  child_f_a, child_f_b,
 *
 *
 */




    for(auto it = orgChart.begin_level_order() ; it != orgChart.end_level_order(); ++it){
        cout << (*it) <<", ";
    }

    cout << endl;



    orgChart.add_root("root_$_");

    /**
     *                        root_$_
     *                          |
     *       ----   --------  -------   ------   ------
     *     |      |         |         |        |       |
     *  child_a, child_b, child_c, child_d, child_e, child_f
     *    |                                            |
     *  ----------  -------                   -------    --------
     *            |                                    |
     *  child_a_a, child_a_b                  child_f_a, child_f_b,
     *
     *
     */




    cout <<"\n--------- pre order order  --------\n";

    for(auto x = orgChart.begin_preorder(); x != orgChart.end_preorder() ; ++x){
        cout << (*x) <<", ";
    }
    cout << endl;
//

}

