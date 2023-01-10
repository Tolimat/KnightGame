#pragma once
#include "0-lib.h"

enum class Status {
	normal,
	stunned,
	charged
};

//change the << operator to print enum Status
std::ostream& operator<<(std::ostream& out, const Status value);

class Skill
{
public:
	Skill(int cooldown, int duration, int success_rate);
	virtual ~Skill() {};
	virtual string get_label() const = 0;
	virtual Status launch() = 0;
	void update_cooldown();
	int get_duration() const;
	int get_cooldown_count() const;
protected:
	int cooldown;
	int cooldown_count;
	int duration;
	int success_rate;
};

