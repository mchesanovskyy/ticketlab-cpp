#pragma once
#include <string>

using namespace std;

class Ticket
{
public:
	static const string ActiveStatus;
	static const string InactiveStatus;

private:
	int _id = 0;
	string _status = InactiveStatus;
	string _name = "";
	double _priceAmount = 0;
	int _maxQty = 0;

public:
	Ticket(int id)
	{
		if (id > 0) {
			_id = id;
		}
	}

	Ticket(int id, string status, string name, double priceAmount, int maxQty) : Ticket(id)
	{
		_status = status;
		_name = name;
		_priceAmount = priceAmount;
		_maxQty = maxQty;
	}

	void SetStatus(string status) {
		if (status == ActiveStatus || status == InactiveStatus) {
			_status = status;
		}
	}

	void SetName(string name) {
		_name = name;
	}

	void SetPriceAmount(double priceAmount) {
		_priceAmount = priceAmount;
	}

	void SetQty(int qty) {
		_maxQty = qty;
	}

	int GetId() {
		return _id;
	}

	string GetName() {
		return _name;
	}

	string GetStatus() {
		return _status;
	}

	double GetPriceAmount() {
		return _priceAmount;
	}

	int GetQty() {
		return _maxQty;
	}
};

const string Ticket::ActiveStatus = "Active";
const string Ticket::InactiveStatus = "Inactive";
