#include "C1-Knight.h"

Knight::Knight(string name) : Character(20, name, 2) {
}

Knight::~Knight(){}

string Knight::get_class() const {
	return "Knight";
}