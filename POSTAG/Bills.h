#ifndef BILLS_H
#define BILLS_H

const double MORE_THAN_TEN = 0.05;
const double MORE_THAN_TWENTYFIVE = 0.08;
const double SALES_TAX = 0.07;
const double SERVICE_CHARGE_100 = 0.10;
const double SERVICE_CHARGE_50 = 0.05;


class Bills
{
public:
	Bills();
	Bills(int, int, int, double);

	void setID(int);
	void setDepart(int);
	void setItemNumber(int);
	void setTotal(double);

	int getID();
	int getDepart();
	int getItemNumber();
	double getTotal();

	void print();

private:
	int id;
	int depart;
	int itemNumber;
	double total;
};

#endif // BILLS_H