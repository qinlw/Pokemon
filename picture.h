#pragma once

#include "atlas.h"


// 主菜单场景
IMAGE img_background_base;							// 背景版
IMAGE img_menu_background;							// 主菜单界面
IMAGE img_start_button;								// 开始按钮
IMAGE img_knapsack_button;							// 背包按钮
IMAGE img_set_button;								// 设置按钮
IMAGE img_exit_button;								// 退出按钮


// 选择场景
IMAGE img_selector_background;						// 选择界面
IMAGE img_return_button;							// 返回按钮
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

// 游戏场景
IMAGE img_sky;										// 天空背景
IMAGE img_sun;										// 太阳
IMAGE img_hills;									// 山脉
IMAGE img_grassland;								// 草地
IMAGE img_tree_centre;								// 中间的树
IMAGE img_tree_1;									// 树一
IMAGE img_tree_2;									// 树二
IMAGE img_tree_3;									// 树三
IMAGE img_continue_game_button;						// 继续游戏按钮
IMAGE img_restart_button;							// 重新开始按钮
IMAGE img_return_menu_button;						// 返回主菜单按钮
IMAGE img_charmander_head_portrait_right;			// 朝向向右的小火龙头像
IMAGE img_charmander_head_portrait_left;			// 朝向向左的小火龙头像
IMAGE img_squirtle_head_portrait_right;				// 朝向向右的杰尼龟头像
IMAGE img_squirtle_head_portrait_left;				// 朝向向左的杰尼龟头像
IMAGE img_bulbasaur_head_portrait_right;			// 朝向向右的妙蛙种子头像
IMAGE img_bulbasaur_head_portrait_left;				// 朝向向左的妙蛙种子头像


Atlas atlas_charmander_left;						// 朝向向左的小火龙
Atlas atlas_charmander_right;						// 朝向向右的小火龙
Atlas atlas_squirtle_left;							// 朝向向左的杰尼龟
Atlas atlas_squirtle_right;							// 朝向向右的杰尼龟
Atlas atlas_bulbasaur_left;							// 朝向向左的妙蛙种子
Atlas atlas_bulbasaur_right;						// 朝向向右的妙蛙种子
Atlas atlas_charmander_high_frame_left;				// 朝向向左的高帧小火龙
Atlas atlas_charmander_high_frame_right;			// 朝向向右的高帧小火龙
Atlas atlas_squirtle_high_frame_left;				// 朝向向左的高帧杰尼龟
Atlas atlas_squirtle_high_frame_right;				// 朝向向右的高帧杰尼龟
Atlas atlas_bulbasaur_high_frame_left;				// 朝向向左的高帧妙蛙种子
Atlas atlas_bulbasaur_high_frame_right;				// 朝向向右的高帧妙蛙种子

// 技能动画
Atlas atlas_fireball;								// 火花发射出的动画
Atlas atlas_fire;									// 火花命中后的动画 

// 胜利动画
IMAGE img_winnner_bar;								// 胜利条背景
IMAGE img_1P_charmander_win_text_bar;				// 1P小火龙胜利文本条动画
IMAGE img_2P_charmander_win_text_bar;				// 2P小火龙胜利文本条动画
IMAGE img_1P_squirtle_win_text_bar;					// 1P杰尼龟胜利文本条动画
IMAGE img_2P_squirtle_win_text_bar;					// 2P杰尼龟胜利文本条动画
IMAGE img_1P_bulbasaur_win_text_bar;				// 1P妙蛙种子胜利文本条动画
IMAGE img_2P_bulbasaur_win_text_bar;				// 2P妙蛙种子胜利文本条动画


