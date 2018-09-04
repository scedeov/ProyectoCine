/*	Version 1.0
	27/09/16
	Steven Cedeño V.
*/
#ifndef ASIENTO
#define ASIENTO

#include <iostream>

using namespace std;

class Asiento
{
private:
	string asi;
public:
	Asiento();
	~Asiento();
	string getAsiento();
	void setAsiento(string);
};

#endif
