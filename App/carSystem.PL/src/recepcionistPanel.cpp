#include "../include/recepcionistPanel.hpp"

recepcionistPanel::recepcionistPanel(string type) :  Scene(type)
{
	InputField* addCar1 = new InputField(RectangleShape(), Vector2f(411, 392), Vector2f(315, 30), "email", 22, Color::Black, false);
	InputField* addCar2 = new InputField(RectangleShape(), Vector2f(817, 392), Vector2f(315, 30), "email", 22, Color::Black, false);
	InputField* addCar3 = new InputField(RectangleShape(), Vector2f(412, 492), Vector2f(315, 30), "email", 22, Color::Black, false);
	InputField* addCar4 = new InputField(RectangleShape(), Vector2f(817, 492), Vector2f(315, 30), "email", 22, Color::Black, false);


	this->inputs.push_back(addCar1);
	this->inputs.push_back(addCar2);
	this->inputs.push_back(addCar3);
	this->inputs.push_back(addCar4);

	this->bgTexture.loadFromFile("./assets/credentials/Receptions.png");
	this->bgSprite.setTexture(bgTexture);

	this->loginRegButton.push_back(Vector2f(1003, 572));
	this->loginRegButton.push_back(Vector2f(140, 42));
}

void recepcionistPanel::updateBg() {
	this->bgTexture.loadFromFile("./assets/credentials/receptionHover/addCarMenu.png");
	this->bgSprite.setTexture(this->bgTexture);
}

void recepcionistPanel::update(float deltaTime)
{
}

void recepcionistPanel::draw(RenderWindow& window)
{
	window.draw(bgSprite);
	for (auto field : this->inputs) {
		field->printInput(window);
	}
}

void recepcionistPanel::draw(RenderWindow& window, int counter)
{

}

void recepcionistPanel::textHandler(RenderWindow& window, Event& event)
{
	for (auto field : this->inputs) {
		field->handleInput(window, event);
	}
}

void recepcionistPanel::getInputs()
{
	for (auto field : this->inputs) {
		this->answers.push_back(field->getInput());
	}
}

bool recepcionistPanel::haltInput()
{
	return false;
}
