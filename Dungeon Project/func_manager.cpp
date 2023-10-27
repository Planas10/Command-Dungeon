#include "func_manager.h"

using namespace std;

int mapa_pos_x;
int mapa_pos_y;

char MAPA[MAXy][MAXx] =
{

	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	{'#','?','B','P','#','.','.','.','#','.','J','.','#','#','#','#','#','#','H','#','.','P','.','.','#',},
	{'#','.','.','.','#','B','#','T','#','.','.','.','#','P','O','.','.','#','.','#','.','.','T','K','#',},
	{'#','.','.','.','#','#','#','$','#','.','.','.','#','.','.','.','.','$','@','$','.','.','.','.','#',},
	{'#','.','.','.','#','.','.','.','#','#','L','#','#','.','.','.','.','#','#','#','.','.','.','.','#',},
	{'#','#','.','#','#','.','.','P','#','.','.','.','#','#','$','#','B','#','X','#','.','.','T','.','#',},
	{'#','#','$','#','#','.','O','.','#','.','.','.','.','#','.','#','#','#','#','#','#','.','.','.','#',},
	{'#','.','.','S','#','.','.','.','#','.','G','.','#','#','.','#','.','.','P','.','#','.','.','P','#',},
	{'#','G','#','#','#','.','.','.','#','.','.','.','#','#','.','$','.','.','.','.','#','#','$','#','#',},
	{'#','.','.','.','#','$','#','#','#','#','$','#','#','#','#','#','.','O','.','.','#','#','$','#','#',},
	{'#','#','#','.','#','.','#','.','.','.','.','$','.','.','T','#','.','.','.','.','#','.','.','B','#',},
	{'#','.','.','$','#','.','#','B','#','#','.','#','#','#','.','#','$','#','#','#','#','.','.','.','#',},
	{'#','.','.','#','#','$','#','.','#','#','$','#','#','#','.','#','.','.','$','.','.','.','.','.','#',},
	{'#','.','.','.','.','.','#','.','#','.','.','.','.','#','.','#','#','#','#','.','.','.','.','.','#',},
	{'#','.','P','G','.','.','#','.','#','.','.','O','.','#','.','.','.','.','$','.','G','.','P','.','#',},
	{'#','.','.','.','.','.','$','.','#','B','.','.','P','#','#','#','#','#','#','.','.','.','.','.','#',},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},


};

char MAPA2[MAXy][MAXx] =
{

	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	{'#','?','B','P','#','.','.','.','#','.','J','.','#','#','#','#','#','#','H','#','.','P','.','.','#',},
	{'#','.','.','.','#','B','#','T','#','.','.','.','#','P','O','.','.','#','.','#','.','.','T','K','#',},
	{'#','.','.','.','#','#','#','$','#','.','.','.','#','.','.','.','.','$','.','$','.','.','.','.','#',},
	{'#','.','.','.','#','.','.','.','#','#','L','#','#','.','.','.','.','#','#','#','.','.','.','.','#',},
	{'#','#','.','#','#','.','.','P','#','.','.','.','#','#','$','#','B','#','X','#','.','.','T','.','#',},
	{'#','#','$','#','#','.','O','.','#','.','.','.','.','#','.','#','#','#','#','#','#','.','.','.','#',},
	{'#','.','.','S','#','.','.','.','#','.','G','.','#','#','.','#','.','.','P','.','#','.','.','P','#',},
	{'#','G','#','#','#','.','.','.','#','.','.','.','#','#','.','$','.','.','.','.','#','#','$','#','#',},
	{'#','.','.','.','#','$','#','#','#','#','$','#','#','#','#','#','.','O','.','.','#','#','$','#','#',},
	{'#','#','#','.','#','.','#','.','.','.','.','$','.','.','T','#','.','.','.','.','#','.','.','B','#',},
	{'#','.','.','$','#','.','#','B','#','#','.','#','#','#','.','#','$','#','#','#','#','.','.','.','#',},
	{'#','.','.','#','#','$','#','.','#','#','$','#','#','#','.','#','.','.','$','.','.','.','.','.','#',},
	{'#','.','.','.','.','.','#','.','#','.','.','.','.','#','.','#','#','#','#','.','.','.','.','.','#',},
	{'#','.','P','G','.','.','#','.','#','.','.','O','.','#','.','.','.','.','$','.','G','.','P','.','#',},
	{'#','.','.','.','.','.','$','.','#','B','.','.','P','#','#','#','#','#','#','.','.','.','.','.','#',},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},


};

