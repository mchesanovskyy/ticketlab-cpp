#pragma once
#include <string>
#include <vector>

class ICommand
{
	public:
		virtual ~ICommand() = default;
		virtual void Execute(const std::vector<std::string>& args) = 0;
};

