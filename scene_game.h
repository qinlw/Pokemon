#pragma once

#include "scene.h"
#include "scene_manager.h"


extern SceneManager* scene_manager;

class SceneGame : public Scene {
public:
	void on_enter() {
		std::cout << "game_enter" << std::endl;

		// 背景坐标
		sky_pos.x = 0;
		sky_pos.y = 0;
		sun_pos.x = getwidth() - img_sun.getwidth() * 2;
		sun_pos.y = img_sun.getheight() / 2;
		hills_pos.x = 0;
		hills_pos.y = 200;
		grassland_pos.x = 0;
		grassland_pos.y = getheight() - img_grassland.getheight();

		// 树的位置坐标
		tree_centre_pos.x = (getwidth() - img_tree_centre.getwidth()) / 2;
		tree_centre_pos.y = grassland_pos.y - img_tree_centre.getheight();

		tree_1_pos.x = rand() % 1280;
		// 如果和中间的树重合则需要重新生成坐标位置
		while (is_regen(tree_1_pos, tree_centre_pos, img_tree_1, img_tree_centre)) 
			tree_1_pos.x = rand() % 1280;
		tree_1_pos.y = grassland_pos.y - img_tree_1.getheight();

		tree_2_pos.x = rand() % 1280;
		// 如果和中间的树重合则需要重新生成坐标位置
		// 如果和第一棵树重合则需要重新生成坐标位置
		while (is_regen(tree_2_pos, tree_centre_pos, img_tree_2, img_tree_centre) ||
			   is_regen(tree_2_pos, tree_1_pos, img_tree_2, img_tree_1)) tree_2_pos.x = rand() % 1280;
		tree_2_pos.y = grassland_pos.y - img_tree_2.getheight();

		tree_3_pos.x = rand() % 1280;
		// 如果和中间的树重合则需要重新生成坐标位置
		// 如果和第一棵树重合则需要重新生成坐标位置
		// 如果和第二棵树重合则需要重新生成坐标位置
		while (is_regen(tree_3_pos, tree_centre_pos, img_tree_3, img_tree_centre) ||
			  is_regen(tree_3_pos, tree_1_pos, img_tree_3, img_tree_1) ||
			  is_regen(tree_3_pos, tree_2_pos, img_tree_3, img_tree_2)) tree_3_pos.x = rand() % 1280;
		tree_3_pos.y = grassland_pos.y - img_tree_3.getheight();

		// 宝可梦位置
		player_1P_pos.x = rand() % (getwidth() / 4 * 3);
		player_1P_pos.y = rand() & (getheight() / 4 * 3);
		player_2P_pos.x = rand() % (getwidth() / 4 * 3);
		player_2P_pos.y = rand() % (getwidth() / 4 * 3);

		// 按钮位置
		restart_btn_pos.x = (getwidth() - img_restart_button.getwidth()) / 2;
		restart_btn_pos.y = (getheight() - img_continue_game_button.getheight()) / 2;
		continue_game_btn_pos.x = (restart_btn_pos.x - img_continue_game_button.getwidth()) / 2;
		continue_game_btn_pos.y = restart_btn_pos.y;
		return_menu_btn_pos.x = (getwidth() + restart_btn_pos.x + img_restart_button.getwidth() - img_return_menu_button.getwidth()) / 2 ;
		return_menu_btn_pos.y = restart_btn_pos.y;
	}

	void on_updata(int delta) {

	}

	void on_draw() {
		std::cout << "game_draw" << std::endl;

		putimage_alpha(sky_pos.x, sky_pos.y, &img_sky);
		putimage_alpha(sun_pos.x, sun_pos.y, &img_sun);
		putimage_alpha(hills_pos.x, hills_pos.y, &img_hills);
		putimage_alpha(grassland_pos.x, grassland_pos.y, &img_grassland);
		putimage_alpha(tree_centre_pos.x, tree_centre_pos.y, &img_tree_centre);
		putimage_alpha(tree_1_pos.x, tree_1_pos.y, &img_tree_1);
		putimage_alpha(tree_2_pos.x, tree_2_pos.y, &img_tree_2);
		putimage_alpha(tree_3_pos.x, tree_3_pos.y, &img_tree_3);

		if (is_esc_btn) {
			putimage_alpha(continue_game_btn_pos.x, continue_game_btn_pos.y, &img_continue_game_button);
			putimage_alpha(restart_btn_pos.x, restart_btn_pos.y, &img_restart_button);
			putimage_alpha(return_menu_btn_pos.x, return_menu_btn_pos.y, &img_return_menu_button);
		}
	}

