#pragma once

#include "atlas.h"


IMAGE img_background_base;							// 背景版
IMAGE img_menu_background;							// 主菜单界面
IMAGE img_start_button;								// 开始按钮
IMAGE img_knapsack_button;							// 背包按钮
IMAGE img_set_button;								// 设置按钮
IMAGE img_exit_button;								// 退出按钮

IMAGE img_return_button;							// 返回按钮

IMAGE img_selector_background;						// 选择界面
IMAGE img_pokeball;									// 精灵球
IMAGE img_1P;										// 1P图像
IMAGE img_2P;										// 2P图像
IMAGE img_1P_selector_btn_idle_right;				// 玩家1向右的默认选择按钮
IMAGE img_1P_selector_btn_idle_left;				// 玩家1向左的默认选择按钮
IMAGE img_1P_selector_btn_down_right;				// 玩家1向右的按下选择按钮
IMAGE img_1P_selector_btn_down_left;				// 玩家1向左的按下选择按钮
IMAGE img_2P_selector_btn_idle_right;				// 玩家2向右的默认选择按钮
IMAGE img_2P_selector_btn_idle_left;				// 玩家2向左的默认选择按钮
IMAGE img_2P_selector_btn_down_right;				// 玩家2向右的默认按下按钮
IMAGE img_2P_selector_btn_down_left;				// 玩家2向左的默认按下按钮

Atlas atlas_pokeball;								// 旋转精灵球图集
Atlas atlas_selector_charmander_left;				// 选择界面小火龙
Atlas atlas_selector_charmander_right;				// 选择界面小火龙
Atlas atlas_selector_squirtle_left;					// 选择界面杰尼龟
Atlas atlas_selector_squirtle_right;				// 选择界面杰尼龟
Atlas atlas_selector_bulbasaur_left;				// 选择界面妙蛙种子
Atlas atlas_selector_bulbasaur_right;				// 选择界面妙蛙种子


void load_res() {
	loadimage(&img_background_base, _T("res/background_base.png"));
	loadimage(&img_menu_background, _T("res/menu_background.png"));
	loadimage(&img_start_button, _T("res/start_button.png"));
	loadimage(&img_knapsack_button, _T("res/knapsack_button.png"));
	loadimage(&img_set_button, _T("res/set_button.png"));
	loadimage(&img_exit_button, _T("res/exit_button.png"));

	loadimage(&img_return_button, _T("res/return_button.png"));

	loadimage(&img_selector_background, _T("res/selector_background.png"));
	loadimage(&img_pokeball, _T("res/pokeball.png"));
	loadimage(&img_1P, _T("res/1P.png"));
	loadimage(&img_2P, _T("res/2P.png"));
	loadimage(&img_1P_selector_btn_idle_right, _T("res/1P_selector_btn_idle.png"));
	flip_image(&img_1P_selector_btn_idle_right, &img_1P_selector_btn_idle_left);
	loadimage(&img_1P_selector_btn_down_right, _T("res/1P_selector_btn_down.png"));
	flip_image(&img_1P_selector_btn_down_right, &img_1P_selector_btn_down_left);
	loadimage(&img_2P_selector_btn_idle_right, _T("res/2P_selector_btn_idle.png"));
	flip_image(&img_2P_selector_btn_idle_right, &img_2P_selector_btn_idle_left);
	loadimage(&img_2P_selector_btn_down_right, _T("res/2P_selector_btn_down.png"));
	flip_image(&img_2P_selector_btn_down_right, &img_2P_selector_btn_down_left);

	rotate_atlas(36, &img_pokeball, atlas_pokeball);
	
	atlas_selector_charmander_left.load_from_file(_T("res/selector_charmander_%d.png"), 3);
	flip_atlas(atlas_selector_charmander_left, atlas_selector_charmander_right);
	atlas_selector_squirtle_left.load_from_file(_T("res/selector_squirtle_%d.png"), 3);
	flip_atlas(atlas_selector_squirtle_left, atlas_selector_squirtle_right);
	atlas_selector_bulbasaur_left.load_from_file(_T("res/selector_bulbasaur_%d.png"), 3);
	flip_atlas(atlas_selector_bulbasaur_left, atlas_selector_bulbasaur_right);
}