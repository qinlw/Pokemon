#pragma once

#include "scene.h"
#include "mysql_fun.h"
#include "timer.h"


extern Scene* menu_scene;

extern bool is_first_game;
extern bool is_attribute_restrain;
extern bool is_open_music;
extern bool is_open_sound_effect;

class SceneSet : public Scene {
public:
	void on_enter() {
		set_background_pos.x = getwidth();
		set_background_pos.y = 0;

		mciSendString(_T("play wooden_cabinet_sound_slide_out from 0"), NULL, 0, NULL);
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


		const int first_bar_to_top_distance = 73;
		const int up_bar_to_down_bar_distance = 60;
		const int left_to_bar_distance = 33;

		// 设置新手教程的位置		
		is_first_game_set_bar_background_clolr_pos.x = set_background_pos.x + left_to_bar_distance;
		is_first_game_set_bar_background_clolr_pos.y = set_background_pos.y + first_bar_to_top_distance;
		novice_teaching_text_pos.x = is_first_game_set_bar_background_clolr_pos.x;
		novice_teaching_text_pos.y = is_first_game_set_bar_background_clolr_pos.y;
		is_first_game_open_or_close_white_background_pos.x = is_first_game_set_bar_background_clolr_pos.x +
			img_set_bar_background_color.getwidth() - img_open_or_close_white_background.getwidth();
		is_first_game_open_or_close_white_background_pos.y = is_first_game_set_bar_background_clolr_pos.y;
		is_first_game_close_text_pos.x = is_first_game_set_bar_background_clolr_pos.x + img_set_bar_background_color.getwidth() - img_close_text.getwidth();
		is_first_game_close_text_pos.y = is_first_game_set_bar_background_clolr_pos.y;
		is_first_game_open_text_pos.x = is_first_game_close_text_pos.x - img_close_text.getwidth();
		is_first_game_open_text_pos.y = is_first_game_set_bar_background_clolr_pos.y;
		if (set_is_first_game_is_open) is_first_game_is_open_or_is_close_pos.x = is_first_game_open_text_pos.x;
		else is_first_game_is_open_or_is_close_pos.x = is_first_game_close_text_pos.x;
		is_first_game_is_open_or_is_close_pos.y = is_first_game_set_bar_background_clolr_pos.y;

		// 设置属性克制的位置
		attribute_restrain_switch_set_bar_background_clolr_pos.x = is_first_game_set_bar_background_clolr_pos.x;
		attribute_restrain_switch_set_bar_background_clolr_pos.y = is_first_game_set_bar_background_clolr_pos.y + up_bar_to_down_bar_distance;
		attribute_restrain_text_pos.x = attribute_restrain_switch_set_bar_background_clolr_pos.x;
		attribute_restrain_text_pos.y = attribute_restrain_switch_set_bar_background_clolr_pos.y;
		attribute_restrain_switch_close_text_pos.x = attribute_restrain_switch_set_bar_background_clolr_pos.x +
			img_set_bar_background_color.getwidth() - img_close_text.getwidth();
		attribute_restrain_switch_close_text_pos.y = attribute_restrain_switch_set_bar_background_clolr_pos.y;
		attribute_restrain_switch_open_text_pos.x = attribute_restrain_switch_close_text_pos.x - img_open_text.getwidth();
		attribute_restrain_switch_open_text_pos.y = attribute_restrain_switch_set_bar_background_clolr_pos.y;
		if (is_attribute_restrain) attribute_restrain_switch_is_open_or_is_close_pos.x = attribute_restrain_switch_open_text_pos.x;
		else attribute_restrain_switch_is_open_or_is_close_pos.x = attribute_restrain_switch_close_text_pos.x;
		attribute_restrain_switch_is_open_or_is_close_pos.y = attribute_restrain_switch_set_bar_background_clolr_pos.y;

		// 设置背景音乐的位置
		const int option_hight = 40;
		background_music_set_bar_background_clolr_pos.x = attribute_restrain_switch_set_bar_background_clolr_pos.x;
		background_music_set_bar_background_clolr_pos.y = attribute_restrain_switch_set_bar_background_clolr_pos.y + up_bar_to_down_bar_distance;
		background_music_text_pos.x = background_music_set_bar_background_clolr_pos.x;
		background_music_text_pos.y = background_music_set_bar_background_clolr_pos.y;
		background_music_choice_pos.x = background_music_set_bar_background_clolr_pos.x + img_set_bar_background_color.getwidth() - img_choice.getwidth();;
		background_music_choice_pos.y = background_music_set_bar_background_clolr_pos.y;
		background_music_current_set_music_pos.x = background_music_choice_pos.x - img_choice_background_color.getwidth();
		background_music_current_set_music_pos.y = background_music_choice_pos.y;
		background_music_underpainting_pos.x = background_music_current_set_music_pos.x;
		background_music_underpainting_pos.y = background_music_current_set_music_pos.y - img_background_music_underpainting.getheight();
		background_music_1.x = background_music_underpainting_pos.x;
		background_music_1.y = background_music_underpainting_pos.y;
		background_music_2.x = background_music_1.x;
		background_music_2.y = background_music_1.y + option_hight;
		background_music_3.x = background_music_2.x;
		background_music_3.y = background_music_2.y + option_hight;
		background_music_choice_background_color_pos.x = background_music_1.x;
		switch (background_music_id) {
		case 1:
			background_music_choice_background_color_pos.y = background_music_1.y;
			break;
		case 2:
			background_music_choice_background_color_pos.y = background_music_2.y;
			break;
		case 3:
			background_music_choice_background_color_pos.y = background_music_3.y;
			break;
		}

		// 设置战斗音乐的位置
		game_music_set_bar_background_clolr_pos.x = background_music_set_bar_background_clolr_pos.x;
		game_music_set_bar_background_clolr_pos.y = background_music_set_bar_background_clolr_pos.y + up_bar_to_down_bar_distance;
		game_music_text_pos.x = game_music_set_bar_background_clolr_pos.x;
		game_music_text_pos.y = game_music_set_bar_background_clolr_pos.y;


		// 设置音乐的位置
		is_open_music_set_bar_background_clolr_pos.x = game_music_set_bar_background_clolr_pos.x;
		is_open_music_set_bar_background_clolr_pos.y = game_music_set_bar_background_clolr_pos.y + up_bar_to_down_bar_distance;
		is_open_music_text_pos.x = is_open_music_set_bar_background_clolr_pos.x;
		is_open_music_text_pos.y = is_open_music_set_bar_background_clolr_pos.y;
		is_open_music_close_text_pos.x = is_open_music_set_bar_background_clolr_pos.x +
			img_set_bar_background_color.getwidth() - img_close_text.getwidth();
		is_open_music_close_text_pos.y = is_open_music_set_bar_background_clolr_pos.y;
		is_open_music_open_text_pos.x = is_open_music_close_text_pos.x - img_open_text.getwidth();
		is_open_music_open_text_pos.y = is_open_music_set_bar_background_clolr_pos.y;
		if (is_open_music) is_open_music_is_open_or_is_close_pos.x = is_open_music_open_text_pos.x;
		else is_open_music_is_open_or_is_close_pos.x = is_open_music_close_text_pos.x;
		is_open_music_is_open_or_is_close_pos.y = is_open_music_set_bar_background_clolr_pos.y;

		// 设置音效的位置
		is_open_sound_effect_set_bar_background_clolr_pos.x = is_open_music_set_bar_background_clolr_pos.x;
		is_open_sound_effect_set_bar_background_clolr_pos.y = is_open_music_set_bar_background_clolr_pos.y + up_bar_to_down_bar_distance;
		is_open_sound_effect_text_pos.x = is_open_sound_effect_set_bar_background_clolr_pos.x;
		is_open_sound_effect_text_pos.y = is_open_sound_effect_set_bar_background_clolr_pos.y;
		is_open_sound_effect_close_text_pos.x = is_open_sound_effect_set_bar_background_clolr_pos.x +
			img_set_bar_background_color.getwidth() - img_close_text.getwidth();
		is_open_sound_effect_close_text_pos.y = is_open_sound_effect_set_bar_background_clolr_pos.y;
		is_open_sound_effect_open_text_pos.x = is_open_sound_effect_close_text_pos.x - img_open_text.getwidth();
		is_open_sound_effect_open_text_pos.y = is_open_sound_effect_set_bar_background_clolr_pos.y;
		if (is_open_sound_effect) is_open_sound_effect_is_open_or_is_close_pos.x = is_open_sound_effect_open_text_pos.x;
		else is_open_sound_effect_is_open_or_is_close_pos.x = is_open_sound_effect_close_text_pos.x;
		is_open_sound_effect_is_open_or_is_close_pos.y = is_open_sound_effect_set_bar_background_clolr_pos.y;
	}

