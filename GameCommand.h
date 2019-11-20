#ifndef GAMECOMMAND_H
#define GAMECOMMAND_H

#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "Building.h"

#include <iostream>
#include "string.h"

using namespace std;

class GameCommand{

    public:

    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToCenterCommand(Model&, int, int);
    void DoMoveToGymCommand(Model&, int, int);
    void DoStopCommand(Model&, int);
    void DoTrainInGymCommand(Model&, int, unsigned int);
    void DoRecoverInCenterCommand(Model&, int, unsigned int);
    //void DoGoCommand(Model&, View&);
    //void DoRunCommand(Model&, View&);
};


#endif