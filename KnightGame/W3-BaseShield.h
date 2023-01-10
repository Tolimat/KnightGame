#pragma once
#include "W0-Weapon.h"
class BaseShield :
    public Weapon
{
public:
    BaseShield();
    ~BaseShield();
    string get_label() const;
};

