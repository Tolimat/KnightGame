#include "S1-Charge.h"

Charge::Charge():Skill(3,1,60){}

Charge::~Charge(){}

string Charge::get_label() const{
	return "Charge";
}

Status Charge::launch() {
	int nb = rand() % 100;
	if (this->cooldown_count == 0) {
		cout << this->get_label() << " launched." << endl;
		if (nb > this->success_rate) {
			this->cooldown_count = this->cooldown+1;
			cout << this->get_label() << " failed." << endl << endl;
		}
		else {
			this->cooldown_count = this->cooldown+1;
			return Status::charged;
		}
	}
	else {
		cout << this->get_label() << " is on cooldown." << endl << endl;
	}
	return Status::normal;
}
