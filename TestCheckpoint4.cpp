#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "View.h"
#include "GameCommand.h"

#include <iostream>
#include "string.h"
#include "math.h"
#include "stdlib.h"


int main()
{
    Model model = Model();
    View view = View();

    view.Clear();
    view.Draw();

    for (int i=0; i<model.GetNumPokemon(); i++)
    {
        view.Plot(model.GetPokemonPtr(i));
    }

    for (int i=0; i<model.GetNumGyms(); i++)
    {
        view.Plot(model.GetPokemonGymPtr(i));
    }

    for (int i=0; i<model.GetNumCenters(); i++)
    {
        view.Plot(model.GetPokemonGymPtr(i));
    }


}

