#ifndef PART_H
#define PART_H
#include "Node.h"
#include <string>
#include <iostream>
using namespace std;


class part {
private:
    string SKU;
    string description;
    int price;
    string UOM;
    int quantityOnHand;
    int leadTime;
public:
    part(string, string, int, string);     //Constructor
    string getPartInfo(string, string);
    int getPrice(int);
    bool inStock();
    bool available(int);

};

part::part(string SKU, string description, int price, string UOM) {
    SKU = "";
    description = "";
    price = 0;
    UOM = "";
    quantityOnHand = 0;

}
//------------------------------------------------------------------------------------
//GetPartInfo – this returns a string containing both SKU concatenated with Description
//------------------------------------------------------------------------------------
string part::getPartInfo(string SKU, string description) {
    string skuDescription = SKU + " " + description;
    return skuDescription;
}

int part::getPrice(int userPrice) {
    userPrice = price;
    return price;

}
//------------------------------------------------------------------------------------
//inStock - returns a bool indicating if the QuantityOnHand is greater than 0
//------------------------------------------------------------------------------------
bool part::inStock() {
    if (quantityOnHand > 0) {
        return true;
    }
    else {
        return false;
    }
}
//------------------------------------------------------------------------------------
//Available - accepts a date.  This returns true if QuantityOnHand is > 0. If it isn’t, it calculates if the desired date is > LeadTime (added to current date) and returns the results of that comparison
//------------------------------------------------------------------------------------
bool part::available(int desiredDate) {
    int difference;
    difference = desiredDate - leadTime;
    if (!inStock()) {
        if (desiredDate > leadTime) {
            cout << "The desired date is larger than the lead time." << endl;
            cout << "The difference is: " << difference << " days" << endl;
        }
    }
    else {
        return true;
    }

}


#endif // PART_H
