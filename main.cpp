#include <iostream>
#include <string>
using namespace std;

struct Custumornode {
        string name;
        string order;
        Customernode* next;
    }

// 10 name
string name[] = {"Frank","Alex","Kai","Kenny","Zoe","Stanley","Timothy","Renee","Nina","Jinx"}
string coffeeorder[] = {"Latte","Expresso","Mocha","Water"}

void coffeeaddqueue(Customernode head, string name, string coffeeorder) {
    Customernode* newnode = new Customernode{name, order, nullptr};
    CustomerNode* temp = head;
    temp = temp->next;
    temp->next = newnode;
}

void servecoffee(Customernode head, string name, string coffeeorder) {
    if (head) {
        head = head->next;
    } else {
        cout << "There is no one Coffe booth " << endl;
    }

void simulationcoffee() {

} 

int main() {

    Customernode* cofffeeQ;

    for ( i = 0; i < 3; i++) {
        addqueue(cofffeeQ, name[rand % 10], coffeeorder[rand % 4]);
    }

}