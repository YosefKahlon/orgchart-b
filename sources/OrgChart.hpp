//
// Created by 97252 on 5/13/2022.
//

#ifndef ORGCHART_A_ORGCHART_HPP
#define ORGCHART_A_ORGCHART_HPP

#include <utility>
#include <stack>
#include <algorithm>
#include <iostream>
#include "vector"
#include "string"
#include "unordered_map"
#include "Node.hpp"
using std::string;
namespace ariel {


    class OrgChart {
        //-----------------------OrgChart---------------------------------


        friend class level_order;
        friend class reverse_order;
        friend class Node;
        friend class pre_order;

    private:

        Node *root{};
        std::unordered_map<std::string, Node *> map;
        std::unordered_map<int, std::vector<Node *>> map_degree;


    public:
        OrgChart();
        ~OrgChart() ;
        OrgChart(const OrgChart & other);
        OrgChart& operator=(const OrgChart& other);
        OrgChart(OrgChart&& other)noexcept;
        OrgChart& operator=(OrgChart&& other)noexcept;


        OrgChart &add_root(string root_);

        OrgChart &add_sub(const string &root_, string other);



        // Node* find_Node(const string& name);



        class Iterator{
        protected:
            Node *pointer_to_current_node;
            const OrgChart &org;


        public:
         Iterator(const OrgChart &organization, Node *ptr) :
                    org(organization),
                    pointer_to_current_node(ptr){}



              string operator*() const; // was this -->  string &operator*();
            const Node *operator->() const;



            bool operator==(const Iterator &) const;
            bool operator!=(const Iterator &) const;


        };



        class level_order : public Iterator{

        private:
            size_t index;
            int de;
        public:
           level_order(const OrgChart &organization, Node *ptr) :
                    Iterator(organization, ptr), index(1) ,de(0) {}

             level_order operator++(int) ;
           const level_order &operator++() ;

            std::string find_map(int degree);
        };


       level_order begin_level_order() const ;

      level_order end_level_order() const ;


//    public:
        class reverse_Order  : public  Iterator{

        private:
            int index;
            int de;

        public:


            reverse_Order(const OrgChart &organization, Node *ptr) :
                    Iterator(organization, ptr),de(organization.map_degree.size() - 1), index(1) {}

           reverse_Order operator++(int);
            reverse_Order &operator++();


        };

        reverse_Order begin_reverse_order() const;
        reverse_Order reverse_order() const;




        class pre_order : public Iterator {
        private:

            std::stack<Node *> stack;
            int index;

        public:

            pre_order(const OrgChart &organization, Node *ptr) :
                    Iterator(organization, ptr) ,index(0) {

//                stack.push(nullptr);
//                if (pointer_to_current_node != nullptr) {
//                    stack.pop();
//                    std::vector<Node *> preorder = this->pointer_to_current_node->getChild();
//
//                    for (int i = preorder.size() - 1; i >= 0; i--) {
//                        stack.push(preorder.at((unsigned long) i));
//
//                    }
//
//                }

            }


             pre_order operator++(int);

            pre_order &operator++();


        };


        void set_entry_num(int num);

        int getEntryNum() const;

        pre_order begin_preorder() const;

        pre_order end_preorder() const;


        friend std::ostream &operator<<(std::ostream &os, const OrgChart &output );

        level_order begin() const;

        level_order end() const;




        void org_copy(const OrgChart &other);

        void org_delete();
    };


}

#endif //ORGCHART_A_ORGCHART_HPP
