#pragma once

#include "C0-Character.h"

class Knight :
	public Character
{
public:
	Knight(string name="Jack");
	~Knight();
	string get_class() const;
};

