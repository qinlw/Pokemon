#include "util.h"
#include "picture.h"
#include "scene_manager.h"
#include "scene_menu.h"
#include "scene_knapsack.h"
#include "scene_set.h"
#include "scene_pokemon.h"
#include "scene_game.h"
#include "pokeman_charmander.h"
#include "pokemon_squirtle.h"
#include "pokemon_bulbasaur.h"
#include "bullet.h"
#include "collision_line.h"
#include "time.h"


const std::string host = "127.0.0.1";
const std::string user = "qin";
const std::string password = "123456";
const std::string db = "pokemon_db";
const unsigned const int port = 3306;

bool is_debug = true;								                            // 是否开启调式模式
bool is_mysql_connect;								                            // 是否成功连接数据库
bool is_first_game;									                            // 是否是第一次游戏

Scene* menu_scene = nullptr;						                            // 菜单场景对象指针
Scene* knapsack_scene = nullptr;					                            // 背包场景对象指针
Scene* set_scene = nullptr;							                            // 设置场景对象指针
Scene* pokemon_scene = nullptr;						                            // 宝可梦场景对象指针
Scene* game_scene = nullptr;						                            // 游戏场景对象指针

SceneManager* scene_manager;						                            // 场景管理对象指针

Pokemon* pokemon_player_1 = nullptr;				                            // 宝可梦玩家1
Pokemon* pokemon_player_2 = nullptr;				                            // 宝可梦玩家2

std::vector<CollisionLine> collision_thwartwise_line_list;					    // 横向的碰撞线容器
std::vector<CollisionLine> collision_vertical_line_list;						// 竖向的碰撞线容器
std::vector<Bullet*> bullet_list;												// 子弹容器

HWND hwnd;																		// 窗口句柄
MYSQL* my;																		// mysql的连接句柄

void connect_mysql(const string host, const string user, const string password, const string db, const unsigned const int port) {
	my = mysql_init(nullptr);
	if (my == nullptr)
	{
		std::cerr << "init MySQL error" << std::endl;
		is_mysql_connect = false;
	}

	if (mysql_real_connect(my, host.c_str(), user.c_str(), password.c_str(), db.c_str(), port, nullptr, 0) == nullptr)
	{
		std::cerr << "connect MySQL error" << std::endl;
		is_mysql_connect = false;
	}
	is_mysql_connect = true;

	std::cout << "mysql connect sucess" << std::endl;

	mysql_set_character_set(my, "utf8");
}
void check_is_first_game() {
	std::string sql = "select * from game_status";
	const int n = mysql_query(my, sql.c_str());
	if (n == 0) std::cout << sql << " sucess:" << n << std::endl;
	else std::cout << sql << " failed:" << n << std::endl;

	MYSQL_RES* res = mysql_store_result(my);
	if (res == nullptr) std::cerr << "mysql_store_result error" << std::endl;

	const int rows = mysql_num_rows(res);			// 获取行数
	const int fields = mysql_num_fields(res);		// 获取列数

	for (int i = 0; i < rows; i++) {
		MYSQL_ROW row = mysql_fetch_row(res);
		for (int j = 0; j < fields; j++) {
			if (strcmp(row[j], "is_first_game") != 0) break;
			if (strcmp(row[++j], "1") == 0) is_first_game = true;
			else false;
			return;
		}
	}
}
void set_is_first_game(bool flag) {
	std::string sql = "update game_status set status = " + " where status_name = 'is_first_game'";
	const int n = mysql_query(my, sql.c_str());
	if (n == 0) std::cout << sql << " sucess:" << n << std::endl;
	else std::cout << sql << " failed:" << n << std::endl;
}

int main() {
	connect_mysql(host, user, password, db, port);
	check_is_first_game();
	set_is_first_game(false);

	srand(time(NULL)); 

	const int FPS = 60;

	ExMessage msg;

    hwnd = initgraph(1280, 720, EX_SHOWCONSOLE);

	load_res();

	menu_scene = new SceneMenu();
	knapsack_scene = new SceneKnapsack();
	set_scene = new SceneSet();
	pokemon_scene = new ScenePokemon();
	game_scene = new SceneGame();

	scene_manager = new SceneManager();

	scene_manager->scene_set(menu_scene);

	BeginBatchDraw();

	while (true) {
		DWORD current_start_time = GetTickCount();

		while (peekmessage(&msg)) {
			scene_manager->on_input(msg);
		}

		static DWORD last_tick_time = GetTickCount();
		DWORD current_tick_time = GetTickCount();
		DWORD delta_time = current_tick_time - last_tick_time;
		scene_manager->on_update(delta_time);
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


// 副主函数
int _main(int x, int y) {
	srand(time(NULL));

	const int FPS = 60;

	ExMessage msg;

	hwnd = initgraph(1280, 720, EX_SHOWCONSOLE);
	SetWindowPos(hwnd, HWND_TOP, x, y, 0, 0, SWP_NOSIZE);

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
		scene_manager->on_update(delta_time);
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