#pragma once

#include "pokemon.h"
#include "charmander_fire.h"


extern bool is_debug;

extern std::vector<Bullet*> bullet_list;

class PokemonCharmander : public Pokemon {
public:
	PokemonCharmander(bool is_facing_right = true) : Pokemon(is_facing_right) {
		animation_pokemon_left.set_atlas(&atlas_charmander_high_frame_left);
		animation_pokemon_left.set_interval(20);
		animation_pokemon_right.set_atlas(&atlas_charmander_high_frame_right);
		animation_pokemon_right.set_interval(20);

		move_speed = 75.0f * base_speed;
		pokemon_ATK = 60;
		pokemon_MATK = 80;
		pokemon_DEF = 65;
		pokemon_MDEF = 65;

		pokemon_size = { 128, 115 };
	}

	void skill_1() {
	
	}

	void skill_2() {
		fire();
	}

	void skill_3() {
	
	}

	void skill_4() {
	
	}

	void on_updata(int delta) {
		Pokemon::on_updata(delta);

		pokemon_left_top_dot = { is_facing_right ? pokemon_pos.x + 50 : pokemon_pos.x + 30, pokemon_pos.y + 50 };
		pokemon_left_low_dot = { is_facing_right ? pokemon_pos.x + 50 : pokemon_pos.x + 30, pokemon_pos.y + 115 };
		pokemon_right_top_dot = { is_facing_right ? pokemon_pos.x + 90 : pokemon_pos.x + 70 , pokemon_pos.y + 50 };
		pokemon_right_low_dot = { is_facing_right ? pokemon_pos.x + 90 : pokemon_pos.x + 70, pokemon_pos.y + 115 };
	}

	void on_draw() {
		Pokemon::on_draw();	
		
		if (is_debug) {
			setcolor(RGB(0, 0, 255));
			rectangle(pokemon_left_top_dot.x, pokemon_left_top_dot.y, pokemon_right_low_dot.x, pokemon_right_low_dot.y);
		}
	}


private:
	

private:
	void fire() {
		Bullet* bullet = new CharmanderFire();

		const int fire_use_mp = bullet->get_use_mp();
		if (fire_use_mp > mp) return;

		const POINT& origin_bullet_size = bullet->get_bullet_size();
		const POINTF& origin_bullet_velocity = bullet->get_bullet_velocity();

		POINT current_bullet_position;
		POINTF current_bullet_velocity;
		current_bullet_position.x = is_facing_right ? pokemon_pos.x + pokemon_size.x - origin_bullet_size.x : pokemon_pos.x + origin_bullet_size.x;
		current_bullet_position.y = pokemon_pos.y + pokemon_size.y / 2;
		current_bullet_velocity.x = is_facing_right ? origin_bullet_velocity.x : -origin_bullet_velocity.x;
		current_bullet_velocity.y = origin_bullet_velocity.y;

		bullet->set_bullet_pos(current_bullet_position.x, current_bullet_position.y);
		bullet->set_bullet_velocity(current_bullet_velocity.x, current_bullet_velocity.y);

		bullet->set_target_player(player_id == PokemonPlayer::P1 ? PokemonPlayer::P2 : PokemonPlayer::P1);

		bullet->set_callback([&]() {
			mp -= 20;
			});

		bullet_list.push_back(bullet);
	}


};