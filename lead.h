#pragma once
#include <iostream>
#include <string>

using namespace std;


struct Lead  {
	string leadDetails;
	long phoneAsId;

	Lead() {
			leadDetails = "";
			phoneAsId = 0;
		}
	Lead(string lead, long phoneAsId);
	string getLeadDetails();
	long getPhoneAsId();
	string toString();
	~Lead() {
		//cout << "Lead destructor" << endl;
	}
	// Overload the < operator to compare leads based on phoneAsId
	bool operator<(const Lead& other) const {
		return phoneAsId < other.phoneAsId;
	}
	// Overload the > operator to compare leads based on phoneAsId
	bool operator>(const Lead& other) const {
		return phoneAsId > other.phoneAsId;
	}
	// Overload the == operator to compare leads based on phoneAsId
	bool operator==(const Lead& other) const {
		return phoneAsId == other.phoneAsId;
	}
	// Overload the != operator to compare leads based on phoneAsId
	bool operator!=(const Lead& other) const {
		return phoneAsId != other.phoneAsId;
	}
	// Overload the <= operator to compare leads based on phoneAsId
	bool operator<=(const Lead& other) const {
		return phoneAsId <= other.phoneAsId;
	}
	// Overload the >= operator to compare leads based on phoneAsId
	bool operator>=(const Lead& other) const {
		return phoneAsId >= other.phoneAsId;
	}
};

string Lead::getLeadDetails() {
	return leadDetails;
}

long Lead::getPhoneAsId() {
	return phoneAsId;
}

Lead::Lead(string lead, long phoneAsId) {
	this->leadDetails = lead;
	this->phoneAsId = phoneAsId;
}
string Lead::toString() {
	return   "ID: "+to_string(phoneAsId) + " Lead: " + leadDetails;
}
