#include "W3-BaseShield.h"

BaseShield::BaseShield() :Weapon(0,50, 1, true) {}

BaseShield::~BaseShield() {}

string BaseShield::get_label() const{
	return "Base Shield";
}
