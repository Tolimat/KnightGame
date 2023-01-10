#pragma once
#include "0-lib.h"
#include "2-weapons.h"
#include "3-skills.h"

class Character
{
	public:
		Character(int life_point, string name, int hands_free=2);
		virtual ~Character();
		virtual string get_class() const = 0;
		bool is_alive() const;
		void equip(Weapon& weapon);
		void take_damage(int attack_point);
		bool can_attack() const;
		void attack(Character &ennemy) const;
		void learn(Skill& skill);
		void take_status(Status status, int duration);
		void inflict(Character& ennemy, Status status, int duration) const;
		void launch_skill(int skill_nb, Character& ennemy);
		void end_turn();//Function that update a character after the end of the turn (Status update, Skill cooldown update).
		void print_skills() const;

	protected:
		bool alive;
		int life_point;
		int attack_point;
		string name;
		Status status;
		int status_duration;
		int hands_free;
		vector<Weapon*>* weapons;
		vector<Skill*>* skills;
};

