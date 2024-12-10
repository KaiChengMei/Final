#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Customernode {
        string name;
        string order;
        Customernode* next;
    };

// 10 name
string names[] = {"Frank","Alex","Kai","Kenny","Zoe","Stanley","Timothy","Renee","Nina","Jinx"};
string coffeeorder[] = {"Latte","Expresso","Mocha","Water"};

void coffeeaddqueue(Customernode*& head, string name, string order) {
    Customernode* newnode = new Customernode{name, order, nullptr};
    if (!head) {
        head = newnode;
    } else {
        Customernode* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}

void servecoffee(Customernode*& head) {
    // print the person served
    if (head) {
        cout << "Coffee Serving: " << head->name << "with drink: " << head->order << endl;
        Customernode* temp = head;
        head = head->next;
        delete temp;
    } else {
        cout << "There is no one Coffe booth " << endl;
    }
}


int main() {

    srand(time(0));

    Customernode* cofffeeQ = nullptr;

    cout << "Initial move: ";
    for ( int i = 0; i < 3; i++) {
        coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
    }
    cout << endl;
    for ( int j = 0; j < 10; j++) {
        cout << "Time: " << j+1 << " CoffeeBooth" << endl;
        servecoffee(cofffeeQ);
        if (rand() % 2 == 0) {
            coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        } 
    }

    return 0;
}