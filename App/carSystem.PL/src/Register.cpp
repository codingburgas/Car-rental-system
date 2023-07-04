#include "../include/Register.hpp"

Register::Register(string type) : Scene(type) {
    this->type = type;
    InputField* nameField     = new InputField(RectangleShape(), Vector2f(45,  243),  Vector2f(370, 34), "text",        22, Color::White);
    InputField* phoneField    = new InputField(RectangleShape(), Vector2f(474, 243),  Vector2f(367, 34), "num",         22, Color::White);
    InputField* emailField    = new InputField(RectangleShape(), Vector2f(45,  448),  Vector2f(370, 34), "email",       22, Color::White);
    InputField* passwordField = new InputField(RectangleShape(), Vector2f(474, 448),  Vector2f(367, 34), "password",    22, Color::White);
    this->inputs.push_back(nameField);
    this->inputs.push_back(phoneField);
    this->inputs.push_back(passwordField);
    this->inputs.push_back(emailField);

    this->registerBlackTexture.loadFromFile("./assets/credentials/loginRegister/register/Register.png");
    this->registerBlack.setTexture(this->registerBlackTexture);

    this->registerWhiteTexture.loadFromFile("./assets/credentials/loginRegister/register/RegisterWhite.png");
    this->registerWhite.setTexture(this->registerWhiteTexture);

    this->renderTexture.create(1280, 720);
    this->renderTexture.clear(Color::Transparent);

    for (int i = 0; i < 100; i++) {
        this->transformProgress[i] = 0.0f;
    }
    
    this->transformSpeed = 0.008f;

    this->logoTexture.loadFromFile("./assets/credentials/Begin screen.png");
    this->logo.setTexture(this->logoTexture);
    this->logo.setColor(Color(255, 255, 255, 0));

    this->registerBlack.setColor(Color(255, 255, 255, 0));

    this->loginRegButton.push_back(Vector2f(45, 633));
    this->loginRegButton.push_back(Vector2f(195, 48));

    this->transitionDuration = 3.f;
}

//sprites and textures depend on what mode the user is currently using
void Register::backgroundTransformation(Sprite sprite1, Sprite sprite2, Texture Texture2, float* transformProgess, int index) {
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

void Register::update(float deltaTime){
    if (this->animState < 4) {
        //cout << "ez" << endl;
        elapsedTime = this->transitionClock.getElapsedTime().asSeconds();

        if (elapsedTime <= this->transitionDuration / 3 && this->animState == 0)
        {
            float interp = this->elapsedTime / (this->transitionDuration / 3);

            this->logo.setColor(sf::Color(255, 255, 255, (255 * (interp))));
        }
        else if (elapsedTime <= this->transitionDuration / 3 && this->animState == 1) {
            float interp = this->elapsedTime / (this->transitionDuration / 3);
        }
        else if (elapsedTime <= this->transitionDuration / 3 && this->animState == 2) {
            float interp = this->elapsedTime / (this->transitionDuration / 3);

            this->logo.setColor(sf::Color(255, 255, 255, (255 * (1 - interp))));
            this->registerBlack.setColor(sf::Color(255, 255, 255, (255 * (interp))));
        }
        else
        {
            if (this->animState == 0) {
                this->logo.setColor(Color(255, 255, 255, 255));
            }
            this->animState++;
            this->transitionClock.restart();
        }
    }
    
}

void Register::draw(RenderWindow& window) {

}

void Register::draw(RenderWindow& window, int counter){
    Sprite renderSprite(renderTexture.getTexture());

    if ((int)logo.getColor().a > 0) {
        window.draw(logo);
    }
    window.draw(registerBlack);

    if (counter % 2 == 0 && counter != 0) {
        backgroundTransformation(registerWhite, registerBlack, registerBlackTexture, transformProgress, counter);
    }
    else if(counter % 2 != 0) {
        backgroundTransformation(registerBlack, registerWhite, registerWhiteTexture, transformProgress, counter);
    }
    
    if (counter != 0) {
        window.draw(renderSprite);
    }

    for (auto field : this->inputs) {
        field->printInput(window);
    }
}

void Register::textHandler(RenderWindow& window, Event& event) {
    for (auto field : this->inputs) {
        field->handleInput(window, event);
    }
}

void Register::getInputs() {
    for (auto field : this->inputs) {
        this->answers.push_back(field->getInput());
    }
}

void Register::updateBg() {

}

int Register::getAnimState() {
    return this->animState;
}

bool Register::haltInput() {
    if (this->animState == 4) {
        return false;
    }
    return true;
}