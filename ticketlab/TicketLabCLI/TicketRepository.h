#pragma once
#include "Ticket.h"
#include <vector>

class TicketRepository
{
public:
	virtual void Add(Ticket* ticket) = 0;
	virtual Ticket* GetById(int id) = 0;
	virtual vector<Ticket*> GetRecords() = 0;
};