char MAPA3[MAXy][MAXx] =
{
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
	{'#','.','#','.','.','.','#','.','#','D','.','.','.','.','#','.','.','.','.','.','.','#','.','.','#',},
	{'#','.','.','.','#','.','#','.','#','#','#','#','#','.','#','.','#','#','#','.','.','#','.','#','#',},
	{'#','#','#','#','#','.','.','.','#','.','#','.','.','.','#','.','#','.','.','.','.','#','.','.','#',},
	{'#','.','.','.','.','#','#','.','#','.','#','.','#','#','#','.','#','.','#','#','#','#','#','.','#',},
	{'#','.','#','#','.','#','.','.','#','.','#','.','#','.','.','.','#','.','.','.','.','.','.','.','#',},
	{'#','.','#','.','.','#','.','#','#','.','#','.','.','.','#','#','#','#','#','.','#','#','.','#','#',},
	{'#','.','.','#','#','.','.','.','#','.','#','#','#','#','#','.','#','.','.','.','.','#','.','.','#',},
	{'#','#','.','.','.','.','#','.','.','.','#','.','#','.','#','.','.','.','#','#','#','#','#','.','#',},
	{'#','.','.','#','#','#','#','#','#','.','.','.','#','.','#','#','#','.','#','.','.','#','.','.','#',},
	{'#','.','#','#','.','.','.','.','M','#','.','#','#','.','.','.','#','.','#','#','.','#','.','#','#',},
	{'#','.','.','#','.','#','#','#','#','#','.','.','.','.','#','.','.','.','.','.','.','#','.','.','#',},
	{'#','#','.','#','.','#','.','.','.','#','#','#','#','.','#','#','#','#','#','.','.','.','#','.','#',},
	{'#','.','.','#','.','.','.','#','.','.','#','.','#','.','#','.','.','.','.','.','#','#','#','.','#',},
	{'#','.','#','#','#','#','#','#','#','.','.','.','#','.','.','.','#','#','#','.','#','.','.','.','#',},
	{'#','.','.','.','.','.','.','.','.','.','#','.','.','.','#','.','.','#','.','.','.','.','#','.','#',},
	{'#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#','#',},
};

//variables booleanas
bool locked_door = true;
bool ret_val = false;
bool game_over = false;
bool mapa_obtenido = false;
bool combat = false;
bool turn_finish = false;
bool diamond = false;
bool exit_yes = false;
bool restart = false;

//structs personaje y enemigos
personaje player;
enemy_status currentEnemy;

int e_dodge_chance = 0;
int crit_chance = 0;
int enemy_souls = 0;

vector<enemy_status> enemy;
vector<enemy_status*> mapEnemies;
string input = "";

//player
void initPlayer() {
	for (int i = 0; i < MAXy; i++) {
		for (int j = 0; j < MAXx; j++) {
			if (MAPA[i][j] == '@') {
				player.pos_x = j;
				player.pos_y = i;
				MAPA[i][j] = '.';
			}
		}
	}
}


void initEnemies() {
	//Base de datos de enemigos del juego
	enemy.resize(LAST_ENEMY);
	enemy[GOBLIN].name = "Goblin";
	enemy[GOBLIN].max_life = 30;
	enemy[GOBLIN].dmg = 10;
	enemy[GOBLIN].crit_dmg = 5;

	enemy[ORC].name = "Orc";
	enemy[ORC].max_life = 45;
	enemy[ORC].dmg = 15;
	enemy[ORC].crit_dmg = 10;

	enemy[TROLL].name = "Troll";
	enemy[TROLL].max_life = 60;
	enemy[TROLL].dmg = 20;
	enemy[TROLL].crit_dmg = 15;

	enemy[BOSS].name = "Jarenaurer";
	enemy[BOSS].max_life = 200;
	enemy[BOSS].dmg = 30;
	enemy[BOSS].crit_dmg = 20;
	enemy[BOSS].sp_a_dmg = 50;
	enemy[BOSS].sp_crit_dmg = 30;
	enemy[BOSS].turns = 0;

	for (int i = 0; i < MAXy; i++) {
		for (int j = 0; j < MAXx; j++) {
			if (MAPA[i][j] == 'G') {
				enemy_status* aGoblin = new enemy_status;
				aGoblin->letter = 'G';
				aGoblin->enemyType = GOBLIN;
				aGoblin->name = enemy[GOBLIN].name;
				aGoblin->max_life = enemy[GOBLIN].max_life;
				aGoblin->cur_life = aGoblin->max_life;
				aGoblin->dmg = enemy[GOBLIN].dmg;
				aGoblin->crit_dmg = enemy[GOBLIN].crit_dmg;
				aGoblin->pos_x = j;
				aGoblin->pos_y = i;
				mapEnemies.push_back(aGoblin);
				MAPA[i][j] = '.';
			}
			else if (MAPA[i][j] == 'T') {
				enemy_status* aTroll = new enemy_status;
				aTroll->letter = 'T';
				aTroll->enemyType = TROLL;
				aTroll->name = enemy[TROLL].name;
				aTroll->max_life = enemy[TROLL].max_life;
				aTroll->cur_life = aTroll->max_life;
				aTroll->dmg = enemy[TROLL].dmg;
				aTroll->crit_dmg = enemy[TROLL].crit_dmg;
				aTroll->pos_x = j;
				aTroll->pos_y = i;
				mapEnemies.push_back(aTroll);
				MAPA[i][j] = '.';
			}
			else if (MAPA[i][j] == 'O') {
				enemy_status* anOrc = new enemy_status;
				anOrc->letter = 'O';
				anOrc->enemyType = ORC;
				anOrc->name = enemy[ORC].name;
				anOrc->max_life = enemy[ORC].max_life;
				anOrc->cur_life = anOrc->max_life;
				anOrc->dmg = enemy[ORC].dmg;
				anOrc->crit_dmg = enemy[ORC].crit_dmg;
				anOrc->pos_x = j;
				anOrc->pos_y = i;
				mapEnemies.push_back(anOrc);
				MAPA[i][j] = '.';
			}
			else if (MAPA[i][j] == 'J') {
				enemy_status* Boss = new enemy_status;
				Boss->enemyType = BOSS;
				Boss->name = enemy[BOSS].name;
				Boss->max_life = enemy[BOSS].max_life;
				Boss->cur_life = Boss->max_life;
				Boss->dmg = enemy[BOSS].dmg;
				Boss->crit_dmg = enemy[BOSS].crit_dmg;
				Boss->pos_x = j;
				Boss->pos_y = i;
				mapEnemies.push_back(Boss);
				MAPA[i][j] = '.';
			}
		}
	}
}
void initCurrentEnemy(enemy_status* enemy) {
	if (enemy == NULL) { return; }
	currentEnemy = *enemy;

	if (enemy->enemyType == GOBLIN) {
		cout << "A goblin is blocking your path!" << endl;
	}
	else if (enemy->enemyType == ORC) {
		cout << "An goblin is blocking your path!" << endl;
	}
	else if (enemy->enemyType == TROLL) {
		cout << "A troll is blocking your path!" << endl;
	}
}

