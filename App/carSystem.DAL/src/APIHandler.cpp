#include "APIHandler.hpp"

APIHandler::APIHandler()
{
    authenticationToken.open(".env");

    if (authenticationToken.is_open()) {
        std::string line;
        int counter = 0;
        while (std::getline(authenticationToken, line)) {
            counter++;
            if (counter == 1)
                adminName = line;
            else
                adminPassword = line;
        }
        authenticationToken.close();
    }
    else {
        return;
    }
}

void APIHandler::postUser(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string enteredRole)
{
    json postData = json{
        {"contactNumber", enteredContactNumber},
        {"email", enteredEmail},
        {"name", enteredName},
        {"password", enteredPassword},
        {"role", enteredRole}
    };

    cpr::Response r = cpr::Post(
        cpr::Url{ "http://localhost:8000/api/users" },
        cpr::Authentication{ adminName, adminPassword },
        cpr::Body{
            postData.dump()
        },
        cpr::Header{ {"Content-Type", "application/json"} }
    );

    if (r.status_code >= 200 && r.status_code < 300) {
        std::cout << "Data posted successfully!\n";
    }
    else {
        std::cout << "Error posting data: " << r.text << "\n";
    }
}

void APIHandler::getUsers()
{
	cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:8000/api/users" },
		cpr::Authentication{ adminName, adminPassword });

    if (r.status_code >= 200 && r.status_code <= 300) {
        try
        {
            JSONRes = json::parse(r.text);
        }
        catch (json::parse_error& ex)
        {
            std::cout << "There is a problem with the server! Please try again later!";
        }
    }
    else
        std::cout << "Error getting data: " << r.text << "\n";
}

bool APIHandler::checkLoginRegister(string enteredName, string enteredContactNumber, string enteredEmail, string enteredPassword, string isLogOrReg)
{
    getUsers();

    for (const auto& obj : JSONRes) {
        string email = obj["email"].get<string>();
        verify.emails.push_back(email);

        string password = obj["password"].get<string>();
        verify.passwords.push_back(password);

        string name = obj["name"].get<string>();
        verify.names.push_back(name);

        string contactNumber = obj["contactNumber"].get<string>();
        verify.contactNumbers.push_back(contactNumber);
    }

    // check if matching email and password are found
    bool foundPassword = false;
    for (const auto& password : verify.passwords) {
        if (enteredPassword == password)
        {
            foundPassword = true;
            break;
        }
    }

    bool foundEmail = false;
    for (const auto& email : verify.emails) {
        if (enteredEmail == email) {
            foundEmail = true;
            break;
        }
    }

    bool foundName = false;
    for (const auto& name : verify.names) {
        if (enteredName == name) {
            foundName = true;
            break;
        }
    }

    bool foundContactNumber = false;
    for (const auto& contactNumber : verify.contactNumbers) {
        if (enteredContactNumber == contactNumber) {
            foundContactNumber = true;
            break;
        }
    }
    
    if (isLogOrReg == "login")
        return foundEmail && foundPassword;
    else if (isLogOrReg == "register")
        return !(foundEmail);

    return 0;
}

int APIHandler::getUserId(string enteredEmail)
{
    getUsers();

    for (const auto& obj : JSONRes) {
        string email = obj.at("email").get<string>();
        verify.emails.push_back(email);
    }

    int i = 0;
    for (const auto& email : verify.emails) {
        if (enteredEmail == email) {
            loggedUserId = i;
            return loggedUserId;
        }
        i++;
    }
    return -1;
}

string APIHandler::getName(string enteredEmail)
{
    getUsers();

    int userId = getUserId(enteredEmail);

    obj = JSONRes[userId];

    if (obj.contains("name") && obj["name"].is_string()) {
        return obj["name"].get<std::string>();
    }
    else {
        std::cout << "Handle throw";
        return "";
    }
}

string APIHandler::getRole(string enteredEmail)
{
    getUsers();

    int userId = getUserId(enteredEmail);

    obj = JSONRes[userId];
    if (obj.contains("role") && obj["role"].is_string()) {
        return obj["role"].get<string>();
    }
    else {
        std::cout << "Handle throw";
        return "";
    }
}

void APIHandler::postLog(int userId, int vehicleId)
{
    json postData = json{
        {"userId", userId},
        {"vehicleId", vehicleId},
    };

    cpr::Response r = cpr::Post(
        cpr::Url{ "http://localhost:8000/api/users" },
        cpr::Authentication{ adminName, adminPassword },
        cpr::Body{
            postData.dump()
        },
        cpr::Header{ {"Content-Type", "application/json"} }
    );

    if (r.status_code >= 200 && r.status_code < 300) {
        std::cout << "Data posted successfully!\n";
    }
    else {
        std::cout << "Error posting data: " << r.text << "\n";
    }
}

void APIHandler::getLogs()
{
    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:8000/api/logs" },
        cpr::Authentication{ adminName, adminPassword });

    if (r.status_code >= 200 && r.status_code <= 300) {
        try
        {
            JSONRes = json::parse(r.text);
        }
        catch (json::parse_error& ex)
        {
            std::cout << "There is a problem with the server! Please try again later!";
        }
    }
    else
        std::cout << "Error getting data: " << r.text << "\n";
}

