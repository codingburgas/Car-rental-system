#include "../include/Map.hpp"

Map::Map(string type) : Scene(type)
{
    authenticationToken.open("../map/.env");

    if (authenticationToken.is_open()) {
        std::string line;
        int counter = 0;
        while (std::getline(authenticationToken, line)) {
            counter++;
            if (counter == 2)
                API_KEY = line;
        }
        authenticationToken.close();
    }
    else {
        return;
    }

    htmlPath = "D:/ne moga da svurja api tokena/App/map/index.html";
}

void Map::update(float deltaTime)
{
    cout << API_KEY;
    listener.listen(3000);
    listener.accept(socket);

    system(("start " + htmlPath).c_str());

    char windowData[128];
    std::size_t received;
    if (socket.receive(windowData, sizeof(windowData), received) == sf::Socket::Done) {
        // Process the received data
        std::string receivedData(windowData, received);

        // Extract the coordinates from the received data
        std::size_t coordsPos = receivedData.find("coords=");
        if (coordsPos != std::string::npos) {
            std::string coordinates = receivedData.substr(coordsPos + 7);
            std::cout << "Coordinates: " << coordinates << std::endl;

            // Extract latitude and longitude
            std::size_t commaPos = coordinates.find(",");
            double latitude = std::stod(coordinates.substr(0, commaPos));
            double longitude = std::stod(coordinates.substr(commaPos + 1));

            // Use geocoding to convert coordinates into an address
            std::string address = geocodeAddress(latitude, longitude);

            // Send the address back to the HTML page
            std::string response = "receiveData('" + address + "');";
            socket.send(response.c_str(), response.length() + 1);
        }
    }
}

void Map::draw(RenderWindow& window)
{
    window.setActive(false);
}

void Map::draw(RenderWindow& window, int counter)
{
}

void Map::textHandler(RenderWindow& window, Event& event)
{
}

void Map::getInputs()
{
}

void Map::updateBg() {

}

bool Map::haltInput()
{
	return false;
}

string Map::geocodeAddress(double latitude, double longitude) {
    sf::Http http("api.opencagedata.com");
    sf::Http::Request request("/geocode/v1/json?pretty=1&key=" + API_KEY + "&q=" +
        std::to_string(latitude) + "," + std::to_string(longitude));
    sf::Http::Response response = http.sendRequest(request);

    nlohmann::json jsonData = nlohmann::json::parse(response.getBody());
    std::string address = jsonData["results"][0]["formatted"].get<std::string>();
    return address;
}