//
// Created by Solomon's PC on 7/12/2024.
//

#include "doubly_linked_list.h"
doubly_linked_list::doubly_linked_list(): head(nullptr), tail(nullptr) {}

doubly_linked_list::doubly_linked_list(const doubly_linked_list &copy_list) {
    head = copyNodes(copy_list.head);
}

doubly_linked_list::~doubly_linked_list() {
    while(head) {
        Node *temp = head;
        head = head->getNext();
        delete temp;
    }
}

bool doubly_linked_list::isEmpty() {
    return head == nullptr;
}

Node* doubly_linked_list::getHead() {
    return head;
}

void doubly_linked_list::setHead(Node* head_node) {
    head = head_node;
}

Node* doubly_linked_list::copyNodes(Node *copied_node) {
    if(!copied_node) return nullptr;
    Node *copiedNode = new Node(
            copied_node->getName(), copied_node->getAge(),
            copied_node->getBreed(), copied_node->getSize(),
            copied_node->getEnergy());
    copiedNode->setNext(copyNodes(copied_node->getNext()));
    return copied_node;
}

void doubly_linked_list::printList() {
    Node* current = head;
    while(current) {
        cout << current->getName() << ": " << current->getBreed() << " -> ";
        current = current->getNext();
    }
    cout << "nullptr" << endl;
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
    return -1;
}

void doubly_linked_list::insertSorted(Node *sort_node) {
    //Base case: if node is null return
    if (!sort_node) return;

    // Getting scores. Lower the score the more priority the Node gets.
    int score = evaluate_score(sort_node->getName());

    if (!head) {
        // If the list is empty I set the new Node as head and tail
        head = tail = sort_node;
        return;
    }

    Node* current = head;
    int current_score = evaluate_score(current->getName());

    // Iterate through and check scores
    while (current && score >= current_score) {
        if (score > current_score) {
            current = current->getNext();
            if (current) {
                current_score = evaluate_score(current->getName());
            }
        } else {
            // Handle score equality by comparing each character after IF prior characters were equal.
            string name_update = sort_node->getName();
            string current_name_update = current->getName();

            //Function to get the minimum, using for clear code as I used a 5 line if else statement last time.
            int min_len = min(name_update.size(), current_name_update.size());
            bool exact_match = true;

            //Iterating through new strings to comapre each name after removing first character.
            for (int i = 1; i < min_len; ++i) {
                char score_char = toupper(name_update[i]);
                char current_score_char = toupper(current_name_update[i]);

                if (score_char != current_score_char) {
                    score = evaluate_score(name_update.substr(i));
                    current_score = evaluate_score(current_name_update.substr(i));
                    exact_match = false;
                    break;
                }
            }
            // Make sure we break the tie and move forward
            if (exact_match) {
                score++;
            } else {
                if (score > current_score) {
                    current = current->getNext();
                    if (current) current_score = evaluate_score(current->getName());
                }
            }
        }
    }

    // Insert the Node, since im using a doubly linked list I have to keep track of tail and head
    if (!current) {
        // Insert at the tail, !current means nullptr.
        tail->setNext(sort_node);
        sort_node->setPrevious(tail);
        tail = sort_node;
    } else if (current == head) {
        // Insert at the head, best case scenario
        sort_node->setNext(head);
        head->setPrevious(sort_node);
        head = sort_node;
    } else {
        // Insert in the middle.
        Node* prev = current->getPrevious();
        prev->setNext(sort_node);
        sort_node->setPrevious(prev);
        sort_node->setNext(current);
        current->setPrevious(sort_node);
    }
}

void doubly_linked_list::deleteNode(Node* node) {
    if(node == head) {
        head = head->getNext();
        if(head) {
            head->setPrevious(nullptr);
        } else if(node == tail) {
            tail = tail->getPrevious();
            if(tail) {
                tail->setNext(nullptr);
            }
        } else {
            node->getPrevious()->setNext(node->getNext());
            node->getNext()->setPrevious(node->getPrevious());
        }
    }
}