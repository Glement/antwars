#pragma once
#include "clan.h"
#include "map"
using namespace std;
///\brief Read next map.
bool read_map(const string & name,map<char,C_Clan> & clans);
///\brief Just help function to save code space and throw to trash newline or space
bool eat_enter(ifstream & file);
