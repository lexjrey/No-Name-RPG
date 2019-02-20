#include <iostream>
#include "weapon.h"
#include <vector>
using namespace std;

//A class to keep track of a single player and store his health and gold
//Also stores the Monsters and minions health
class Actors {
	private: 	
		int health = 100;
		int gold = 0;
		int minionhealth = 20;
		int monsterhealth = 50;

	public:
		//public functions to get and set the health gold and monsters health
		int get_monsterhealth() { 
       		return monsterhealth;
        } 
        void set_monsterhealth(int new_monsterhealth) { 
       		monsterhealth = new_monsterhealth;
        } 
    	int get_minionhealth() {
            return minionhealth;
        }
        void set_minionhealth(int new_minionhealth) { 
           minionhealth = new_minionhealth;
		}
		int get_health() {
			return health;
		}
		void set_health(int new_health) {
			health = new_health;
		}
		int get_gold() {
			return gold;
		}
		void set_gold(int new_gold) {
			gold = new_gold;
		}
		
			


};
