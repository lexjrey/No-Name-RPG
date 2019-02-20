//Christian Vaughn & Tyler Reynolds
#include <iostream>
#include "splash.h"
#include "map.h"
#include "actors.h"
#include "battle.h"
#include <algorithm>
#include <list>
#include <queue>
#include <cmath>
#include <ctime>
#include <vector>

using namespace std;

//function that prints the hud showing all the information the player needs.
void hud(Actors player1, list<string> &weapons, Weapon &playa) {
	//outputs hp, gold, and if in battle the monsters health
	if (on_monster) {
		cout << "Gold: " << player1.get_gold() << "     	       Monster HP: " << player1.get_monsterhealth() << endl;
		cout << "HP: " << player1.get_health() << "                Minion HP: " << player1.get_minionhealth() << endl;
	} else {
		cout << "Gold: " << player1.get_gold() << endl;
		cout << "HP: " << player1.get_health() << endl;
	}

	//uses linked list to itterate and output the current weapon that is equiped and then show the other weapons below it
	int count = 1;
	for (list<string>::iterator iter = weapons.begin(); iter != weapons.end(); iter++) {
		if (count == 1) {
			cout << "CurrWpn: " << *iter << endl;
			playa.weapon = *iter;
			if (*iter == "Sword")
				playa.damage = 20;
			if (*iter == "Axe")
				playa.damage = 25;
			if (*iter == "Bow")
				playa.damage = 15;
		} else
			cout << count << ". " << *iter << endl;
		count++;
	}
}

int main() {
	srand(time(NULL));//seeds random generator 
	//variables used throught the game
	Move player;
	Actors player1;
	Move temp;
	Weapon playa;
	char direction = ' ';
	player.column = 17;
	player.row = 10;
	char attack = ' ';
	int dmgoutmon = 0;
	int dmgoutmin = 0;
	bool minion = false;
	list <string> weapons;
  weapons  = {"Sword", "Axe", "Bow"};

	//prints splash screen and has user enter anything to start game
	print_splash();
	while (true) {
		char endsplash = ' ';
		cin >> endsplash;
		if (cin) {
			system("clear");
			break;
		}
	}

	temp = player;
	print_map(player);
	hud(player1, weapons, playa);
	
	//while loop that keeps game running until gameover or win happens
	while (true) {
		//when 100 coins gained end game
		if (player1.get_gold() == 100) {
			cout << yellow  << "You won! Congratulations!" << reset << endl;
			exit(EXIT_FAILURE);
		}

		//input for the controls and checks for trying to move out of bounds
		cout << ">";
		cin >> direction;
		if (direction == 'w' && player.row > 1) {
			temp.row--;
		} else if (direction == 's' && player.row < map.size() - 2) {
			temp.row++;
		} else if (direction == 'a' && player.column > 1) {
			temp.column--;
		} else if (direction == 'd' && player.column < map.at(0).size() - 2) {
			temp.column++;
		//Changes weapon
		} else if (direction == 'c') {
			weapons.push_back(playa.weapon);
			weapons.pop_front();
		}

		//checks map to see if player can move to that space
		if (check_map(temp)) {
			player = temp;
			system("clear");
			
			//starts the battle part of game if player is on a monsters space
			if (on_monster) {
				print_battle();
				hud(player1, weapons, playa);
				
				//min heap to make low powered attacks go before higher powered
				priority_queue<int, vector<int>, greater<int> > damage;

				cout << "\nYou have encountered a monster you must fight!" << endl;
				cout << "The Monster has deployed his minions!" << endl;
				
				
				while (true) {
					//generates monsters attack damage for the turn
					int monsterdamage = (rand() % 10) + 25;
					int miniondamage = (rand() % 5) + 5;
					
					//enter a command and either switch weapons or  attack
					cout << ">";
					cin >> attack;

					if (attack == 'c') {
						weapons.push_back(playa.weapon);
						weapons.pop_front();

						system("clear");
						print_battle();
						hud(player1, weapons, playa);

					} else if (attack == 'z') {
						//push all attacks of alive actors onto the heap
						damage.push(playa.damage);
						damage.push(monsterdamage);
						if (player1.get_minionhealth() > 0) {
							damage.push(miniondamage);
						}
						//no damage done if player and monster did same attack damage
						if (monsterdamage == playa.damage && damage.size() == 2) {
							cout << "You and the Monster did the same attack and blocked each other, so no damage was done!" << endl;
							damage.pop();
							damage.pop();
						}

						//loop until heap is empty
						while (!damage.empty()) {
							//damage the monster if the player's atack is on top of heap
							if (damage.top() == playa.damage) {
								if (player1.get_minionhealth() > 0) {
									player1.set_minionhealth(player1.get_minionhealth() - damage.top());
									if (player1.get_minionhealth() < 0) {
										player1.set_minionhealth(0);
									}
								} 
								else {
									player1.set_monsterhealth(player1.get_monsterhealth() - damage.top());
								}
								damage.pop();
							//damages player if top of heap was monster or minions attack
							} else if (damage.top() == monsterdamage) {
								player1.set_health(player1.get_health() - damage.top());
								dmgoutmon = damage.top();
								damage.pop();
							}
							else if (damage.top() == miniondamage) {
								player1.set_health(player1.get_health() - damage.top());
								dmgoutmin = damage.top();
								minion = true;
								damage.pop();
							}

							//gives player gold and quits battle loop if monsters are dead
							if (player1.get_monsterhealth() <= 0) {
								player1.set_gold(player1.get_gold() + LOOTREWARD);
								break;
							} 
							//if player died show game over screen and quit game 
							else if (player1.get_health() <= 0) {
								system("clear");
								system("cowsay -f dragon GAMEOVER! I killed you!");
								//cout<<"GAME OVER! You lost!"<<endl;
								exit(EXIT_FAILURE);
							}
						}
						//if the player won reset monster health and changes to overworld map
						if (player1.get_monsterhealth() <= 0) {
							player1.set_monsterhealth(50);
							player1.set_minionhealth(20);
							player1.set_health(100);
							system("clear");
							print_map(player);
							hud(player1, weapons, playa);
							on_monster = false;
							break;
						} 
						
						//if monster is still alive output damages that have been done by player and monsters
						else {
							system("clear");
							print_battle();
							hud(player1, weapons, playa);
							cout << "The Monster's attack did " << dmgoutmon << " damage!" << endl;
							if (minion) {
								cout << "The Minion's attack did " << dmgoutmin << " damage!" << endl;
								minion = false;
							}
							cout << "Your attack did " << playa.damage << " damage!" << endl;
						}
					}
				}
			}
			
			//gives gold if the player is on a treaasure spot
			else if (on_treasure) {
				player1.set_gold(player1.get_gold() + REWARD);
				print_map(player);
				hud(player1, weapons, playa);
				on_treasure = false;
				cout << "\nYou found " << REWARD << " gold in a chest!" << endl;
			}

			//moves player to open spot if not on treasure or monster
			else {
				print_map(player);
				hud(player1, weapons, playa);
			}
		}
		//redraws whole map as is if player tries to move out of bounds
		else {
			temp = player;
			system("clear");
			print_map(player);
			hud(player1, weapons, playa);
		}
	}
}
