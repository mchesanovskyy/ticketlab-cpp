#pragma once
#include <memory>
#include <map>

#include "CreateTicketCommand.h"
#include "HelpCommand.h"
#include "ShowTicketsCommand.h"
#include "TicketManager.h"

class CommandInitializer
{
	std::map<std::string, ICommand*> _commands;

public:
	CommandInitializer(TicketManager& ticketManager)
	{
		_commands["create ticket"] = new CreateTicketCommand(ticketManager);
		_commands["show tickets"] = new ShowTicketsCommand(ticketManager);

		_commands["help"] = nullptr;
		_commands["help"] = new HelpCommand(GetAllKeys());
	}

	/// <summary>
	/// Search ICommand by entered command value.
	///	Returns nullptr if command not found
	/// </summary>
	ICommand* GetCommand(const string& key)
	{
		const auto cmd = _commands.find(key);
		if (cmd != _commands.end())
		{
			return cmd->second;
		}

		return nullptr;
	}

	vector<string> GetAllKeys() const
	{
		std::vector<string> keys;
		for (auto cmd : _commands) {
			keys.push_back(cmd.first);
		}
		return keys;;
	}
};
