#pragma once

#include "scene.h"
#include "scene_manager.h"
#include "collision_line.h"


extern bool is_debug;

extern SceneManager* scene_manager;

extern std::vector<CollisionLine> collision_thwartwise_line_list;
extern std::vector<CollisionLine> collision_vertical_line_list;

class SceneGame : public Scene {
public:
	void on_enter() {
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

		// 宝可梦位置
		pokemon_player_1->set_pokemon_pos(200, 50);
		pokemon_player_2->set_pokemon_pos(975, 50);

		// 宝可梦速度
		pokemon_player_1->set_velocity(0, 0);

		// 碰撞线条初始化信息
		collision_thwartwise_line_list.resize(9);
		collision_vertical_line_list.resize(16);

		CollisionLine& line_0 = collision_thwartwise_line_list[0];
		line_0.line_pos.pos_1 = { grassland_pos.x, grassland_pos.y + 20 };
		line_0.line_pos.pos_2 = { grassland_pos.x + img_grassland.getwidth(), grassland_pos.y + 20};

		CollisionLine& line_1 = collision_thwartwise_line_list[1];
		line_1.line_pos.pos_1 = { tree_centre_pos.x + 10, tree_centre_pos.y + 20 };
		line_1.line_pos.pos_2 = { tree_centre_pos.x + img_tree_centre.getwidth() - 10, tree_centre_pos.y + 20 };
		CollisionLine& line_2 = collision_thwartwise_line_list[2];
		line_2.line_pos.pos_1 = { tree_centre_pos.x + 10, tree_centre_pos.y + 60 };
		line_2.line_pos.pos_2 = { tree_centre_pos.x + img_tree_centre.getwidth() - 15, tree_centre_pos.y + 60 };
		CollisionLine& line_addition_0 = collision_vertical_line_list[0];
		line_addition_0.line_pos.pos_1 = line_1.line_pos.pos_1;
		line_addition_0.line_pos.pos_2 = line_2.line_pos.pos_1;
		CollisionLine& line_addition_1 = collision_vertical_line_list[1];
		line_addition_1.line_pos.pos_1 = line_1.line_pos.pos_2;
		line_addition_1.line_pos.pos_2 = line_2.line_pos.pos_2;
		CollisionLine& line_3 = collision_vertical_line_list[2];
		//line_3.line_pos.pos_1 = { tree_centre_pos.x + 60, grassland_pos.y - img_tree_centre.getheight() + 22 };
		line_3.line_pos.pos_1 = { tree_centre_pos.x + 60, line_2.line_pos.pos_1.y };
		line_3.line_pos.pos_2 = { tree_centre_pos.x + 60, line_0.line_pos.pos_1.y };
		CollisionLine& line_4 = collision_vertical_line_list[3];
		//line_4.line_pos.pos_1 = { tree_centre_pos.x + 93, grassland_pos.y - img_tree_centre.getheight() + 22 };
		line_4.line_pos.pos_1 = { tree_centre_pos.x + 93, line_3.line_pos.pos_1.y };
		line_4.line_pos.pos_2 = { tree_centre_pos.x + 93, line_0.line_pos.pos_1.y };

		CollisionLine& line_5 = collision_thwartwise_line_list[3];
		line_5.line_pos.pos_1 = { tree_1_pos.x + 10, tree_1_pos.y + 25 };
		line_5.line_pos.pos_2 = { tree_1_pos.x + img_tree_1.getwidth() - 10, tree_1_pos.y + 25 };
		CollisionLine& line_6 = collision_thwartwise_line_list[4];
		line_6.line_pos.pos_1 = { tree_1_pos.x + 10, tree_1_pos.y + 50 };
		line_6.line_pos.pos_2 = { tree_1_pos.x + img_tree_1.getwidth() - 20, tree_1_pos.y + 50 };
		CollisionLine& line_addition_4 = collision_vertical_line_list[4];
		line_addition_4.line_pos.pos_1 = line_5.line_pos.pos_1;
		line_addition_4.line_pos.pos_2 = line_6.line_pos.pos_1;
		CollisionLine& line_addition_5 = collision_vertical_line_list[5];
		line_addition_5.line_pos.pos_1 = line_5.line_pos.pos_2;
		line_addition_5.line_pos.pos_2 = line_6.line_pos.pos_2;
		CollisionLine& line_7 = collision_vertical_line_list[6];
		//line_7.line_pos.pos_1 = { tree_1_pos.x + 70, grassland_pos.y - img_tree_1.getheight() + 27 };
		line_7.line_pos.pos_1 = { tree_1_pos.x + 70, line_6.line_pos.pos_1.y };
		line_7.line_pos.pos_2 = { tree_1_pos.x + 70, line_0.line_pos.pos_1.y };
		CollisionLine& line_8 = collision_vertical_line_list[7];
		//line_8.line_pos.pos_1 = { tree_1_pos.x + 113, grassland_pos.y - img_tree_1.getheight() + 27 };
		line_8.line_pos.pos_1 = { tree_1_pos.x + 113, line_7.line_pos.pos_1.y };
		line_8.line_pos.pos_2 = { tree_1_pos.x + 113, line_0.line_pos.pos_1.y };

		CollisionLine& line_9 = collision_thwartwise_line_list[5];
		line_9.line_pos.pos_1 = { tree_2_pos.x + 10, tree_2_pos.y + 30 };
		line_9.line_pos.pos_2 = { tree_2_pos.x + img_tree_2.getwidth() - 10, tree_2_pos.y + 30 };
		CollisionLine& line_10 = collision_thwartwise_line_list[6];
		line_10.line_pos.pos_1 = { tree_2_pos.x + 10, tree_2_pos.y + 80 };
		line_10.line_pos.pos_2 = { tree_2_pos.x + img_tree_2.getwidth() - 20, tree_2_pos.y + 80 };
		CollisionLine& line_addition_8 = collision_vertical_line_list[8];
		line_addition_8.line_pos.pos_1 = line_9.line_pos.pos_1;
		line_addition_8.line_pos.pos_2 = line_10.line_pos.pos_1;
		CollisionLine& line_addition_9 = collision_vertical_line_list[9];
		line_addition_9.line_pos.pos_1 = line_9.line_pos.pos_2;
		line_addition_9.line_pos.pos_2 = line_10.line_pos.pos_2;
		CollisionLine& line_11 = collision_vertical_line_list[10];
		//line_11.line_pos.pos_1 = { tree_2_pos.x + 60, grassland_pos.y - img_tree_2.getheight() + 33 };
		line_11.line_pos.pos_1 = { tree_2_pos.x + 60, line_10.line_pos.pos_1.y };
		line_11.line_pos.pos_2 = { tree_2_pos.x + 60, line_0.line_pos.pos_1.y };
		CollisionLine& line_12 = collision_vertical_line_list[11];
		//line_12.line_pos.pos_1 = { tree_2_pos.x + 95, grassland_pos.y - img_tree_2.getheight() + 33 };
		line_12.line_pos.pos_1 = { tree_2_pos.x + 95, line_11.line_pos.pos_1.y };
		line_12.line_pos.pos_2 = { tree_2_pos.x + 95, line_0.line_pos.pos_1.y };

		CollisionLine& line_13 = collision_thwartwise_line_list[7];
		line_13.line_pos.pos_1 = { tree_3_pos.x + 10, tree_3_pos.y + 60 };
		line_13.line_pos.pos_2 = { tree_3_pos.x + img_tree_3.getwidth() - 10, tree_3_pos.y + 60 };
		CollisionLine& line_14 = collision_thwartwise_line_list[8];
		line_14.line_pos.pos_1 = { tree_3_pos.x + 10, tree_3_pos.y + 120 };
		line_14.line_pos.pos_2 = { tree_3_pos.x + img_tree_3.getwidth() - 20, tree_3_pos.y + 120 };
		CollisionLine& line_addition_12 = collision_vertical_line_list[12];
		line_addition_12.line_pos.pos_1 = line_13.line_pos.pos_1;
		line_addition_12.line_pos.pos_2 = line_14.line_pos.pos_1;
		CollisionLine& line_addition_13 = collision_vertical_line_list[13];
		line_addition_13.line_pos.pos_1 = line_13.line_pos.pos_2;
		line_addition_13.line_pos.pos_2 = line_14.line_pos.pos_2;
		CollisionLine& line_15 = collision_vertical_line_list[14];
		//line_15.line_pos.pos_1 = { tree_3_pos.x + 75, grassland_pos.y - img_tree_3.getheight() + 65 };
		line_15.line_pos.pos_1 = { tree_3_pos.x + 75, line_14.line_pos.pos_1.y };
		line_15.line_pos.pos_2 = { tree_3_pos.x + 75, line_0.line_pos.pos_1.y };
		CollisionLine& line_16 = collision_vertical_line_list[15];
		//line_16.line_pos.pos_1 = { tree_3_pos.x + 123, grassland_pos.y - img_tree_3.getheight() + 65 };
		line_16.line_pos.pos_1 = { tree_3_pos.x + 123, line_15.line_pos.pos_1.y };
		line_16.line_pos.pos_2 = { tree_3_pos.x + 123, line_0.line_pos.pos_1.y };
	}

