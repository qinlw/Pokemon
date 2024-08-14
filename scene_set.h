#pragma once

#include "scene.h"
#include "timer.h"


extern Scene* menu_scene;
//extern Scene* scene_manager;

class SceneSet : public Scene {
public:
	void on_enter() {
		set_background_pos.x = getwidth();
		set_background_pos.y = 0;
	}

	void on_update(int delta) {
		if (is_exit_set) {
			set_background_pos.x += set_background_slide_speed * delta * 2;
			if (set_background_pos.x > getwidth()) {
				is_exit_set = false;
				scene_manager->switch_scene(SceneManager::SceneType::Menu);
			}
		}
		else if (set_background_pos.x > getwidth() - img_set_background.getwidth()) {
			set_background_pos.x -= set_background_slide_speed * delta;
			if (set_background_pos.x < getwidth() - img_set_background.getwidth()) set_background_pos.x = getwidth() - img_set_background.getwidth();
		}
		set_return_to_menu_button_pos.x = set_background_pos.x - img_set_return_to_menu_button.getwidth();
		set_return_to_menu_button_pos.y = 0;
	}

	void on_draw() {
		menu_scene->on_draw();
		putimage_alpha(set_background_pos.x, set_background_pos.y, &img_set_background);
		putimage_alpha(set_return_to_menu_button_pos.x, set_return_to_menu_button_pos.y, &img_set_return_to_menu_button);
	}

	void on_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_LBUTTONUP:
			if (msg.x < set_background_pos.x) is_exit_set = true;
			break;
		}
	}

	void on_exit() {

	}

private:
	const float set_background_slide_speed = 0.8f;									// 设置背景滑动速度

private:
	POINT set_background_pos = { 0 };												// 设置背景的位置
	POINT set_return_to_menu_button_pos = { 0 };									// 返回按钮的位置

	bool is_exit_set = false;														// 是否退出设置

};