#include "../include/KeyInput.hpp"

InputField::InputField(RectangleShape _mfield, Vector2f _mposition, Vector2f _msize, string _mtype, float _mfontSize, Color _mtextColor, bool haveOutline)
{
	this->field = _mfield;
    this->field.setPosition(_mposition);
    this->field.setSize(_msize);
    this->field.setFillColor(Color::Transparent);
    if (haveOutline)
        this->field.setOutlineColor(Color(31, 254, 170));
    else
        this->field.setOutlineColor(Color::Transparent);

	this->type = _mtype;
	this->fontSize = _mfontSize;
	this->textColor = _mtextColor;
	this->font.loadFromFile("assets/fonts/texgyreadventor-bold.otf");

    if (this->type == "num") {
        this->maxChars = 15;
    }
    else if (type == "email") {
		this->maxChars = 60;
    }
    else {
		this->maxChars = 18;
    }
}

void InputField::updateField(Vector2f mousePos, RenderWindow& window, Event& event)
{
    printInput(window);
    selectField(mousePos);

    if (!this->isSelected)
        return;

    handleInput(window, event);
}

void InputField::printInput(RenderWindow& window)
{
    char toPass[30] = "";

    if (this->type == "password")
    {
        for (int i = 0; i < this->charCount; i++) {
			toPass[i] = '*';
        }

        for (int i = this->charCount; i < 30; i++) {
            toPass[i] = '\0';
        }
    }

    Text text("", this->font, this->fontSize);

    if (this->type == "password") {
        text.setString(toPass);
    }
    else {
        if (this->charCount > 18) {
            string subStr = this->input.substr(this->charCount - 18);
            text.setString(subStr);
        }
        else {
            text.setString(this->input);
        }
    }

    text.setFillColor(this->textColor);
    text.setPosition(this->field.getPosition().x + 5, this->field.getPosition().y + 4);
    string str = this->input;
    window.draw(this->field);
    window.draw(text);
}

void InputField::handleInput(RenderWindow& window, Event& event) {
    if (!this->isSelected) {
        return;
    }

    if (event.text.unicode == '\b') // Backspace
    {
        if (this->input.length() > 0) {
            this->input.pop_back();
        }
    }
    else if (event.text.unicode < 128) // ASCII characters
    {
        if (this->input.length() < this->maxChars) {
            uint_least32_t key = static_cast<uint_least32_t>(event.text.unicode);
            this->input.push_back(key);
        }
    }

    this->charCount = this->input.length();
}


void InputField::selectField(Vector2f mousePos)
{
    if (field.getGlobalBounds().contains(mousePos))
    {
        this->isSelected = true;
        this->field.setOutlineThickness(2);
        return;
    }
    this->isSelected = false;
    this->field.setOutlineThickness(0);
}

void InputField::resetField(){
    for (int i = 0; i < 30; i++)
    {
        this->input[i] = '\0';
    }
    this->charCount = 0;
}

void InputField::changePos(float x, float y)
{
	this->field.move(x, y);
}

string InputField::getInput()
{
    return this->input;
}