//mapa
void show_map() {
	//Codigo inicialización mazmorra
	for (int i = 0; i < MAXy; i++) {
		for (int j = 0; j < MAXx; j++) {

			//cout << " ";
			if (player.pos_y == i && player.pos_x == j) {
				ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
				cout << '@';
			}
			else {


				bool enemyShown = false;
				int enemyNum = mapEnemies.size();
				for (int e = 0; e < enemyNum; e++) {
					if (mapEnemies[e]->pos_y == i && mapEnemies[e]->pos_x == j
						&& mapEnemies[e]->cur_life > 0) {
						char letter = mapEnemies[e]->name[0];
						switch (letter) {
						case 'G':
							ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
							break;
						case 'O':
							ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
							break;
						case 'T':
							ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);
							break;
						case 'J':
							ConsoleSetColor(ConsoleColor::DARKBLUE, ConsoleColor::BLACK);
							break;
						default: break;
						}

						cout << letter;
						enemyShown = true;
						break;
					}
				}
				switch (MAPA[i][j]) {

				case '#':
					ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::DARKGREY);
					break;
				case 'P':
					ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
					break;
				case 'B':
					ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::BLACK);
					break;
				case 'S':
					ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
					break;
				case 'M':
					ConsoleSetColor(ConsoleColor::BLUE, ConsoleColor::BLACK);
					break;
				case 'K':
					ConsoleSetColor(ConsoleColor::MAGENTA, ConsoleColor::BLACK);
					break;
				case 'L':
					ConsoleSetColor(ConsoleColor::MAGENTA, ConsoleColor::MAGENTA);
					break;

				case 'H':
					ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
					break;
				case '?':
					ConsoleSetColor(ConsoleColor::DARKCYAN, ConsoleColor::DARKCYAN);
					break;
				case 'A':
					ConsoleSetColor(ConsoleColor::DARKYELLOW, ConsoleColor::BLACK);
					break;
				case '.':
					ConsoleSetColor(ConsoleColor::BLACK, ConsoleColor::BLACK);
					break;
				case '$':
					ConsoleSetColor(ConsoleColor::BLACK, ConsoleColor::BLACK);
					break;
				default:
					break;
				}
				if (!enemyShown) {
					cout << MAPA[i][j];

				}

			}
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
		}
		cout << endl;
	}
}
bool collisionMap(int pos_x, int pos_y) {
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) {
		ret_val = true;
	}
	if (MAPA[pos_y][pos_x] == '#') {
		cout << "you can't go there" << endl;
		ret_val = true;

	}
	else if (MAPA[pos_y][pos_x] == '?') {
		cout << "12 souls are needed to unlock the seal" << endl;
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'H') {
		cout << "No name" << endl;
		ret_val = true;
	}
	else {
		ret_val = false;
	}
	return ret_val;
}
bool enemy_collisionMap(int pos_x, int pos_y) {
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) {
		ret_val = true;
	}
	if (MAPA[pos_y][pos_x] == '#') {
		ret_val = true;

	}
	else if (MAPA[pos_y][pos_x] == 'L') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'L') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == '$') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'B') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'P') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'K') {
		ret_val = true;
	}
	else if (MAPA[pos_y][pos_x] == 'M') {
		ret_val = true;
	}
	else {
		ret_val = false;
	}
	return ret_val;
}

