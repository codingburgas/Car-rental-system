#include "../include/EndScreen.hpp"

endScreen::endScreen(string type) : Scene(type)
{
	this->endScreenTexture.loadFromFile("./assets/credentials/CongratScreen.png");
	this->endScreenSprite.setTexture(endScreenTexture);
}

void endScreen::update(float deltaTime)
{
}

void endScreen::draw(RenderWindow& window)
{
	window.draw(endScreenSprite);
}

void endScreen::draw(RenderWindow& window, int counter)
{
}

void endScreen::textHandler(RenderWindow& window, Event& event)
{
}

void endScreen::getInputs()
{
}

void endScreen::updateBg() {

}

bool endScreen::haltInput()
{
	return false;
}
