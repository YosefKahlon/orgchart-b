//
// Created by 97252 on 5/22/2022.
//


#include "Node.hpp"

ariel::Node::Node(std::string &title_, int degree_) {
    this->parent = nullptr;
    this->title = title_;
    this->size_ = 0;
    this->degree = degree_;
    this->pos = 0;
}

std::ostream &ariel::operator<<(std::ostream &os, const ariel::Node &output) {
    if ((&output) != nullptr) {
        os << output.title;
        return os;
    }
    return os;
}


int ariel::Node::size() const {
    return this->size_;
}

int ariel::Node::getDegree() const {
    return this->degree;
}

const std::vector<ariel::Node *> &ariel::Node::getChild() const {
    return this->child;
}



void ariel::Node::setTitle(const std::string &title) {
    this->title = title;
}

ariel::Node *ariel::Node::getParent() const {
    return parent;
}

void ariel::Node::setParent(ariel::Node *parent) {
    this->parent = parent;
}

void ariel::Node::setSize(int size) {
    this->size_ = size;
}

void ariel::Node::setChild(const std::vector<Node *> &child) {
    this->child = child;
}

void ariel::Node::setDegree(int degree) {
    this->degree = degree;
}

const std::string& ariel::Node::getTitle() const {
    return (this->title);
}

int ariel::Node::getSize() const {
    return size_;
}

int ariel::Node::getPos() const {
    return this->pos;
}

void ariel::Node::setPos(size_t pos_) {
    this->pos = pos_;
}


