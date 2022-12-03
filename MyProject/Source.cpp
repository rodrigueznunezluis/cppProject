//Header Files
#include <iostream>
#include <fstream>
#include <string>
using std::string;


class ticket { //Class definition for ticket
private:
	static string issuedBy;
	static int ids;
	const int ticketid;
	float price;
	char* eventname = nullptr;
	int seatNumber;
	int row;
	string stand;
public:

	ticket() :ticketid(ids) { ids++; price = 0; }

	ticket(float price, const char* name, int Seat, int Row, string Stand) :ticketid(ids) {
		setPrice(price);
		SetEventName(name);
		ids++;
		seatNumber = Seat;
		row = Row;
		stand = Stand;

	}
	ticket(ticket& copy) :ticketid(ids) {
		setPrice(copy.price);
		setEventName(Copy.eventname);
		ids++;
		seatNumber = copy.seatNumber;
		row = copy.row;
		stand = copy.stand;

	}
	~ticket() {

		if (eventname != nullptr)
			delete[] eventname;
	}
	//getters and setters
	void setPrice(float Price) {
		if (price > 0) {
			this->price = Price;
		}
	}
	float getPrice() { return this->price; }

	void setSeat(int Seat) { seatNumber = Seat; }
	int getSeat() { return seatNumber; }
};