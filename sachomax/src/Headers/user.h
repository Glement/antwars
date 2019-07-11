#pragma once
#include "player.h"
#include "clan.h"
using namespace std;
///\brief User class , baby of class C_Player.
class C_User:public C_Player
{
public:
    C_User(const char & name){set_type(name);}
    ///\brief Scan input and make turn depends on input.
    bool make_turn      (map<char,C_Clan> & clans);
    ~C_User(){};
};
