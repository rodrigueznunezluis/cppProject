//Header Files
#include <iostream>
#include <fstream>
#include <string>
using std::string;
using namespace std;

//Class definition for ticket 
class ticket {
     public: 
         char name[10];
         char cno[10];
}  t ; //object definition for the ticket

//Class definition for card 
class card : public ticket { //inheritence for public ticket
public:
    char address[50];
    char emailid[20];
} v; //object definition for card

//Prototype Call for the functions definitions.
void pay(int);
void random();
void card();

//Main function 
int main() {
    system("CLS");
    //Integer Declaration
    int ent, a, b, N, x, cardid;

    char ans;
};