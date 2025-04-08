#pragma once
#include "TicketRepository.h"
#include "FileRepositoryBase.h"
#include "StringHelper.h"

using namespace str_helpers;

class FileTicketRepository final : public FileRepositoryBase<Ticket>, public TicketRepository
{
public:
	virtual void Add(Ticket* ticket) override 
	{
		AppendToFile(ticket);
	}

	virtual Ticket* GetById(int id) override
	{
		auto records = GetRecords();
		throw new exception("Not implemented");
	}
	
	virtual vector<Ticket*> GetRecords() override {}

protected:
	virtual string ToString(Ticket* entity) override
	{
		return Join({}, '|');
	}

	virtual Ticket* ToEntity(string value) override
	{
		
	}
};


