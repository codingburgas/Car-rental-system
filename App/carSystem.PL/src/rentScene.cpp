#include "../include/rentScene.hpp"

rentScene::rentScene(string type, string email) : Scene(type) {
	this->type = type;
	this->bgTexture.loadFromFile("./assets/credentials/CarScreen.png");
	this->bgSprite.setTexture(this->bgTexture);

	this->loginRegButton.push_back(Vector2f(50, 600));
	this->loginRegButton.push_back(Vector2f(215, 645));

	this->userId = logRegister.getUserId(email);

	eclipseSprites.resize(35);
    eclipseTextures.resize(35);
	for (int i = 0; i < 35; i++) {
		this->eclipseTextures.at(i).loadFromFile("./assets/rent scene animation/eclipses/Frame " + to_string(i + 5) + ".png");;

		this->eclipseSprites.at(i).setTexture(this->eclipseTextures.at(i));
        this->eclipseSprites.at(i).setPosition(225, -75);
	}

    this->currentFrame = 0;
    this->frameDuration = 0.8f;
    this->elapsedTimeFrame = 0.0f;
    this->animate = true;

    this->location.loadFromFile("./assets/rent scene animation/icons/location.png");
    this->model.loadFromFile("./assets/rent scene animation/icons/model.png");
    this->manufacturer.loadFromFile("./assets/rent scene animation/icons/manufacturer.png");
    this->vehicleType.loadFromFile("./assets/rent scene animation/icons/vehicle type.png");

    this->locationSprite.setTexture(this->location);
    this->locationSprite.setPosition(845, 560);

    this->modelSprite.setTexture(this->model);
    this->modelSprite.setPosition(930, 405);

    this->manufacturerSprite.setTexture(this->manufacturer);
    this->manufacturerSprite.setPosition(915, 210);

    this->vehicleTypeSprite.setTexture(this->vehicleType);
    this->vehicleTypeSprite.setPosition(790, 60);

    this->fadeDuration = 2.0f;
    this->alpha = 0.0f;
    this->elapsedTime = 0.0f;

    this->elapsedTimeBegin = 0.0f;
}

void rentScene::update(float deltaTime) {
    Time timeBegin = clockTimeBegin.restart();
    elapsedTimeBegin += timeBegin.asSeconds();

    if (elapsedTimeBegin >= 0.85f) {
        //ellipse animation
        if (animate) {
            Time frameTime = clockEllipse.restart();
            elapsedTimeFrame += frameTime.asSeconds();

            if (elapsedTimeFrame >= frameDuration) {
                currentFrame = (currentFrame + 1) % eclipseSprites.size();
                elapsedTimeFrame = 0.0f;

                if (currentFrame == 0) {
                    animate = false;
                    lastFrameVisible = true;
                }
            }
        }
    }

    //fade animation
    float frameTime = clockIcon.restart().asSeconds();
    elapsedTime += frameTime;
    if (elapsedTime < fadeDuration)
    {
        float progress = elapsedTime / fadeDuration;
        alpha = progress * 255.0f;
        if (alpha > 255.0f) {
            alpha = 255.0f;
        }
    }

    Color spriteColor = locationSprite.getColor();
    spriteColor.a = static_cast<sf::Uint8>(alpha);

    locationSprite.setColor(spriteColor);
    modelSprite.setColor(spriteColor);
    manufacturerSprite.setColor(spriteColor);
    vehicleTypeSprite.setColor(spriteColor);
}

void rentScene::draw(RenderWindow& window) {
	window.draw(this->bgSprite);

    if (animate)
        window.draw(eclipseSprites[currentFrame]);
    else if (lastFrameVisible)
        window.draw(eclipseSprites[34]);

    window.draw(locationSprite);
    window.draw(modelSprite);
    window.draw(manufacturerSprite);
    window.draw(vehicleTypeSprite);
}

void rentScene::draw(RenderWindow& window, int counter) {
}

void rentScene::textHandler(RenderWindow& window, Event& event) {

}

void rentScene::getInputs() {

}

void rentScene::updateBg() {

}

bool rentScene::haltInput() {
    return false;
}