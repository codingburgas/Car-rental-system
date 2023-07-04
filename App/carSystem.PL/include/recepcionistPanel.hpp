#pragma once

#include "precompile.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

class recepcionistPanel : virtual public Scene {
private:
	Texture bgTexture;
	Sprite bgSprite;
public:
	recepcionistPanel(string type);
	~recepcionistPanel() = default;

	void update(float deltaTime) override;

	void draw(RenderWindow& window) override;

	void draw(RenderWindow& window, int counter) override;

	void textHandler(RenderWindow& window, Event& event) override;

	void getInputs() override;

	bool haltInput() override;

	void updateBg() override;
};