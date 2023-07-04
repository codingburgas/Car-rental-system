#include "../include/LoginRegister.hpp"

void LoginRegister::postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole)
{
	this->handler.postUser(enteredName, enteredContactNumber, enteredEmail, enteredPassword, enteredRole);
}

void LoginRegister::getUsers()
{
	this->handler.getUsers();
}

bool LoginRegister::checkLoginRegister(string enteredName, string eneteredContactNumber, string email, string password, string isLogOrReg)
{
	return this->handler.checkLoginRegister(enteredName, eneteredContactNumber, email, password, isLogOrReg);
}

string LoginRegister::getName(string enteredEmail)
{
	return this->handler.getName(enteredEmail);
}

string LoginRegister::getRole(string enteredEmail)
{
	return this->handler.getRole(enteredEmail);
}

int LoginRegister::getUserId(string enteredEmail)
{
	return this->handler.getUserId(enteredEmail);
}

void LoginRegister::putVehicle(string vehicleType, string name, string manufacturer, string model, bool isReserved, string reservationDate, string location, string price, int reservedById)
{
	this->handler.putVehicles(vehicleType, name, manufacturer, model, isReserved,
		reservationDate, location, price, reservedById);
}

//void LoginRegister::passData(std::vector<vehicles> data)
//{
//	this->handler.passedData(data);
//}

//std::vector<int> LoginRegister::getVehiclePricesIndexes(int budgetChoice, string carType)
//{
//	return this->handler.getVehiclePricesIndex(budgetChoice, carType);
//}