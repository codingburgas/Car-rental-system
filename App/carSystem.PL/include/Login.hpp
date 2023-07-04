#pragma once
#include "Scene.hpp"  

class Login : public Scene {
private:
	Texture textureLoginBlack;
	Sprite spriteLoginBlack;

	Texture textureLoginWhite;
	Sprite spriteLoginWhite;

	RenderTexture renderTexture;

	float transformProgress[100];
	float transformSpeed;
public:
	Login(string type);
	~Login() = default;

	void backgroundTransformation(Sprite sprite1, Sprite sprite2, Texture Texture2, float* transformProgess, int index);
	void update(float deltaTime) override;
	void draw(RenderWindow& window) override;
	void draw(RenderWindow& window, int counter) override;
	void textHandler(RenderWindow& window, Event& event) override;
	void getInputs() override;
	bool haltInput() override;
	void updateBg() override;
};