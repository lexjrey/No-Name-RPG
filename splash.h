#include <iostream>
using namespace std;

//Function that prints this beautiful splashscreen with game instructions to the screen
void print_splash() {
	system("clear");
	
	//cool jazz to make colors
	const string red ("\033[1;31m");
	const string blue ("\033[1;34m");
	const string green ("\033[1;32m");
	const string reset ("\033[0m");
	cout << green << " ___                     _      ____                        _   _" << endl;                      
	cout << green << "|_ _|_ __  ___  ___ _ __| |_   / ___| __ _ _ __ ___   ___  | \\ | | __ _ _ __ ___   ___" << endl; 
	cout << green << " | || '_ \\/ __|/ _ \\ '__| __| | |  _ / _` | '_ ` _ \\ / _ \\ |  \\| |/ _` | '_ ` _ \\ / _ \\" << endl;
	cout << green << " | || | | \\__ \\  __/ |  | |_  | |_| | (_| | | | | | |  __/ | |\\  | (_| | | | | | |  __/" << endl;
	cout << green << "|___|_| |_|___/\\___|_|   \\__|  \\____|\\__,_|_| |_| |_|\\___| |_| \\_|\\__,_|_| |_| |_|\\___|" << endl;
	cout << reset;				                                                                                        

	cout<< blue << "\n------------------------------------------------ Story ---------------------------------------------------------------------" << endl;
	cout << "    Roam the land as you defeat various monsters and their minions while also finding loot on your quest for 100 gold" << endl;
	cout << "  Your lifeforce is dependent on monster guts, so kill monster to regain health, but one false move and they can kill you " << endl; 
	cout << "----------------------------------------------------------------------------------------------------------------------------\n" << endl;

	cout << "--------------------- Controls ---------------------------------------------\n";
	cout << "   Use w, a, s, or d followed by the return key to navigate around the map. \n";
	cout <<	"         While in battle use z to attack, and c to switch weapons \n";
	cout << "-----------------------------------------------------------------------------\n" << endl;
	cout << "Enter anything to continue\n";
	cout << reset;
}
