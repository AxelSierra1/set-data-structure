#include "../include/Node.h"

Node::Node(string word) {
    element = word;
    next = NULL;
    previous = NULL;
}

Node::~Node(){
    delete next;
    delete previous;
}

string Node::get_element(){
    return element;
}

Node* Node::get_next(){
    return next;
}

Node* Node::get_previous(){
    return previous;
}

void Node::set_element(string word){
    element = word;
}

void Node::set_next(Node* nxt){
    next = nxt;
}

void Node::set_previous(Node* prev){
    previous = prev;
}
