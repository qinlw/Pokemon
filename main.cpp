#include "util.h"
#include "picture.h"
#include "scene_manager.h"
#include "scene_menu.h"
#include "scene_knapsack.h"
#include "scene_set.h"
#include "scene_pokemon.h"
#include "scene_game.h"
#include "time.h"


Scene* menu_scene = nullptr;
Scene* knapsack_scene = nullptr;
Scene* set_scene = nullptr;
Scene* pokemon_scene = nullptr;
Scene* game_scene = nullptr;

SceneManager* scene_manager;

int main() {
	srand(time(NULL));

	const int FPS = 60;

	ExMessage msg;

	initgraph(1280, 720, EX_SHOWCONSOLE);

	load_res();

	menu_scene = new SceneMenu();
	knapsack_scene = new SceneKnapsack();
	set_scene = new SceneSet();
	pokemon_scene = new ScenePokemon();
	game_scene = new SceneGame();

	scene_manager = new SceneManager();

	scene_manager->scene_set(pokemon_scene);

	BeginBatchDraw();

	while (true) {
		DWORD current_start_time = GetTickCount();

		while (peekmessage(&msg)) {
			scene_manager->on_input(msg);
		}

		static DWORD last_tick_time = GetTickCount();
		DWORD current_tick_time = GetTickCount();
		DWORD delta_time = current_tick_time - last_tick_time;
		scene_manager->on_updata(delta_time);
		last_tick_time = current_start_time;

		cleardevice();
		scene_manager->on_draw();
		FlushBatchDraw();

		DWORD current_end_time = GetTickCount();
		DWORD current_delta_time = current_end_time - current_start_time;
		if (current_delta_time < 1000 / FPS) Sleep(1000 / FPS - current_delta_time);
	}

	closegraph();
	return 0;
}