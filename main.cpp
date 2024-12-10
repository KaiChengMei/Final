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
        cout << "*Empty Coffe booth " << endl;
    }
}

void servemuffin(deque<Customer>& queue) {
    if (!queue.empty()) {
        cout << "Muffin Serving: " << queue.front().name << " with flavor: " << queue.front().order << endl;
        queue.pop_front();
    } else {
        cout << "*Empty Muffin booth " << endl;
    }
}

void servebracelet(vector<Customer> queue) {
    if (!queue.empty()) {
        cout << "Bracelet Serving: " << queue.front().name << " with material: " << queue.front().order << endl;
        queue.erase(queue.begin());
    } else {
        cout << "*Empty Bracelet booth " << endl;
    }
}

void serveicecream(queue<Customer> queue) {
    if (!queue.empty()) {
        cout << "Ice cream Serving: " << queue.front().name << " with flavor: " << queue.front().order << endl;
        queue.pop();
    } else {
        cout << "*Empty ice cream booth " << endl;
    }
}

// print 
void printcoffee(const Customernode* head) {
    cout << "Coffee booth: ";
    if (head) {
        cout << "Empty";
        return;
    }
    while (head) {
        cout << head->name << "(" << head->order << ") -";
        head = head->next;
    }
    cout << endl;
}

void printmuffin(const deque<Customer> queue) {
    cout << "muffin booth: ";
    if (!queue.empty()) {
        cout << "Empty";
        return;
    }
    for ()
}

void printbracelet(const vector<Customer> queue) {
    
}

void printicecream(const queue<Customer> queue) {
    
}


int main() {

    srand(time(0));

    Customernode* cofffeeQ = nullptr;
    deque<Customer> muffinQ;
    vector<Customer> braceletQ;
    queue<Customer> icecreamQ;

    cout << "Initial move done";
    for ( int i = 0; i < 3; i++) {
        coffeeaddqueue(cofffeeQ, names[rand() % 10], coffeeorder[rand() % 4]);
        muffinQ.push_back({names[rand() % 10], muffinorder[rand() % 4]});
        braceletQ.push_back({names[rand() % 10], braceletorder[rand() % 4]});
        icecreamQ.push({names[rand() % 10], icecreamorder[rand() % 4]});
    }
    cout << endl;

    string tempname;
    string temporder;
    for ( int j = 0; j < 10; j++) {
        cout << "Time: " << j+1 << endl;

        // CoffeeBooth
        cout << "----CoffeeBooth----" << endl;
        servecoffee(cofffeeQ);
        if (rand() % 2 == 0) {
            tempname = names[rand() % 10];
            temporder = coffeeorder[rand() % 4];
            cout << "New coffee order: " << tempname << "(" << temporder << ")" << endl;
            coffeeaddqueue(cofffeeQ, tempname, temporder);
        } 
        // print 
        printcoffee(cofffeeQ);


        // MuffinBooth
        cout << "----MuffinBooth----" << endl;
        servemuffin(muffinQ);
        if (rand() % 2 == 0) {
            tempname = names[rand() % 10];
            temporder = muffinorder[rand() % 4];
            cout << "New muffin order: " << tempname << "(" << temporder << ")" << endl;
            muffinQ.push_back({tempname,temporder});
        } 
        // print 
        printmuffin(muffinQ);

        // BraceletBooth
        cout << "----BraceletBooth----" << endl;
        servebracelet(braceletQ);
        if (rand() % 2 == 0) {
            tempname = names[rand() % 10];
            temporder = braceletorder[rand() % 4];
            cout << "New bracelet order: " << tempname << "(" << temporder << ")" << endl;
            braceletQ.push_back({tempname, temporder});
        } 
        // print 
        printbracelet(braceletQ);

        // IcecreamBooth
        cout << "----IcecreamBooth----" << endl;
        serveicecream(icecreamQ);
        if (rand() % 2 == 0) {
            tempname = names[rand() % 10];
            temporder = icecreamorder[rand() % 4];
            cout << "New ice cream order: " << tempname << "(" << temporder << ")" << endl;
            icecreamQ.push({tempname, temporder});
        } 
        // print 
        printicecream(icecreamQ);

        cout << endl;
    }

    return 0;
}