#include <iostream>
#include <string>
#include <cstdlib> 
#include <ctime>
using namespace std;

class Goat {
private:
    int age;
    string name;
    string color;

    string names[15] = {"Buddy", "Daisy", "Charlie", "Luna", "Max", 
    "Bella", "Oreo", "Chloe", "Bob", "Lucy", 
    "Buster", "Sam", "Ruby", "Oscar", "Penny"};

    string colors[15] = {"Red", "Gold", "Mauve", "White", "Yellow", 
    "Black", "Brown", "Grey", "Spotted", "Tan", 
    "Cream", "Silver", "Patchy", "Dark", "Light"};

public:
    Goat() {   
        age = (rand() % 20) + 1; // Random age 1-20
        name = names[rand() % 15]; // Random name
        color = colors[rand() % 15]; // Random color
    }

    Goat(int a, string n, string c) {
        age = a;
        name = n;
        color = c;
    }

    int getAge() { return age; }
    string getName() { return name; }
    string getColor() { return color; }
};

struct Node {
    Goat data; 
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    void push_front(Goat g) {
        Node* newNode = new Node;
        newNode->data = g;
        newNode->prev = nullptr;
        newNode->next = head;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            head->prev = newNode;
            head = newNode;
        }
    }

    void push_back(Goat g) {
        Node* newNode = new Node;
        newNode->data = g;
        newNode->next = nullptr;
        newNode->prev = tail;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Forward:" << endl;
        Node* current = head;
        while (current != nullptr) {
            cout << "    " << current->data.getName() 
                 << " (" << current->data.getColor() 
                 << ", " << current->data.getAge() << ")" << endl;
            current = current->next;
        }
    }

    void print_reverse() { //copy pasted from above and just changed the names and some other smaller stuff
        if (head == nullptr) {
            cout << "List is empty" << endl;
            return;
        }
        
        cout << "Backward:" << endl;
        Node* current = tail;
        while (current != nullptr) {
            cout << "    " << current->data.getName() 
                 << " (" << current->data.getColor() 
                 << ", " << current->data.getAge() << ")" << endl;
            current = current->prev;
        }
    }

};

int main(){
    srand(time(0));

    DoublyLinkedList list;
    int numGoats = (rand() % 16) + 5;

    for (int i = 0; i < numGoats; i++) {
        Goat newGoat; 
        list.push_back(newGoat); 
    }

    list.print();
    list.print_reverse();
}