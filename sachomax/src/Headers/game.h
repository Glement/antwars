#pragma once
#include "save.h"
#include "clan.h"
#include "bot.h"
#include "user.h"
#include "player.h"
#include <map>
using namespace std;
///\brief Menu of the game, space for play, any other key to escape.
bool  menu();
///\brief Play until win, lose, or dead end.
bool  game();
