#pragma once
#include "precompile.hpp"
#include "Scene.hpp"
#include "MainMenu.hpp"

class SceneManager {
public:
	void switchToScene(shared_ptr<Scene> newScene) {
		currentScene = move(newScene);
	}
	void update(float deltaTime) {
		currentScene->update(deltaTime);
	}
	void draw(RenderWindow& window) {
		currentScene->draw(window);
	}
	void draw(RenderWindow& window, int counter) {
		currentScene->draw(window, counter);
	}
	shared_ptr<Scene> getScene() {
		return currentScene;
	}

private:
	shared_ptr<Scene> currentScene;
};
