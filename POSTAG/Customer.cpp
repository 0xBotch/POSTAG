#include "Customer.h"
#include<iostream>
#include<vector>

Customer::Customer(){}

Customer::Customer(int Id){
	id = Id;
}

void Customer::setId(int Id){
	id = Id;
}

void Customer::setDepart(int Depart){
	depart.push_back(Depart);
}

void Customer::setItemNumber(int ItemNumber){
	itemNumber.push_back(ItemNumber);
}

void Customer::setTotal(double Total){
	total.push_back(Total);
}

int Customer::getID(){

	return id;
}

int Customer::getDepart(int i)
{
	return depart[i];
}

int Customer::getItemNumber(int i)
{
	return itemNumber[i];
}

double Customer::getTotal(int i)
{
	return total[i];
}

int Customer::getSize()
{
	return itemNumber.size();
}






