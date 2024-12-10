#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <vector>
#include <queue>
using namespace std;

struct Customernode {
    string name;
    string order;
    Customernode* next;
};

struct Customer {
    string name;
    string order;
};

// 10 name 4 coffee muffin bracelet icecream
string names[] = {"Frank","Alex","Kai","Kenny","Zoe","Stanley","Timothy","Renee","Nina","Jinx"};
string coffeeorder[] = {"Latte","Expresso","Mocha","Water"};
string muffinorder[] = {"Blueberry","Chocolate","original","Banana"};
string braceletorder[] = {"Gold","Silver","Copper","18K"};
string icecreamorder[] = {"Chocolate chip","Cookies and cream","Mango","Apple"};

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

void servemuffin(depue<Customer> queue) {
    if (!queue.empty()) {
        cout << "Muffin Serving:" << queue.front;
        queue.popfont();
    } else {
        cout << "There is no one Muffin booth " << endl;
    }
}

void servebracelet(vector<Customer> queue) {

}

void serveicecream(queue<Customer> queue) {

}

int main() {

    srand(time(0));

    Customernode* cofffeeQ = nullptr;
    depue<Customer> muffinQ;
    vector<Customer> braceletQ;
    queue<Customer> icecreamQ;

    cout << "Initial move: ";
    for ( int i = 0; i < 3; i++) {
        coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        muffinQ.push_back(names[rand() % 10], muffinorder[rand() % 4]);
        braceletQ.push_back(names[rand() % 10], braceletorder[rand() % 4]);
        icecreamQ.push_back(names[rand() % 10], icecreamorder[rand() % 4]);
    }
    cout << endl;
    for ( int j = 0; j < 10; j++) {
        cout << "Time: " << j+1;

        cout << " CoffeeBooth" << endl;
        servecoffee(cofffeeQ);
        if (rand() % 2 == 0) {
            coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        } 

        cout << " MuffinBooth" << endl;
        serveMuffin(muffinQ);
        if (rand() % 2 == 0) {
            coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        } 
    }

    return 0;
}