#include "Day.h"
#include <cstdlib>
#include <array>
#include<iostream>
#include <iomanip>

/*
The Day Class add, updates, process and prints the transactions happening at the POS
*/
//Contructor
Day::Day(){
	start();
}
/*
get the data from the text file for each department on the machine and updates it
when scaling it, the data is to be received from POS scanner
*/
void Day::start(){
	in.open("assi3.txt");
	while (!in.eof()) {
		double temp;

		for (int i = 0; i < 12; i++) {
			in >> temp;
			bill[i].setID((int)temp);
			in >> temp;
			bill[i].setDepart((int)temp);
			in >> temp;
			bill[i].setItemNumber((int)temp);
			in >> temp;
			bill[i].setTotal(temp);
		}

		//process the bill data
		process();
	}
	in.close();
}
/*
process the the data from each department separately, adds applicatble taxes and calculates the total amount due
*/
void Day::process(){
	Bills bill1;
	Customer customer132;
	Customer customer254;
	for (int i = 0; i < 12; i++) {
			bill1 = Bills(bill[i].getID(), bill[i].getDepart(), bill[i].getItemNumber(), bill[i].getTotal());

			if (bill1.getID() == 132){
				customer132.setId(132);
				customer132.setDepart(bill1.getDepart());
				customer132.setItemNumber(bill1.getItemNumber());
				customer132.setTotal(bill1.getTotal());
			}
			else if (bill1.getID() == 254) {
				customer254.setId(254);
				customer254.setDepart(bill1.getDepart());
				customer254.setItemNumber(bill1.getItemNumber());
				customer254.setTotal(bill1.getTotal());
			}

	}




	print(customer254);


	//print bill for customer i iterative
	// when scaling, data can be send to printer
}

void Day::print(Customer customer){
	out.open("result.txt");

	//bill display
	out << "                  HIGH FASHION DEPARTMENT STORE" << std::endl;
	out << "                    MONTHLY BILLING STATEMENT" << std::endl;
	out << "                             " << customer.getID() << std::endl;

	out << std::endl << std::endl;
	out << "DEPT NBR " << " ITEM NBR " << " AMOUNT OF PURCHASE " << " DISCOUNT AMOUNT " << " NET AMOUNT " << std::endl;
	out << "---------------------------------------------------------------" << std::endl;

	for (int i = 0; i < customer.getSize(); i++) {
		out << std::left << std::setw(10) << customer.getDepart(i);
		out << std::left << std::setw(10) << customer.getItemNumber(i);
		out << std::left << std::setw(20) << customer.getTotal(i);

		if (customer.getDepart(i) == 1 || customer.getDepart(i) == 2){
			if (customer.getTotal(i) >= 10) {
				out << std::left << std::setw(17) << (customer.getTotal(i) * 0.05);
				out << std::left << std::setw(10) << (customer.getTotal(i)) - (customer.getTotal(i) * 0.05) << std::endl;
				if (customer.getDepart(i) == 1) {
					depart[1] += customer.getTotal(i);
					discount[1] += (customer.getTotal(i) * 0.05);
				}
				else{
					depart[2] += customer.getTotal(i);
					discount[2] += (customer.getTotal(i) * 0.05);
				}
			}
			else {
				out << std::left << std::setw(17) << "0.00";
				out << std::left << std::setw(10) << customer.getTotal(i) << std::endl;
				if (customer.getDepart(i) == 1) {
					depart[1] += customer.getTotal(i);
				}
				else {
					depart[2] += customer.getTotal(i);
				}
			}
		}
		else if(customer.getDepart(i) == 3 || customer.getDepart(i) == 4){
			if (customer.getTotal(i) >= 25) {
				out << std::left << std::setw(17) << (customer.getTotal(i) * 0.08);
				out << std::left << std::setw(10) << (customer.getTotal(i)) - (customer.getTotal(i) * 0.08) << std::endl;
				if (customer.getDepart(i) == 3) {
					depart[3] += customer.getTotal(i);
					discount[3] += (customer.getTotal(i) * 0.08);
				}
				else {
					depart[4] += customer.getTotal(i);
					discount[4] += (customer.getTotal(i) * 0.08);
				}
			}
			else {
				out << std::left << std::setw(17) << "0.00";
				out << std::left << std::setw(10) << customer.getTotal(i) << std::endl;
				if (customer.getDepart(i) == 3) {
					depart[3] += customer.getTotal(i);
				}
				else {
					depart[4] += customer.getTotal(i);
				}
			}
		}
	}


	out << std::left << std::setw(20) << "Total Depart 1";
	out << std::left << std::setw(20) << depart[1];
	out << std::left << std::setw(17) << discount[1];
	out << std::left << std::setw(10) << (depart[1] - discount[1]) << std::endl;

	out << std::left << std::setw(20) << "Total Depart 2";
	out << std::left << std::setw(20) << depart[2];
	out << std::left << std::setw(17) << discount[2];
	out << std::left << std::setw(10) << (depart[2] - discount[2]) << std::endl;

	out << std::left << std::setw(20) << "Total Depart 3";
	out << std::left << std::setw(20) << depart[3];
	out << std::left << std::setw(17) << discount[3];
	out << std::left << std::setw(10) << (depart[3] - discount[3]) << std::endl;

	out << std::left << std::setw(20) << "Total Depart 4";
	out << std::left << std::setw(20) << depart[4];
	out << std::left << std::setw(17) << discount[4];
	out << std::left << std::setw(10) << (depart[4] - discount[4]) << std::endl;

	for (int i = 0; i < 5; i++) {
		total += (depart[i] - discount[i]);
	}


	out << "						NET TOTAL AMOUNT		" << total << "**" << std::endl;
	out << "						SALES TAX AT 7%			" << (total * 0.07) << std::endl;

	if (total < 100 && total >= 50) {
		total += (total * 0.05);
		out << "						SERVICE CHARGE			" << total << std::endl;
	}
	else if (total < 50) {
		total += (total * 0.10);
		out << "						SERVICE CHARGE			" << total << std::endl;
	}
	else {
		out << "						SERVICE CHARGE			" << "0.00" << std::endl;
	}


	out << std::endl;
	out << "FINAL TOTAL - (PLEASE PAY THIS AMOUNT)	" << (total) + (total * 0.07) << "***" << std::endl;


}
