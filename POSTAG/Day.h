#ifndef DAY_H
#define DAY_H
#include <fstream>
#include "Bills.h"
#include "Customer.h"


class Day
{
public:
	Day(); //constructor for scenario 1

	void start();
	void process();
	void print(Customer);

private:
	Bills bill[13];
	double depart[5];
	double discount[5];
	double total;
	std::ifstream in;
	std::ofstream out;
};

#endif // DAY_H