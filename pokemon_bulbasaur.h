#pragma once

#include "pokemon.h"


class PokemonBulbasaur : public Pokemon {
public:
	PokemonBulbasaur() {
		animation_pokemon_left.set_atlas(&atlas_bulbasaur_left);
		animation_pokemon_left.set_interval(200);
		animation_pokemon_right.set_atlas(&atlas_bulbasaur_right);
		animation_pokemon_right.set_interval(200);
	}

	void on_updata(int delta) {
		Pokemon::on_updata(delta);
	}

	void on_draw() {
		Pokemon::on_draw();
	}


};