void load_res() {
	// 主菜单场景资源加载
	loadimage(&img_background_base, _T("res/background_base.png"));
	loadimage(&img_menu_background, _T("res/menu_background.png"));
	loadimage(&img_start_button, _T("res/start_button.png"));
	loadimage(&img_knapsack_button, _T("res/knapsack_button.png"));
	loadimage(&img_set_button, _T("res/set_button.png"));
	loadimage(&img_exit_button, _T("res/exit_button.png"));

	// 选择场景资源加载
	loadimage(&img_selector_background, _T("res/selector_background.png"));
	loadimage(&img_return_button, _T("res/return_button.png"));
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

	// 游戏内场景资源加载
	loadimage(&img_sky, _T("res/sky.png"));
	loadimage(&img_sun, _T("res/sun.png"));
	loadimage(&img_hills, _T("res/hills.png"));
	loadimage(&img_grassland, _T("res/grassland.png"));
	loadimage(&img_tree_centre, _T("res/tree_centre.png"));
	loadimage(&img_tree_1, _T("res/tree_1.png"));
	loadimage(&img_tree_2, _T("res/tree_2.png"));
	loadimage(&img_tree_3, _T("res/tree_3.png"));
	loadimage(&img_continue_game_button, _T("res/continue_game_button.png"));
	loadimage(&img_restart_button, _T("res/restart_button.png"));
	loadimage(&img_return_menu_button, _T("res/return_menu_button.png"));

	loadimage(&img_charmander_head_portrait_right, _T("res/charmander_head_portrait_right.png"));
	flip_image(&img_charmander_head_portrait_right, &img_charmander_head_portrait_left);
	loadimage(&img_squirtle_head_portrait_right, _T("res/squirtle_head_portrait_right.png"));
	flip_image(&img_squirtle_head_portrait_right, &img_squirtle_head_portrait_left);
	loadimage(&img_bulbasaur_head_portrait_right, _T("res/bulbasaur_head_portrait_right.png"));
	flip_image(&img_bulbasaur_head_portrait_right, &img_bulbasaur_head_portrait_left);


	atlas_charmander_left.load_from_file(_T("res/charmander_%d.png"), 3);
	flip_atlas(atlas_charmander_left, atlas_charmander_right);
	atlas_squirtle_left.load_from_file(_T("res/squirtle_%d.png"), 3);
	flip_atlas(atlas_squirtle_left, atlas_squirtle_right);
	atlas_bulbasaur_left.load_from_file(_T("res/bulbasaur_%d.png"), 3);
	flip_atlas(atlas_bulbasaur_left, atlas_bulbasaur_right);

	atlas_charmander_high_frame_left.high_frame_load_from_file(10,_T("res/charmander_%d.png"), 2);
	flip_atlas(atlas_charmander_high_frame_left, atlas_charmander_high_frame_right);
	atlas_squirtle_high_frame_left.high_frame_load_from_file(10, _T("res/squirtle_%d.png"), 2);
	flip_atlas(atlas_squirtle_high_frame_left, atlas_squirtle_high_frame_right);
	atlas_bulbasaur_high_frame_left.high_frame_load_from_file(10, _T("res/bulbasaur_%d.png"), 2);
	flip_atlas(atlas_bulbasaur_high_frame_left, atlas_bulbasaur_high_frame_right);

	//技能动画资源加载
	atlas_fireball.load_from_file(_T("res/fireball_%d.png"), 13);
	atlas_fire.load_from_file(_T("res/fire_%d.png"), 9);

	//胜利动画
	loadimage(&img_winnner_bar, _T("res/winner_bar.png"));
	loadimage(&img_1P_charmander_win_text_bar, _T("res/1P_charmander_win_text_bar.png"));
	loadimage(&img_2P_charmander_win_text_bar, _T("res/2P_charmander_win_text_bar.png"));
	loadimage(&img_1P_squirtle_win_text_bar, _T("res/1P_squirtle_win_text_bar.png"));
	loadimage(&img_2P_squirtle_win_text_bar, _T("res/2P_squirtle_win_text_bar.png"));
	loadimage(&img_1P_bulbasaur_win_text_bar, _T("res/1P_bulbasaur_win_text_bar.png"));
	loadimage(&img_2P_bulbasaur_win_text_bar, _T("res/2P_bulbasaur_win_text_bar.png"));
}