//posicion boss
void boss_pos() {
	for (int y = 0; y < MAXy; y++) {
		for (int x = 0; x < MAXx; x++) {
			if (MAPA[y][x] == 'J') {
				mapa_pos_x = x;
				mapa_pos_y = y;

			}
		}
	}
	ConsoleXY(30, 13);
	cout << "You feel a strange aura at ";
	if (mapa_pos_x > player.pos_x && mapa_pos_y > player.pos_y) {
		cout << "SOUTH-WEST..." << endl;
	}
	else if (mapa_pos_x > player.pos_x && mapa_pos_y < player.pos_y) {
		cout << "NORTH-EAST..." << endl;
	}
	else if (mapa_pos_x < player.pos_x && mapa_pos_y > player.pos_y) {
		cout << "SOUTH-EAST..." << endl;
	}
	else if (mapa_pos_x < player.pos_x && mapa_pos_y < player.pos_y) {
		cout << "NORTH-WEST..." << endl;
	}
	else if (mapa_pos_x == player.pos_x && mapa_pos_y < player.pos_y) {
		cout << "NORTH..." << endl;
	}
	else if (mapa_pos_x == player.pos_x && mapa_pos_y > player.pos_y) {
		cout << "SOUTH..." << endl;
	}
	else if (mapa_pos_x > player.pos_x && mapa_pos_y == player.pos_y) {
		cout << "EAST..." << endl;
	}
	else if (mapa_pos_x < player.pos_x && mapa_pos_y == player.pos_y) {
		cout << "WEST..." << endl;
	}
}

//camino disponible
void mostrar_camino_disponible() {
	ConsoleXY(30, 14);
	cout << "You can go: ";
	if (MAPA[player.pos_y][player.pos_x - 1] != '#') {
		cout << "[WEST]";
	}
	if (MAPA[player.pos_y][player.pos_x + 1] != '#') {
		cout << "[EAST]";
	}
	if (MAPA[player.pos_y - 1][player.pos_x] != '#') {
		cout << "[NORTH]";
	}
	if (MAPA[player.pos_y + 1][player.pos_x] != '#') {
		cout << "[SOUTH]";
	}
	cout << endl;
}

//codigo puerta
void door() {
	string split_door;
	cout << "Do you want to use a key to open the door door? (yes/no) ";
	getline(cin, split_door);
	vector <string > split_input = splitString(split_door, ' ');
	if (split_door.size() > 0) {
		if (split_input[0] == "yes") {
			if (player.key_yes == true) {
				cout << player.name << " used a key to open the door" << endl;
				MAPA[player.pos_y][player.pos_x] = '.';
				locked_door = false;
				system("pause");
				system("cls");
			}
			else {
				cout << "You need a key to open the door...." << endl;
				player.pos_y = player.pos_y + 1;
				system("pause");
				system("cls");
			}
		}
		if (split_input[0] == "no") {
			cout << "You decided to not open the door" << endl;
			player.pos_y = player.pos_y + 1;
			system("pause");
			system("cls");
		}
		else if (split_input[0] != "yes" && split_input[0] != "no") {
			cout << "You are not going to open the door with that" << endl;
			player.pos_y = player.pos_y + 1;
			system("pause");
			system("cls");
		}
	}
	else {
		cout << "wrong option" << endl;
		player.pos_y = player.pos_y + 1;
	}
}

