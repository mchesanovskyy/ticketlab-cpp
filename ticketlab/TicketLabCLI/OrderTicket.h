#pragma once
#include <string>

using namespace std;

class OrderTicket {
private:
	int _id = 0;
	int _ticketId = 0;
	int _attendeeId = 0;
	int _paidQty = 0;
	double _paidAmount = 0;

public:
	OrderTicket(int id) {
		if (id >= 0) {
			_id = id;
		}
	}

	OrderTicket(int id, int ticketId, int attendeeId, int paidQty, double paidAmount) : OrderTicket(id) {
		_ticketId = ticketId;
		_attendeeId = attendeeId;
		_paidQty = paidQty;
		_paidAmount = paidAmount;
	}

	void SetTicketId(int ticketId) {
		_ticketId = ticketId;
	}

	void SetAttendeeId(int attendeeId) {
		_attendeeId = attendeeId;
	}

	void SetPaidQty(int paidQty) {
		_paidQty = paidQty;
	}

	void SetPaidAmount(double paidAmount) {
		_paidAmount = paidAmount;
	}

	int GetId() {
		return _id;
	}

	int GetTicketId() {
		return _ticketId;
	}

	int GetAttendeeId() {
		return _attendeeId;
	}

	int GetPaidQty() {
		return _paidQty;
	}

	int GetPaidAmount() {
		return _paidAmount;
	}
};

