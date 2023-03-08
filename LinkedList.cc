// Collection of nodes where each node contains a data field and a reference to next node

// Advantages: Size is not fixed, Insertion and deletion are cheap. Though not as cheap as std::vector for up to ~500,000 items.

// Disadvantages: Random access not allowed, have to access sequentially from start
// requires extra memory for the reference, reverse traversing not possible in original form, searching is costly O(n) time, sorting is costly)


#include <bits/stdc++.h>
#include <iostream>

class Linked_List{

    class Node{

        int data;

        Node* next_node;

        public:

            Node(){
            this->data = 0;
            this->next_node = NULL;
            }

            Node(int this_data){
            this->data = this_data;
            this->next_node = NULL;
            }

            void set_data(int given_data){
            this->data = given_data;
            return;
            }

            int get_data(){
            return this->data;
            }

            void set_next_node(Node *given_next_node){
            this->next_node = given_next_node;
            return;
            }

            Node* get_next_node(){
            return this->next_node;
            }
    };

    Node* head;

    public:

    Linked_List(){
    this->head = NULL;
    }

    void set_head(Node* new_head){
    this->head = new_head;
    return;
    }

    void print_list(){

        if (head == NULL){
            std::cout << "Empty list"<<std::endl;
            return;
            }

        int start = head->get_data();
        std::cout << start << ' ';
        Node* n = head->get_next_node();

        while (n != NULL){
            std::cout << n->get_data() << ' ';
            n = n->get_next_node();
            }

        std::cout << std::endl << "End of list" << std::endl;
        return;
    }

    void add_node_at_end(int new_data){

        Node* new_node = new Node(new_data);

        if (this->head == NULL) {
            this->head = new_node;
            return;
        }

        Node* temp = this->head;
        while (temp->get_next_node() != NULL){
            temp = temp->get_next_node();
        }

        temp->set_next_node(new_node);

        return;
    }

    void add_node_at_start(int new_data){

        Node* new_node = new Node(new_data);

        if (this->head == NULL) {
            this->head = new_node;
            return;
        }

        new_node->set_next_node(this->head);
        this->head = new_node;
        return;
    }

    void iterative_reverse_list(){

        if( this->head == NULL){
        return;
        }

        Node* temp_node = this->head->get_next_node();
        this->head->set_next_node(NULL);
        Node* previous_node = this->head;
        Node* next_node = NULL;

        while (temp_node != NULL){
            next_node = temp_node->get_next_node();
            temp_node -> set_next_node(previous_node);
            previous_node = temp_node;

            temp_node = next_node;
            }

        this->set_head(previous_node);

        delete previous_node;
        delete temp_node;
        delete next_node;

        return;
    }

    void remove_head(){

    Node* temp_head = this->head->get_next_node();
    delete head;
    head = temp_head;
    }

    void recursive_reverse_list{

    Linked_List* new_list = new Linked_list();


    while (this->head != NULL){
        temp_list->add_at_end(head);
        this->remove_head();
        }
    return;
    }

};



int main() {

    Linked_List this_list;

    this_list.print_list();

    this_list.add_node_at_end(1);

    this_list.add_node_at_end(2);

    this_list.add_node_at_end(3);

    this_list.add_node_at_end(4);

    this_list.print_list();

    this_list.iterative_reverse_list();

    this_list.print_list();

    this_list.recursive_reverse_list();

    this_list.print_list();

    return 0;

}
