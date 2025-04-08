#pragma once
#include "CommandInitializer.h"
#include "CreateTicketCommand.h"
#include "FileTicketRepository.h"

using namespace std;

class ConsoleApp
{

public:
	void Run()
	{
		auto commandInitializer = InitComponents();

		while (true)
		{
			string cmd;
			cout << "\033[1;32m CMD:> \033[0m";
			getline(cin, cmd);

			auto command = commandInitializer.GetCommand(cmd);
			if(command == nullptr)
			{
				cout << "Sorry, we can't find this command.\n";
				cout << "Please try again or use 'help' to see all available commands";
				continue;
			}

			// don't send any args for now
			command->Execute({});

			cout << "\n\n";
		}
	}

private:
	static CommandInitializer& InitComponents()
	{
		TicketRepository* ticketRepository = new FileTicketRepository();
		TicketManager* ticketManager = new TicketManager(*ticketRepository);
		CommandInitializer* commandInitializer = new CommandInitializer(*ticketManager);
		return *commandInitializer;
	}
};
