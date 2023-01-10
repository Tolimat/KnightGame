#include "S2-Stun.h"

Stun::Stun() :Skill(5,1, 20) {}

Stun::~Stun() {}

string Stun::get_label() const {
	return "Stun";
}

Status Stun::launch() {
	int nb = rand() % 100;
	if (this->cooldown_count == 0) {
		cout << this->get_label() << " launched." << endl;
		if (nb > this->success_rate) {
			this->cooldown_count = this->cooldown+1;
			cout << this->get_label() << " failed." << endl << endl;
		}
		else {
			this->cooldown_count = this->cooldown+1;
			return Status::stunned;
		}
	}
	else {
		cout << this->get_label() << " is on cooldown." << endl << endl;
	}
	return Status::normal;
}