//Header Files
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using namespace std;

class ticket {
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



};