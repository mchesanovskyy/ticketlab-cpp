#pragma once
#include <iostream>

#include "ICommand.h"
#include "TicketManager.h"

using namespace std;

class CreateTicketCommand : public ICommand
{
private:
    TicketManager& _manager;

public:
    explicit CreateTicketCommand(TicketManager& manager) : _manager(manager) {}

    void Execute(const vector<string>& args) override
    {
        //TODO: consider using args for quick creation

    	cout << "Let's create your ticket!\n\n";

        cout << "What is the name of your ticket?\n";
        cout << ":";
    	string name;
        getline(cin, name);


        cout << "How much should each ticket cost? (0 - free)\n";
        cout << ":";
        double amount;
        cin >> amount;
    	cin.ignore(numeric_limits<streamsize>::max(), '\n');


        cout << "How many tickets would you like to sell? (0 - unlimited)\n";
        cout << ":";
        int qty = 0;
        cin >> qty;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    	try
        {
            _manager.CreateTicket(name, amount, qty);
            cout << "Your ticket has been successfully created!\n";
        }
        catch (const exception& ex)
        {
			cout << "Oops! Something went wrong: " << ex.what() << '\n';
        }
    }
};
