#pragma once
#include <stdexcept>
#include <string>
#include <optional>

#include "TicketRepository.h"

using namespace std;

class TicketManager
{
	int* _lastUsedId = nullptr; // Nullptr until initialized

	TicketRepository& _repository; // Don't create an object in TicketManager,
								   // expect to receive the instance from constructor

public:
	TicketManager(TicketRepository& repository) : _repository(repository)
	{
	}

	/// <summary>
    /// Creates a new ticket with validation, auto-generated ID, and default status.
    /// </summary>
	void CreateTicket(const string& name, double amount, int qty)
	{
		// Validate input data
		ValidateInput(name, amount, qty);

		// Create and assign a new ID
		const int nextId = GetIncrementedLastUsedId();

		 // Create a ticket
		Ticket* newTicket = new Ticket(nextId, Ticket::ActiveStatus, name, amount, qty);

		// Save the ticket
		_repository.Add(newTicket);

		// Remove allocated ticket from memory
		// TODO: use smart pointers later
		delete newTicket; 
	}

	vector<Ticket*> GetTickets() const
	{
		return _repository.GetAll();
	}

	~TicketManager()
	{
		delete _lastUsedId;
	}

private:
	static void ValidateInput(const string& name, double amount, int qty)
	{
		if (name.empty())
			throw invalid_argument("Ticket name cannot be empty.");
		if (amount < 0)
			throw invalid_argument("Ticket price must be greater or equal to 0.");
		if (qty <= 0)
			throw invalid_argument("Ticket quantity must be greater than 0.");
	}

	int GetIncrementedLastUsedId()
	{
		//TODO: store last used id in configs and don't read all records for this purpose
		if (_lastUsedId == nullptr)
		{
			InitializeLastIdFromRepository();
		}

		return ++(*_lastUsedId);
	}

	void InitializeLastIdFromRepository()
	{
		int maxId = 0;
		const auto tickets = _repository.GetAll();
		for (const auto ticket : tickets)
		{
			if (ticket->GetId() > maxId)
			{
				maxId = ticket->GetId();
			}
		}

		_lastUsedId = new int(maxId);
	}
};