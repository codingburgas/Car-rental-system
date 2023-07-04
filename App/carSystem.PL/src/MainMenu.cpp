#include "../include/MainMenu.hpp"

MainMenu::MainMenu(string type, string email) : Scene(type) {
	InputField* loopField = new InputField(RectangleShape(), Vector2f(640, 145), Vector2f(370, 34), "loop", 22, Color::White);

	this->inputs.push_back(loopField);

	this->type = type;
	this->bgTexture.loadFromFile("./assets/credentials/Main.png");
	this->bg.setTexture(this->bgTexture);

	this->name = logRegister.getName(email);
	this->role = logRegister.getRole(email);
	transform(role.begin(), role.end(), role.begin(), ::tolower);

	if (!font.loadFromFile("./assets/fonts/texgyreadventor-bold.otf")) {
		cout << "Handle error";
	}

	this->textName.setFont(font);
	this->textRole.setFont(font);

	this->textName.setString(name);
	this->textRole.setString(role);

	this->textName.setCharacterSize(24);
	this->textRole.setCharacterSize(16);

	this->textName.setStyle(Text::Bold);

	this->textName.setPosition(100.0f, 35.0f);
	this->textRole.setPosition(102.0f, 63.0f);
}

void MainMenu::update(float deltaTime) {

}

void MainMenu::draw(RenderWindow& window) {
	window.draw(this->bg);
	window.draw(this->textName);
	window.draw(this->textRole);
}

void MainMenu::draw(RenderWindow& window, int counter)
{
}

void MainMenu::textHandler(RenderWindow& window, Event& event) {

}

void MainMenu::getInputs() {
	for (auto field : this->inputs) {
		this->answers.push_back(field->getInput());
	}
}

void MainMenu::updateBg() {

}

bool MainMenu::haltInput() {
	return false;
}