	void on_draw() {
		menu_scene->on_draw();
		putimage_alpha(set_background_pos.x, set_background_pos.y, &img_set_background);
		putimage_alpha(set_return_to_menu_button_pos.x, set_return_to_menu_button_pos.y, &img_set_return_to_menu_button);

		// 设置新手教程
		putimage_alpha(is_first_game_set_bar_background_clolr_pos.x, is_first_game_set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(novice_teaching_text_pos.x, novice_teaching_text_pos.y, &img_novice_teaching_text);
		putimage_alpha(is_first_game_open_or_close_white_background_pos.x, is_first_game_open_or_close_white_background_pos.y, &img_open_or_close_white_background);
		putimage_alpha(is_first_game_is_open_or_is_close_pos.x, is_first_game_is_open_or_is_close_pos.y, &img_is_open_or_is_close);
		putimage_alpha(is_first_game_close_text_pos.x, is_first_game_close_text_pos.y, &img_close_text);
		putimage_alpha(is_first_game_open_text_pos.x, is_first_game_open_text_pos.y, &img_open_text);
		// 设置属性克制
		putimage_alpha(attribute_restrain_switch_set_bar_background_clolr_pos.x, attribute_restrain_switch_set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(attribute_restrain_text_pos.x, attribute_restrain_text_pos.y, &img_attribute_restrain_switch);
		putimage_alpha(attribute_restrain_switch_is_open_or_is_close_pos.x, attribute_restrain_switch_is_open_or_is_close_pos.y, &img_is_open_or_is_close);
		putimage_alpha(attribute_restrain_switch_close_text_pos.x, attribute_restrain_switch_close_text_pos.y, &img_close_text);
		putimage_alpha(attribute_restrain_switch_open_text_pos.x, attribute_restrain_switch_open_text_pos.y, &img_open_text);
		// 设置背景音乐
		putimage_alpha(background_music_set_bar_background_clolr_pos.x, background_music_set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(background_music_text_pos.x, background_music_text_pos.y, &img_background_music_text);
		putimage_alpha(background_music_choice_pos.x, background_music_choice_pos.y, &img_choice);
		putimage_alpha(background_music_current_set_music_pos.x, background_music_current_set_music_pos.y, &img_choice_background_color);
		putimage_alpha(background_music_underpainting_pos.x, background_music_underpainting_pos.y, &img_background_music_underpainting);
		switch (background_music_id) {
		case 1:
			putimage_alpha(background_music_current_set_music_pos.x, background_music_current_set_music_pos.y, &img_music_1);
			putimage_alpha(background_music_1.x, background_music_1.y, &img_choice_background_color);
			break;
		case 2:
			putimage_alpha(background_music_current_set_music_pos.x, background_music_current_set_music_pos.y, &img_music_2);
			putimage_alpha(background_music_2.x, background_music_2.y, &img_choice_background_color);
			break;
		case 3:
			putimage_alpha(background_music_current_set_music_pos.x, background_music_current_set_music_pos.y, &img_music_3);
			putimage_alpha(background_music_3.x, background_music_3.y, &img_choice_background_color);
			break;
		}
		putimage_alpha(background_music_1.x, background_music_1.y, &img_music_1);
		putimage_alpha(background_music_2.x, background_music_2.y, &img_music_2);
		putimage_alpha(background_music_3.x, background_music_3.y, &img_music_3);
		// 设置战斗音乐
		putimage_alpha(game_music_text_pos.x, game_music_text_pos.y, &img_game_music_text);
		// 设置音乐
		putimage_alpha(is_open_music_set_bar_background_clolr_pos.x, is_open_music_set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(is_open_music_text_pos.x, is_open_music_text_pos.y, &img_is_open_music_text);
		putimage_alpha(is_open_music_is_open_or_is_close_pos.x, is_open_music_is_open_or_is_close_pos.y, &img_is_open_or_is_close);
		putimage_alpha(is_open_music_close_text_pos.x, is_open_music_close_text_pos.y, &img_close_text);
		putimage_alpha(is_open_music_open_text_pos.x, is_open_music_open_text_pos.y, &img_open_text);
		// 设置音乐
		putimage_alpha(is_open_sound_effect_set_bar_background_clolr_pos.x, is_open_sound_effect_set_bar_background_clolr_pos.y, &img_set_bar_background_color);
		putimage_alpha(is_open_sound_effect_text_pos.x, is_open_sound_effect_text_pos.y, &img_is_open_sound_effect_text);
		putimage_alpha(is_open_sound_effect_is_open_or_is_close_pos.x, is_open_sound_effect_is_open_or_is_close_pos.y, &img_is_open_or_is_close);
		putimage_alpha(is_open_sound_effect_close_text_pos.x, is_open_sound_effect_close_text_pos.y, &img_close_text);
		putimage_alpha(is_open_sound_effect_open_text_pos.x, is_open_sound_effect_open_text_pos.y, &img_open_text);
	}

	void on_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_LBUTTONUP:
			// 退出判断
			if (msg.x < set_background_pos.x) {
				is_exit_set = true;
				mciSendString(_T("play wooden_cabinet_sound_slide_in from 0"), NULL, 0, NULL);
				break;
			}

			// 设置新手教程的设置判断
			if (msg.y < is_first_game_set_bar_background_clolr_pos.y + img_set_bar_background_color.getheight() && msg.y > is_first_game_set_bar_background_clolr_pos.y) {
				if (msg.x < is_first_game_open_text_pos.x + img_open_text.getwidth() && msg.x > is_first_game_open_text_pos.x) {
					set_is_first_game_is_open = true;
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				else if (msg.x < is_first_game_close_text_pos.x + img_close_text.getwidth() && msg.x > is_first_game_close_text_pos.x) {
					set_is_first_game_is_open = false;
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				break;
			}

			// 设置属性克制的设置判断
			if (msg.y < attribute_restrain_switch_set_bar_background_clolr_pos.y + img_set_bar_background_color.getheight() && msg.y > attribute_restrain_switch_set_bar_background_clolr_pos.y) {
				if (msg.x < attribute_restrain_switch_open_text_pos.x + img_open_text.getwidth() && msg.x > attribute_restrain_switch_open_text_pos.x) {
					is_attribute_restrain = true;
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				else if (msg.x < attribute_restrain_switch_close_text_pos.x + img_close_text.getwidth() && msg.x > attribute_restrain_switch_close_text_pos.x) {
					is_attribute_restrain = false;
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				break;
			}

			// 设置音乐的设置判断
			if (msg.y < is_open_music_set_bar_background_clolr_pos.y + img_set_bar_background_color.getheight() && msg.y > is_open_music_set_bar_background_clolr_pos.y) {
				if (msg.x < is_open_music_open_text_pos.x + img_open_text.getwidth() && msg.x > is_open_music_open_text_pos.x) {
					if (is_open_music) break;
					set_is_open_music(true);
					is_open_music = true;			
					switch (background_music_id) {
					case 1:
						mciSendString(_T("play background_music_1 repeat from 0"), NULL, 0, NULL);
						is_playing_background_music = true;
						break;
					case 2:
						mciSendString(_T("play background_music_2 repeat from 0"), NULL, 0, NULL);
						is_playing_background_music = true;
						break;
					case 3:
						mciSendString(_T("play background_music_3 repeat from 0"), NULL, 0, NULL);
						is_playing_background_music = true;
						break;
					}
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				else if (msg.x < is_open_music_close_text_pos.x + img_close_text.getwidth() && msg.x > is_open_music_close_text_pos.x) {
					is_open_music = false;
					set_is_open_music(false);
					switch (background_music_id) {
					case 1:
						mciSendString(_T("stop background_music_1"), NULL, 0, NULL);
						is_playing_background_music = false;
						break;
					case 2:
						mciSendString(_T("stop background_music_2"), NULL, 0, NULL);
						is_playing_background_music = false;
						break;
					case 3:
						mciSendString(_T("stop background_music_3"), NULL, 0, NULL);
						is_playing_background_music = false;
						break;
					}
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				break;
			}

			// 设置音效的设置判断
			if (msg.y < is_open_sound_effect_set_bar_background_clolr_pos.y + img_set_bar_background_color.getheight() && msg.y > is_open_sound_effect_set_bar_background_clolr_pos.y) {
				if (msg.x < is_open_sound_effect_open_text_pos.x + img_open_text.getwidth() && msg.x > is_open_sound_effect_open_text_pos.x) {
					is_open_sound_effect = true;
					set_is_open_sound_effect(true);
					mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
				}
				else if (msg.x < is_open_sound_effect_close_text_pos.x + img_close_text.getwidth() && msg.x > is_open_sound_effect_close_text_pos.x) {
					if (is_open_sound_effect) mciSendString(_T("play click_sound_1 from 50"), NULL, 0, NULL);
					set_is_open_sound_effect(false);
					is_open_sound_effect = false;
				}
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
	POINT is_first_game_set_bar_background_clolr_pos = { 0 };						// 设置条背景色的位置
	POINT novice_teaching_text_pos = { 0 };											// 新手教程文本的位置
	POINT is_first_game_open_or_close_white_background_pos = { 0 };					// 白色背景位置的位置
	POINT is_first_game_close_text_pos = { 0 };										// 关闭文本的位置
	POINT is_first_game_open_text_pos = { 0 };										// 打开文本的位置
	POINT is_first_game_is_open_or_is_close_pos = { 0 };							// 是打开 or 是关闭  的位置
	// 设置属性克制的位置
	POINT attribute_restrain_switch_set_bar_background_clolr_pos = { 0 };			// 设置条背景色的位置
	POINT attribute_restrain_text_pos = { 0 };										// 属性克制文本的位置
	POINT attribute_restrain_switch_close_text_pos = { 0 };							// 关闭文本的位置
	POINT attribute_restrain_switch_open_text_pos = { 0 };							// 打开文本的位置
	POINT attribute_restrain_switch_is_open_or_is_close_pos = { 0 };				// 是打开 or 是关闭  的位置
	// 设置背景音乐的位置
	POINT background_music_set_bar_background_clolr_pos = { 0 };					// 设置条背景色的位置
	POINT background_music_text_pos = { 0 };										// 背景音乐文本的位置
	POINT background_music_choice_pos = { 0 };										// 背景音乐选择器的位置
	POINT background_music_current_set_music_pos = { 0 };							// 当前设置的音乐的位置
	POINT background_music_underpainting_pos = { 0 };								// 背景色的位置
	POINT background_music_choice_background_color_pos = { 0 };						// 选择的音乐的颜色
	POINT background_music_1 = { 0 };												// 音乐1的位置
	POINT background_music_2 = { 0 };												// 音乐2的位置
	POINT background_music_3 = { 0 };												// 音乐3的位置
	// 设置战斗音乐的位置
	POINT game_music_set_bar_background_clolr_pos = { 0 };							// 设置条背景色的位置
	POINT game_music_text_pos = { 0 };												// 战斗音乐文本的位置
	POINT game_music_choice_pos = { 0 };											// 战斗音乐选择器的位置
	POINT game_music_current_set_music_pos = { 0 };									// 当前设置的音乐的位置
	POINT game_music_underpainting_pos = { 0 };										// 背景色的位置
	POINT game_music_choice_background_color_pos = { 0 };							// 选择的音乐的颜色
	POINT game_music_1 = { 0 };														// 音乐5的位置
	POINT game_music_2 = { 0 };														// 音乐4的位置
	POINT game_music_3 = { 0 };														// 音乐3的位置
	POINT game_music_4 = { 0 };														// 音乐2的位置
	POINT game_music_5 = { 0 };														// 音乐1的位置
	// 设置音乐的位置			
	POINT is_open_music_set_bar_background_clolr_pos = { 0 };						// 设置条背景色的位置
	POINT is_open_music_text_pos = { 0 };											// 音乐文本的位置
	POINT is_open_music_close_text_pos = { 0 };										// 关闭文本的位置
	POINT is_open_music_open_text_pos = { 0 };										// 打开文本的位置
	POINT is_open_music_is_open_or_is_close_pos = { 0 };							// 是打开 or 是关闭  的位置
	// 设置音效的位置			
	POINT is_open_sound_effect_set_bar_background_clolr_pos = { 0 };				// 设置条背景色的位置
	POINT is_open_sound_effect_text_pos = { 0 };									// 音乐文本的位置
	POINT is_open_sound_effect_close_text_pos = { 0 };								// 关闭文本的位置
	POINT is_open_sound_effect_open_text_pos = { 0 };								// 打开文本的位置
	POINT is_open_sound_effect_is_open_or_is_close_pos = { 0 };						// 是打开 or 是关闭  的位置

	bool is_exit_set = false;														// 是否退出设置
	bool set_is_first_game_is_open = is_first_game;									// 设置新手教程 是否为打开状态
};