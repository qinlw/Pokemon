#pragma once

#include "pokemon.h"


class PokemonSquirtle : public Pokemon {
public:
	PokemonSquirtle() {
		animation_pokemon_left.set_atlas(&atlas_squirtle_left);
		animation_pokemon_left.set_interval(200);
		animation_pokemon_right.set_atlas(&atlas_squirtle_right);
		animation_pokemon_right.set_interval(200);
	}

	void on_updata(int delta) {
		Pokemon::on_updata(delta);
	}

	void on_draw() {
		Pokemon::on_draw();
	}

};