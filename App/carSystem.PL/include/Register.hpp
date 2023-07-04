#pragma once
#include "precompile.hpp"
#include "Scene.hpp"  
#include "KeyInput.hpp"

class Register : public Scene{
private:
	Texture registerBlackTexture;
	Sprite registerBlack;
	Texture logoTexture;
	Sprite logo;

	Clock transitionClock;
	int animState = 0;
	float elapsedTime = 0;
	float transitionDuration = 0;

	Texture registerWhiteTexture;
	Sprite registerWhite;

	RenderTexture renderTexture;

	float transformProgress[100];
	float transformSpeed;
public:

	Register(string type);
	~Register() = default;
	
	void backgroundTransformation(Sprite sprite1, Sprite sprite2, Texture Texture2, float* transformProgess, int index);
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void draw(RenderWindow& window, int counter) override;
	void textHandler(RenderWindow& window, Event& event) override;
	void getInputs() override;
	bool haltInput() override;
	void updateBg() override;

	int getAnimState();
};