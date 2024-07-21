#pragma once

#include "scene.h"


class SceneSet : public Scene {
public:
	void on_enter() {
		std::cout << "set";
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