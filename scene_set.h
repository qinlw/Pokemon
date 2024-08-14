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
		// 背景的位置
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

		// 返回按钮的位置
		set_return_to_menu_button_pos.x = set_background_pos.x - img_set_return_to_menu_button.getwidth();
		set_return_to_menu_button_pos.y = 0;

		// 设置新手教程的位置		
		const int first_bar_to_top_distance = 73;
		const int left_to_bar_distance = 33;
		set_bar_background_clolr_pos.x = set_background_pos.x + left_to_bar_distance;
		set_bar_background_clolr_pos.y = set_background_pos.y + first_bar_to_top_distance;
		novice_teaching_text_pos.x = set_bar_background_clolr_pos.x;
		novice_teaching_text_pos.y = set_bar_background_clolr_pos.y;
		open_or_close_white_background_pos.x = set_bar_background_clolr_pos.x +
			img_set_bar_background_color.getwidth() - img_open_or_close_white_background.getwidth();
		open_or_close_white_background_pos.y = set_bar_background_clolr_pos.y;
		close_text_pos.x = set_bar_background_clolr_pos.x + img_set_bar_background_color.getwidth() - img_close_text.getwidth();
		close_text_pos.y = set_bar_background_clolr_pos.y;
		open_text_pos.x = close_text_pos.x - img_close_text.getwidth();
		open_text_pos.y = set_bar_background_clolr_pos.y;
		if (set_is_first_game_is_open) is_open_or_is_close_pos.x = open_text_pos.x;
		else is_open_or_is_close_pos.x = close_text_pos.x;
		is_open_or_is_close_pos.y = set_bar_background_clolr_pos.y;
	}

	void on_draw() {
		menu_scene->on_draw();
		putimage_alpha(set_background_pos.x, set_background_pos.y, &img_set_background);
		putimage_alpha(set_return_to_menu_button_pos.x, set_return_to_menu_button_pos.y, &img_set_return_to_menu_button);

		// 设置新手教程
		putimage_alpha(set_bar_background_clolr_pos.x, set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(novice_teaching_text_pos.x, novice_teaching_text_pos.y, &img_novice_teaching_text);
		putimage_alpha(open_or_close_white_background_pos.x, open_or_close_white_background_pos.y, &img_open_or_close_white_background);
		putimage_alpha(is_open_or_is_close_pos.x, is_open_or_is_close_pos.y, &img_is_open_or_is_close);
		putimage_alpha(open_text_pos.x, open_text_pos.y, &img_open_text);
		putimage_alpha(close_text_pos.x, close_text_pos.y, &img_close_text);
	}

	void on_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_LBUTTONUP:
			// 退出判断
			if (msg.x < set_background_pos.x) {
				is_exit_set = true;
				break;
			}

			// 设置新手教程的设置判断
			if (msg.y < set_bar_background_clolr_pos.y + img_set_bar_background_color.getheight() && msg.y > set_bar_background_clolr_pos.y) {
				if (msg.x < open_text_pos.x + img_open_text.getwidth() && msg.x > open_text_pos.x) set_is_first_game_is_open = true;
				else if (msg.x < close_text_pos.x + img_close_text.getwidth() && msg.x > close_text_pos.x) set_is_first_game_is_open = false;
				break;
			}
		}
	}

	void on_exit() {

	}

private:
	const float set_background_slide_speed = 0.8f;									// 设置背景滑动速度

private:
	POINT set_background_pos = { 0 };												// 设置背景的位置
	POINT set_return_to_menu_button_pos = { 0 };									// 返回按钮的位置
	// 设置新手教程的位置
	POINT set_bar_background_clolr_pos = { 0 };										// 设置条背景色的位置
	POINT novice_teaching_text_pos = { 0 };											// 新手教程文本的位置
	POINT open_or_close_white_background_pos = { 0 };								// 白色背景位置的位置
	POINT is_open_or_is_close_pos = { 0 };											// 是打开 or 是关闭  的位置
	POINT open_text_pos = { 0 };													// 打开文本的位置
	POINT close_text_pos = { 0 };													// 关闭文本的位置

	bool is_exit_set = false;														// 是否退出设置
	bool set_is_first_game_is_open = false;											// 设置新手教程 是否为打开状态

};