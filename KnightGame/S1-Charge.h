#pragma once
#include "S0-Skill.h"
class Charge :
    public Skill
{
public:
	Charge();
	virtual ~Charge();
	virtual string get_label() const;
	virtual Status launch();
};

