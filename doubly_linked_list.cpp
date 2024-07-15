//
// Created by Solomon's PC on 7/12/2024.
//

#include "doubly_linked_list.h"
doubly_linked_list::doubly_linked_list(): head(nullptr) {}

doubly_linked_list::doubly_linked_list(const doubly_linked_list &copy_list) {
    head = copyNodes(copy_list.head);
}

doubly_linked_list::~doubly_linked_list() {
    while(head) {
        node *temp = head;
        head = head->getNext();
        delete temp;
    }
}

node* doubly_linked_list::copyNodes(node *copied_node) {
    if(!node) return nullptr;
    node *copiedNode = new node(
            copied_node->getName(), copied_node->getAge(),
            copied_node->getBreed(), copied_node->getSize(),
            copied_node->getEnergy());
    copiedNode->setNext(copyNodes(copied_node->getNext()));
    return copied_node;
}

int evaluate_score(string name) {
    char scores[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                       'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S',
                       'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

    for(int i = 0; i < name.size(); i++) {
        name[i] = toupper(name[i]);
    }
    for(int i = 0; i < 26; i++) {
        if(name[0] == scores[i]) {
            return i;
        }
    }
    cout << "Failed to find score" << endl;
}

void doubly_linked_list::insertSorted(node *sort_node) {
    //Getting scores. Lower the score the more priority the node gets.
    int score = evaluate_score(sort_node->getName());
    int head_score = evaluate_score(head->getName());

    //Iterate through and check scores.
    while(score >= head_score) {
        //Instantiating variables and reupdating each one for each new comparison needed.
        int name_size = (sort_node->getName().size());
        int head_name_size = (head->getName().size());

        //strings for udpated names, in the case two are equal scores and I need to check next character/
        string name_update = sort_node->getName();
        string head_name_update = head->getName();

        //Setting minimum for iterating through each character.
        int min = 0;
        if(name_size >= head_name_size) {
            min = head_name_size;
        } else {
            min = name_size;
        }

        //Go to next node to compare if score is too high.
        if(score > head_score) {
            head = head->getNext();
            head_score = evaluate_score(head->getName());

        /*
         * Iterate through each character in order to find the lower priority and move forward. If exact matches,
         * head_score will add 1 to break while loop and will insert beside eachother.
         */
        } else if(score == head_score) {
            while(score == head_score) {
                if(min > 1) {
                    for(int i = 1; i<min; i++) {
                        name_update[i-1] = name_update[i];
                        head_name_update[i-1] = head_name_update[i];
                    }
                    min = min - 1;

                    score = evaluate_score(name_update);
                    head_score = evaluate_score(head_name_update);
                } else {
                    head_score += 1;
                }
            }
        }
    }
    sort_node->setPrevious(head);
    sort_node->setNext(head->getNext());
    head->setNext(sort_node);
    sort_node->getNext()->setPrevious(sort_node);
}

bool doubly_linked_list::remove(const string &name, const string &breed) {
    node *temp = head;
    while(temp != nullptr) {
        if(temp->getName() != name || temp->getBreed() != breed) {
            temp = temp->getNext();
        } else {
            temp->getPrevious()->setNext(temp->getNext());
            temp->getNext()->setPrevious(temp->getPrevious());
            delete temp;
        }
    }
}