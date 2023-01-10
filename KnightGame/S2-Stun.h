#pragma once
#include "S0-Skill.h"
class Stun :
    public Skill
{
public:
	Stun();
	virtual ~Stun();
	virtual string get_label() const;
	virtual Status launch();
};

