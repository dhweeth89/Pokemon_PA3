
#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include <iostream>
#include "string.h"
#include "math.h"

using namespace std;
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

void Pokemon::StartMoving(Point2D dest)
{ 
    SetupDestination(dest);
    
    if ((fabs(this->location.x - dest.x)) <= delta.x && (fabs(this->location.y - dest.y) <= delta.y))
    {
        cout << this->display_code << this->id_num << ": I'm already here. See?" << endl;
    }
    else if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    }
    else
    {
        cout << this->display_code << this->id_num << ": On my way." << endl;
        state = MOVING;
    }
}

void Pokemon::StartMovingToCenter(PokemonCenter* center)
{
    SetupDestination(center->GetLocation());
    
    if ((fabs(this->location.x - center->GetLocation().x)) <= delta.x && (fabs(this->location.y - center->GetLocation().y) <= delta.y))
    {
        cout << this->display_code << this->id_num << ": I'm already at the Pokemon Center!" << endl;
    }
    else if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted so I can't move to recover stamina." << endl;
    }
    else
    {
        cout << this->display_code << this->id_num << ": On my way to gym " << center->GetId() << endl;
        state = MOVING;
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym->GetLocation());
    
    if ((fabs(this->location.x - gym->GetLocation().x)) <= delta.x && (fabs(this->location.y - gym->GetLocation().y) <= delta.y))
    {
        cout << this->display_code << this->id_num << ": I'm already at the Pokemon Gym!" << endl;
    }
    else if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted so I shouldn't be going to the gym..." << endl;
    }
    else
    {
        cout << this->display_code << this->id_num << ": On my way to gym " << gym->GetId() << endl;
        state = MOVING;
    }
}

void Pokemon::StartTraining(unsigned int num_training_units)
{
    if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted so no more training for me..." << endl; 
    }
    else if (state != IN_GYM)
    {
        cout << this->display_code << this->id_num << ": I can only train at a Pokemon Gym!" << endl;
    }
    else if (current_gym->GetState() == BEATEN)
    {
        cout << this->display_code << this->id_num << ": Cannot train! This Pokemon Gym is already beaten!" << endl;
    }
    else if ((current_gym->GetDollarCost(1) > this->pokemon_dollars) && (current_gym->GetStaminaCost(1) > this->stamina))
    {
        cout << this->display_code << this->id_num << ": Not enough money and/or stamina for training." << endl;
    }
    else
    {
        if (num_training_units > current_gym->GetNumTrainingUnitsRemaining())
        {
            training_units_to_buy = current_gym->GetNumTrainingUnitsRemaining();
        }
        else
        {
            training_units_to_buy = num_training_units;
        }    
    }

}


void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (current_center->GetNumStaminaPointsRemaining() == 0)
    {
        cout << this->display_code << this->id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center!" << endl;
        stamina_points_to_buy = 0; 
    }
    else if (state != IN_CENTER)
    {
        cout << this->display_code << this->id_num << ": I can only recover stamina points at a Pokemon Center!" << endl;
        stamina_points_to_buy = 0;
    }
    else if (current_center->GetDollarCost(num_stamina_points) > this->pokemon_dollars)
    {
        cout << this->display_code << this->id_num << ": Not enough money to recover any stamina." << endl;
        stamina_points_to_buy = 0;
    }
    else
    {
        if (num_stamina_points > current_center->GetNumStaminaPointsRemaining())
        {
            stamina_points_to_buy = current_center->GetNumStaminaPointsRemaining();
        }
        else
        {
            stamina_points_to_buy = num_stamina_points;
        }    
    }

}

void Pokemon::Stop()
{
    cout << this->display_code << this->id_num << ": Stopping..." << endl;
    state = STOPPED;
}

