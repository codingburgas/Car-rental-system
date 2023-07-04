#pragma once
#include "Precompile.hpp"
#include <APIHandler.hpp>
#include <Vehicle.hpp>

class Handler {
private: 
	APIHandler handler;

public:

	void postLogging(int userId, int vehicleId);
	void getLoggings();

	void postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole);
	void getUsers();

	bool checkLoginRegister(string enteredName, string eneteredContactNumber, string email, string password, string isLogOrReg);

	string getName(string enteredEmail);
	string getRole(string enteredEmail);

	int getUserId(string enteredEmail);

	void putVehicles(string vehicleType, string name, string manufacturer, string model, bool isReserved,
		string reservationDate, string location, string price, int reservedById);

	//void passedData(std::vector<vehicles> data);

	//std::vector<int> getVehiclePricesIndex(int budgetChoice, string carType);
};