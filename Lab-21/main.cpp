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


};

int main(){

}