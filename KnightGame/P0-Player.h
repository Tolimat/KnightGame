#pragma once
#include "0-lib.h"
#include "1-characters.h"

class Player
{
public:
	Player();
	~Player();
	int select_character(vector<Character*> list_characters);
	int select_skill(Character& character);
};

