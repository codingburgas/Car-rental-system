#pragma once
#include "precompile.hpp"
#include "Scene.hpp"
#include "LoginRegister.hpp"
#include "SceneManager.hpp"

class MainMenu : virtual public Scene, LoginRegister{
private:
	LoginRegister logRegister;

	Texture bgTexture;
	Sprite bg;

	string name, role;
	
	Font font;
	Text textName, textRole;

	vector<vector<Vector2f>> buttons = {
		{}
	};
	
public:
	MainMenu(string type, string email);
	~MainMenu() = default;

	void update(float deltaTime) override;

	void draw(RenderWindow& window) override;

	void draw(RenderWindow& window, int counter) override;

	void textHandler(RenderWindow& window, Event& event) override;

	void getInputs() override;

	bool haltInput() override;
	void updateBg() override;
};