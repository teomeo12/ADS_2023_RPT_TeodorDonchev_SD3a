#pragma once
#include <iostream>
#include <string>

using namespace std;


class Lead {
private:
	string leadDetails;
	long phoneAsId;
public:
	Lead() {
			leadDetails = "";
			phoneAsId = 0;
		}
	Lead(string lead, long phoneAsId);
	string getLeadDetails();
	long getPhoneAsId();
	/*void setLeadDetails(string leadDetails);
	void setPhoneAsId(long phoneAsId);*/
	string toString();

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
	return "Lead: " + leadDetails + " Phone: " + to_string(phoneAsId);
}
