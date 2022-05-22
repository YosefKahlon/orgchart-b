//
// Created by 97252 on 5/16/2022.
//

#include "OrgChart.hpp"
#include "iostream"

using namespace ariel;


//--------------------------Iterator------------------------------------
string OrgChart::Iterator::operator*() const { // was this string &OrgChart::Iterator::operator*()
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
//---------------------------level_order---------------------------------



OrgChart::level_order OrgChart::level_order::operator++(int) {
    auto it = *this;
    ++(*this);
    return it;
}


const OrgChart::level_order &OrgChart::level_order::operator++() {

//    std::cout << this->pointer_to_current_node->getTitle() << std::endl;
    if (index < this->org.map_degree.at(this->pointer_to_current_node->getDegree()).size()) {
        this->pointer_to_current_node = this->org.map_degree.at(this->pointer_to_current_node->getDegree()).at(index);
        index++;
    } else {

        index = 0;
        int temp_degree = this->pointer_to_current_node->getDegree();
        temp_degree++;
        this->pointer_to_current_node->setDegree(temp_degree);
        if (find_map(this->pointer_to_current_node->getDegree()) == "Element Present" &&
            index < this->org.map_degree.at(this->pointer_to_current_node->getDegree()).size()) {
            this->pointer_to_current_node = this->org.map_degree.at(this->pointer_to_current_node->getDegree()).at(
                    index);
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


//----------------------------reverse_Order----------------------------------------


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


//----------------------------pre_order----------------------------------------


OrgChart::pre_order OrgChart::pre_order::operator++(int) {
    auto copy = *this;
    ++(*this);
    return copy;
}

OrgChart::pre_order &OrgChart::pre_order::operator++() {


    if (!stack.empty()) {
        this->pointer_to_current_node = this->stack.top();
        this->stack.pop();

        if (this->pointer_to_current_node != nullptr) {
            //
            std::vector<Node *> preorder = this->pointer_to_current_node->getChild();
            for (size_t i = preorder.size() - 1; i >= 0; i--) {

                stack.push(preorder.at( i));
            }
        }
    } else {
        this->pointer_to_current_node = nullptr;
    }
    return *this;
}
