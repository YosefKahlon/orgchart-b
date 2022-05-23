//
// Created by 97252 on 5/16/2022.
//

#include "OrgChart.hpp"
#include "iostream"

using namespace ariel;


/**--------------------------Iterator------------------------------------
implementation of  the methods for using iterator .
-------------------------------------------------------------------- **/
string OrgChart::Iterator::operator*() const {
    return (this->pointer_to_current_node->getTitle());
}

const ariel::Node *OrgChart::Iterator::operator->() const {
    return (this->pointer_to_current_node);
}

bool OrgChart::Iterator::operator==(const OrgChart::Iterator &other) const {
    return this->pointer_to_current_node == other.pointer_to_current_node;
}

bool OrgChart::Iterator::operator!=(const OrgChart::Iterator &other) const {
    return this->pointer_to_current_node != other.pointer_to_current_node;
}


/**--------------------------level_order------------------------------------
  Postfix - copy then increase   , Prefix - Go through the map by levels (from up to down )
---------------------------------------------------------------------------**/
OrgChart::level_order OrgChart::level_order::operator++(int) {
    auto copy = *this;
    ++(*this);
    return copy;
}


const OrgChart::level_order &OrgChart::level_order::operator++() {

    if (index < this->org.map_degree.at(this->de).size()) {
        this->pointer_to_current_node = this->org.map_degree.at(this->de).at(index);
        index++;
    } else {

        index = 0;
        this->de++;

        if (find_map(this->de) == "Element Present" &&
            index < this->org.map_degree.at(this->de).size()) {
            this->pointer_to_current_node = this->org.map_degree.at(this->de).at(index);
            index++;
        } else {
            this->pointer_to_current_node = nullptr;
        }
    }


    return *this;

}


std::string OrgChart::level_order::find_map(int degree) {
    if (this->org.map_degree.find(degree) == this->org.map_degree.end()) {
        return "Element Not Present";
    }
    return "Element Present";

}


/**--------------------------reverse_Order------------------------------------
  Postfix - copy then increase   , Prefix - Go through the map by levels (from down to up )
---------------------------------------------------------------------------**/
OrgChart::reverse_Order OrgChart::reverse_Order::operator++(int) {
    auto copy = *this;
    ++(*this);
    return copy;
}

OrgChart::reverse_Order &OrgChart::reverse_Order::operator++() {


    if (index < this->org.map_degree.at(this->de).size()) {
        this->pointer_to_current_node = this->org.map_degree.at(this->de).at((unsigned long) index);

        index++;
    } else {
        this->de--;
        if (this->de >= 0) {

            index = 0;

            if (this->org.map_degree.find(this->de) != this->org.map_degree.end() &&
                index < this->org.map_degree.at(this->de).size()) {
                this->pointer_to_current_node = this->org.map_degree.at(this->de).at((unsigned long) index);
                //   std::cout << this->org.map_degree.at(this->de).at(index)->title << std::endl;
                index++;
            } else {
                this->pointer_to_current_node = nullptr;
            }

        } else {
            this->pointer_to_current_node = nullptr;
        }
    }
    return *this;
}


/**--------------------------pre_order------------------------------------
  Postfix - copy then increase   , Prefix -
---------------------------------------------------------------------------**/

OrgChart::pre_order OrgChart::pre_order::operator++(int) {
    auto copy = *this;
    ++(*this);
    return copy;
}

OrgChart::pre_order &OrgChart::pre_order::operator++() {


//    if (!stack.empty()) {
//        this->pointer_to_current_node = this->stack.top();
//        this->stack.pop();
//
//        if (this->pointer_to_current_node != nullptr) {
//            //
//            std::vector<Node *> preorder = this->pointer_to_current_node->getChild();
//            size_t pre_size = ( preorder.size() - 1);
//            for (int i = pre_size; i >= 0; i--) {
//
//
//                stack.push(preorder.at( (unsigned  long)i));
//            }
//        }
//    } else {
//        this->pointer_to_current_node = nullptr;
//    }




    //root
    if (this->pointer_to_current_node == this->org.root) {
        if (this->pointer_to_current_node->getChild().empty()) {
            this->pointer_to_current_node = nullptr;
            return *this;
        }
        this->pointer_to_current_node = this->pointer_to_current_node->getChild().at(0);
        return *this;
    }

    if (this->pointer_to_current_node->getChild().empty()) {

        while (this->pointer_to_current_node->getParent()->getChild().at(
                this->pointer_to_current_node->getParent()->getChild().size() - 1) == this->pointer_to_current_node) {
            this->pointer_to_current_node = this->pointer_to_current_node->getParent();
            if (this->pointer_to_current_node->getParent() == nullptr) {
                this->pointer_to_current_node = nullptr;
                return *this;
            }
        }



        this->pointer_to_current_node = this->pointer_to_current_node->getParent()->getChild().at(
                (size_t) this->pointer_to_current_node->getChildIndex() + 1);

    } else {
        this->pointer_to_current_node = this->pointer_to_current_node->getChild().at(0);
        return *this;
    }


    return *this;
}
