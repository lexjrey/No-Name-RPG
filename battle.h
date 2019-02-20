#include <iostream>
#include <vector>
using namespace std;


// vector holding a cool battle picture 
vector<string> battle = {
"|--------------------------------------|",
"|                                      |",
"|                       (__)    )      |",
"|                       (..)   /|\\     |",
"|                      (o_o)  / | \\    |",
"|  /+====>             ___) \\/,-|,-\\   |",
"|  \\O___            //,-/_\\ )  '  '    |",
"|   |                  (//,-'\\         |",
"|   |                  (  ( . \\_       |",
"|  / \\                 `._\\(___`.      |",
"| /   \\                 '---' _)/      |",
"|--------------------------------------|",
};
//function that prints the vector above
void print_battle() {	
	for (unsigned int i = 0; i < battle.size(); i++) {
		for (unsigned int j = 0; j < battle.at(i).size(); j++) {
			cout << battle.at(i).at(j);
		}
		cout << endl;
	}
}
