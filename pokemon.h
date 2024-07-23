#pragma once

#include "picture.h"
#include "pokemon_player.h"
#include "animation.h"


class Pokemon {
public:
	Pokemon(bool flag = true) : is_facing_right(flag) {
		animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
	}

	void on_updata(int delta) {
		int direction = is_right_btn - is_left_btn;
		if (direction) {
			is_facing_right = direction > 0;
			animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
		}
		else {
			animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
		}

		animation_current_pokemon->on_updata(delta);
	}

	void on_draw() {
		animation_current_pokemon->on_draw(pokemon_pos.x, pokemon_pos.y);
	}

	void on_input(const ExMessage& msg) {
		switch (msg.message) {
		case WM_KEYDOWN: {
			switch (player_id) {
			case PokemonPlayer::P1:
				switch (msg.vkcode) {
				// 'A'
				case 0x41:
					is_left_btn = true;
					break;
				// 'D'
				case 0x44:
					is_right_btn = true;
					break;
				}
				break;
			case PokemonPlayer::P2:
				switch (msg.vkcode) {
				// '⬅'
				case VK_LEFT:
					is_left_btn = true;
					break;
				// '➡'
				case VK_RIGHT:
					is_right_btn = true;
					break;
				}
				break;
			}
		}
		break;
		case WM_KEYUP: {
			switch (player_id) {
			case PokemonPlayer::P1:
				switch (msg.vkcode) {
					// 'A'
				case 0x41:
					is_left_btn = false;
					break;
					// 'D'
				case 0x44:
					is_right_btn = false;
					break;
				}
				break;
			case PokemonPlayer::P2:
				switch (msg.vkcode) {
					// '⬅'
				case VK_LEFT:
					is_left_btn = false;
					break;
					// '➡'
				case VK_RIGHT:
					is_right_btn = false;
					break;
				}
				break;
			}
		}
		}
	}

	void set_pokemon_pos(int x, int y) {
		pokemon_pos.x = x;
		pokemon_pos.y = y;
	}

	void set_id(PokemonPlayer id) {
		player_id = id;
	}


protected:
	POINT pokemon_pos = { 0 };											// 宝可梦的位置

	Animation* animation_current_pokemon = nullptr;						// 当前宝可梦动画

	Animation animation_pokemon_left;									// 朝向向左的宝可梦动画
	Animation animation_pokemon_right;									// 朝向向右的宝可梦动画

	PokemonPlayer player_id;											// 玩家id

	bool is_facing_right = false;										// 当前是否朝向右边
	bool is_left_btn = false;											// 是否按下了左移按钮
	bool is_right_btn = false;											// 是否按下了右移按钮

private:



};