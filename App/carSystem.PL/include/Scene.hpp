#pragma once 
#include "precompile.hpp"
#include "KeyInput.hpp"

class Scene {
public:
	Scene(string type);
	~Scene() = default;

	// vector of input field pointers
	vector<InputField*> inputs;

	// vector of values inside input fields
	vector<string> answers;

	// 2d vector with each button position and their respective size
	vector<Vector2f> loginRegButton;

	string type;

	virtual void updateBg() = 0;
	virtual void update(float deltaTime) = 0;
	virtual void draw(RenderWindow& window) = 0;
	virtual void draw(RenderWindow& window, int counter) = 0;
	virtual void textHandler(RenderWindow& window, Event& event) = 0;
	virtual void getInputs() = 0;
	virtual bool haltInput() = 0;
};