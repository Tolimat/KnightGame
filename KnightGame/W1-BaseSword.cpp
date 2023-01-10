#include "W1-BaseSword.h"

BaseSword::BaseSword() :Weapon(5,0, 1, false) {}

BaseSword::~BaseSword(){}

string BaseSword::get_label() const{
	return "Base Sword";
}