//presentacion inicial
void mensaje_inicial() {
	ConsoleXY(14, 6);
	cout << "--------------------------------- H E R O ' S  Q U E S T ---------------------------------" << endl;
	ConsoleXY(36, 7);
	cout << "The evil Jarenaurer has stolen the sacred gem.";
	ConsoleXY(15, 8);
	cout << "It is your duty to as the chosen hero to defeat him and retrieve de gem to restore the peace." << endl;
	ConsoleXY(25, 9);
	cout << "You have an enchanted charm that tells you where Jareneurer's lair is.\n" << endl;
	ConsoleXY(38, 10);
	cout << "Use the HELP command to show the options" << endl;
	ConsoleXY(14, 11);
	cout << "------------------------------------------------------------------------------------------" << endl;
	ConsoleXY(42, 13);
	cout << "May I ask your name , brave hero?" << endl;
	ConsoleXY(45, 14);
	cout << ">";
	ConsoleXY(47, 14);
	cin >> player.name;
	ConsoleXY(37, 16);
	cout << "Go forth, " << player.name << "! For the glory of your mother!\n" << endl;
	ConsoleXY(37, 19);
	system("pause");
	system("cls");
	show_map();
	ConsoleXY(26, 1);
	cout << "Here you have the dungeon map.";
	ConsoleXY(26, 2);
	cout << "You are here '@'" << endl;
	ConsoleXY(26, 9);
	cout << "Us de commands [go north][go south][go east][go west] to move inside the dungeon" << endl;
}
void mensaje_inicial_reset() {
	ConsoleXY(35, 6);
	cout << "------------ H E R O ' S  Q U E S T ------------" << endl;
	ConsoleXY(36, 7);
	cout << "The evil Jarenaurer has stolen the sacred gem.";
	ConsoleXY(15, 8);
	cout << "It is your duty to as the chosen hero to defeat him and retrieve de gem to restore the peace." << endl;
	ConsoleXY(25, 9);
	cout << "You have an enchanted charm that tells you where Jareneurer's lair is.\n" << endl;
	ConsoleXY(38, 10);
	cout << "Use the HELP command to show the options" << endl;
	ConsoleXY(35, 11);
	cout << "------------------------------------------------" << endl;
	ConsoleXY(42, 12);
	cout << "May I ask your name , brave hero?" << endl;
	ConsoleXY(45, 13);
	cout << ">";
	ConsoleXY(47, 13);
	cin >> player.name;
	ConsoleXY(37, 16);
	cout << "Go forth, " << player.name << "! For the glory of your mother!\n" << endl;
}


//Help commands
void enemies_info() {
	show_map();
	ConsoleXY(30, 3);
	cout << "-------------------------------ENEMIES INFORMATION---------------------------------" << endl;
	ConsoleXY(30, 4);
	ConsoleSetColor(ConsoleColor::GREEN, ConsoleColor::BLACK);
	cout << "G";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": Thats a goblin. Goblins have 30hp and deal 10 dmg each attack." << endl;
	ConsoleXY(30, 5);
	ConsoleSetColor(ConsoleColor::DARKGREEN, ConsoleColor::BLACK);
	cout << "O";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's an orc. Orcs have 45 hp and deal 15 dmg each attack." << endl;
	ConsoleXY(30, 6);
	ConsoleSetColor(ConsoleColor::YELLOW, ConsoleColor::BLACK);
	cout << "T";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": that's a troll. Trolls have 60 hp and deal 20 dmg each attack." << endl;
	ConsoleXY(30, 7);
	ConsoleSetColor(ConsoleColor::DARKBLUE, ConsoleColor::BLACK);
	cout << "J";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's the final boss, Jarenaurer. Jarenaurer is diferent from the other enemies." << endl;
	ConsoleXY(33, 8);
	cout << "It has 200 hp and deals 30 dmg each attack. It also has a special attack, be careful..." << endl;
}
void objects_info() {
	show_map();
	ConsoleXY(30, 3);
	cout << "------------------------OBJECTS DESCRIPTION--------------------------" << endl;
	ConsoleXY(30, 4);
	cout << "Here you have a guide of the objects that you can find inside the dungeon :" << endl;
	ConsoleXY(30, 5);
	ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
	cout << "P";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's a potion. Use it to restore 20 hp(one use item)" << endl;
	ConsoleXY(30, 6);
	ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::BLACK);
	cout << "B";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's a bomb.Use it to deal 100 dmg to one enemy(one use item)" << endl;
	ConsoleXY(30, 7);
	ConsoleSetColor(ConsoleColor::MAGENTA, ConsoleColor::BLACK);
	cout << "K";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's a key. Tou can use it to open locked doors'L'(one use item)" << endl;
	ConsoleXY(30, 8);
	ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
	cout << "S";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": Thats a sword. Use it to defeat you enemies" << endl;
	ConsoleXY(30, 9);
	//cout << "M: That's the dungeon map. You can use it to see the actual state of the dungenon." << endl;
	ConsoleSetColor(ConsoleColor::DARKYELLOW, ConsoleColor::BLACK);
	cout << "A";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": That's a super cool armor. Use it to reduce 25 all damage.\n" << endl;
	ConsoleXY(30, 10);
	cout << "Use 'pick' to pick objects that are on the floor." << endl;
}
void status_info() {
	ConsoleXY(30, 0);
	cout << "--------------PLAYER STATUS---------------" << endl;
	ConsoleXY(30, 1);
	cout << "name: " << player.name << endl;
	ConsoleXY(30, 2);
	cout << "MAP position: [" << player.pos_x << "][" << player.pos_y << "]" << endl;
	ConsoleXY(30, 3);
	cout << "------------------------------------------" << endl;
	ConsoleXY(30, 4);
	cout << "HP: " << player.cur_life << "/" << player.max_life << endl;
	ConsoleXY(30, 5);
	if (player.sword == true) {
		cout << "attack damage: " << player.sword_dmg << endl;
	}
	else {
		cout << "attack damage: " << player.base_dmg << endl;
	}
	ConsoleXY(30, 6);
	if (player.armor_def == true) {
		cout << "defense: " << player.def << endl;
	}
	else {
		cout << "defense: 0" << endl;
	}
	ConsoleXY(30, 7);
	cout << "enemies defeated: " << player.enemies_defeated << endl;
}
void inventory() {
	ConsoleXY(73, 0);
	cout << "---------------INVENTORY--------------" << endl;
	ConsoleXY(76, 1);
	ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
	cout << "potions";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": " << player.potions << endl;
	ConsoleXY(76, 2);
	ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
	cout << "sword";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": " << player.a_sword << endl;
	ConsoleXY(76, 3);
	ConsoleSetColor(ConsoleColor::DARKYELLOW, ConsoleColor::BLACK);
	cout << "armor";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": " << player.a_armor << endl;
	ConsoleXY(76, 4);
	ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::BLACK);
	cout << "bombs";
	ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	cout << ": " << player.bombs << endl;
	if (enemy_souls > 0)
	{
		ConsoleXY(76, 6);
		cout << "souls: " << enemy_souls << endl;
	}
	else
	{
		ConsoleXY(76, 6);
		cout << "??????: ?? " << endl;
	}
}

