#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include<vector>

class Customer
{
public:
	Customer();
	Customer(int Id);
	
	void setId(int);
	void setDepart(int);
	void setItemNumber(int);
	void setTotal(double);

	int getID();
	int getDepart(int);
	int getItemNumber(int);
	double getTotal(int);

	int getSize();
private:
	int id;
	std::vector<int> depart;
	std::vector<int> itemNumber;
	std::vector<double> total;
	int size;
};

#endif // CUSTOMER_H
