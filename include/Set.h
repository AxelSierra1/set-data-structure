#include "../src/Node.cpp"

class Set{
    private:
        Node* start;
        Node* end;

    public:
        Set();
        ~Set();

        Node* get_start();
        Node* get_end();
        void set_start(Node*);
        void set_end(Node*);

        // Operations
        void insert(string);
        Node* search(string);
        void remove(string);
        void sort();
        void print();

        void swap_elements(string, string);

        Set* union_(Set*);
        Set* intersection(Set*);
        Set* difference(Set*);
        Set* symmetric_difference(Set*);
};