//objects
bool hasobject(int pos_x, int pos_y) {
	ret_val = false;
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) {
		ret_val = false;
	}
	else {
		if (MAPA[pos_y][pos_x] == 'B' || MAPA[pos_y][pos_x] == 'K' || MAPA[pos_y][pos_x] == 'S' || MAPA[pos_y][pos_x] == 'P' || MAPA[pos_y][pos_x] == 'M' || MAPA[pos_y][pos_x] == 'A' || MAPA[pos_y][pos_x] == '~') {
			ret_val = true;
		}
	}
	return ret_val;
}
bool hasdoor(int pos_x, int pos_y) {
	ret_val = false;
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) {
		ret_val = false;
	}
	else {
		if (MAPA[pos_y][pos_x] == 'L') {
			ret_val = true;
		}
	}
	return ret_val;
}
void surrounditems() {
	if (hasobject(player.pos_x, player.pos_y)) {
		ConsoleXY(30, 16);
		if (MAPA[player.pos_y][player.pos_x] == 'P') {
			cout << "There is a ";
			ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
			cout << "POTION";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'S') {
			cout << "There is a ";
			ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
			cout << "SWORD";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'B') {
			cout << "There is a ";
			ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::BLACK);
			cout << "BOMB";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'K') {
			cout << "There is a ";
			ConsoleSetColor(ConsoleColor::MAGENTA, ConsoleColor::BLACK);
			cout << "KEY";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'M') {
			cout << "There is a ";
			ConsoleSetColor(ConsoleColor::BLUE, ConsoleColor::BLACK);
			cout << "MAP";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'A') {
			cout << "There is an ";
			ConsoleSetColor(ConsoleColor::DARKYELLOW, ConsoleColor::BLACK);
			cout << "ARMOR";
			ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
			cout << " on the floor" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'A') {
			cout << "There is something on the floor. It's lika a soul..." << endl;
		}
	}
	ConsoleXY(30, 17);
	if (hasobject(player.pos_x + 1, player.pos_y)) {
		cout << "There is an object to the east" << endl;
	}
	if (hasobject(player.pos_x - 1, player.pos_y)) {
		cout << "There is an object to the west" << endl;
	}
	if (hasobject(player.pos_x, player.pos_y - 1)) {
		cout << "There is an object to the north" << endl;
	}
	if (hasobject(player.pos_x, player.pos_y + 1)) {
		cout << "There is an object to the south" << endl;
	}
	ConsoleXY(30, 18);
	if (hasdoor(player.pos_x, player.pos_y - 1)) {
		cout << "There is a locked door in front of you" << endl;
	}
}


