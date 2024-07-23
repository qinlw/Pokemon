#pragma once

#include "picture.h"
#include "pointf.h"
#include "pokemon_player.h"
#include "animation.h"
#include "collision_line.h"


extern std::vector<CollisionLine> collision_thwartwise_line_list;
extern std::vector<CollisionLine> collision_vertical_line_list;

class Pokemon {
public:
	Pokemon(bool flag = true) : is_facing_right(flag) {
		animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
	}

	virtual void on_updata(int delta) {
		int direction = is_right_btn - is_left_btn;
		if (direction) {
			is_facing_right = direction > 0;
			animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
			float distance = direction * run_velocity * delta;
			run_pos_change(distance);
		}
		else {
			animation_current_pokemon = is_facing_right ? &animation_pokemon_right : &animation_pokemon_left;
		}

		animation_current_pokemon->on_updata(delta);

		move_collision(delta);
	}

	virtual void on_draw() {
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
					// 'W'
				case 0x57:
					jump();
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
					// '⬆'
				case VK_UP:
					jump();
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

	void set_velocity(float x, float y) {
		pokemon_velocity.x = x;
		pokemon_velocity.y = y;
	}

	void set_pokemon_pos(int x, int y) {
		pokemon_pos.x = x;
		pokemon_pos.y = y;
	}

	void set_id(PokemonPlayer id) {
		player_id = id;
	}

	void run_pos_change(float distance) {
		pokemon_pos.x += distance;
	}

	void jump() {
		if (!is_platform) return;
		pokemon_velocity.y += jump_velocity;
		is_platform = false;
	}
	

protected:
	const float gravity = 1.6e-3f;										// 重力加速度
	const float run_velocity = 0.5f;									// 奔跑速度
	const float jump_velocity = -0.75f;									// 起跳速度

protected:
	POINTF pokemon_velocity;											// 宝可梦速度
	POINT pokemon_pos;													// 宝可梦的位置
	POINT pokemon_size;													// 宝可梦的大小
	POINT pokemon_left_top_dot;											// 宝可梦的左上检测点
	POINT pokemon_left_low_dot;											// 宝可梦的左下检测点
	POINT pokemon_right_top_dot;										// 宝可梦的右上检测点
	POINT pokemon_right_low_dot;										// 宝可梦的右下检测点

	Animation* animation_current_pokemon = nullptr;					 	// 当前宝可梦动画

	Animation animation_pokemon_left;									// 朝向向左的宝可梦动画
	Animation animation_pokemon_right;									// 朝向向右的宝可梦动画

	PokemonPlayer player_id;											// 玩家id

	bool is_platform = false;											// 是否在平台上
	bool is_facing_right = false;										// 当前是否朝向右边
	bool is_left_btn = false;											// 是否按下了左移按钮
	bool is_right_btn = false;											// 是否按下了右移按钮

private:
	void move_collision(int delta) {
		const float last_tick_velocity = pokemon_velocity.y;
		const float last_tick_low = pokemon_pos.y + 115;

		pokemon_pos.y += pokemon_velocity.y * (float)delta;
		pokemon_velocity.y += gravity * (float)delta;
		pokemon_pos.x += pokemon_velocity.x * delta;

		// 屏幕周围
		if (pokemon_pos.x < -30) pokemon_pos.x = -30;
		if (pokemon_pos.x > collision_thwartwise_line_list[0].line_pos.pos_2.x - 97)
			pokemon_pos.x = collision_thwartwise_line_list[0].line_pos.pos_2.x - 97;

		// 横线
		if (pokemon_velocity.y > 0) {
			for (auto line : collision_thwartwise_line_list) {
				const bool is_collision_x = pokemon_left_low_dot.x <= line.line_pos.pos_2.x && pokemon_right_low_dot.x >= line.line_pos.pos_1.x;
				const bool is_collision_y = pokemon_left_top_dot.y <= line.line_pos.pos_1.y && pokemon_left_low_dot.y >= line.line_pos.pos_1.y;

				if (is_collision_x && is_collision_y && last_tick_velocity > 0) {
					pokemon_pos.y = line.line_pos.pos_1.y - pokemon_size.y;
					pokemon_velocity.y = 0;
					is_platform = true;
					break;
				}
			}
		}
		else if (pokemon_velocity.y <= 0) {
			for (auto line : collision_thwartwise_line_list) {
				const bool is_collision_x = pokemon_left_low_dot.x < line.line_pos.pos_2.x && pokemon_right_low_dot.x > line.line_pos.pos_1.x;
				const bool is_collision_y = pokemon_left_top_dot.y < line.line_pos.pos_1.y && pokemon_left_low_dot.y > line.line_pos.pos_1.y;

				if (is_collision_x && is_collision_y) {
					pokemon_pos.y = line.line_pos.pos_1.y - 20;
					pokemon_velocity.y = 0;
					break;
				}
			}
		}

		// 竖线
		for (auto line : collision_vertical_line_list) {
			const bool is_collision_x = pokemon_left_low_dot.x < line.line_pos.pos_1.x && pokemon_right_low_dot.x > line.line_pos.pos_1.x;
			const bool is_collision_y = pokemon_left_low_dot.y > line.line_pos.pos_1.y && pokemon_left_top_dot.y < line.line_pos.pos_2.y;

			if (!is_collision_x || !is_collision_y) continue;

			if (is_facing_right) {
				if (pokemon_pos.x > line.line_pos.pos_1.x - 97) 
					pokemon_pos.x = line.line_pos.pos_2.x - 97;
			}
			else {
				if (pokemon_pos.x < line.line_pos.pos_1.x - 30) 
					pokemon_pos.x = line.line_pos.pos_1.x - 30;
			}
		}
	}


};