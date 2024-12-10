#include <iostream>
#include <string>
using namespace std;

struct custumor {
        string name;
        string order;
        Customernode* next;
    }

// 10 name
string name[] = {"Frank","Alex","Kai","Kenny","Zoe","Stanley","Timothy","Renee","Nina","Jinx"}
string coffeeorder[] = {"Latte","Expresso","Mocha","Water"}

void coffeeaddqueue(Customernode head, string name) {

}


void simulationcoffee() {

} 

int main() {

    Customernode* cofffeeQ;

    for ( i = 0; i < 3; i++) {
        addqueue(cofffeeQ, name[rand % 10]);
    }

}