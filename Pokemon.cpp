
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include <iostream>
#include "string.h"


/*
unsigned int experience_points;
        double pokemon_dollars;
        unsigned int training_units_to_buy;
        unsigned int stamina_points_to_buy;
        string name;
        PokemonCenter* current_center;
        PokemonGym* current_gym;
        Point2D destination;
        Vector2D delta;


*/
Pokemon::Pokemon() : GameObject('P')
{
    speed = 5;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    name = "Default Pokemon";
    current_center = NULL;
    current_gym = NULL;
    destination = Point2D();
    delta = Vector2D();

    cout << "Pokemon default constructed." << endl;
}

Pokemon::Pokemon(char in_code) : GameObject('P')
{
    speed = 5;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    name = "Default Pokemon";
    current_center = NULL;
    current_gym = NULL;
    destination = Point2D();
    delta = Vector2D();
    cout << "Pokemon default constructed." << endl;   

}

Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc) : GameObject(in_loc, in_id, in_code)
{
    name = in_name;
    speed = in_speed;
    is_in_gym = false;
    is_in_center = false;
    stamina = 20;
    experience_points = 0;
    pokemon_dollars = 0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    destination = Point2D();
    delta = Vector2D();
    cout << "Pokemon constructed" << endl;
}

void Pokemon::ShowStatus()
{
   cout << name;
   GameObject::ShowStatus();
   cout << " status: " << endl;
   cout << endl;
   GameObject::ShowStatus();

   switch (state)
   {
       case STOPPED:  
       {
            cout << " stopped" << endl;
            break;
       }

       case MOVING:
       {
           cout << " moving at a speed of " << speed << " to destination " << destination << "at each step of" << delta << endl; 
       }

       case MOVING_TO_CENTER:
       {
           cout << " heading to Pokemon Center " << current_center->id_num << " at a speed of " << speed << " at each step of " << delta << endl;
       }

       case MOVING_TO_GYM:
       {
           cout << " heading to Pokemon Gym " << current_gym->id_num << " at a speed of " << speed << " at each step of " << delta << endl;
       }

       case IN_CENTER:
       {
           cout << " inside Pokemon Center " << current_center->id_num << endl;
       }

       case IN_GYM:
       {
           cout << " inside Pokemon Gym " << current_gym->id_num << endl;
       }

       case TRAINING_IN_GYM:
       {
           cout << " training in Pokemon Gym " << current_gym->id_num << endl;
       }

       case RECOVERING_STAMINA:
       {
           cout << " recovering stamina in Pokemon Center " << current_center->id_num << endl;
       }    
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
