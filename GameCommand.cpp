#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include "Building.h"
#include "GameCommand.h"
#include "View.h"

#include <iostream>
#include "string.h"

using namespace std;

/*

    void DoMoveCommand(Model&, int, Point2D);
    void DoMoveToCenterCommand(Model&, int, int);
    void DoMoveToGymCommand(Model&, int, int);
    void DoStopCommand(Model&, int);
    void DoTrainInGymCommand(Model&, int, unsigned int);
    void DoRecoverInCenterCommand(Model&, int, unsigned int);
    //void DoGoCommand(Model&, View&);
    //void DoRunCommand(Model&, View&);

*/

void DoMoveCommand(Model& model, int pokemon_id, Point2D p1)
{
    if (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon())
    {
        cout << "Error: Please enter a valid command!" << endl; 
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);

        ptrPokemon->StartMoving(p1);
        cout << "Moving " << ptrPokemon->getName() << " to " << p1 << endl;
    }
    
}

void DoMoveToCenterCommand(Model& model, int pokemon_id, int center_id)
{
    if ( (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon()) || (center_id <= 0 || pokemon_id > model.GetNumCenters() ) )
    {
        cout << "Error: Please enter a valid command!" << endl; 
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonCenter* ptrCenter = model.GetPokemonCenterPtr(center_id);

        ptrPokemon->StartMovingToCenter(ptrCenter);
        cout << "Moving " << ptrPokemon->getName() << " to Center " << center_id << endl;
    }

}

void DoMoveToGymCommand(Model& model, int pokemon_id, int gym_id)
{
    if ( (pokemon_id <= 0 || pokemon_id > model.GetNumPokemon()) || (gym_id <= 0 || gym_id > model.GetNumGyms() ) )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        PokemonGym* ptrGym = model.GetPokemonGymPtr(gym_id);

        ptrPokemon->StartMovingToGym(ptrGym);
        cout << "Moving " << ptrPokemon->getName() << " to Gym " << gym_id << endl;
    }
    
}


void DoStopCommand(Model& model, int pokemon_id)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        ptrPokemon->Stop();
        cout << "Stopping " << ptrPokemon->getName() << endl;
    }
    
}

void DoTrainInGymCommand(Model& model, int pokemon_id, unsigned int training_units)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Training " << ptrPokemon->getName() << endl;
        ptrPokemon->StartTraining(training_units);
    }
    
}


void DoRecoverInCenterCommand(Model& model, int pokemon_id, unsigned int stamina_points)
{
    if ( pokemon_id <= 0 || pokemon_id > model.GetNumPokemon() )
    {
        cout << "Error: Please enter a valid command!" << endl;
    }
    else
    {
        Pokemon* ptrPokemon = model.GetPokemonPtr(pokemon_id);
        cout << "Recovering " << ptrPokemon->getName() << "'s stamina" << endl;
        ptrPokemon->StartRecoveringStamina(stamina_points);
    }
}


void DoGoCommand(Model& model, View& view)
{
    cout << "Advancing one tick." << endl;
    model.Update();
    model.Display(view);
}


void DoRunCommand(Model& model, View& view)
{
    cout << "Advancing to next event." << endl;
    int i = 0;
    bool updateTruth = false;

    while (i<5 && !(updateTruth))
    {
        //model.Display(view);
        updateTruth = model.Update();
        model.Display(view);
        i++;
    }

    //If the thing updates, it stops running.  If i reaches 5, you stop.  Only one of these conditions has to be met to exit loop
}

