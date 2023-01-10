#pragma once
#include "W0-Weapon.h"
class BaseSword :
    public Weapon
{
public:
    BaseSword();
    ~BaseSword();
    string get_label() const;
};