void APIHandler::putVehicle(string vehicleType, string name, string manufacturer, string model, bool isReserved,
string reservationDate, string location, string price, int reservedById)
{
    json postData = json{
        {"vehicleType", vehicleType},
        {"name", name},
        {"manufacturer", manufacturer},
        {"model", model},
        {"isReserved", isReserved},
        {"reservationDate", reservationDate},
        {"location", location},
        {"price", price},
        {"reservedById", reservedById}
    };

    cpr::Response r = cpr::Put(
        cpr::Url{ "http://localhost:8000/api/users" },
        cpr::Authentication{ adminName, adminPassword },
        cpr::Body{
            postData.dump()
        },
        cpr::Header{ {"Content-Type", "application/json"} }
    );

    if (r.status_code >= 200 && r.status_code < 300) {
        std::cout << "Data posted successfully!\n";
    }
    else {
        std::cout << "Error posting data: " << r.text << "\n";
    }
}

void APIHandler::getVehicles()
{
    cpr::Response r = cpr::Get(cpr::Url{ "http://localhost:8000/api/vehicles" },
        cpr::Authentication{ adminName, adminPassword });

    if (r.status_code >= 200 && r.status_code <= 300) {
        try
        {
            JSONRes = json::parse(r.text);
        }
        catch (json::parse_error& ex)
        {
            std::cout << "There is a problem with the server! Please try again later!";
        }
    }
    else
        std::cout << "Error getting data: " << r.text << "\n";
}

void APIHandler::getVehicleParametres()
{
    getVehicles();

    for (const auto& obj : JSONRes) {
        std::string vehicleType = obj["vehicleType"].get<std::string>();
        vehicle.vehicleTypes.push_back(vehicleType);

        std::string name = obj["name"].get<std::string>();
        vehicle.names.push_back(name);

        std::string manufacturer = obj["manufacturer"].get<std::string>();
        vehicle.manufacturers.push_back(manufacturer);

        std::string model = obj["model"].get<std::string>();
        vehicle.models.push_back(model);

        bool reserved = obj["isReserved"].get<bool>();
        vehicle.isReserved.push_back(reserved);

        std::string reservationDate = obj["reservationDate"].get<std::string>();
        vehicle.reservationDates.push_back(reservationDate);

        std::string location = obj["location"].get<std::string>();
        vehicle.locations.push_back(location);

        int price = obj["price"].get<int>();
        vehicle.prices.push_back(price);

        /*std::string reservedById = obj["reservedById"].get<std::string>();
        reservedByIds.push_back(reservedById);*/

        data.push_back(vehicle);
    }
}

void APIHandler::passData(vehicles& dataVector) {
    getVehicleParametres();

    dataVector = vehicle;
}

std::vector<int> APIHandler::getVehiclePricesIndexes(int budgetChoice, string vehicleType, std::vector<int> vehicleP, std::vector<string> vehicleT)
{
    getVehicleParametres();

    vehiclePrices = vehicleP;
    vehicleTypes = vehicleT;

    switch (budgetChoice) {
    case 1:
    {
        std::vector<int> minIndexes;
        std::vector<int> minValues;
        int count = 0;

        for (int i = 0; i < vehiclePrices.size(); i++) {
            if (vehicleType == "allTypes" || vehicleType == vehicleTypes.at(i)) {
                if (count < 3) {
                    minIndexes.push_back(i);
                    minValues.push_back(vehiclePrices.at(i));
                    count++;
                }
                else {
                    auto max_element = std::max_element(minValues.begin(), minValues.end());
                    if (vehiclePrices.at(i) < *max_element) {
                        *max_element = vehiclePrices.at(i);
                        minIndexes[std::distance(minValues.begin(), max_element)] = i;
                    }
                }
            }
        }

        return minIndexes;
    }

    case 2:
    {
        std::vector<int> middleIndexes;

        std::vector<int> sortedVehiclePrices = vehiclePrices;
        std::sort(sortedVehiclePrices.begin(), sortedVehiclePrices.end());

        int middleIndex = sortedVehiclePrices.size() / 2;

        for (int i = 0; i < vehiclePrices.size(); i++) {
            if (vehicleType == "allTypes" || vehicleType == vehicleTypes.at(i)) {
                if (vehiclePrices[i] == sortedVehiclePrices[middleIndex] ||
                    vehiclePrices[i] == sortedVehiclePrices[middleIndex - 1] ||
                    vehiclePrices[i] == sortedVehiclePrices[middleIndex + 1])
                {
                    middleIndexes.push_back(i);
                }
            }
        }

        return middleIndexes;
    }

    case 3:
    {
        std::vector<int> maxIndexes;
        std::vector<int> maxValues;
        int count = 0;

        for (int i = 0; i < vehiclePrices.size(); i++) {
            if (vehicleType == "allTypes" || vehicleType == vehicleTypes.at(i)) {
                if (count < 3) {
                    maxIndexes.push_back(i);
                    maxValues.push_back(vehiclePrices.at(i));
                    count++;
                }
                else {
                    auto min_element = std::min_element(maxValues.begin(), maxValues.end());
                    if (vehiclePrices.at(i) > *min_element) {
                        *min_element = vehiclePrices.at(i);
                        maxIndexes[std::distance(maxValues.begin(), min_element)] = i;
                    }
                }
            }
        }

        return maxIndexes;
    }
    }

    return std::vector<int>();
}

//int main() {
//    APIHandler handler;
//    std::vector<int> da = handler.getVehiclePricesIndexes(1, "SUV");
//
//    /*for (int i = 0; i < 3; i++) {
//        if (i < da.size()) {
//            std::cout << da[i] << " ";
//        }
//    }*/
//    
//    std::vector<vehicles> dataV;
//    dataV.resize(handler.data.size());
//    handler.passData(dataV);
//
//    for (int i = 0; i < 100; i++) {
//        if (i < dataV.size()) {
//            std::cout << dataV.at(i).vehicleTypes.at(i) << " ";
//        }
//    }
//}