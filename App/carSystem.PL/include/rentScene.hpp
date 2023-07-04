#pragma once

#include "precompile.hpp"
#include "Scene.hpp"
#include "SceneManager.hpp"

class rentScene : virtual public Scene, LoginRegister {
private:
	LoginRegister logRegister;

	Texture bgTexture;
	Sprite bgSprite;

	int userId, vehicleId;

	//ellipse animation
	vector<Texture> eclipseTextures;
	vector<Sprite> eclipseSprites;

	int currentFrame;
	int frameDuration;
	Clock clockEllipse;
	float elapsedTimeFrame;
	int frameIndex;
	bool animate, lastFrameVisible;

	//icon animation
	Texture location, model, manufacturer, vehicleType;
	Sprite locationSprite, modelSprite, manufacturerSprite, vehicleTypeSprite;

	Clock clockIcon;
	float fadeDuration;
	float alpha;
	float elapsedTime;

	float elapsedTimeBegin;
	Clock clockTimeBegin;

public:
	rentScene(string type, string email);
	~rentScene() = default;

	void update(float deltaTime) override;

	void draw(RenderWindow& window) override;

	void draw(RenderWindow& window, int counter) override;

	void textHandler(RenderWindow& window, Event& event) override;

	void getInputs() override;

	bool haltInput() override;
	void updateBg() override;
};