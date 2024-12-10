#include <iostream>
#include <string>
using namespace std;

struct Customernode {
        string name;
        string order;
        Customernode* next;
    };

// 10 name
string names[] = {"Frank","Alex","Kai","Kenny","Zoe","Stanley","Timothy","Renee","Nina","Jinx"};
string coffeeorder[] = {"Latte","Expresso","Mocha","Water"};

void coffeeaddqueue(Customernode* head, string name, string coffeeorder) {
    Customernode* newnode = new Customernode{name, coffeeorder, nullptr};
    Customernode* temp = head;
    temp = temp->next;
    temp->next = newnode;
}

void servecoffee(Customernode* head) {
    // print the person served
    cout << "Coffee Serving: " << head->name << "with drik: " << head ->order << endl;

    if (head) {
        head = head->next;
    } else {
        cout << "There is no one Coffe booth " << endl;
    }
}


int main() {

    Customernode* cofffeeQ;

    for ( int i = 0; i < 3; i++) {
        cout << "Initial move: ";
        coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
    }

    for ( int j = 0; j < 10; j++) {
        cout << "Time: " << j+1 << "CoffeeBooth" << endl;
        servecoffee(cofffeeQ);
        if (rand() % 2 == 0) {
            coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        } 
    }
}