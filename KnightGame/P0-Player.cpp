#include "P0-Player.h"

Player::Player() {}

Player::~Player() {}

int Player::select_character(vector<Character*> list_characters) {
	int selected=-1;
	//Doubled this code on top because of a bug(does not recognize the first input)
	cout << endl;
	cout << "Choose your character (press the corresponding number):" << endl;
	for (int i = 0; i < (int)list_characters.size(); i++) {
		cout << i << "- " << list_characters[i]->get_class() << endl;
	}

	while (!(cin >> selected) || (selected < 0)){
		cout << endl;
		cout << "Choose your character (press the corresponding number):" << endl;
		for (int i = 0; i < (int)list_characters.size(); i++) {
			cout << i << "- " << list_characters[i]->get_class() << endl;
		}
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	cout << endl;
	return selected;
}

int Player::select_skill(Character& character) {
	int selected;
	do {
		cout << endl;
		cout << "What skills do you want to launch (press the corresponding number):" << endl;
		cout << "0- None " << endl;
		character.print_skills();
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	} while (!(cin >> selected) || (selected < 0));
	cout << endl;
	return selected;
}