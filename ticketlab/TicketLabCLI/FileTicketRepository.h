#pragma once
#include "TicketRepository.h"
#include "FileRepositoryBase.h"
#include "StringHelper.h"

using namespace str_helpers;

class FileTicketRepository final : public FileRepositoryBase<Ticket>, public TicketRepository
{
public:
	FileTicketRepository() : FileRepositoryBase("tickets.mydb")
	{
	}

	/// <summary>
	/// Adds a ticket to the repository by appending it to the file.
	/// </summary>
	/// <param name="ticket">The ticket to add.</param>
	virtual void Add(Ticket* ticket) override
	{
		// Save the ticket as a new line in the file.
		AppendToFile(ticket);
	}

	/// <summary>
	/// Retrieves a ticket by its ID.
	/// Note: This reads the entire file into memory, which may not scale well with large data.
	/// </summary>
	/// <param name="id">The ID of the ticket to find.</param>
	/// <returns>A pointer to the matching ticket if found; otherwise, nullptr.</returns>
	virtual Ticket* GetById(int id) override
	{
		// Read all ticket records from the file.
		const auto records = ReadRecords();

		// Iterate through each ticket in the vector.
		for (const auto entity : records)
		{
			// If the ID matches the requested ID, return the matching ticket.
			if (entity->GetId() == id)
			{
				return entity;
			}
		}

		// If no matching ticket is found, return nullptr.
		return nullptr;
	}

	/// <summary>
	/// Retrieves all tickets from the repository.
	/// </summary>
	/// <returns>A vector of pointers to all tickets.</returns>
	virtual vector<Ticket*> GetAll() override
	{
		// Load all ticket records from the file.
		return ReadRecords(); 
	}

protected:

	/// <summary>
	/// Converts a Ticket entity to its string representation, with fields separated by '|'.
	///	This method will be used by the parent class
	///	Result Example: "112|Concert|49.99|200|Active"
	/// </summary>
	/// <param name="entity">The ticket to convert.</param>
	/// <returns>A string containing the ticket data.</returns>
	virtual string ToString(Ticket* entity) override
	{
		const string parts[] = {
			to_string(entity->GetId()),            // Convert ID to string
			entity->GetName(),                     // Get ticket name
			to_string(entity->GetPriceAmount()),   // Convert price to string
			to_string(entity->GetQty()),           // Convert quantity to string
			entity->GetStatus()                    // Get ticket status
		};

		// Join all parts using '|' as the delimiter
		return Join(parts, '|');
	}

	virtual Ticket* ToEntity(string value) override
	{
		// Split the input string into parts using '|' as the delimiter
		const vector<string> parts = Split(value, '|');

		// Check if the correct number of fields is present
		if (parts.size() != 5)
		{
			// Malformed input
			// TODO: use internal log for this case.
			return nullptr;
		}

		// Extract & convert values
		const int id = stoi(parts[0]);        // Convert ID from string to int
		const string& name = parts[1];        // Ticket name
		const double price = stod(parts[2]);  // Convert price from string to double
		const int qty = stoi(parts[3]);       // Convert quantity from string to int
		const string& status = parts[4];      // Ticket status

		// Create and return a new Ticket object
		return new Ticket(id, status, name, price, qty);
	}
};