	void on_input(const ExMessage& msg) {
		std::cout << "game_input" << std::endl;

		switch (msg.message) {
		case WM_LBUTTONDOWN: {
			if (msg.y >= restart_btn_pos.y && msg.y <= restart_btn_pos.y + img_restart_button.getheight()) {
				if (msg.x >= continue_game_btn_pos.x && msg.x <= continue_game_btn_pos.x + img_continue_game_button.getwidth()) {
					is_continue_game_btn = true;
					button_sink_animatioin(5, 50, continue_game_btn_pos, &img_continue_game_button);
					break;
				}
				else if (msg.x >= restart_btn_pos.x && msg.x <= restart_btn_pos.x + img_restart_button.getwidth()) {
					is_restart_btn = true;
					button_sink_animatioin(5, 50, restart_btn_pos, &img_restart_button);
					break;
				}
				else if (msg.x >= return_menu_btn_pos.x && msg.x <= return_menu_btn_pos.x + img_restart_button.getwidth()) {
					is_return_menu_btn = true;
					button_sink_animatioin(5, 50, return_menu_btn_pos, &img_return_button);
					break;
				}
			}
			break;
		}
		case WM_LBUTTONUP: {
			if (msg.y >= restart_btn_pos.y && msg.y <= restart_btn_pos.y + img_restart_button.getheight()) {
				if (msg.x >= continue_game_btn_pos.x && msg.x <= continue_game_btn_pos.x + img_continue_game_button.getwidth() && is_continue_game_btn) {
					is_continue_game_btn = false;
					button_bulge_animatioin(5, 300, continue_game_btn_pos, &img_continue_game_button);
					is_esc_btn = false;
					break;
				}
				else if (msg.x >= restart_btn_pos.x && msg.x <= restart_btn_pos.x + img_restart_button.getwidth() && is_restart_btn) {
					is_esc_btn = false;
					is_restart_btn = false;
					button_bulge_animatioin(5, 300, restart_btn_pos, &img_restart_button);
					scene_manager->switch_scene(SceneManager::SceneType::Pokemon);
					break;
				}
				else if (msg.x >= return_menu_btn_pos.x && msg.x <= return_menu_btn_pos.x + img_restart_button.getwidth() && is_return_menu_btn) {
					is_esc_btn = false;
					is_return_menu_btn = false;
					button_bulge_animatioin(5, 300, return_menu_btn_pos, &img_return_menu_button);
					scene_manager->switch_scene(SceneManager::SceneType::Menu);
					break;
				}
				else {
					if (is_continue_game_btn) {
						is_continue_game_btn = false;
						button_bulge_animatioin(5, 300, continue_game_btn_pos, &img_continue_game_button);
					}
					else if (is_restart_btn) {
						is_restart_btn = false;
						button_bulge_animatioin(5, 300, restart_btn_pos, &img_restart_button);
					}
					else if (is_return_menu_btn) {
						is_return_menu_btn = false;
						button_bulge_animatioin(5, 300, return_menu_btn_pos, &img_return_menu_button);
					}
					
				}
			}
			else {
				if (is_continue_game_btn) {
					is_continue_game_btn = false;
					button_bulge_animatioin(5, 300, continue_game_btn_pos, &img_continue_game_button);
				}
				else if (is_restart_btn) {
					is_restart_btn = false;
					button_bulge_animatioin(5, 300, restart_btn_pos, &img_restart_button);
				}
				else if (is_return_menu_btn) {
					is_return_menu_btn = false;
					button_bulge_animatioin(5, 300, return_menu_btn_pos, &img_return_menu_button);
				}

			}
			break;
		}
		}

		switch (msg.vkcode) {
		case 0x001B:
			is_esc_btn = true;
			break;
		}
	}

	void on_exit() {

	}

private:
	POINT sky_pos = { 0 };							// 天空位置
	POINT sun_pos = { 0 };							// 太阳位置
	POINT hills_pos = { 0 };						// 山脉位置
	POINT grassland_pos = { 0 };					// 草地位置
	POINT tree_centre_pos = { 0 };					// 中间树的位置
	POINT tree_1_pos = { 0 };						// 树1的位置
	POINT tree_2_pos = { 0 };						// 树2的位置
	POINT tree_3_pos = { 0 };						// 树3的位置
	POINT player_1P_pos = { 0 };					// 玩家1P的宝可梦位置
	POINT player_2P_pos = { 0 };					// 玩家2P的宝可梦位置
	POINT continue_game_btn_pos = { 0 };			// 继续游戏按钮的位置
	POINT restart_btn_pos = { 0 };					// 重新开始按钮的位置
	POINT return_menu_btn_pos = { 0 };				// 返回主菜单按钮的位置

	Animation animation_charmander_left;			// 朝向向左的小火龙动画
	Animation animation_charmander_right;			// 朝向向右的小火龙动画
	Animation animation_squirtle_left;				// 朝向向左的杰尼龟动画
	Animation animation_squirtle_right;				// 朝向向右的杰尼龟动画
	Animation animation_bulbasaur_left;				// 朝向向左的妙蛙种子动画
	Animation animation_bulbasaur_right;			// 朝向向右的妙蛙种子动画

	bool is_esc_btn = false;						// 是否按下了esc按键
	bool is_continue_game_btn = false;				// 是否按下了继续游戏按钮
	bool is_restart_btn = false;					// 是否按下了重新开始按钮
	bool is_return_menu_btn = false;				// 是否按下了返回主菜单按钮

};