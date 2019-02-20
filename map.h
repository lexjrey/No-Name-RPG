#include <iostream>
#include <vector>
#include "move.h"
using namespace std;

//variables describing the characters used in the map below
const char PLAYER = 'X';
const char MONSTER = 'M';
const char TREASURE = 'T';
const char WALL = '#';
const int REWARD = 25;
const int LOOTREWARD = 10;
bool on_monster = false;
bool on_treasure = false;
//cool string color jazz
const string blue ("\033[1;34m");
const string reset ("\033[0m");
const string red ("\033[1;31m");
const string yellow ("\033[1;33m");
const string grey ("\033[0;37m");
const string green ("\033[1;32m");
const string cyan("\033[1;36m");

//vector holding the whole map
vector<string> map = {
"|----------------------------------|",
"|                                 M|",
"|    #                 ''''''      |",
"| M  #               '''''''''''   |",
"|T   #              ''''''''''''   |",
"|#####             ''''''''''''    |",
"|                   ''''''''''     |",
"|                    ''''''''      |",
"|                     ''''         |",
"|                                  |",
"|                                  |",
"|                     M            |",
"|                                  |",
"|    ''''''''                      |",
"|  '''''''''''                     |",
"| '''''''''''''                    |",
"|   ''''''''''''            #######|",
"|  ''''''''''''          #         |",
"|    '''''''''           #    M    |",
"|M                       #       T |",
"|----------------------------------|"
};

//prints the map created above
void print_map(Move cur = {}) {
	for (unsigned int i = 0; i < map.size(); i++) {
		for (unsigned int j = 0; j < map.at(i).size(); j++) {
			if (cur.row != 0 && cur.column != 0 && cur.column != map.at(i).size()-1 && cur.row != map.size() && i == cur.row && j == cur.column) cout << cyan << PLAYER << reset;
			else if (map.at(i).at(j) == '\'') {
				cout << blue << map.at(i).at(j) << reset;
			}
			else if (map.at(i).at(j) == 'M'){
				cout << red << map.at(i).at(j) << reset;
			}
			else if (map.at(i).at(j) == 'T'){
				cout << yellow << map.at(i).at(j) << reset;
			}
			else if (map.at(i).at(j) == '#'){
				cout << grey << map.at(i).at(j) << reset;
			}
			else cout << green << map.at(i).at(j) <<reset;
		}
		cout << endl;
	}

}

//Checks to see if a spot is able to walk on
//Returns true if space is empty, a monster, or treasure

bool check_map(Move test, char test_char = ' ') {
	
	if (map.at(test.row).at(test.column) == test_char || map.at(test.row).at(test.column) == TREASURE || map.at(test.row).at(test.column) == MONSTER) { 
		// checks to see if player has encountered a monster
		if (map.at(test.row).at(test.column) == MONSTER) {
			map.at(test.row).at(test.column) = ' ';
			on_monster = true;
		}
		//checks to see if player has encountered treasure
		if (map.at(test.row).at(test.column) == TREASURE) {	
			map.at(test.row).at(test.column) = ' ';
			on_treasure = true;
		}
		return true;
	}
	return false;
}

