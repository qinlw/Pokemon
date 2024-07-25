#pragma once

#include "pokemon.h"
#include "bullet.h"


extern std::vector<Bullet*> bullet_list;

class Fire : public Bullet, public Pokemon {
public:
	Fire() {
		animation_fireball.set_atlas(&atlas_fireball);
		animation_fireball.set_interval(100);
		animation_fire.set_atlas(&atlas_fire);
		animation_fire.set_interval(200);
		animation_fire.set_is_loop(false);
		animation_fire.set_callback([&]() {
			is_can_remove = true;
			});

		timer_is_inflict_one_harm.set_wait_time(200);
		timer_is_inflict_one_harm.set_one_shot(true);
		timer_is_inflict_one_harm.set_callback([&]() {
			is_inflict_one_harm = true;
			});

		bullet_ATK = 0;
		bullet_MATK = 15;
		use_mp = 20;

		bullet_size = { 32, 32 };
		bullet_velocity = { 0.5f, 0.0f };

		bullet_attribute = BulletAttribute::Fire;
	}

	void on_updata(int delta) {
		if (!is_harm) {
			bullet_pos.x += bullet_velocity.x * delta;
			bullet_pos.y += bullet_velocity.y * delta;
		}
		else {
		}

		if (!is_harm) animation_fireball.on_updata(delta);
		else animation_fire.on_updata(delta);

		if (!is_inflict_one_harm) timer_is_inflict_one_harm.on_updata(delta);

		if (check_is_exceed_screen()) is_can_remove = true;

		Bullet::on_draw();
	}

	void on_draw() {
		if (!is_harm) animation_fireball.on_draw(bullet_pos.x, bullet_pos.y);
		else animation_fire.on_draw(bullet_pos.x, bullet_pos.y);

		Bullet::on_draw();
	}

	int get_use_mp() {
		return use_mp;
	}

	POINTF get_bullet_velocity() {
		return bullet_velocity;
	}


private:
	Animation animation_fireball;								// »ðÇò¶¯»­£¨»ð»¨Î´Åö×²¶¯»­£©
	Animation animation_fire;									// »ð»¨¶¯»­

};