//enemies
bool hasenemy(int pos_x, int pos_y) {
	ret_val = false;
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) {
		ret_val = false;
	}
	else {
		if (MAPA[pos_y][pos_x] == 'G' || MAPA[pos_y][pos_x] == 'O' || MAPA[pos_y][pos_x] == 'T' || MAPA[pos_y][pos_x] == 'J') {
			ret_val = true;
		}
	}
	return ret_val;
}
void surroundenemies() {
	if (hasenemy(player.pos_x, player.pos_y)) {
		if (MAPA[player.pos_y][player.pos_x] == 'G') {
			cout << "A goblin is blocking your way" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'O') {
			cout << "An orc is blocking your way" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'T') {
			cout << "A troll is blocking your way" << endl;
		}
		else if (MAPA[player.pos_y][player.pos_x] == 'J') {
			cout << "Finaly you found Jarenaurer.\nIn order to retrieve the gem, you have to defeat him\n\nBe aware of his special attack.... " << endl;
		}
		system("pause");

	}
	if (hasenemy(player.pos_x + 1, player.pos_y)) {
		ConsoleXY(30, 15);
		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		cout << "There is an enemy to the east" << endl;
		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	}
	if (hasenemy(player.pos_x - 1, player.pos_y)) {
		ConsoleXY(30, 15);
		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		cout << "There is an enemy to the west" << endl;
		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	}
	if (hasenemy(player.pos_x, player.pos_y - 1)) {
		ConsoleXY(30, 15);
		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		cout << "There is an enemy to the north" << endl;
		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	}
	if (hasenemy(player.pos_x, player.pos_y + 1)) {
		ConsoleXY(30, 15);
		ConsoleSetColor(ConsoleColor::RED, ConsoleColor::BLACK);
		cout << "There is an enemy to the south" << endl;
		ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
	}

}
enemy_status* enemyOnTile(int pos_x, int pos_y) {
	if (pos_x < 0 || pos_x >= MAXx || pos_y < 0 || pos_y >= MAXy) { return NULL; }

	int enemyNum = mapEnemies.size();
	for (int e = 0; e < enemyNum; e++) {
		if (mapEnemies[e]->cur_life <= 0) { continue; }
		if (mapEnemies[e]->pos_y == pos_y && mapEnemies[e]->pos_x == pos_x) {
			return mapEnemies[e];
		}
	}

	return NULL;
};


//reset
void reset() {
	//mapa
	for (size_t i = 0; i < MAXy; i++) {
		for (size_t j = 0; j < MAXx; j++) {
			MAPA[i][j] = MAPA2[i][j];
		}
	}
	//variables player
	player.cur_life = player.max_life;
	player.sword = false;
	player.key_yes = false;
	player.bombs = 0;
	player.potions = 0;
	player.armor_def = false;
	player.enemies_defeated = 0;
	player.pos_x = 2;
	player.pos_y = 2;

	//variables enemies
	enemy_souls = 0;
	currentEnemy.cur_life = currentEnemy.max_life;
	currentEnemy.turns = 0;

	//variables booleanas
	locked_door = true;
	ret_val = false;
	game_over = false;
	mapa_obtenido = false;
	combat = false;
	turn_finish = false;
	restart = true;
	system("cls");
	mensaje_inicial_reset();
}

void moveEnemies() {
	int enemyNum = mapEnemies.size();
	for (int e = 0; e < enemyNum; e++) {
		if (mapEnemies[e]->cur_life <= 0) { 
		}
		int randDir = rand() % 4;
		switch (randDir) {
		case 0: //North
			if (!enemy_collisionMap(mapEnemies[e]->pos_x, mapEnemies[e]->pos_y - 1)) {
				mapEnemies[e]->pos_y--;
			}
			break;
		case 1: //South
			if (!enemy_collisionMap(mapEnemies[e]->pos_x, mapEnemies[e]->pos_y + 1)) {
				mapEnemies[e]->pos_y++;
			}
			break;
		case 2: //East
			if (!enemy_collisionMap(mapEnemies[e]->pos_x - 1, mapEnemies[e]->pos_y)) {
				mapEnemies[e]->pos_x--;
			}
			break;
		case 3: //West
			if (!enemy_collisionMap(mapEnemies[e]->pos_x + 1, mapEnemies[e]->pos_y)) {
				mapEnemies[e]->pos_x++;
			}
			break;
		default:
			break;
		}
	}
}

