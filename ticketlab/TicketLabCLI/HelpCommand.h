#pragma once
#include <iostream>

#include "ICommand.h"
using namespace std;

class HelpCommand : public ICommand
{
	vector<string> _commands;

public:
	HelpCommand(const vector<string>& commands) : _commands(commands)
	{

	}

	void Execute(const std::vector<std::string>& args) override
	{
		cout << "Available Commands:\n";

		for (const auto& cmd : _commands)
		{
			cout << "  -\t'" << cmd << "'\n";
		}
	}
};

