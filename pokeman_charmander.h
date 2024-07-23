#pragma once

#include "pokemon.h"


extern bool is_debug;

class PokemonCharmander : public Pokemon {
public:
	PokemonCharmander(bool is_facing_right = true) : Pokemon(is_facing_right) {
		animation_pokemon_left.set_atlas(&atlas_charmander_high_frame_left);
		animation_pokemon_left.set_interval(20);
		animation_pokemon_right.set_atlas(&atlas_charmander_high_frame_right);
		animation_pokemon_right.set_interval(20);

		pokemon_size = { 128, 115 };
	}

	void on_updata(int delta) {
		Pokemon::on_updata(delta);

		pokemon_left_top_dot = { pokemon_pos.x + 70, pokemon_pos.y + 50 };
		pokemon_left_low_dot = { pokemon_pos.x + 70, pokemon_pos.y + 115 };
		pokemon_right_top_dot = { pokemon_pos.x + 90 , pokemon_pos.y + 50 };
		pokemon_right_low_dot = { pokemon_pos.x + 90, pokemon_pos.y + 115 };
	}

	void on_draw() {
		Pokemon::on_draw();	
		
		if (is_debug) {
			setcolor(RGB(0, 0, 255));
			rectangle(pokemon_left_top_dot.x, pokemon_left_top_dot.y, pokemon_right_low_dot.x, pokemon_right_low_dot.y);
		}
		
	}

};