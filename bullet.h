#pragma once

#include "picture.h"
#include "pokemon_player.h"
#include "bullet_attribute.h"
#include "animation.h"


extern bool is_debug;

class Bullet {
public:
	void set_ATK(int val) {
		bullet_ATK = val;
	}

	void set_MATK(int val) {
		bullet_MATK = val;
	}

	void set_use_mp(int val) {
		use_mp = val;
	}

	int get_use_mp() {
		return use_mp;
	}

	void set_bullet_velocity(float x, float y) {
		bullet_velocity.x = x;
		bullet_velocity.y = y;
	}

	POINTF get_bullet_velocity() {
		return bullet_velocity;
	}

	POINT get_bullet_size() {
		return bullet_size;
	}

	void set_bullet_pos(int x, int y) {
		bullet_pos.x = x;
		bullet_pos.y = y;
	}

	void set_target_player(PokemonPlayer pokemon_player) {
		target_player = pokemon_player;
	}

	PokemonPlayer get_target_player() {
		return target_player;
	}

	void set_is_valid(bool flag) {
		is_valid = flag;
	}

	bool get_is_valid() {
		return is_valid;
	}

	void set_is_can_remove(bool flag) {
		is_can_remove = flag;
	}

	void set_callback(std::function<void()> callback) {
		this->callback = callback;
	}

	void on_collision() {
		callback();
	}

	bool check_is_collision(POINT pos, POINT size) {
		return (max(bullet_pos.x + bullet_size.x, pos.x + size.x) - min(bullet_pos.x, pos.x)) < bullet_size.x + size.x
			&& (max(bullet_pos.y + bullet_size.y, pos.y + size.y) - min(bullet_pos.y, pos.y)) < bullet_size.y + size.y;
	}

	virtual void on_updata(int delta) {}

	virtual void on_draw() {
		if (is_debug) {
			setcolor(RGB(255, 255, 255));
			rectangle(bullet_pos.x, bullet_pos.y, bullet_pos.x + bullet_size.x, bullet_pos.y + bullet_size.y);
			circle(bullet_pos.x + bullet_size.x / 2, bullet_pos.y + bullet_size.y / 2, bullet_size.x / 2);
		}
	}
	 

protected:
	int bullet_ATK;													// 子弹的基础物攻
	int bullet_MATK;												// 子弹的基础特攻
	int use_mp;														// 能量消耗

protected:
	POINTF bullet_velocity;											// 子弹速度
	POINT bullet_size;												// 子弹大小
	POINT bullet_pos;												// 子弹位置

	PokemonPlayer target_player = PokemonPlayer::P1;				// 子弹目标玩家
	BulletAttribute bullet_attribute;								// 子弹属性

	bool is_valid = true;											// 子弹是否有效果
	bool is_can_remove = false;										// 子弹是否能被移除

	std::function<void()> callback;									// 子弹碰撞回调函数

protected:
	bool check_is_exceed_screen() {
		return (bullet_pos.x + bullet_size.x < 0) || (bullet_pos.x > getwidth())
			|| (bullet_pos.y + bullet_size.y < 0) || (bullet_pos.y > getheight());
	}

};