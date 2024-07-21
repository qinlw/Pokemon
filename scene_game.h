#pragma once

#include "scene.h"


class SceneGame : public Scene {
public:
	void on_enter() {
		std::cout << "game";
	}

	void on_updata(int delta) {

	}

	void on_draw() {

	}

	void on_input(const ExMessage& msg) {

	}

	void on_exit() {

	}

};