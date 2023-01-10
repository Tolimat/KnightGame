#include "S0-Skill.h"

//Operator overload to print Status correctly 
std::ostream& operator<<(std::ostream& out, const Status value) {
	const char* s = 0;
#define PROCESS_VAL(p) case(p): s = #p; break;
	switch (value) {
		PROCESS_VAL(Status::normal);
		PROCESS_VAL(Status::stunned);
		PROCESS_VAL(Status::charged);
	}
#undef PROCESS_VAL

	return out << s+8;
}

Skill::Skill(int cooldown, int duration, int success_rate) {
	this->cooldown = cooldown;
	this->cooldown_count = 0;
	this->duration = duration;
	this->success_rate = success_rate;
}

void Skill::update_cooldown() {
	if (this->cooldown_count > 0) {
		this->cooldown_count--;
	}
}

int Skill::get_duration() const{
	return(this->duration);
}

int Skill::get_cooldown_count() const {
	return(this->cooldown_count);
}
