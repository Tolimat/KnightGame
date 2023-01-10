#include "W2-BaseAxe.h"

BaseAxe::BaseAxe() :Weapon(8,0, 2, false) {}

BaseAxe::~BaseAxe() {}

string BaseAxe::get_label() const{
	return "Base Axe";
}
