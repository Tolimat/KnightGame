#include "C0-Character.h"

Character::Character(int life_point, string name, int hands_free) {
	this->alive = true;
	this->life_point = life_point;
	this->attack_point = 0;
	this->name = name;
	this->status = Status::normal;
	this->status_duration = 0;
	this->hands_free = hands_free;
	this->weapons = new vector<Weapon*>;
	this->skills = new vector<Skill*>;
}

Character::~Character() {
	vector<Weapon*>::iterator it;
	for (it = weapons->begin(); it != weapons->end(); it++) {
		delete (*it);
	}
	vector<Skill*>::iterator it1;
	for (it1 = skills->begin(); it1 != skills->end(); it1++) {
		delete (*it1);
	}
	delete weapons;
	delete skills;
}

bool Character::is_alive() const{
	return alive;
}

void Character::equip(Weapon& weapon) {
	if (hands_free >= weapon.get_hands_taken()) {
		this->weapons->push_back(&weapon);
		this->hands_free -= weapon.get_hands_taken();
		this->attack_point += weapon.get_attack_point();
		cout << this->get_class() << " " << this->name << ": Weapon " << weapon.get_label() << " is now equiped." << endl << endl;
	}
	else {
		cout << this->get_class() << " " << this->name << "has only " << hands_free << " slot(s) left, you cannot equip this " << weapon.get_label() << "." << endl <<endl;
	}
}

void Character::take_damage(int attack_point) {
	vector<Weapon*>::iterator it;
	int attack_point_left = attack_point;
	for (it = this->weapons->begin(); it != this->weapons->end(); it++) {
		if ((*it)->get_is_shield()) {
			attack_point_left = (*it)->absorb_damage(attack_point);
		}
	}
	life_point -= attack_point_left;
	cout << this->get_class() << " " << this->name << " took " << attack_point_left << " damage(s)." << endl;
	if (life_point <= 0) {
		life_point = 0;
		alive = false;
		cout << this->get_class() << " " << this->name << " died." << endl << endl;
	}
	else {
		cout << life_point << " health point(s) left." << endl<<endl;
	}
}

bool Character::can_attack() const{
	switch (this->status)
	{
	case Status::stunned:
		cout << this->get_class() << " " << this->name << " can't act, He's stunned!" << endl << endl;
		return(false);
	default:
		return(true);
	}
}

void Character::attack(Character& ennemy) const{
	if (this->can_attack()) {
		cout << this->get_class() << " " << this->name << " attacked!" << endl;
		ennemy.take_damage(this->attack_point);
	}
}

void Character::learn(Skill& skill) {
	this->skills->push_back(&skill);
	cout << this->get_class() << " " << this->name << ": Skill " << skill.get_label() << " is now learned." << endl << endl;
}

void Character::take_status(Status status, int duration) {
	this->status = status;
	this->status_duration = duration;
	cout << this->get_class() << " " << this->name << " is now " << status << "." << endl << endl;
}

void Character::inflict(Character& ennemy,Status status,int duration) const {
	ennemy.take_status(status,duration);
}

void Character::launch_skill(int skill_nb, Character& ennemy) {
	if (skill_nb > (int)this->skills->size() - 1) {
		throw string("Error: Skill number does not exist!");
	}
	if (this->can_attack()) {
		Status s = (*skills)[skill_nb]->launch();
		switch (s)
		{
		case Status::charged:
			this->attack_point *= 2;
			this->take_status(Status::charged, (*skills)[skill_nb]->get_duration());
			break;
		case Status::stunned:
			inflict(ennemy, Status::stunned, (*skills)[skill_nb]->get_duration());
			break;
		default:
			break;
		}
	}
}

void Character::end_turn() {
	if (this->status_duration == 1 && this->status != Status::normal) {
		this->status_duration--;
		switch (this->status) {
		case Status::charged:
			this->attack_point /= 2;
			break;
		default:
			break;
		}
		this->take_status(Status::normal, 0);
	}
	else if(this->status_duration > 1 && this->status != Status::normal){
		this->status_duration--;
	}

	for (int i = 0; i < (int)skills->size(); i++) {
		(*skills)[i]->update_cooldown();
	}
}

void Character::print_skills() const {
	for (int i = 0; i < (int)skills->size(); i++) {
		cout << "Skill " << i+1 << ": " << (*skills)[i]->get_label();
		if ((*skills)[i]->get_cooldown_count() > 0) {
			cout << " on cooldown (" << (*skills)[i]->get_cooldown_count() << " turn(s))." << endl;
		}
		else {
			cout << endl;
		}
	}
}
