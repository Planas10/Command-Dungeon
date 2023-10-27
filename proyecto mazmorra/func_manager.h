#ifndef FUNC_MANAGER_H
#define FUNC_MANAGER_H

#include <iostream>
#include <vector>
#include <string>
#include <random>
#include "ConsoleControl.h"
#include "Utils.h"

using namespace std;

enum Enemies { GOBLIN, ORC, TROLL, BOSS, LAST_ENEMY };

//Declarar la variable dungeon
const int MAXx = 25;
const int MAXy = 17;
extern int mapa_pos_x;
extern int mapa_pos_y;

extern char MAPA[MAXy][MAXx];
//mapa reinicio
extern char MAPA2[MAXy][MAXx];
//mapa final
extern char MAPA3[MAXy][MAXx];

struct personaje {
	string name;
	int max_life = 100;
	int cur_life = 100;
	int bombs = 0;
	bool key_yes = false;
	bool sword = false;
	int base_dmg = 5;
	int sword_dmg = 20;
	int potions = 0;
	bool armor_def = false;
	const int def = 25;
	int pos_x = 0;
	int pos_y = 0;
	int prev_pos_x = 0;
	int prev_pos_y = 0;
	int crit_chance = 0;
	int sword_crit = 20;
	int base_crit = 10;
	int p_dodge_chance = 0;
	int enemies_defeated = 0;
	int run_chance = 0;
	bool run_yes = false;
	string a_sword = "no";
	string a_armor = "no";
};
extern personaje player;

extern int e_dodge_chance;
extern int crit_chance;
extern int enemy_souls;

struct enemy_status {
	Enemies enemyType;
	string name;
	string letter;
	int max_life;
	int cur_life;
	int dmg;
	int crit_dmg;
	int pos_x;
	int pos_y;
	int sp_a_dmg = 50;
	int sp_crit_dmg = 30;
	int turns = 0;
};

extern enemy_status currentEnemy;
extern vector<enemy_status> enemy;
extern vector<enemy_status*> mapEnemies;


extern string input;

//variables booleanas
extern bool locked_door;
extern bool ret_val;
extern bool game_over;
extern bool mapa_obtenido;
extern bool combat;
extern bool turn_finish;
extern bool diamond;
extern bool exit_yes;
extern bool restart;

//player
void initPlayer();

void initEnemies();
void initCurrentEnemy(enemy_status* enemy);

//mapa
void show_map();
bool collisionMap(int pos_x, int pos_y);
bool enemy_collisionMap(int pos_x, int pos_y);

void boss_pos();

//camino disponible
void mostrar_camino_disponible();

//codigo puerta
void door();

void mensaje_inicial();
void mensaje_inicial_reset();

//Help commands
void enemies_info();
void objects_info();
void status_info();
void inventory();

//objects
bool hasobject(int pos_x, int pos_y);
bool hasdoor(int pos_x, int pos_y);
void surrounditems();

//enemies
bool hasenemy(int pos_x, int pos_y);
void surroundenemies();
enemy_status* enemyOnTile(int pos_x, int pos_y);

//reset
void reset();

void moveEnemies();

//combates
void Combat(string _enemyName, int life, int max_life, int E_dmg, bool turn_finish, int e_crit);

void mapa_final();

#endif
