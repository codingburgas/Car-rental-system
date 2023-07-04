#pragma once

#include "precompile.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

class Map : virtual public Scene {
private:

	fstream authenticationToken;
	string htmlPath;
	TcpListener listener;
	TcpSocket socket;

	string API_KEY;
public:
	Map(string type);
	~Map() = default;

	void update(float deltaTime) override;

	void draw(RenderWindow& window) override;

	void draw(RenderWindow& window, int counter) override;

	void textHandler(RenderWindow& window, Event& event) override;

	void getInputs() override;

	bool haltInput() override;
	void updateBg() override;

	string geocodeAddress(double latitude, double longitude);
};