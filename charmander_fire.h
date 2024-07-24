#pragma once

#include "bullet.h"


extern std::vector<Bullet*> bullet_list;

class CharmanderFire : public Bullet {
public:
	CharmanderFire() {
		animation_fireball.set_atlas(&atlas_fireball);
		animation_fireball.set_interval(100);
		animation_fire.set_atlas(&atlas_fire);
		animation_fire.set_interval(100);

		bullet_ATK = 50;
		bullet_MATK = 0;
		use_mp = 20;

		bullet_size = { 32, 32 };
		bullet_velocity = { 0.5f, 0.0f };

		bullet_attribute = BulletAttribute::Fire;
	}

	void on_updata(int delta) {
		bullet_pos.x += bullet_velocity.x * delta;
		bullet_pos.y += bullet_velocity.y * delta;

		if (is_valid) animation_fireball.on_updata(delta);
		else animation_fire.on_updata(delta);

		if (check_is_exceed_screen()) is_can_remove = true;

		Bullet::on_draw();
	}

	void on_draw() {
		if (is_valid) animation_fireball.on_draw(bullet_pos.x, bullet_pos.y);
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