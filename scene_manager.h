#pragma once

#include "scene.h"


extern Scene* menu_scene;
extern Scene* knapsack_scene;
extern Scene* set_scene;
extern Scene* pokemon_scene;
extern Scene* game_scene;

class SceneManager {
public:
	enum class SceneType {
		Menu,
		Knapscack,
		Set,
		Pokemon,
		Game,
	};

	void scene_set(Scene* scene) {
		current_scene = scene;
		current_scene->on_enter();
	}

	void switch_scene(SceneType type) {
		current_scene->on_exit();
		switch (type) {
		case SceneManager::SceneType::Menu:
			current_scene = menu_scene;
			break;
		case SceneManager::SceneType::Knapscack:
			current_scene = knapsack_scene;
			break;
		case SceneManager::SceneType::Set:
			current_scene = set_scene;
			break;
		case SceneManager::SceneType::Pokemon:
			current_scene = pokemon_scene;
			break;
		case SceneManager::SceneType::Game:
			current_scene = game_scene;
			break;
		}
		current_scene->on_enter();
	}

	void on_enter() {
		current_scene->on_enter();
	}

	void on_updata(int delta) {
		current_scene->on_updata(delta);
	}

	void on_draw() {
		current_scene->on_draw();
	}

	void on_input(const ExMessage& msg) {
		current_scene->on_input(msg);
	}

	void on_exit() {
		current_scene->on_exit();
	}

private:
	Scene* current_scene = nullptr;

};