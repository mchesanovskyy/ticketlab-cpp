#pragma once
#include <string>

using namespace std;

class Attendee {
private:
	int _id = 0;
	string _email = "";
	string _firstName = "";
	string _lastName = "";

public:
	Attendee(int id)
	{
		if (id >= 0) {
			_id = id;
		}
	}

	Attendee(int id, string email, string firstName, string lastName) : Attendee(id)
	{
		_email = email;
		_firstName = firstName;
		_lastName = lastName;
	}

	void SetEmail(string email)
	{
		_email = email;
	}

	void SetFirstName(string firstName)
	{
		_firstName = firstName;
	}

	void SetLastName(string lastName) {
		_lastName = lastName;
	}

	int GetId() {
		return _id;
	}

	string GetEmail() {
		return _email;
	}

	string GetFirstName() {
		return _firstName;
	}

	string GetLastName() {
		return _lastName;
	}
};
