#pragma once
#pragma once
#include <iostream>

#include "ICommand.h"
#include "TicketManager.h"

using namespace std;

class ShowTicketsCommand : public ICommand
{

private:
	TicketManager& _manager;

public:
	explicit ShowTicketsCommand(TicketManager& manager) : _manager(manager) {}

	void Execute(const vector<string>& args) override
	{
		cout << "List of tickets:\n";
		try
		{
			auto tickets = _manager.GetTickets();
			if (tickets.empty())
			{
				cout << "No tickets found.\n";
				return;
			}

			for (auto ticket : tickets)
			{
				cout << " ID:       " << ticket->GetId() << '\n';
				cout << " Name:     " << ticket->GetName() << '\n';
				cout << " Price:    " << ticket->GetPriceAmount() << '\n';
				cout << " Quantity: " << ticket->GetQty() << '\n';
				cout << " Status:   " << ticket->GetStatus() << "\n";
				cout << "-----------------------------------\n";
			}
		}
		catch (const exception& ex)
		{
			cout << "\033[1;31m Error:\033[0m " << ex.what() << '\n';
		}
	}
};
