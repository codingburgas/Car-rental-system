#pragma once
#include <Handler.hpp>
#include <Vehicle.hpp>

class LoginRegister {
private:
	Handler handler;
public:

	LoginRegister() = default;
	~LoginRegister() = default;

	void postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole);
	void getUsers();

	bool checkLoginRegister(string enteredName, string eneteredContactNumber, string email, string password, string isLogOrReg);

	string getName(string enteredEmail);
	string getRole(string enteredEmail);

	int getUserId(string enteredEmail);

	void putVehicle(string vehicleType, string name, string manufacturer, string model, bool isReserved,
		string reservationDate, string location, string price, int reservedById);

	/*vector<vehicles> getVehicleParametres();

	void passData(std::vector<vehicles> data);*/

	//vector<int> getVehiclePricesIndexes(int budgetChoice, string carType);
};