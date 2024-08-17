#pragma once

#include "atlas.h"

#include <Windows.h>

#pragma comment(lib, "Winmm.lib")


// 主菜单场景
IMAGE img_background_base;							// 主菜单背景版
IMAGE img_menu_background;							// 主菜单界面
IMAGE img_start_button;								// 开始按钮
IMAGE img_knapsack_button;							// 背包按钮
IMAGE img_set_button;								// 设置按钮
IMAGE img_exit_button;								// 退出按钮

Atlas atlas_mysql_unconnected;						// 数据库未连接的文本提示


// 设置场景
IMAGE img_set_background;							// 设置场景背景
IMAGE img_set_return_to_menu_button;				// 返回按钮
// 设置选项通用背景文字等
IMAGE img_set_bar_background_color;					// 设置条背景色
IMAGE img_open_or_close_white_background;			// 白色背景（上面绘制打开和关闭文本）
IMAGE img_is_open_or_is_close;						// 是打开 or 是关闭
IMAGE img_open_text;								// 打开文本
IMAGE img_close_text;								// 关闭文本
// 设置选项名等
IMAGE img_novice_teaching_text;						// 新手教程文本
IMAGE img_attribute_restrain_switch;				// 属性克制开关选项的文本


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
IMAGE img_again_button;								// 再来一把按钮
IMAGE img_return_menu_button;						// 返回主菜单按钮
IMAGE img_new_return_menu_button;					// 新的返回主菜单按钮
IMAGE img_charmander_head_portrait_right;			// 朝向向右的小火龙头像
IMAGE img_charmander_head_portrait_left;			// 朝向向左的小火龙头像
IMAGE img_squirtle_head_portrait_right;				// 朝向向右的杰尼龟头像
IMAGE img_squirtle_head_portrait_left;				// 朝向向左的杰尼龟头像
IMAGE img_bulbasaur_head_portrait_right;			// 朝向向右的妙蛙种子头像
IMAGE img_bulbasaur_head_portrait_left;				// 朝向向左的妙蛙种子头像

IMAGE img_skill_frame;								// 技能提示框

IMAGE img_skill_frame_strike;						// 撞击的技能提示框

IMAGE img_skill_frame_fire;							// 火花的技能提示框
IMAGE img_skill_frame_flame_jet;					// 火焰喷射的技能提示框

IMAGE img_skill_frame_water_gun;					// 水枪的技能提示框
IMAGE img_skill_frame_drink_water;					// 饮水的技能提示框

IMAGE img_skill_frame_fly_leaf;						// 飞叶的技能提示框
IMAGE img_skill_frame_parasitism;					// 寄生的技能提示框
IMAGE img_skill_frame_straw_tying;					// 打草结的技能提示框

IMAGE img_tutorial_prompt_text_A;					// 教程提示文本A
IMAGE img_tutorial_prompt_text_D;					// 教程提示文本D
IMAGE img_tutorial_prompt_text_left_arrow;			// 教程提示文本⬅
IMAGE img_tutorial_prompt_text_right_arrow;			// 教程提示文本➡
IMAGE img_tutorial_prompt_text_jump_1P;				// 教程提示文本W
IMAGE img_tutorial_prompt_text_jump_2P;				// 教程提示文本⬆
IMAGE img_tutorial_prompt_text_skill_1P;			// 教程提示文本1P的技能按钮
IMAGE img_tutorial_prompt_text_skill_2P;			// 教程提示文本2P的技能按钮


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
Atlas atlas_flame_jet_x_01;							// 火焰喷射发射的动画切片1
Atlas atlas_flame_jet_x_02;							// 火焰喷射发射的动画切片2
Atlas atlas_flame_jet_x_03;							// 火焰喷射发射的动画切片3
Atlas atlas_flame_jet_x_04;							// 火焰喷射发射的动画切片4
Atlas atlas_flame_jet_x_05;							// 火焰喷射发射的动画切片5
Atlas atlas_flame_jet_x_06;							// 火焰喷射发射的动画切片6
Atlas atlas_flame_jet_x_07;							// 火焰喷射发射的动画切片7
Atlas atlas_flame_jet_x_08;							// 火焰喷射发射的动画切片8
Atlas atlas_flame_jet_x_09;							// 火焰喷射发射的动画切片9
Atlas atlas_flame_jet_x_10;							// 火焰喷射发射的动画切片10
Atlas atlas_flame_jet_x_11;							// 火焰喷射发射的动画切片11
Atlas atlas_flame_jet_x_12;							// 火焰喷射发射的动画切片12
Atlas atlas_flame_jet_x_13;							// 火焰喷射发射的动画切片13
Atlas atlas_flame_jet_x_14;							// 火焰喷射发射的动画切片14
Atlas atlas_flame_jet_x_15;							// 火焰喷射发射的动画切片15
Atlas atlas_flame_jet_x_16;							// 火焰喷射发射的动画切片16

