#include "../include/Set.h"

using namespace std;

Set::Set(){
    start = NULL;
    end = NULL;
}

Set::~Set(){
    delete start;
    delete end;
}

Node* Set::get_start(){
    return start;
}

Node* Set::get_end(){
    return end;
}

void Set::set_start(Node* s){
    start = s;
}

void Set::set_end(Node* e){
    end = e;
}

// Element operations

void Set::insert(string word){
    if(start == NULL){
        start = new Node(word);
        end = start;
    }else{
        if(this->search(word) == NULL){
            Node* new_node = new Node(word);
            new_node->set_previous(end);
            end->set_next(new_node);
            end = new_node;
        }
    }
}

Node* Set::search(string word){
    if(start == NULL){
        return NULL;
    }
    Node* temp = start;
    while(temp != NULL){
        if(temp->get_element() == word){
            return temp;
        }
        temp = temp->get_next();
    }
    return NULL;
}

void Set::remove(string word){
    Node* node = this->search(word);
    if(node != NULL){
        if(start == end){
            start = NULL;
            end = NULL;
        }else if (node == start){
            node->get_next()->set_previous(NULL);
            start = node->get_next();
        }else if (node == end){
            node->get_previous()->set_next(NULL);
            end = node->get_previous();
        }else{
            node->get_previous()->set_next(node->get_next());
            node->get_next()->set_previous(node->get_previous());
        }
    }
}

void Set::print(){
    if(start == NULL){
        cout << "{ }";
    }else{
        Node* temp = start;
        cout << "{ ";
        while (temp != NULL){
            if(temp != end){
                cout << temp->get_element() << ", ";
            }else{
                cout << temp->get_element() << " ";
            }
            temp = temp->get_next();
        }
        cout << "}";
    }
}

void Set::swap_elements(string elem1, string elem2){
    if (this->search(elem1) != NULL && this->search(elem2) != NULL){
        Node* temp1 = this->search(elem1);
        Node* temp2 = this->search(elem2);

        temp1->set_element(elem2);
        temp2->set_element(elem1);
    }
}

void Set::sort(){
    Node* temp_start = start;
    Node* temp_end = end;
    bool swapped = true;

    if(start == NULL || start == end){
        return;
    }else if(start->get_next() == end){
        if(start->get_element() > end->get_element()){
            this->swap_elements(start->get_element(), end->get_element());
        }
        return;
    }else{
        while(swapped){
            swapped = false;
            while(temp_start->get_next() != NULL){
                if (temp_start->get_element() > temp_start->get_next()->get_element()){
                    this->swap_elements(temp_start->get_element(), temp_start->get_next()->get_element());
                    swapped = true;
                }
                temp_start = temp_start->get_next();
            }
            temp_start = start;
        }
    }
}

// Set operations

Set* Set::union_(Set* B){
    Set* new_set = new Set();
    Node* temp_this = start;
    Node* temp_B = B->get_start();

    if(start == NULL && temp_B != NULL){
        return B;
    }else if(temp_B == NULL && start != NULL){
        return this;
    }else if(start == NULL && temp_B == NULL){
        return new_set;
    }

    while(temp_this != NULL){
        new_set->insert(temp_this->get_element());
        temp_this = temp_this->get_next();
    }
    while(temp_B != NULL){
        new_set->insert(temp_B->get_element());
        temp_B = temp_B->get_next();
    }
    return new_set;
}

Set* Set::intersection(Set* B){
    Set* new_set = new Set();
    Node* temp_this = start;
    Node* temp_B = B->get_start();

    if(start == NULL || temp_B == NULL){
        return new_set;
    }

    while(temp_this != NULL){
        if(B->search(temp_this->get_element()) != NULL){
            new_set->insert(temp_this->get_element());
        }
        temp_this = temp_this->get_next();
    }
    return new_set;
}

Set* Set::difference(Set* B){
    Set* new_set = new Set();
    Node* temp_this = start;
    Node* temp_B = B->get_start();
    Node* temp_inter = this->intersection(B)->get_start();

    if(start == NULL){
        return this;
    }else if (temp_B == NULL){
        return this;
    }else if (temp_inter == NULL){
        return this;
    }

    while(temp_this != NULL){
        if (this->search(temp_this->get_element()) != NULL &&
            B->search(temp_this->get_element()) == NULL){
            new_set->insert(temp_this->get_element());
        }
        temp_this = temp_this->get_next();
    }
    return new_set;
}

Set* Set::symmetric_difference(Set* B){
    Node* temp_this = start;
    Node* temp_B = B->get_start();
    Node* temp_inter = this->intersection(B)->get_start();
    Set* union_set = this->union_(B);

    if(start == NULL){
        return B;
    }else if(temp_B == NULL){
        return this;
    }else if(temp_inter == NULL){
        return union_set;
    }

    while(temp_inter != NULL){
        union_set->remove(temp_inter->get_element());
        temp_inter = temp_inter->get_next();
    }
    return union_set;
}