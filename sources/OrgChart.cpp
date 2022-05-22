//
// Created by 97252 on 5/13/2022.
//

#include "OrgChart.hpp"

#include <utility>
#include <algorithm>
#include "iostream"

using namespace ariel;

OrgChart::OrgChart() {
    this->root = nullptr;
}
    OrgChart::~OrgChart() {
        for(const auto& x : map_degree){
            for (const auto & i : x.second) {
                delete  i;
            }
        }
    }




/**
 * Create new root if tree is not initialize yet
 * else : replace the name on the root
 *
 */
OrgChart &OrgChart::add_root(string root_) {

    if (this->root == nullptr) {
        this->root = new Node(root_, 0);
        this->map.insert({root_, this->root}); //[root name , Node*]
        this->map_degree.insert({0, {this->root}});// [root degree , Node*]
        this->root->setParent(nullptr);
        this->root->setSize(root_.length());


    } else {
        this->map.erase(this->root->getTitle());
        this->map.insert({root_, this->root}); //[root name , Node*]
        this->root->setTitle(root_);
        this->root->setSize(root_.length());
    }

    return *this;
}


OrgChart &OrgChart::add_sub(const string &root_, string other) {

    if (this->map.find(root_) == this->map.end()) {
        throw std::invalid_argument("First argument is not exist !");
    }


    Node *child_ = new Node(other, this->map.at(root_)->getDegree() + 1);


    child_->setParent((this->map.at(root_)));
    child_->setSize(other.length());

    std::vector<Node *> temp = this->map.at(root_)->getChild();
    //  this->map.at(root_)->getChild().push_back(child_);
    temp.push_back(child_);
    this->map.at(root_)->setChild(temp);

    this->map.insert({other, child_});


    if (map_degree.find(child_->getDegree()) == map_degree.end()) {
        std::vector<Node *> v;
        v.push_back(child_);
        child_->setPos((unsigned long )v.size() - 1);
        this->map_degree.insert({child_->getDegree(), v});
    } else {

        if (child_->getDegree() >= 2) {
            for (int i = 0; i < this->map_degree.at(child_->getDegree()).size(); ++i) {
                if (child_->getParent()->getPos() < this->map_degree.at(child_->getDegree()).at((size_t)i)->getParent()->getPos()) {
                    auto pos = this->map_degree.at(child_->getDegree()).begin() + i;
                    this->map_degree.at(child_->getDegree()).insert(pos, child_);
                    child_->setPos((unsigned long )i);
                    i = this->map_degree.at(child_->getDegree()).size();
                } else if (child_->getParent()->getPos() == this->map_degree.at(child_->getDegree()).at((size_t)i)->getParent()->getPos()) {
                    auto pos = this->map_degree.at(child_->getDegree()).begin() + i + 1;
                    this->map_degree.at(child_->getDegree()).insert(pos, child_);
                    child_->setPos((unsigned long )i + 1);
                    i = this->map_degree.at(child_->getDegree()).size();
                } else {
                    continue;
                }

            }
        }else {
            this->map_degree.at(child_->getDegree()).push_back(child_);
           child_->setPos(  (unsigned long )this->map_degree.at(child_->getDegree()).size()-1);
        }


    }


    return *this;
}


std::ostream &ariel::operator<<(std::ostream &os, const OrgChart &output) {


    os << "----- \n";

    for (const auto &x: output.map_degree) {
        for (const auto& i : output.map_degree.at(x.first)) {
            os << i->getTitle() << ", ";
        }
        os << "\n-----\n";
    }



    return os;
}

OrgChart::level_order OrgChart::begin_level_order() const {
    return level_order{*this, this->root};
}

OrgChart::level_order OrgChart::end_level_order() const {
    if (this->map.empty()){
        throw std::invalid_argument("Empty OrgChart !");
    }


    auto it = level_order(*this, nullptr);
    return it;

}


OrgChart::level_order OrgChart::begin() const {
    return level_order{*this, this->root};
}


//no need to check the end
OrgChart::level_order OrgChart::end() const {
    if (this->map.empty()){
        throw std::invalid_argument("Empty OrgChart !");
    }


    auto it = level_order(*this, nullptr);
    return it;
}

OrgChart::reverse_Order OrgChart::begin_reverse_order() const {
    return OrgChart::reverse_Order(*this, this->map_degree.at(map_degree.size() - 1).at(0));
}

OrgChart::reverse_Order OrgChart::reverse_order() const {
    if (this->map.empty()){
        throw std::invalid_argument("Empty OrgChart !");
    }
    return OrgChart::reverse_Order(*this, nullptr);
}

OrgChart::pre_order OrgChart::begin_preorder() const {
    return OrgChart::pre_order(*this, this->root);
}

OrgChart::pre_order OrgChart::end_preorder() const {
    if (this->map.empty()){
        throw std::invalid_argument("Empty OrgChart !");
    }

    return OrgChart::pre_order(*this, nullptr);
}

OrgChart &OrgChart::operator=(const OrgChart &other) {
    if(this != &other){
        org_delete();
        org_copy(other);
    }
    return *this;

}


OrgChart::OrgChart(const OrgChart &other) {
    org_copy(other);
}

OrgChart::OrgChart(OrgChart &&other) noexcept {
    this->root = other.root;
    other.root = nullptr;
}

OrgChart &OrgChart::operator=(OrgChart &&other) noexcept {
  if (this != &other){
      org_delete();
      this->root = other.root;
      other.root = nullptr;
  }
    return *this;
}



void OrgChart::org_copy(const OrgChart &other) {
    if(other.root == nullptr){
        this->root = nullptr;
        return;
    }
    this->root = nullptr;
    this->add_root(other.root->getTitle());


    std::unordered_map<string , std::vector<Node*>> vec;

    for(const auto& x: other.map){
        vec.at(x.first) =  x.second->getChild();

    }

    for(const auto& x: vec){
        for (int i = 0; i < x.second.size() ; ++i) {
         //   std::cout <<  "root "<<  x.first << "child" <<   x.second.at(i)->getTitle() <<std:: endl;
            this->add_sub(x.first,x.second.at((unsigned long )i)->getTitle());
        }
    }



}

void OrgChart::org_delete() {

    for (const auto& x: this->map_degree) {
        for (const auto & i : x.second) {
            delete i;
        }

    }
}






