#pragma once
#include <iostream>
#include <string>

using namespace std;


struct Lead  {
	string leadDetails;                       // lead details
	long phoneAsId;	                          // phone number as id for lead

	Lead();								      // default constructor
	Lead(string lead, long phoneAsId);        // lead constructor
	string getLeadDetails() const;            // returns lead details
	long getPhoneAsId() const;                // returns phone as id
	string toString();					      // returns string representation of lead
	bool operator>(const Lead& other) const;  // Overload the > operator to compare leads based on phoneAsId
	bool operator==(const Lead& other) const; // Overload the == operator to compare leads based on phoneAsId
	~Lead()                                   // destructor
	{
		//cout << "Lead destructor" << endl;
	}
};

Lead::Lead()	
{
	leadDetails = "";
	phoneAsId = 0;
}

Lead::Lead(string lead, long phoneAsId) {
	this->leadDetails = lead;
	this->phoneAsId = phoneAsId;
}

string Lead::getLeadDetails() const {
	return leadDetails;
}

long Lead::getPhoneAsId() const {
	return phoneAsId;
}

string Lead::toString() {
	return   "ID: "+to_string(phoneAsId) + " Lead: " + leadDetails;
}

bool Lead::operator>(const Lead& other) const {
	return phoneAsId > other.phoneAsId;
}

bool Lead::operator==(const Lead& other) const {
	return phoneAsId == other.phoneAsId;
}