//
// Created by 97252 on 5/22/2022.
//

#ifndef ORGCHART_B_NODE_HPP
#define ORGCHART_B_NODE_HPP


#include <vector>
#include <string>


namespace ariel {
    class Node {

    private:
        std::vector<Node *> child;
        Node *parent;
        int size_;
        int degree;
        std::string title;
        size_t pos ;
       size_t child_index;
       bool print;

    public:
        Node(std::string &title_, int degree_);

        bool isPrint() const;

        void setPrint(bool print_);

        friend std::ostream &operator<<(std::ostream &os, const Node &output);

        const  std::string& getTitle() const;

        int size() const;

        size_t getChildIndex() const;

        void setChildIndex(size_t childIndex);

        int getPos() const;

        void setPos(size_t pos_);

        int getDegree() const;

        void setDegree(int degree);

        void setChild(const std::vector<Node *> &child);

       const  std::vector<Node *> &getChild() const ;

        void setTitle(const std::string &title);

        Node *getParent() const;

        void setParent(Node *parent);

        void setSize(int size);

        int length() const;

        char at(int i ) const;

    };
}

#endif //ORGCHART_B_NODE_HPP