	void on_updata(int delta) {
		if (is_esc_btn) return;
		pokemon_player_1->on_updata(delta);
		pokemon_player_2->on_updata(delta);
	}

	void on_draw() {
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

		pokemon_player_1->on_draw();
		pokemon_player_2->on_draw();

		if (is_debug) {
			for (auto line : collision_thwartwise_line_list) {
				line.on_draw();
			}
			for (auto line : collision_vertical_line_list) {
				line.on_draw();
			}
		}

		// 碰撞线条
		/*
			line(grassland_pos.x, grassland_pos.y, grassland_pos.x + img_grassland.getwidth(), grassland_pos.y);
			line(tree_centre_pos.x + 10, tree_centre_pos.y + 20, tree_centre_pos.x + img_tree_centre.getwidth() - 10, tree_centre_pos.y + 20);	// 中心树木上层碰撞线
			line(tree_centre_pos.x + 10, tree_centre_pos.y + 60, tree_centre_pos.x + img_tree_centre.getwidth() - 15, tree_centre_pos.y + 60);	// 中心树木下层碰撞线
			line(tree_centre_pos.x + 60, grassland_pos.y - img_tree_centre.getheight() + 22 , tree_centre_pos.x + 60, grassland_pos.y);			// 中心树桩左侧碰撞竖线
			line(tree_centre_pos.x + 93, grassland_pos.y - img_tree_centre.getheight() + 22 , tree_centre_pos.x + 93, grassland_pos.y);			// 中心树桩左侧碰撞竖线

			line(tree_1_pos.x + 10, tree_1_pos.y + 25, tree_1_pos.x + img_tree_1.getwidth() - 10, tree_1_pos.y + 25);							// 树1上层碰撞线
			line(tree_1_pos.x + 10, tree_1_pos.y + 50, tree_1_pos.x + img_tree_1.getwidth() - 20, tree_1_pos.y + 50);							// 树1下层碰撞线
			line(tree_1_pos.x + 70, grassland_pos.y - img_tree_1.getheight() + 27, tree_1_pos.x + 70, grassland_pos.y);							// 中心树桩左侧碰撞竖线
			line(tree_1_pos.x + 113, grassland_pos.y - img_tree_1.getheight() + 27, tree_1_pos.x + 113, grassland_pos.y);						// 中心树桩左侧碰撞竖线

			line(tree_2_pos.x + 10, tree_2_pos.y + 30, tree_2_pos.x + img_tree_2.getwidth() - 10, tree_2_pos.y + 30);							// 树2上层碰撞线
			line(tree_2_pos.x + 10, tree_2_pos.y + 80, tree_2_pos.x + img_tree_2.getwidth() - 20, tree_2_pos.y + 80);							// 树2下层碰撞线
			line(tree_2_pos.x + 60, grassland_pos.y - img_tree_2.getheight() + 33, tree_2_pos.x + 60, grassland_pos.y);							// 中心树桩左侧碰撞竖线
			line(tree_2_pos.x + 95, grassland_pos.y - img_tree_2.getheight() + 33, tree_2_pos.x + 95, grassland_pos.y);							// 中心树桩右侧碰撞竖线

			line(tree_3_pos.x + 10, tree_3_pos.y + 60, tree_3_pos.x + img_tree_3.getwidth() - 10, tree_3_pos.y + 60);							// 树3上层碰撞线
			line(tree_3_pos.x + 10, tree_3_pos.y + 120, tree_3_pos.x + img_tree_3.getwidth() - 20, tree_3_pos.y + 120);							// 树3上层碰撞线
			line(tree_3_pos.x + 75, grassland_pos.y - img_tree_3.getheight() + 65, tree_3_pos.x + 75, grassland_pos.y);							// 树3上层碰撞线
			line(tree_3_pos.x + 123, grassland_pos.y - img_tree_3.getheight() + 65, tree_3_pos.x + 123, grassland_pos.y);						// 树3上层碰撞线	
		*/
	}

	void on_input(const ExMessage& msg) {
		// 宝可梦控制
		pokemon_player_1->on_input(msg);
		pokemon_player_2->on_input(msg);

		// 判断暂停后的情况
		if (is_esc_btn) {
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
		}

		switch (msg.message) {
		case WM_KEYUP: {
			// 'esc'
			if (msg.vkcode == 0x001B) {
				is_esc_btn = true;
				break;
			}
			// ’Q'
			if (msg.vkcode == 0x51) {
				is_debug = !is_debug;
				break;
			}
			break;
		}
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