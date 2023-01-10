#pragma once
#include "0-lib.h"

class Weapon
{
public:
	Weapon(int attack_point, int shield_point, int hands_taken, bool is_shield);
	~Weapon();
	int get_attack_point() const;
	int get_hands_taken() const;
	bool get_is_shield() const;
	int absorb_damage(int const attack_point);
	virtual string get_label() const = 0;

protected:
	int attack_point;
	int shield_point;
	int hands_taken;
	bool is_shield;
};

