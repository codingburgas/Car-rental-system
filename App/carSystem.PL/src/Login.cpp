#include "../include/Login.hpp"
Login::Login(string type) : Scene(type) {
    InputField* emailField    = new InputField(RectangleShape(), Vector2f(455, 279), Vector2f(370, 34), "email",    22, Color::White);
    InputField* passwordField = new InputField(RectangleShape(), Vector2f(455, 462), Vector2f(370, 34), "password", 22, Color::White);

    this->inputs.push_back(passwordField);
    this->inputs.push_back(emailField);

    this->textureLoginBlack.loadFromFile("./assets/credentials/loginRegister/login/Login.png");
    this->spriteLoginBlack.setTexture(this->textureLoginBlack);

    this->textureLoginWhite.loadFromFile("./assets/credentials/loginRegister/login/LoginWhite.png");
    this->spriteLoginWhite.setTexture(this->textureLoginWhite);

    this->renderTexture.create(1280, 720);
    this->renderTexture.clear(Color::Transparent);

    for (int i = 0; i < 100; i++) {
        this->transformProgress[i] = 0.0f;
    }

    this->transformSpeed = 0.008f;

    this->loginRegButton.push_back(Vector2f(542, 601));
    this->loginRegButton.push_back(Vector2f(195, 48));
}

void Login::backgroundTransformation(Sprite sprite1, Sprite sprite2, Texture Texture2, float* transformProgess, int index) {
    renderTexture.clear(Color::Transparent);
    renderTexture.draw(sprite1);

    transformProgress[index] += transformSpeed;
    if (transformProgress[index] > 1.0f)
        transformProgress[index] = 1.0f;

    sf::Sprite combinedSprite(Texture2);
    combinedSprite.setPosition(sprite1.getPosition());
    combinedSprite.setColor(sf::Color(255, 255, 255, 255 * transformProgress[index]));
    renderTexture.draw(combinedSprite);

    renderTexture.display();
}

void Login::update(float deltaTime) {

}

void Login::draw(RenderWindow& window) {
}

void Login::draw(RenderWindow& window, int counter)
{
    Sprite renderSprite(renderTexture.getTexture());

    window.draw(spriteLoginBlack);

    if (counter % 2 == 0 && counter != 0) {
        backgroundTransformation(spriteLoginWhite, spriteLoginBlack, textureLoginBlack, transformProgress, counter);
    }
    else if (counter % 2 != 0) {
        backgroundTransformation(spriteLoginBlack, spriteLoginWhite, textureLoginWhite, transformProgress, counter);
    }

    if (counter != 0)
        window.draw(renderSprite);

    for (auto field : this->inputs) {
        field->printInput(window);
    }
}

void Login::textHandler(RenderWindow& window, Event& event) {
    for (auto field : this->inputs) {
        field->handleInput(window, event);
    }
}

void Login::getInputs() {
    for (auto field : this->inputs) {
        this->answers.push_back(field->getInput());
    }
}

void Login::updateBg() {

}

bool Login::haltInput() {
    return false;
}

