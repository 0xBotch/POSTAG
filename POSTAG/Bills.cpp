#include "Bills.h"
#include<iostream>

//Default Contructor
Bills::Bills(){}

//Contructor
Bills::Bills(int Id, int Depart, int ItemNumber, double Total){
	id = Id;
	depart = Depart;
	itemNumber = ItemNumber;
	total = Total;
}


void Bills::setID(int Id){
	id = Id;
}

void Bills::setDepart(int Depart){
	depart = Depart;
}

void Bills::setItemNumber(int ItemNumber){
	itemNumber = ItemNumber;
}

void Bills::setTotal(double Total){
	total = Total;
}

int Bills::getID(){
	return id;
}

int Bills::getDepart(){
	return depart;
}

int Bills::getItemNumber(){
	return itemNumber;
}

double Bills::getTotal(){
	return total;
}
void Bills::print(){
	std::cout << id << " " << depart << " " << itemNumber << " " << total << std::endl;
}
