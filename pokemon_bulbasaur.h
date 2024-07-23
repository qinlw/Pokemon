#pragma once

#include "pokemon.h"


class PokemonBulbasaur : public Pokemon {
public:
	PokemonBulbasaur() {
		animation_pokemon_left.set_atlas(&atlas_bulbasaur_high_frame_left);
		animation_pokemon_left.set_interval(20);
		animation_pokemon_right.set_atlas(&atlas_bulbasaur_high_frame_right);
		animation_pokemon_right.set_interval(20);
	}

	void on_updata(int delta) {
		Pokemon::on_updata(delta);
	}

	void on_draw() {
		Pokemon::on_draw();
	}


};