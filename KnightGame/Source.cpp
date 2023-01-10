#include "1-characters.h"
#include "2-weapons.h"
#include "3-skills.h"
#include "P0-Player.h"

using namespace std;

int main() {
	srand(time(0));

	//CHARACTER CREATION
	vector<Character*> list_characters;

	Knight* k = new Knight();
	BaseSword* s1= new BaseSword();
	BaseShield* sh1= new BaseShield();
	Charge* ch1 = new Charge();
	k->equip(*s1);
	k->equip(*sh1);
	k->learn(*ch1);

	Orc* o = new Orc();
	BaseAxe* axe = new BaseAxe();
	Stun* stun = new Stun();
	o->equip(*axe);
	o->learn(*stun);

	list_characters.push_back(k);
	list_characters.push_back(o);

	//CHARACTER SELECTION
	Player *p1 = new Player;
	Character* enemy;
	Character* character_played;

	int selected_character = p1->select_character(list_characters);

	
	while (selected_character > list_characters.size() - 1) {
		cerr << "Error: Character number does not exist! Please restart the game" << endl;
		selected_character = p1->select_character(list_characters);
	}
	character_played = list_characters[selected_character];

	if (selected_character != 0) {
		enemy = list_characters[0];
	}
	else {
		enemy = list_characters[1];
	}

	//GAME LOOP
	int turn_nb = 0;

	while (character_played->is_alive() && enemy->is_alive()) {
		turn_nb++;
		cout << "Turn: " << turn_nb << endl << endl << endl;
		int skill_chosen = p1->select_skill(*character_played);
		if (skill_chosen != 0) {
			try {
				character_played->launch_skill(skill_chosen - 1, *enemy);
			}
			catch (string& e) {
				cerr << e << endl;
			}
		}
		enemy->launch_skill(0, *character_played);
		if (character_played->is_alive()) {
			character_played->attack(*enemy);
		}
		if (enemy->is_alive()) {
			enemy->attack(*character_played);
		}
		if (enemy->is_alive() && character_played->is_alive()) {
			character_played->end_turn();
			enemy->end_turn();
		}
		if (!enemy->is_alive()) {
			cout << "YOU WON!" << endl;
		}
		else if(!character_played->is_alive())
		{
			cout << "YOU LOSE!" << endl;
		}
	}
	system("pause");
	return 0;
}