//
//  #1: Merge linked lists
//  Runtime O: O(n+m) n=length of list1, m = length of list2
//  Spacetime O: O(1)
//

// Assume node has the following definition:
// struct Node {
//  int value;
//  Node* next;
//  Node(int x) : val(x), next(nullptr) {}
// }

LinkedList merge(LinkedList list1, LinkedList list2) {
    Node* temp = new Node(-1);
    Node* tail = temp;

    Node* l1 = list1.head;
    Node* l2 = list2.head;

    while (l1 && l2) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1) tail->next = l1;
    else if (l2) tail->next = l2;

    LinkedList merged;
    merged.head = temp->next;
    delete temp;
}


//
//  #2: delete Nth node
//  Runtime O: O(n) n=length of list
//  Spacetime O: O(1)
//

bool deleteNthNodeFromEnd(int n) {
    Node* temp = new Node(-1);
    temp->next = head;

    Node* fast = temp;
    Node* slow = temp;

    for (int i = 0; i < n; ++i) {
        if (!fast->next) {
            delete temp;
            return false;
        }
        fast = fast->next;
    }

    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* toDelete = slow->next;
    if (toDelete) {
        slow->next = toDelete->next;
        delete toDelete;
        head = temp->next;
        delete temp;
        return true;
    } else {
        delete temp;
        return false;
    }
}

//
//  #3
//  Runtime O: O(n^2) n=length of list
//  Spacetime O: O(1)
//

#include <iostream>
#include <fstream>

struct node
{
    std::string first_name;
    std::string last_name;
    node* next;
}

void append(const std::string& first_name, const std::string& last_name) {
    node* newNode = new node(first_name, last_name);
    if (!head) {
        head = newNode;
        return;
    }

    node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

bool isGreater(node* a, node* b) {
    if (a->first_name == b->first_name)
        return a->last_name > b->last_name;
    return a->first_name > b->first_name;
}

void selectionSort() {
    for (node* i = head; i && i->next; i = i->next) {
        node* minNode = i;
        for (node* j = i->next; j; j = j->next) {
            if (isGreater(minNode, j)) {
                minNode = j;
            }
        }
        if (minNode != i) {
            std::swap(i->first_name, minNode->first_name);
            std::swap(i->last_name, minNode->last_name);
        }
    }
}

void writeToFile(const std::string& filename) {
    std::ofstream out(filename);
    node* temp = head;
    while (temp) {
        out << temp->first_name << " " << temp->last_name << "\n";
        temp = temp->next;
    }
    out.close();
}

void print() {
    node* temp = head;
    while (temp) {
        std::cout << temp->first_name << " " << temp->last_name << "\n";
        temp = temp->next;
    }
}


int main() {

//    3(2)

    std::ofstream outFile("list.txt", std::ios::app); // append mode
    if (outFile.is_open()) {
        outFile << "YourFirstName YourLastName\n";
        outFile.close();
    } else {
        std::cout << "Unable to open file for writing.\n";
    }

//    3(3)
    LinkedList list;

    std::ifstream inFile("list.txt");
    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        std::string fname, lname;
        if (iss >> fname >> lname) {
            list.append(fname, lname);
        }
    }
    inFile.close();

    list.selectionSort();

    list.writeToFile("sorted_names.txt");

    return 0;
}
