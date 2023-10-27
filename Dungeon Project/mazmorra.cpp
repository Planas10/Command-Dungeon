#include "func_manager.h"

using namespace std;

int main() {
	initPlayer();
	initEnemies();
	mensaje_inicial();
	ConsoleXY(26,13);
	system("pause");
	system("cls");
	srand(time(NULL));

	

	while (!game_over && !exit_yes) {
		//codigo combates
		if (combat) {
			//goblin combat
			if (currentEnemy.enemyType == GOBLIN) {
				Combat("goblin", currentEnemy.cur_life, currentEnemy.max_life, currentEnemy.dmg, turn_finish, currentEnemy.crit_dmg);
			}
			//orc combat
			else if (currentEnemy.enemyType == ORC) {
				Combat("orc", currentEnemy.cur_life, currentEnemy.max_life, currentEnemy.dmg, turn_finish, currentEnemy.crit_dmg);
			}
			//troll combat
			else if (currentEnemy.enemyType == TROLL) {
				Combat("troll", currentEnemy.cur_life, currentEnemy.max_life, currentEnemy.dmg, turn_finish, currentEnemy.crit_dmg);

			}
			//boss combat
			else if (currentEnemy.enemyType == BOSS) {
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
				while (player.cur_life > 0 && currentEnemy.cur_life > 0) {
					cout << "potions: " << player.potions << endl;
					cout << "bombs: " << player.bombs << endl;
					cout << "armor: " << player.a_armor << endl;
					cout << "------------------------------------------------------" << endl;
					cout << player.name << " HP: " << player.cur_life << "/" << player.max_life << endl;
					cout << "Janeraurer hp: " << currentEnemy.cur_life << "/" << currentEnemy.max_life << endl;
					cout << "------------------------------------------------------" << endl;
					cout << "Choose your move " << player.name << " attack, potion, bomb, run" << endl;
					getline(cin, input);
					vector< string > split_combat_move = splitString(input, ' ');
					//player turn
					if (split_combat_move.size() > 0) {
						if (split_combat_move.size() == 1) {
							if (split_combat_move[0] == "attack") {
								e_dodge_chance = (rand() % 12) + 1;
								player.crit_chance = (rand() % 8) + 1;
								if (e_dodge_chance != 9) {
									if (player.sword == true) {
										if (player.crit_chance == 6) {
											currentEnemy.cur_life = currentEnemy.cur_life - (player.sword_dmg + player.sword_crit);
											cout << "A critical hit! Jarenaurer lost " << player.sword_dmg + player.sword_crit << "HP" << endl;
										}
										else {
											currentEnemy.cur_life = currentEnemy.cur_life - player.sword_dmg;
											cout << "Jarenaurer lost " << player.sword_dmg << "HP" << endl;
										}
									}
									//sword no
									else {
										if (player.crit_chance == 6) {
											currentEnemy.cur_life = currentEnemy.cur_life - (player.base_dmg + player.base_crit);
											cout << "A critical hit! Jarenaurer lost " << player.base_dmg + player.base_crit << "HP" << endl;
										}
										else {
											currentEnemy.cur_life = currentEnemy.cur_life - player.base_dmg;
											cout << "Jarenaurer lost " << player.base_dmg << "HP" << endl;
										}
									}
									turn_finish = true;
								}
								else {
									cout << "Bruh, Jarenaurer dodged your attack" << endl;
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
									currentEnemy.cur_life = currentEnemy.cur_life - 100;
									player.bombs--;
									cout << player.name << " used a bomb dealing 100 dmg" << endl;
									turn_finish = true;
								}
								else {
									cout << "You don't have bombs" << endl;
									turn_finish = false;
								}
							}
							else if (split_combat_move[0] == "run") {
								cout << "You can't escape from this battle!" << endl;
								turn_finish = false;
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
					if (currentEnemy.cur_life > 0 && turn_finish == true) {
						player.p_dodge_chance = (rand() % 12) + 1;
						crit_chance = (rand() % 8) + 1;
						if (player.p_dodge_chance != 9) {
							//armour no
							if (player.armor_def == false) {
								if (currentEnemy.turns < 5) {
									if (crit_chance == 6) {
										player.cur_life = player.cur_life - (currentEnemy.dmg + currentEnemy.crit_dmg);
										cout << "A critical hit! " << player.name << " lost " << currentEnemy.dmg + currentEnemy.crit_dmg << "HP" << endl;
									}
									else {
										player.cur_life = player.cur_life - currentEnemy.dmg;
										cout << player.name << " lost " << currentEnemy.dmg << "HP" << endl;
									}
									cout << "special attack in: " << 5 - currentEnemy.turns << " Be carefull..." << endl;
									currentEnemy.turns++;
								}
								//special attack
								else if (currentEnemy.turns == 5) {
									currentEnemy.turns = 0;
									if (crit_chance == 6) {
										player.cur_life = player.cur_life - (currentEnemy.sp_a_dmg + currentEnemy.sp_crit_dmg);
										cout << "A critical hit! " << player.name << " lost " << currentEnemy.sp_a_dmg + currentEnemy.sp_crit_dmg << "HP" << endl;
									}
									else {
										player.cur_life = player.cur_life - currentEnemy.sp_a_dmg;
										cout << player.name << " lost " << currentEnemy.sp_a_dmg << "HP" << endl;
									}
									currentEnemy.turns++;
								}
							}
							//armour yes
							else {
								if (currentEnemy.turns < 5) {
									if (crit_chance == 6) {
										player.cur_life = player.cur_life - (currentEnemy.dmg + currentEnemy.crit_dmg - player.def);
										cout << "A critical hit! " << player.name << " lost " << currentEnemy.dmg + currentEnemy.crit_dmg - player.def << "HP" << endl;
									}
									else {
										player.cur_life = player.cur_life - (currentEnemy.dmg - player.def);
										cout << player.name << " lost " << currentEnemy.dmg - player.def << "HP" << endl;
									}
									cout << "special attack in: " << 5 - currentEnemy.turns << " Be carefull..." << endl;
									currentEnemy.turns++;
								}
								//special attack
								else if (currentEnemy.turns == 5) {
									currentEnemy.turns = 0;
									if (crit_chance == 6) {
										player.cur_life = player.cur_life - (currentEnemy.sp_a_dmg + currentEnemy.sp_crit_dmg - player.def);
										cout << "A critical hit! " << player.name << " lost " << currentEnemy.sp_a_dmg + currentEnemy.sp_crit_dmg - player.def << "HP" << endl;
									}
									else {
										player.cur_life = player.cur_life - (currentEnemy.sp_a_dmg - player.def);
										cout << player.name << " lost " << currentEnemy.sp_a_dmg - player.def << "HP" << endl;
									}
									currentEnemy.turns++;
								}
							}
						}
						else {
							cout << "You dodged Jarenaurer's attack with your incredible skills" << endl;

						}

					}

					system("pause");
					system("cls");
				}
				if (player.cur_life <= 0) {
					cout << "You lost all your HP" << endl;
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
				else if (currentEnemy.cur_life <= 0) {
					system("cls");
					cout << "CONGRATULATIONS! YOU HAVE DEFEATED JARENAURER!" << endl;
					MAPA[player.pos_y][player.pos_x] = '.';
					combat = false;
					game_over = true;
					mapa_final();
				}
			}
		}
		//codigo fuera de combate
		else {

			if (MAPA[player.pos_x][player.pos_y] == 'L') {
				door();
			}
			if (enemy_souls == 12) {
				system("cls");
				for (int i = 0; i < MAXy; i++) {
					for (int j = 0; j < MAXx; j++) {
						if (MAPA[i][j] == '?') {
							MAPA[i][j] = 'A';
						}
					}
				}
				cout << "Something has appeared in the dungeon..." << endl << endl;
				enemy_souls = -1;
			}
			else {
				//informacion constante
				show_map(); //mostrar el mapa siempre
				status_info();
				inventory();
				ConsoleXY(30, 11);
				cout << "[Use the option 'help' for more information]" << endl << endl;
				ConsoleXY(28, 9);
				cout << "-------------------------------------------------------------------------------";
				boss_pos();
				mostrar_camino_disponible();
				surrounditems();
				surroundenemies();
				ConsoleXY(30, 19);
				cout << "[" << player.name << "] at [" << player.pos_x << "][" << player.pos_y << "]" << endl;
				ConsoleXY(30, 20);
				cout << "What are you going to do?";
				ConsoleXY(30, 21);
				cout << ">";
				getline(cin, input);
				cout << endl;


				//Tratar el input
				vector <string > split_input = splitString(input, ' ');

				//Input help
				if (split_input.size() > 0) {
					if (split_input.size() == 1) {
						if (input == "help") {
							cout << "What do you want to know?: enemies, objects, status, inventory, map, exit, restart" << endl;
						}
						else if (input == "enemies") {
							system("cls");
							enemies_info();
						}
						//Objects guide
						else if (input == "objects") {
							system("cls");
							objects_info();
						}
						//Status help
						/*else if (input == "status") {
							system("cls");
							status_info();
						}*/
						//inventory
						/*else if (input == "inventory") {
							system("cls");
							inventory();
						}*/
						//exit
						else if (input == "exit") {
							ConsoleXY(30, 22);
							cout << "Are you sure? ";
							ConsoleXY(44, 22);
							getline(cin, input);
							vector <string > split_input = splitString(input, ' ');
							if (input == "yes") {
								exit_yes = true;
								break;
							}
							else if (input == "no") {

							}
							else {
							}
						}
						//restart
						else if (input == "restart") {
							ConsoleXY(30, 22);
							cout << "This will restart your progress. Continue? ";
							ConsoleXY(73, 22);
							getline(cin, input);
							vector <string > split_input = splitString(input, ' ');
							if (input == "yes") {
								reset();
							}
							else if (input == "no") {

							}
							else {
							}
						}
						//Display map
						/*else if (input == "map") {
							if (mapa_obtenido == true) {
								system("cls");
								show_map();
								cout << endl;
							}
							else {
								ConsoleXY(30, 22);
								cout << "You searched in your bag for a map....... wait you don't have a map." << endl;
							}
						}*/
						else if (input == "attack") {
							ConsoleXY(30, 22);
							cout << "The air dodged your attack" << endl;
						}
						else {
							ConsoleXY(30, 22);
							cout << "do what?" << endl;
						}


					}
					//Input pick objects
					else if (split_input.size() == 2) {
						if (split_input[0] == "pick") {
							//potion
							if (split_input[1] == "potion") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'P') {
									MAPA[player.pos_y][player.pos_x] = '.';
									player.potions++;
									cout << player.name << " picked up a ";
									ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
									cout << "potion" << endl;
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
								}
								else {
									cout << " no potion" << endl;
								}
							}
							//sword
							else if (split_input[1] == "sword") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'S') {
									MAPA[player.pos_y][player.pos_x] = '.';
									player.sword = true;
									player.a_sword = "yes";
									cout << player.name << " picked up a ";
									ConsoleSetColor(ConsoleColor::CYAN, ConsoleColor::BLACK);
									cout << "sword" << endl;
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
								}
								else {
									cout << " no sword" << endl;
								}
							}
							//bomb
							else if (split_input[1] == "bomb") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'B') {
									MAPA[player.pos_y][player.pos_x] = '.';
									player.bombs++;
									cout << player.name << " picked up a ";
									ConsoleSetColor(ConsoleColor::DARKGREY, ConsoleColor::BLACK);
									cout << "bomb" << endl;
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
								}
								else {
									cout << " no bomb" << endl;
								}
							}
							//key
							else if (split_input[1] == "key") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'K') {
									MAPA[player.pos_y][player.pos_x] = '.';
									cout << player.name << " picked up the ";
									ConsoleSetColor(ConsoleColor::MAGENTA, ConsoleColor::BLACK);
									cout << "dungeon key" << endl;
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
									player.key_yes = true;
								}
								else {
									cout << " no key" << endl;
								}
							}
							//map
							/*else if (split_input[1] == "map") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'M') {
									MAPA[player.pos_y][player.pos_x] = '.';
									mapa_obtenido = true;
									cout << player.name << " picked up the ";
									ConsoleSetColor(ConsoleColor::BLUE, ConsoleColor::BLACK);
									cout << "dungeon map." << endl;
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
								}
								else {
									cout << " no map" << endl;
								}
							}*/
							else if (split_input[1] == "armor") {
								ConsoleXY(30, 22);
								if (MAPA[player.pos_y][player.pos_x] == 'A') {
									MAPA[player.pos_y][player.pos_x] = '.';
									player.armor_def = true;
									player.a_armor = "yes";
									cout << player.name << " picked up a ";
									ConsoleSetColor(ConsoleColor::DARKYELLOW, ConsoleColor::BLACK);
									cout << "super cool armor";
									ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
									cout << ".\nYou feel stronger\nYou gain + 15 def" << endl;
								}
								else {
									cout << " no armor" << endl;
								}
							}
							//soul
							else if (split_input[1] == "soul")
							{
								ConsoleXY(30, 22);
								cout << "You picked up a soul. So strange...";
								MAPA[player.pos_y][player.pos_x] = '.';
								enemy_souls++;
							}
							else {
								ConsoleXY(30, 22);
								cout << "do what?" << endl;
							}
						}
						else if (split_input[0] == "use") {
							if (split_input[1] == "potion") {
								ConsoleXY(30, 22);
								if (player.potions > 0) {
									if ((player.max_life - player.cur_life) < 20 && (player.max_life - player.cur_life) != 0) {
										cout << player.name << " used a ";
										ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
										cout << "potion";
										ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
										cout << " and restored " << player.max_life - player.cur_life << " HP" << endl;
										player.cur_life = player.max_life;
										player.potions--;
									}
									else if ((player.max_life - player.cur_life) >= 20) {
										player.cur_life = player.cur_life + 20;
										cout << player.name << " used a ";
										ConsoleSetColor(ConsoleColor::DARKRED, ConsoleColor::BLACK);
										cout << "potion";
										ConsoleSetColor(ConsoleColor::WHITE, ConsoleColor::BLACK);
										cout << " and restored 20 HP" << endl;
										player.potions--;
									}
									else if (player.cur_life == player.max_life) {
										cout << "Your life is full" << endl;
									}

								}
								else {
									cout << " you have no potions" << endl;
								}


							}
							else {
								ConsoleXY(30, 22);
								cout << "do what?" << endl;
							}
						}
						//Input movimiento
						else if (split_input[0] == "go") {
							ConsoleXY(30, 22);
							player.prev_pos_x = player.pos_x;
							player.prev_pos_y = player.pos_y;
							int prev_x = player.pos_x;
							int prev_y = player.pos_y;
							if (split_input[1] == "north") {
								if (!collisionMap(player.pos_x, player.pos_y - 1)) {
									player.pos_y--;
									cout << player.name << " went north" << endl;
								}
							}
							else if (split_input[1] == "south") {
								if (!collisionMap(player.pos_x, player.pos_y + 1)) {
									player.pos_y++;
									cout << player.name << " went south" << endl;
								}
							}
							else if (split_input[1] == "east") {
								if (!collisionMap(player.pos_x + 1, player.pos_y)) {
									player.pos_x++;
									cout << player.name << " went east" << endl;
								}
							}
							else if (split_input[1] == "west") {
								if (!collisionMap(player.pos_x - 1, player.pos_y)) {
									player.pos_x--;
									cout << player.name << " went west" << endl;
								}
							}
							else {
								ConsoleXY(30, 22);
									cout << "Go where?" << endl;
							}
							/*if (prev_x != player.pos_x || prev_y != player.pos_y) {
								if (MAPA[player.pos_y][player.pos_x] == 'G' || MAPA[player.pos_y][player.pos_x] == 'O' || MAPA[player.pos_y][player.pos_x] == 'T' || MAPA[player.pos_y][player.pos_x] == 'J') {
									combat = true;
								}
							}*/
							//Si me he movido
							if (player.pos_x != prev_x || player.pos_y != prev_y) {
								enemy_status* enemy = enemyOnTile(player.pos_x, player.pos_y);
								if (enemy != NULL) {
									combat = true;
									//Inicializo la info del combate
									initCurrentEnemy(enemy);
								}
							}
							moveEnemies();
						}
						else {
							ConsoleXY(30, 22);
							cout << "do what?" << endl;
						}

					}
					else if (split_input.size() > 2 || split_input.size() == 0) {
						ConsoleXY(30, 22);
						cout << "What are you trying to do" << endl;
					}
				}
			}

		}
		ConsoleXY(30, 23);
		system("pause");
		system("cls"); //Limpiar consola
	}
	while (!diamond && !exit_yes)
	{
		show_map();
		cout << "Use help for info" << endl << endl;
		mostrar_camino_disponible();
		cout << endl;
		cout << "What will you do?\n>";
		getline(cin, input);
		vector <string > split_input = splitString(input, ' ');
		if (split_input.size() > 0)
		{
			if (split_input[0] == "help") {
				cout << "You are inside Jarenaurer's vault. Here you can't use the map or any potions or bombs.\nThere are also no enemies.\nYou can use these options: exit, restart.\nUse go [north][south][east][west] to move and find the stolen gem. " << endl << endl;
			}
			else if (split_input[0] == "exit") {
				cout << "Are you sure? ";
				getline(cin, input);
				vector <string > split_input = splitString(input, ' ');
				if (split_input[0] == "yes") {
					break;
				}
				else if (split_input[0] == "no") {

				}
				else {
				}
			}
			else if (split_input[0] == "restart") {
				cout << "This will restart your progress. Continue? ";
				getline(cin, input);
				vector <string > split_input = splitString(input, ' ');
				if (split_input[0] == "yes") {
					reset();
				}
				else if (split_input[0] == "no") {

				}
				else {
				}
			}
			else if (split_input[0] == "go") {
				player.prev_pos_x = player.pos_x;
				player.prev_pos_y = player.pos_y;
				int prev_x = player.pos_x;
				int prev_y = player.pos_y;
				if (split_input[1] == "north") {
					if (!collisionMap(player.pos_x, player.pos_y - 1)) {
						player.pos_y--;
						cout << player.name << " went north" << endl;
					}
				}
				else if (split_input[1] == "south") {
					if (!collisionMap(player.pos_x, player.pos_y + 1)) {
						player.pos_y++;
						cout << player.name << " went south" << endl;
					}
				}
				else if (split_input[1] == "east") {
					if (!collisionMap(player.pos_x + 1, player.pos_y)) {
						player.pos_x++;
						cout << player.name << " went east" << endl;
					}
				}
				else if (split_input[1] == "west") {
					if (!collisionMap(player.pos_x - 1, player.pos_y)) {
						player.pos_x--;
						cout << player.name << " went west" << endl;
					}
				}
				else {
					cout << "Go where?" << endl;
				}
			}
		}
		else
		{
			cout << "do what?" << endl;
		}
		system("pause");
		system("cls"); //Limpiar consola
	}
	system("pause");
	return 0;
}