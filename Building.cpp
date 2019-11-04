#include <iostream>
#include "Point2D.h"
#include "GameObject.h"
#include "Building.h"

using namespace std;

Building::Building() : GameObject('B')
{
    pokemon_count = 0;
    cout << "Building default constructed" << endl;
}

Building::Building(char in_code, int in_Id, Point2D in_loc) : GameObject(in_loc, in_Id, in_code)
{
    pokemon_count = 0;
    id_num = in_Id;
    location = in_loc;
    display_code = in_code; 
    cout << "Building constructed" << endl;
}

void Building::AddOnePokemon()
{
    pokemon_count++;
}

void Building::RemoveOnePokemon()
{
    pokemon_count--;
}

void Building::ShowStatus()
{
    cout << display_code << id_num << " located at " << location << endl;
    
    if (pokemon_count == 1)
    {
        cout << pokemon_count << " pokemon is in this building" << endl;
    }
    else
    {
        cout << pokemon_count << " pokemon are in this building" << endl;
    }
    
}

bool Building::ShouldBeVisible()
{
    return true;
}