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
		setEventName(name);
		ids++;
		seatNumber = Seat;
		row = Row;
		stand = Stand;

	}
	ticket(ticket& copy) :ticketid(ids) {
		setPrice(copy.price);
		setEventName(copy.eventname);
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

	void SetRow(int Row) { row = Row; }
	int getRow() { return row; }

	void setStand(string Stand) { stand = Stand; }
	string getStand() { return stand; }

	void setEventName(const char* Name) {
		if (std::strlen(Name) > 0) {
			eventname = new char[std::strlen(Name) + 1 ];
			strcpy_s(eventname, std::strlen(Name) + 1, Name);
		}
	}
	const char* getEventName() {
		return this->eventname;
	}
	int getTicketid() {
		return ticketid;
	}
	static int getCurrentid() {
		return ids;
	}
	static string getIssuer() {
		return issuedBy;
	}
	static void setIssuer(string issuer) {
		issuedBy = issuer;
	}
	//Operators
	ticket* operator=(const ticket& copy) {
		setEventName(copy.eventname);
		setPrice(copy.price);
		return this;
	}
};

string ticket::issuedBy("LuisRodriguez");
int ticket::ids(0);

class entryCard {
private:
	ticket* tickets;
	int noGuests;

public:
	entryCard() {
		tickets = nullptr;
			noGuests = 0;
	}
	entryCard(const ticket* Vtickets, int guest) {
		setTickets(Vtickets, guest);
	}
	~entryCard() {
		if (tickets != nullptr)
			delete[] tickets;
	}

	void setTickets(const ticket* Vtickets, int guests) {
		if (guests > 0 && Vtickets != nullptr) {
			if (tickets != nullptr)
				delete[]tickets;
			tickets = new ticket[guests];
			for (int i(0); i < guests; i++)
				tickets[i] = Vtickets[i];
			noGuests = guests;
		}
	}
	
	ticket& operator[](int index) {
		if(index < noGuests)
			return tickets[index];
	}
};

class Event { //private class event
private:
	struct Stand { string name; float price; };
	string name;
	string adress;
	Stand* stands;
	int noStandTypes;
	int noSeats;

public:
	Event() {
		name = "";
		adress = "";
		stands = nullptr;
		noSeats = 0;
	}
	Event(string Name, string Adress, Stand* VStands, int Stands, int Seats) {
		setName(Name);
		setAdress(Adress);
		setStands(VStands, Stands);
		setSeats(Seats);
	}


	void setName(string Name) { name = Name; }
	string getName() { return name; }

	void setAdress(string Adress) { adress = Adress; }
	string getAdress() { return adress; }

	void setSeats(int Seats) { noSeats = Seats; }
	int getSeats() { return noSeats; }

	void setStands(Stand* VStands, int Stands) {
		if (Stands > 0 && VStands != nullptr) {
			if (stands != nullptr)
				delete[] stands;
			stands = new Stand[Stands];
			for (int i(0); i < Stands; i++) {
				stands[i].name = VStands[i].name;
				stands[i].price = VStands[i].price;
			}
			noStandTypes = Stands;

		}
	}
	~Event() {
		if (stands != nullptr)
			delete[] stands;
	}
	Stand* operator[](int index) {
		if (index < noStandTypes)
			return &(stands[index]);
		else
			return nullptr;
	}
};
int main(int argc, char* argv) {

	return 0;
}

			