bool Pokemon::IsExhausted()
{
    if (this->stamina == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Pokemon::ShouldBeVisible()
{
    if (this->state != EXHAUSTED)
    {
        return true;
    }
    else
    {
        return false;
    }
    
}

void Pokemon::ShowStatus()
{
   cout << name;
   GameObject::ShowStatus();
   cout << " status: " << endl;
   cout << endl;

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
           cout << " heading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
       }

       case MOVING_TO_GYM:
       {
           cout << " heading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
       }

       case IN_CENTER:
       {
           cout << " inside Pokemon Center " << current_center->GetId() << endl;
       }

       case IN_GYM:
       {
           cout << " inside Pokemon Gym " << current_gym->GetId() << endl;
       }

       case TRAINING_IN_GYM:
       {
           cout << " training in Pokemon Gym " << current_gym->GetId() << endl;
       }

       case RECOVERING_STAMINA:
       {
           cout << " recovering stamina in Pokemon Center " << current_center->GetId() << endl;
       }    
   }

   cout << "Stamina: " << stamina << endl;
   cout << "Pokemon Dollars: " << pokemon_dollars << endl;
   cout << "Experience Points: " << experience_points << endl;

}

bool Pokemon::Update()
{
    switch (state)
    {
        case STOPPED:
        {
            return false;
        }

        case MOVING:
        {
            if (UpdateLocation())
            {
                state = STOPPED;
                return true;
            }
            else
            {
                state = MOVING;
                return false;
            }
        }

        case MOVING_TO_CENTER:
        {
            if (UpdateLocation())
            {
                state = IN_CENTER;
                return true;
            }
            else
            {
                state = MOVING;
                return false;
            }
        }

        case MOVING_TO_GYM:
        {
            if (UpdateLocation())
            {
                state = IN_GYM;
                return true;
            }
            else
            {
                state = MOVING;
                return false;
            }
            
        }

        case IN_CENTER:
        {
            return false;
        }

        case IN_GYM:
        {
            return false;
        }

        case TRAINING_IN_GYM:
        {
            unsigned int experience_points_gained = current_gym->TrainPokemon(training_units_to_buy);
            unsigned int stamina_points_bought = current_gym->GetStaminaCost(training_units_to_buy);

            stamina -= stamina_points_bought;
            pokemon_dollars -= current_gym->GetDollarCost(stamina_points_bought);
            experience_points += experience_points_gained;
        
            if (training_units_to_buy == 1)
            {
                cout << "** " << this->name << " completed " << training_units_to_buy << " training unit!**" << endl;
            }
            else
            {
                cout << "** " << this->name << " completed " << training_units_to_buy << " training units!**" << endl;
            }

            if (experience_points_gained == 1)
            {
                cout << "** " << this->name << " gained " << experience_points_gained << " experience point!**" << endl;
            }
            else
            {
                 cout << "** " << this->name << " gained " << experience_points_gained << " experience points!**" << endl;
            }
            state = IN_GYM;
            return true; 
        }

        case RECOVERING_STAMINA:
        {
           unsigned int stamina_points_gained = current_center->DistributeStamina(stamina_points_to_buy);

           stamina += stamina_points_gained;
           pokemon_dollars -= current_center->GetDollarCost(stamina_points_gained);

           if (stamina_points_gained == 1)
           {
            cout << "**" << this->name << " recovered " << stamina_points_gained << " stamina point!**" << endl;
           }
           else
           {
            cout << "**" << this->name << " recovered " << stamina_points_gained << " stamina points!**" << endl;   
           }

           state = IN_CENTER;
           return true;
        }
    }
}

bool Pokemon::UpdateLocation()
{
    if (fabs(this->location.x - this->destination.x) <= this->delta.x && fabs(this->location.y - this->destination.y) <= this->delta.y )
    {
        cout << this->display_code << this->id_num << ": I'm there!" << endl;
        return true;
    }
    else 
    {
        cout << this->display_code << this->id_num << ": step..." << endl;
        return false;
    }
}

void Pokemon::SetupDestination(Point2D dest)
{
    this->delta.x = (destination.x - location.x) * (speed / GetDistanceBetween(this->destination, this->location));
    this->delta.y = (destination.y - location.y) * (speed / GetDistanceBetween(this->destination, this->location));
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
