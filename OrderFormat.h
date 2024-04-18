// #include <string>
// #include <iostream>
// #include "NODE.h"
#include <unistd.h>
#include "LL.h"
using namespace std;
// class 

int checkError(string nameP)
{
    if (nameP.size() > 30)
        return 1;
    return 0;
}

class orderFormat : public LinkedList
{
private:
    // string name;
    int numberContainer;
    int itemAmount = 0;
    // LinkedList allItems("item", 0);
    // struct item
    // {
    //     string productName;
    //     int productAmount;
        
    // }item[1000];

public:
    orderFormat(string, int);
    void mainMenu();
    void addProduct();
    void removeProduct();
    void checkProduct();
    void confirm();

    // 1 cig 20
    // 2 car 10
    // 3 book 30

    // 1 add product
    // 2 remove product
    // 3 check product
    // 4 confirm
    // 0 cancle
    
};

orderFormat::orderFormat(string name, int numContainer) : LinkedList(name, 0)
{
    numberContainer = numContainer;
}

void orderFormat::mainMenu()
{
    int choice = 0;
    while (1)
    {
        // displayAll();
        cout << "1 Add product" << endl;
        cout << "2 Remove product" << endl;
        cout << "3 Check product" << endl;
        cout << "4 confirm" << endl;
        cout << "0 Cancle" << endl;
        cout << "input : ";
        cin >> choice;
        if (choice == 1)
        {
            addProduct();
        }
        else if (choice == 2)
        {
            removeProduct();
        }
        else if (choice == 3)
        {
            checkProduct();
        }
        else if (choice == 4)
        {
            confirm();
            break;
        }
        else if (choice == 0)
        {
            break;
        }
        else
        {
            cout << "Please input 1 - 4" << endl;
            sleep(1);
        }
    }
}

void orderFormat::addProduct()
{
    string nameP;
    int amount;
    while (1)
    {
        cout << "Add product name : ";
        cin >> nameP;
        if (checkError(nameP) == 0)
        {
            break;
        }
        else
        {
            cout << "Error try again" << endl;
        }
    }
    cout << "Add amount : ";
    cin >> amount;
    add_NODE(nameP, amount);
    itemAmount += 1;
}

void orderFormat::removeProduct()
{
    string nameP;
    cout << "Remove product name : ";
    cin >> nameP;
    delete_NODE_Got(nameP);
    itemAmount -= 1;
}

void orderFormat::checkProduct()
{
    displayAll();
}

void orderFormat::confirm()
{
    save_data();
}

