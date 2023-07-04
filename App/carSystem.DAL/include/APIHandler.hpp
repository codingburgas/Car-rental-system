#pragma once

#include "Precompile.hpp"
#include "Vehicle.hpp"

class APIHandler {

private:
	std::fstream authenticationToken;
	string adminName, adminPassword;

	json JSONRes;

	struct verification {
		std::vector<string> names, contactNumbers, emails, passwords;
	};
	verification verify;

	//convert to int because of NULL casting error
	std::vector<int> reserveIds;

	//vehicle sorting by price
	std::vector<int> vehiclePrices;
	std::vector<string> vehicleTypes;

	int loggedUserId;

	json obj;
	unsigned objectIndex;

public:
	vehicles vehicle;
	std::vector<vehicles> data;

	APIHandler();
	~APIHandler() = default;

	//User methods
	void postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole);
	void getUsers();

	bool checkLoginRegister(string enteredName, string eneteredContactNumber, string email, string password, string isLogOrReg);

	string getName(string enteredEmail);
	string getRole(string enteredEmail);

	int getUserId(string enteredEmail);

	//Log methods
	void postLog(int userId, int vehicleId);
	void getLogs();

	//Vehicle methods
	void putVehicle(string vehicleType, string name, string manufacturer, string model, bool isReserved,
		string reservationDate, string location, string price, int reservedById);

	void getVehicles();
	void getVehicleParametres();
	void passData(vehicles& dataVector);

	//choice can be 1 -> budget, 2 -> mid, 3 -> expensive
	//carType choice 1 -> all types, 2 -> car, 3 -> van, 4 -> motor, 5 -> truck, 6 -> suv, ;
	std::vector<int> getVehiclePricesIndexes(int budgetChoice, string vehicleType, std::vector<int> vehicleP, std::vector<string> vehicleT);
};