#pragma once

#include "scene.h"
#include "animation.h"
#include "util.h"

#pragma comment(lib, "MSIMG32.LIB")


extern bool is_mysql_connect;

extern SceneManager* scene_manager;

class SceneMenu : public Scene {
public:
	SceneMenu() = default;
	~SceneMenu() = default;

	void on_enter() {
		int button_x_reduce = -38;
		int button_y_add = (getheight() - img_start_button.getheight() * 4) / 5;
		start_button_pos.x = getwidth() - img_start_button.getwidth() + button_x_reduce;
		start_button_pos.y = (getheight() - img_start_button.getheight() * 4) / 5;
		knapsack_button_pos.x = start_button_pos.x;
		knapsack_button_pos.y = start_button_pos.y + img_start_button.getheight() + button_y_add;
		set_button_pos.x = start_button_pos.x;
		set_button_pos.y = start_button_pos.y + (img_start_button.getheight() + button_y_add) * 2;
		exit_button_pos.x = start_button_pos.x;
		exit_button_pos.y = start_button_pos.y + (img_start_button.getheight() + button_y_add) * 3;

		animation_mysql_unconnected_text.set_atlas(&atlas_mysql_unconnected);
		animation_mysql_unconnected_text.set_interval(200);
		animation_mysql_unconnected_text.set_is_loop(false);
	}

	void on_update(int delta) {
		if (is_display_mysql_unconnected_text) animation_mysql_unconnected_text.on_update(delta);
	}

	void on_draw() {
		putimage(0, 0, &img_menu_background);
		putimage_alpha(start_button_pos.x, start_button_pos.y, &img_start_button);
		putimage_alpha(knapsack_button_pos.x, knapsack_button_pos.y, &img_knapsack_button);
		putimage_alpha(set_button_pos.x, set_button_pos.y, &img_set_button);
		putimage_alpha(exit_button_pos.x, exit_button_pos.y, &img_exit_button);

		if (is_display_mysql_unconnected_text) animation_mysql_unconnected_text.on_draw(532, 40);
	}

	void on_input(const ExMessage& msg) {
		switch (msg.message) {
		// 鼠标左键按下
		case WM_LBUTTONDOWN: {
			if (msg.x >= start_button_pos.x && msg.x <= start_button_pos.x + img_start_button.getwidth()) {
				if (msg.y >= start_button_pos.y && msg.y < start_button_pos.y + img_start_button.getheight()) {
					is_start_btn = true;
					button_sink_animatioin(5, 50, start_button_pos, &img_start_button);
				}
				else if (msg.y >= knapsack_button_pos.y && msg.y < knapsack_button_pos.y + img_knapsack_button.getheight()) {
					is_knapsack_btn = true;
					button_sink_animatioin(5, 50, knapsack_button_pos, &img_knapsack_button);
				}
				else if (msg.y >= set_button_pos.y && msg.y < set_button_pos.y + img_set_button.getheight()) {
					is_set_btn = true;
					button_sink_animatioin(5, 50, set_button_pos, &img_set_button);
				}
				else if (msg.y >= exit_button_pos.y && msg.y < exit_button_pos.y + img_exit_button.getheight()) {
					is_exit_btn = true;
					button_sink_animatioin(5, 50, exit_button_pos, &img_exit_button);
				}
			}
			break;
		}
		// 鼠标左键弹起
		case WM_LBUTTONUP: {
			if (msg.x >= start_button_pos.x && msg.x <= start_button_pos.x + img_start_button.getwidth()) {
				if (msg.y >= start_button_pos.y && msg.y < start_button_pos.y + img_start_button.getheight() && is_start_btn) {
					is_start_btn = false;
					button_bulge_animatioin(5, 300, start_button_pos, &img_start_button);
					scene_manager->switch_scene(SceneManager::SceneType::Pokemon);
				}
				else if (msg.y >= knapsack_button_pos.y && msg.y < knapsack_button_pos.y + img_knapsack_button.getheight() && is_knapsack_btn) {
					is_knapsack_btn = false;
					button_bulge_animatioin(5, 300, knapsack_button_pos, &img_knapsack_button);
					scene_manager->switch_scene(SceneManager::SceneType::Knapscack);
				}
				else if (msg.y >= set_button_pos.y && msg.y < set_button_pos.y + img_set_button.getheight() && is_set_btn) {
					is_set_btn = false;
					button_bulge_animatioin(5, 300, set_button_pos, &img_set_button);
					scene_manager->switch_scene(SceneManager::SceneType::Set);
				}
				else if (msg.y >= exit_button_pos.y && msg.y < exit_button_pos.y + img_exit_button.getheight() && is_exit_btn) {
					is_exit_btn = false;
					button_bulge_animatioin(5, 300, exit_button_pos, &img_exit_button);
					exit(0);
				}
				else {
					if (is_start_btn) {
						is_start_btn = false;
						button_bulge_animatioin(5, 300, start_button_pos, &img_start_button);
					}
					else if (is_knapsack_btn) {
						is_knapsack_btn = false;
						button_bulge_animatioin(5, 300, knapsack_button_pos, &img_knapsack_button);
					}
					else if (is_set_btn) {
						is_set_btn = false;
						button_bulge_animatioin(5, 300, set_button_pos, &img_set_button);
					}
					else if (is_exit_btn) {
						is_exit_btn = false;
						button_bulge_animatioin(5, 300, exit_button_pos, &img_exit_button);
					}
				}
			}
			else {
				if (is_start_btn) {
					is_start_btn = false;
					button_bulge_animatioin(5, 300, start_button_pos, &img_start_button);
				}
				else if (is_knapsack_btn) {
					is_knapsack_btn = false;
					button_bulge_animatioin(5, 300, knapsack_button_pos, &img_knapsack_button);
				}
				else if (is_set_btn) {
					is_set_btn = false;
					button_bulge_animatioin(5, 300, set_button_pos, &img_set_button);
				}
				else if (is_exit_btn) {
					is_exit_btn = false;
					button_bulge_animatioin(5, 300, exit_button_pos, &img_exit_button);
				}
			}
			break;
		}
		}
	}

	void on_exit() {

	}

private:
	POINT start_button_pos = { 0 };							               // 开始按钮位置
	POINT knapsack_button_pos = { 0 };						               // 背包按钮位置
	POINT set_button_pos = { 0 };							               // 设置按钮位置
	POINT exit_button_pos = { 0 };							               // 退出按钮位置

	Animation animation_mysql_unconnected_text;				               // 数据库未连接的文本

	bool is_start_btn = false;								               // 开始按钮是否按下
	bool is_knapsack_btn = false;							               // 背包按钮是否按下
	bool is_set_btn = false;								               // 设置按钮是否按下
	bool is_exit_btn = false;								               // 退出按钮是否按下
	bool is_display_mysql_unconnected_text = !is_mysql_connect;			   // 是否显示数据未连接的文本

};