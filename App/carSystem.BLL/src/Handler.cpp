#include "../include/Handler.hpp"

void Handler::postLogging(int userId, int vehicleId)
{
	this->handler.postLog(userId, vehicleId);
}

void Handler::getLoggings()
{
	this->handler.getLogs();
}

void Handler::postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole)
{
	this->handler.postUser(enteredName, enteredContactNumber, enteredEmail, enteredPassword, enteredRole);
}

void Handler::getUsers()
{
	this->handler.getUsers();
}

bool Handler::checkLoginRegister(string enteredName, string eneteredContactNumber, string email, string password, string isLogOrReg)
{
	if (email == "" || password == "")
		return 0;
	if (isLogOrReg == "register" && (enteredName == "" || eneteredContactNumber == ""))
		return 0;

	return this->handler.checkLoginRegister(enteredName, eneteredContactNumber, email, password, isLogOrReg);
}

string Handler::getName(string enteredEmail)
{
	return this->handler.getName(enteredEmail);
}

string Handler::getRole(string enteredEmail)
{
	return this->handler.getRole(enteredEmail);
}

int Handler::getUserId(string enteredEmail)
{
	return this->handler.getUserId(enteredEmail);
}

void Handler::putVehicles(string vehicleType, string name, string manufacturer, string model, bool isReserved, string reservationDate, string location, string price, int reservedById)
{
	this->handler.putVehicle(vehicleType, name, manufacturer, model, isReserved,
		reservationDate, location, price, reservedById);
}

//void Handler::passedData(std::vector<vehicles> data)
//{
//	handler.passData(data);
//}

//std::vector<int> Handler::getVehiclePricesIndex(int budgetChoice, string carType)
//{
//	return this->handler.getVehiclePricesIndexes(budgetChoice, carType);
//}

//int main() {
//	Handler handler;
//	std::vector<string> v;
//	v.resize(14);
//	handler.getVehicleParametre(v);
//}