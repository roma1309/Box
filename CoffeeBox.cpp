#include <iostream>
#include <stdlib.h>

using namespace std;

void showEmptyCups(int cups);
void showMenu(double balance);
void makeCoffee(int numberCoffee);
void showServiceMenu();
void printInsufficientFunds();
void printInsufficientCups();
void showBalance(double totalMoney);

double withdrawalOfProceeds(double totalMoney);
double addCoins();

bool isInsertingRightPin();

int addEmptyCups(int cups);

double const COST_OF_AMERICANO = 1.80;
double const COST_OF_CAPPUCINO = 2.30;
double const COST_OF_ESPRESSO = 1.80;

int const STANDART_NUMBER_OF_CUPS = 7;
int const MAX_NUMBER_OF_CUPS = 700;
int const MIN_NUMBER_OF_CUPS = 5;
int const RIGHT_PIN = 1234;

int main()
{
    double totalMoney = 0.0;
    double balance = 0.0;
    int cups = STANDART_NUMBER_OF_CUPS;
    int choice = 0;

    while (true)
    {
        if (cups <= MIN_NUMBER_OF_CUPS) 
        {
            cout << "Warning : remains " << cups << " cups" << endl << endl;
        }
        showMenu(balance);

        int choice = 0;
        cin >> choice;

        system("cls");

        switch (choice)
            {
            case 1:
            {
                double addedCoins = addCoins();
                balance += addedCoins;
                totalMoney += addedCoins;
                break;
            }
            case 2:
            {
                if (cups <= 0)
                {
                    printInsufficientCups();
                }
                else if (balance >= COST_OF_AMERICANO)
                {
                    makeCoffee(2);
                    cups--;
                    balance -= COST_OF_AMERICANO;
                }
                else
                {
                    printInsufficientFunds();
                }
                break;
            }
            case 3:
            {
                if (cups <= 0)
                {
                    printInsufficientCups();
                }
                else if (balance >= COST_OF_CAPPUCINO)
                {
                    makeCoffee(3);
                    cups--;
                    balance -= COST_OF_CAPPUCINO;
                }
                else
                {
                    printInsufficientFunds();
                }
                break;
            }
            case 4:
            {
                if (cups <= 0)
                {
                    printInsufficientCups();
                }
                else if (balance >= COST_OF_ESPRESSO)
                {
                   makeCoffee(4);
                    cups--;
                    balance -= COST_OF_ESPRESSO;
                }
                else
                {
                    printInsufficientFunds();
                }
                break;
            }
            case 5:
            {
                if (!isInsertingRightPin())
                {
                    cout << " The box is locked ";
                    return 1;
                }
                else
                {
                    bool isInServiceMenu = true;

                    while (isInServiceMenu)
                    {
                        showServiceMenu();
                        cin >> choice;

                        system("cls");

                        switch (choice)
                        {
                            case 1:
                            {
                                showBalance(totalMoney);
                                break;
                            }
                            case 2:
                            {
                                totalMoney = withdrawalOfProceeds(totalMoney);
                                break;
                            }
                            case 3:
                            {
                                showEmptyCups(cups);
                                break;
                            }
                            case 4:
                            {
                                cups += addEmptyCups(cups);
                                break;
                            }
                            case 5:
                            {
                                isInServiceMenu = false;
                                break;
                            }
                            default:
                            {
                                cout << "Incorrect number , please reinsert the number" << endl << endl;
                                break;
                            }
                        }
                    }
                }
                break;
            }
            default:
                cout << "Incorrect number , please reinsert the number" << endl << endl;
                break;
            }
        }
    return 0;
}


void showMenu(double money)
{
    cout << "Balance: " << money << " BYN." << endl << endl
         << "1.Add coins, BYN." << endl
         << "2.Order an americano (1,80 BYN)" << endl
         << "3.Order a cappuccino (2,30 BYN)" << endl
         << "4.Order an espresso (1,80 BYN)" << endl
         << "5.Service menu." << endl
         << endl << "Insert number: ";
}

double addCoins()
{
    double coins = 0;
    cout << "The coffee box accepts only 2, 1, 0.50, 0.20 and 0.10 kopecks"
         << endl << "Insert money, BYN: ";

    cin >> coins;
    cout << endl;

    if (coins == 2 || coins == 1 || coins == 0.5 || coins == 0.2 || coins == 0.1) 
    {
        return coins;
    }
    else
    {
        cout << "Incorrect currency" << endl << endl;
        return 0;
    }
}

void makeCoffee(int numberCoffee)
{
    if (numberCoffee == 2)
    {
        cout << " Making amerikano..." << endl;
        cout << "Take your Americano" << endl << endl;
    }
    else if (numberCoffee == 3)
    {
        cout << " Making cappuccino..." << endl;
        cout << "Take your cappuccino " << endl << endl;
    }
    else
    {
        cout << " Making espresso..." << endl;
        cout << "Take your espresso" << endl << endl;
    }
}

void showServiceMenu()
{
    cout << "1.View balance" << endl
         << "2.Withdrawal of proceeds" << endl
         << "3.View the number of empty cups" << endl
         << "4.Add empty cups" << endl
         << "5.Return to main menu" << endl << endl
         << "Please, insert number: ";
}

bool isInsertingRightPin()
{
    int pin = 0;
    int attempts = 3;

    while (attempts > 0)
    {
        cout << "Insert PIN (****) : ";
        cin >> pin;

        if (pin == RIGHT_PIN)
        {
            cout << endl;

            return true;
        }
        else
        {
            attempts--;
            cout << "Incorrect PIN, you have " << attempts
                << " attempt(s) left" << endl;
        }
    }
    cout << endl;

    return false;
}
void printInsufficientFunds()
{
    cout << "Insufficient funds" << endl << endl;
}

void printInsufficientCups()
{
    cout << "Insufficient cups" << endl << endl;
}

void showBalance(double totalMoney)
{
    cout << "Balance = " << totalMoney << " BYN." << endl;
}

double withdrawalOfProceeds(double totalMoney)
{
    cout << "Withdrawal of proceeds..." << endl << endl
        << "Here is your totalMoney : " << totalMoney << " BYN" << endl << endl;

    return 0.0;
}

void showEmptyCups(int cups)
{
    cout << "Empty cups = " << cups << endl << endl;
}

int addEmptyCups(int cups)
{
    int addedCups = 0;
    int allCups = 0;
    
    cout << "At the moment, " << cups << " cups of " << MAX_NUMBER_OF_CUPS << endl;
    cout << "Insert quantity of cups you wanted to add: ";
    cin >> addedCups;

    allCups = cups + addedCups;

    if (allCups > MAX_NUMBER_OF_CUPS or addedCups < 0)
    {
        cout << "The device can not hold so many cups" << endl << endl;
        return 0;
    }
    else
    {
        cout << "You added : " << addedCups << " cups. " << endl << endl;
        return addedCups;
    }
}




