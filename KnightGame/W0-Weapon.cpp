#include "W0-Weapon.h"

Weapon::Weapon(int attack_point, int shield_point, int hands_taken, bool is_shield) {
	this->attack_point = attack_point;
	this->shield_point = shield_point;
	this->hands_taken = hands_taken;
	this->is_shield = is_shield;
}

Weapon::~Weapon() {}

int Weapon::get_attack_point() const {
	return attack_point;
}

int Weapon::get_hands_taken() const {
	return hands_taken;
}

bool Weapon::get_is_shield() const {
	return is_shield;
}

int Weapon::absorb_damage(int const attack_point) {
	int attack_point_left;
	if (attack_point <= shield_point) {
		shield_point -= attack_point;
		attack_point_left = 0;
	}
	else {
		attack_point_left = attack_point - shield_point;
		shield_point = 0;
	}
	cout << this->get_label() << " absorbed " << attack_point - attack_point_left << " damage(s). " << this->shield_point << " shield point(s) left."<<endl;
	return attack_point_left;

}