Atlas atlas_water_droplet_right;					// 水枪向右发射出的动画
Atlas atlas_water_droplet_left;						// 水枪向左发射出的动画
Atlas atlas_splashes;								// 水枪命中后的动画

Atlas atlas_fly_leaf_left;							// 飞叶向左发射出的动画
Atlas atlas_fly_leaf_right;							// 飞叶向右发射出的动画


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

	atlas_mysql_unconnected.load_from_file(_T("res/mysql_unconnected_%d.png"), 21);

	//设置场景资源加载
	loadimage(&img_set_background, _T("res/set/set_background.png"));
	loadimage(&img_set_return_to_menu_button, _T("res/set/set_return_to_menu_button.png"));
	// 设置选项通用背景文字等
	loadimage(&img_set_bar_background_color, _T("res/set/set_bar_background_color.png"));
	loadimage(&img_open_or_close_white_background, _T("res/set/open_or_close_white_background.png"));
	loadimage(&img_is_open_or_is_close, _T("res/set/is_open_or_is_close.png"));
	loadimage(&img_open_text, _T("res/set/open_text.png"));
	loadimage(&img_close_text, _T("res/set/close_text.png"));
	// 设置选项名等
	loadimage(&img_novice_teaching_text, _T("res/set/novice_teaching_text.png"));
	loadimage(&img_attribute_restrain_switch, _T("res/set/attribute_restrain_switch.png"));


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
	loadimage(&img_again_button, _T("res/again_button.png"));
	loadimage(&img_return_menu_button, _T("res/return_menu_button.png"));
	loadimage(&img_new_return_menu_button, _T("res/new_return_menu_button.png"));

	loadimage(&img_charmander_head_portrait_right, _T("res/charmander_head_portrait_right.png"));
	flip_image(&img_charmander_head_portrait_right, &img_charmander_head_portrait_left);
	loadimage(&img_squirtle_head_portrait_right, _T("res/squirtle_head_portrait_right.png"));
	flip_image(&img_squirtle_head_portrait_right, &img_squirtle_head_portrait_left);
	loadimage(&img_bulbasaur_head_portrait_right, _T("res/bulbasaur_head_portrait_right.png"));
	flip_image(&img_bulbasaur_head_portrait_right, &img_bulbasaur_head_portrait_left);

	loadimage(&img_skill_frame, _T("res/skill_frame.png"));
	loadimage(&img_skill_frame_strike, _T("res/skill_frame_strike.png"));
	loadimage(&img_skill_frame_fire, _T("res/skill_frame_fire.png"));
	loadimage(&img_skill_frame_flame_jet, _T("res/skill_frame_flame_jet.png"));
	loadimage(&img_skill_frame_water_gun, _T("res/skill_frame_water_gun.png"));
	loadimage(&img_skill_frame_drink_water, _T("res/skill_frame_drink_water.png"));
	loadimage(&img_skill_frame_fly_leaf, _T("res/skill_frame_fly_leaf.png"));
	loadimage(&img_skill_frame_parasitism, _T("res/skill_frame_parasitism.png"));
	loadimage(&img_skill_frame_straw_tying, _T("res/skill_frame_straw_tying.png"));
	loadimage(&img_tutorial_prompt_text_A, _T("res/tutorial_prompt_text_A.png"));
	loadimage(&img_tutorial_prompt_text_D, _T("res/tutorial_prompt_text_D.png"));
	loadimage(&img_tutorial_prompt_text_left_arrow, _T("res/tutorial_prompt_text_left_arrow.png"));
	loadimage(&img_tutorial_prompt_text_right_arrow, _T("res/tutorial_prompt_text_right_arrow.png"));
	loadimage(&img_tutorial_prompt_text_jump_1P, _T("res/tutorial_prompt_text_jump_1P.png"));
	loadimage(&img_tutorial_prompt_text_jump_2P, _T("res/tutorial_prompt_text_jump_2P.png"));
	loadimage(&img_tutorial_prompt_text_skill_1P, _T("res/tutorial_prompt_text_skill_1P.png"));
	loadimage(&img_tutorial_prompt_text_skill_2P, _T("res/tutorial_prompt_text_skill_2P.png"));


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
	atlas_flame_jet_x_01.load_from_file(_T("res/flame_jet_%d_01.png"), 5);
	atlas_flame_jet_x_02.load_from_file(_T("res/flame_jet_%d_02.png"), 5);
	atlas_flame_jet_x_03.load_from_file(_T("res/flame_jet_%d_03.png"), 5);
	atlas_flame_jet_x_04.load_from_file(_T("res/flame_jet_%d_04.png"), 5);
	atlas_flame_jet_x_05.load_from_file(_T("res/flame_jet_%d_05.png"), 5);
	atlas_flame_jet_x_06.load_from_file(_T("res/flame_jet_%d_06.png"), 5);
	atlas_flame_jet_x_07.load_from_file(_T("res/flame_jet_%d_07.png"), 5);
	atlas_flame_jet_x_08.load_from_file(_T("res/flame_jet_%d_08.png"), 5);
	atlas_flame_jet_x_09.load_from_file(_T("res/flame_jet_%d_09.png"), 5);
	atlas_flame_jet_x_10.load_from_file(_T("res/flame_jet_%d_10.png"), 5);
	atlas_flame_jet_x_11.load_from_file(_T("res/flame_jet_%d_11.png"), 5);
	atlas_flame_jet_x_12.load_from_file(_T("res/flame_jet_%d_12.png"), 5);
	atlas_flame_jet_x_13.load_from_file(_T("res/flame_jet_%d_13.png"), 5);
	atlas_flame_jet_x_14.load_from_file(_T("res/flame_jet_%d_14.png"), 5);
	atlas_flame_jet_x_15.load_from_file(_T("res/flame_jet_%d_15.png"), 5);
	atlas_flame_jet_x_16.load_from_file(_T("res/flame_jet_%d_16.png"), 5);
	atlas_water_droplet_right.load_from_file(_T("res/water_droplet_%d.png"), 11);
	flip_atlas(atlas_water_droplet_right, atlas_water_droplet_left);
	atlas_splashes.load_from_file(_T("res/splashes_%d.png"), 5);
	atlas_fly_leaf_left.load_from_file(_T("res/fly_leaf_%d.png"), 3);
	flip_atlas(atlas_fly_leaf_left, atlas_fly_leaf_right);

	//胜利动画
	loadimage(&img_winnner_bar, _T("res/winner_bar.png"));
	loadimage(&img_1P_charmander_win_text_bar, _T("res/1P_charmander_win_text_bar.png"));
	loadimage(&img_2P_charmander_win_text_bar, _T("res/2P_charmander_win_text_bar.png"));
	loadimage(&img_1P_squirtle_win_text_bar, _T("res/1P_squirtle_win_text_bar.png"));
	loadimage(&img_2P_squirtle_win_text_bar, _T("res/2P_squirtle_win_text_bar.png"));
	loadimage(&img_1P_bulbasaur_win_text_bar, _T("res/1P_bulbasaur_win_text_bar.png"));
	loadimage(&img_2P_bulbasaur_win_text_bar, _T("res/2P_bulbasaur_win_text_bar.png"));

	mciSendString(_T("open res/music/background_music_1.mp3 alias background_music_1"), NULL, 0, NULL);
	mciSendString(_T("open res/music/background_music_2.mp3 alias background_music_2"), NULL, 0, NULL);
	mciSendString(_T("open res/music/background_music_3.mp3 alias background_music_3"), NULL, 0, NULL);
	mciSendString(_T("open res/music/click_sound_1.wav alias click_sound_1"), NULL, 0, NULL);
	mciSendString(_T("open res/music/click_sound_2.wav alias click_sound_2"), NULL, 0, NULL);
	mciSendString(_T("open res/music/click_sound_3.wav alias click_sound_3"), NULL, 0, NULL);
}