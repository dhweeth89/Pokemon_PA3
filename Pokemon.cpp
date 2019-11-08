
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include <iostream>
#include "string.h"

Pokemon::Pokemon() : GameObject('P')
{
    speed = 5;
    cout << "Pokemon default constructed." << endl;
}

Pokemon::Pokemon(char in_code) : GameObject('P')
{
    speed = 5;
    cout << "Pokemon default constructed." << endl;   

}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    name = in_name;
    speed = in_speed;
    cout << "Pokemon constructed" << endl;
}

void Pokemon::ShowStatus()
{
   cout << name << " status: " << endl;
   cout << endl;
   GameObject::ShowStatus();

   switch (state)
   {
       case 0:  
       {
            cout << " stopped" << endl;
            break;
       }

       //case 1:
       //{
       //    cout << " moving at a speed of " << speed << " to destination " << location << at each step of 
       //}
   }

   cout << "Stamina: " << stamina << endl;
   cout << "Pokemon Dollars: " << pokemon_dollars << endl;
   cout << "Experience Points: " << experience_points << endl;

}

// bool UpdateLocation();
// void SetupDestination(Point2D);

// Pokemon();
// Pokemon(char);
// Pokemon(string, int, char, unsigned int, Point2D);    
// void StartMoving(Point2D);
// void StartMovingToCenter(PokemonCenter*);
// void StartMovingToGym(PokemonGym*);
//         void StartTraining(unsigned int);
//         void StartRecoveringStamina(unsigned int);
//         void Stop();
//         bool IsExhausted();
//         bool ShouldBeVisible();
//         void ShowStatus();
//         bool Updaate();
