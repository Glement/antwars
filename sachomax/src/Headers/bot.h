#pragma once
#include "player.h"
#include "clan.h"
using namespace std;
///\brief Class Bot, baby from class C_Player.
class C_Bot:public C_Player
{
public:
    C_Bot(const char & name){set_type(name);}///\brief Make turn depends on current situation.
    bool make_turn          (map<char,C_Clan> & clans);///\brief Set bot's hard(increase) depends on current map.
    void set_hard           (const int & level){hard=level;}
    ~C_Bot(){};
private:///\brief Bots level of hard= level of increase
    int hard;
};
