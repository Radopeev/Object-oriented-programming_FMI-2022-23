#include<iostream>
#include "Constants.h"
#include "ShoppingCart.h"
#include <sstream>
using namespace Messages;
using namespace Command;

void Menu() {
    ShoppingCart shoppingCart;
    while (true) {
        char userInput[100], command[20];
        std::cout << GREATER_THAN;
        std::cin.getline(userInput, 100);
        std::stringstream ss(userInput);
        ss >> command;
        if (strcmp(command, ADD_ITEM) == 0) {
            char name[20];
            bool availabilty;
            float price;
            ss >> name >> availabilty >> price;
            if (shoppingCart.addItem(name, availabilty, price)) {
                std::cout << ITEM_ADDED << std::endl;
            }
            else {
                std::cout << ALREADY_EXISTS << std::endl;
            }
        }
        else if (strcmp(command, REMOVE_ITEM) == 0) {
            char name[20];
            ss >> name;
            if (shoppingCart.removeItem(name)) {
                std::cout << ITEM_REMOVED << std::endl;
            }
            else {
                std::cout << DOES_NOT_EXISTS << std::endl;
            }
        }
        else if (strcmp(command, GET_ITEMS_COUNT) == 0) {
            std::cout << NUMBER_OF_ITEMS_IS << shoppingCart.getItemsCount() << std::endl;
        }
        else if (strcmp(command, IS_EMPTY) == 0) {
            if (shoppingCart.isEmpty()) {
                std::cout << THE_CART_IS_EMPTY << std::endl;
            }
            else {
                std::cout << THE_CART_IS_NOT_EMPTY << std::endl;
            }
        }
        else if (strcmp(command, GET_PRICE_OF) == 0) {
            char name[20];
            ss >> name;
            if (shoppingCart.getPriceOf(name) != -1) {
                std::cout << THE_PRICE_OF << name << IS << shoppingCart.getPriceOf(name) << std::endl;
            }
            else {
                std::cout << DOES_NOT_EXISTS << std::endl;
            }
        }
        else if (strcmp(command, GET_TOTAL_PRICE) == 0) {
            std::cout << TOTAL_PRICE_IS << shoppingCart.getTotalPrice() << std::endl;;
        }
        else if (strcmp(command, SORT_BY_NAME) == 0) {
            shoppingCart.sortByName();
            std::cout << SORTED_CART << std::endl;
        }
        else if (strcmp(command, SAVE) == 0) {
            char fileName[20];
            ss >> fileName;
            std::ofstream myFile(fileName);
            if (shoppingCart.saveToFile(myFile)) {
                std::cout << SAVED_CART << fileName;
            }
            else {
                std::cout << ERROR << std::endl;
            }
            myFile.close();
            break;
        }
    }
}