#pragma once
#include "C0-Character.h"

class Orc :
    public Character
{
public:
	Orc(string name = "Boark");
	~Orc();
	string get_class() const;
};

