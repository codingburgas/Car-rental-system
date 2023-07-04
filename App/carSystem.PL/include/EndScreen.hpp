#pragma once
#include "Scene.hpp"  

class endScreen : public Scene {
private:
	Texture endScreenTexture;
	Sprite endScreenSprite;

public:
	endScreen(string type);
	~endScreen() = default;

	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void draw(RenderWindow& window, int counter) override;
	void textHandler(RenderWindow& window, Event& event) override;
	void getInputs() override;
	bool haltInput() override;
	void updateBg() override;
};