#pragma once
#include "W0-Weapon.h"
class BaseAxe :
    public Weapon
{
public:
    BaseAxe();
    ~BaseAxe();
    string get_label() const;
};