//combates
void Combat(string _enemyName, int life, int max_life, int E_dmg, bool turn_finish, int e_crit) {
	//armor
	if (player.armor_def == true) {
		player.a_armor = "yes";
	}
	else {
		player.a_armor = "no";
	}
	//sword
	if (player.sword == true) {
		player.a_sword = "yes";
	}
	else {
		player.a_sword = "no";
	}
	while (player.cur_life > 0 && life > 0 && combat == true) {
		cout << "potions: " << player.potions << endl;
		cout << "bombs: " << player.bombs << endl;
		cout << "armor: " << player.a_armor << endl;
		cout << "------------------------------------------------------" << endl;
		cout << player.name << " HP: " << player.cur_life << "/" << player.max_life << endl;
		cout << _enemyName << " HP: " << life << " / " << max_life << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "Choose your move " << player.name << " attack, potion, bomb, run" << endl;
		getline(cin, input);
		vector<string > split_combat_move = splitString(input, ' ');
		//player turn
		if (split_combat_move.size() > 0) {
			if (split_combat_move.size() == 1) {
				if (split_combat_move[0] == "attack") {
					e_dodge_chance = (rand() % 12) + 1;
					player.crit_chance = (rand() % 8) + 1;
					if (e_dodge_chance != 9) {
						//sword yes
						if (player.sword == true) {
							if (player.crit_chance == 6) {
								life = life - (player.sword_dmg + player.sword_crit);
								cout << "A critical hit! The " << _enemyName << " lost " << player.sword_dmg + player.sword_crit << "HP" << endl;
							}
							else {
								life = life - player.sword_dmg;
								cout << "The " << _enemyName << " lost " << player.sword_dmg << "HP" << endl;
							}
						}
						//sword no
						else {
							if (player.crit_chance == 6) {
								life = life - (player.base_dmg + player.base_crit);
								cout << "A critical hit! The " << _enemyName << " lost " << player.base_dmg + player.base_crit << "HP" << endl;
							}
							else {
								life = life - player.base_dmg;
								cout << "The " << _enemyName << " lost " << player.base_dmg << "HP" << endl;
							}
						}
						turn_finish = true;
					}
					else {
						cout << "Bruh, the " << _enemyName << " dodged you attack" << endl;
						turn_finish = true;
					}

				}
				else if (split_combat_move[0] == "potion") {
					if (player.potions > 0) {
						if ((player.max_life - player.cur_life < 20) && (player.max_life - player.cur_life) != 0) {
							player.cur_life = player.max_life;
							cout << player.name << " used a potion and restored" << player.max_life - player.cur_life << " HP" << endl;
							player.potions--;
							turn_finish = true;
						}
						else if ((player.max_life - player.cur_life) >= 20) {
							player.cur_life = player.cur_life + 20;
							cout << player.name << " used a potion and restored 20 HP" << endl;
							player.potions--;
							turn_finish = true;
						}
						else if (player.cur_life == player.max_life) {
							cout << "Your life is full" << endl;
							turn_finish = false;
						}
					}
					else {
						cout << "You don't have potions" << endl;
						turn_finish = false;
					}
				}
				else if (split_combat_move[0] == "bomb") {
					if (player.bombs > 0) {
						life = life - 100;
						player.bombs--;
						cout << player.name << " used a bomb dealing 100 dmg" << endl;
						turn_finish = true;
					}
					else {
						cout << "You don't have bombs lmao" << endl;
						turn_finish = false;
					}
				}
				else if (split_combat_move[0] == "run") {
					player.run_chance = (rand() % 5) + 1;
					if (player.run_chance == 3) {
						system("cls");
						player.run_yes = true;
						combat = false;
						turn_finish = false;
						cout << "You escaped from the battle..." << endl;
						player.pos_x = player.prev_pos_x;
						player.pos_y = player.prev_pos_y;
					}
					else {
						cout << "You couldn't escape..." << endl;
						turn_finish = true;
					}
				}
				else {
					cout << "Wrong option" << endl;
					turn_finish = false;
				}
			}
			else {
				cout << "Wrong option" << endl;
				turn_finish = false;
			}
		}

		//enemy turn
		if (life > 0 && turn_finish == true) {
			player.p_dodge_chance = (rand() % 12) + 1;
			if (player.p_dodge_chance != 9) {
				crit_chance = (rand() % 8) + 1;
				if (crit_chance == 6) {
					player.cur_life = player.cur_life - (E_dmg + e_crit);
					cout << "A critical hit! " << player.name << " lost " << E_dmg + e_crit << "HP" << endl;
				}
				else {
					player.cur_life = player.cur_life - E_dmg;
					cout << player.name << " lost " << E_dmg << "HP" << endl;
				}
			}
			else {
				cout << "You dodged the " << _enemyName << "'s attack with your incredible skills" << endl;
			}

		}
		system("pause");
		system("cls");
	}
	if (player.cur_life <= 0) {
		cout << "You lost all your HP" << endl << endl;
		cout << "Do you want to try again? This will reset all your progress.\n> ";
		getline(cin, input);
		vector< string > split_input = splitString(input, ' ');
		if (split_input.size() == 1) {
			if (split_input[0] == "yes") {
				reset();
			}
			else if (split_input[0] == "no") {
				system("cls");
				cout << "GAME OVER" << endl;
				system("pause");
				game_over = true;
			}
		}
	}
	else if (life <= 0) {
		cout << "You have defeated the " << _enemyName << ".\nIt dropped something right in front of you..." << endl;
		MAPA[player.pos_y][player.pos_x] = '~';
		player.enemies_defeated++;
		player.pos_x = player.prev_pos_x;
		player.pos_y = player.prev_pos_y;
		combat = false;
	}

}

void mapa_final() {
	for (size_t i = 0; i < MAXy; i++) {
		for (size_t j = 0; j < MAXx; j++) {
			MAPA[i][j] = MAPA3[i][j];
		}
	}
	player.pos_x = 1;
	player.pos_y = 1;
	mapa_obtenido = false;
}
