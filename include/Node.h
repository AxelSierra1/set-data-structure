#include <iostream>
using namespace std;

class Node{
    private:
        string element;
        Node* next;
        Node* previous;

    public:
        Node(string);
        ~Node();

        string get_element();
        Node* get_next();
        Node* get_previous();
        void set_element(string);
        void set_next(Node*);
        void set_previous(Node*);
};
