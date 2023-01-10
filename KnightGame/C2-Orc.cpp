#include "C2-Orc.h"

Orc::Orc(string name) : Character(60, name, 2) {
}

Orc::~Orc() {}

string Orc::get_class() const {
	return "Orc";
}