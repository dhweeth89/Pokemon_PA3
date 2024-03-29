
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
    state = STOPPED;
    delta = Vector2D();

    cout << "Pokemon default constructed." << endl;
}

Pokemon::Pokemon(char in_code) : GameObject(in_code)
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
    state = STOPPED;
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
    pokemon_dollars = 0.0;
    training_units_to_buy = 0;
    stamina_points_to_buy = 0;
    current_center = NULL;
    current_gym = NULL;
    destination = Point2D();
    delta = Vector2D();
    state = STOPPED;
    cout << "Pokemon constructed" << endl;
}

Pokemon::~Pokemon()
{
    cout << "Pokemon destructed" << endl;
}

void Pokemon::StartMoving(Point2D dest)
{ 
    SetupDestination(dest);

    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }

    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    }
 

    if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted. I may move but you cannot see me." << endl;
    }
    else if ((fabs(this->location.x - dest.x)) <= fabs(delta.x) && (fabs(this->location.y - dest.y) <= fabs(delta.y)))
    {
        cout << this->display_code << this->id_num << ": I'm already here. See?" << endl;
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
        
    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }

    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    } 
    
    
    current_center = center;

    if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted so I can't move to recover stamina." << endl;
    }
    else if ((fabs(this->location.x - destination.x)) <= fabs(delta.x) && (fabs(this->location.y - destination.y) <= fabs(delta.y)))
    {
        cout << this->display_code << this->id_num << ": I'm already at the Pokemon Center!" << endl;
        state = IN_CENTER;
    }
    else
    {
        cout << this->display_code << this->id_num << ": On my way to the Pokemon Center... " << endl;
        state = MOVING_TO_CENTER;
    }
}

void Pokemon::StartMovingToGym(PokemonGym* gym)
{
    SetupDestination(gym->GetLocation());
    

    if (state == IN_CENTER)
    {
        current_center->RemoveOnePokemon();
        current_center = NULL;
    }

    if (state == IN_GYM)
    {
        current_gym->RemoveOnePokemon();
        current_gym = NULL;
    }

    current_gym = gym;
 
    if (this->state == EXHAUSTED)
    {
        cout << this->display_code << this->id_num << ": I am exhausted so I shouldn't be going to the gym..." << endl;
    }
    else if ((fabs(this->location.x - destination.x)) <= fabs(delta.x) && (fabs(this->location.y - destination.y) <= fabs(delta.y)))
    {
        cout << this->display_code << this->id_num << ": I'm already at the Pokemon Gym!" << endl;
        state = IN_GYM;
    }
    else
    {
        cout << this->display_code << this->id_num << ": On my way to gym " << gym->GetId() << endl;
        state = MOVING_TO_GYM;
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
    else if ((current_gym->GetDollarCost(num_training_units) > this->pokemon_dollars) || (current_gym->GetStaminaCost(num_training_units) > this->stamina))
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

        cout << this->display_code << this->id_num << ": Started to train at Pokemon Gym " << current_gym->GetId() <<  " with " << training_units_to_buy << " training units" << endl;

        state = TRAINING_IN_GYM;    
    }

}


void Pokemon::StartRecoveringStamina(unsigned int num_stamina_points)
{
    if (state != IN_CENTER)
    {
        cout << this->display_code << this->id_num << ": I can only recover stamina points at a Pokemon Center!" << endl;
        stamina_points_to_buy = 0;
    }
    else if (current_center->GetNumStaminaPointsRemaining() == 0)
    {
        cout << this->display_code << this->id_num << ": Cannot recover! No stamina points remaining in this Pokemon Center!" << endl;
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

        cout << this->display_code << this->id_num << ": Started recovering " << stamina_points_to_buy << " stamina points at Pokemon Center " << current_center->GetId() << endl;
        

        state = RECOVERING_STAMINA;    
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
   cout << endl;
   cout << name << " status: ";
   GameObject::ShowStatus();

   switch (state)
   {
       case STOPPED:  
       {
            cout << "\tStopped" << endl;
            break;
       }

       case MOVING:
       {
           cout << "\tMoving at a speed of " << speed << " to destination " << destination << "at each step of " << delta << endl;
           break; 
       }

       case MOVING_TO_CENTER:
       {
           cout << "\tHeading to Pokemon Center " << current_center->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
           break; 
       }

       case MOVING_TO_GYM:
       {
           cout << "\tHeading to Pokemon Gym " << current_gym->GetId() << " at a speed of " << speed << " at each step of " << delta << endl;
           break; 
       }

       case IN_CENTER:
       {
           cout << "\tInside Pokemon Center " << current_center->GetId() << endl;
           cout << endl;
           break;
       }

       case IN_GYM:
       {
           cout << "\tInside Pokemon Gym " << current_gym->GetId() << endl;
           cout << endl;
           break; 
       }

       case TRAINING_IN_GYM:
       {
           cout << "\tTraining in Pokemon Gym " << current_gym->GetId() << endl;
           break; 
       }

       case RECOVERING_STAMINA:
       {
           cout << "\tRecovering stamina in Pokemon Center " << current_center->GetId() << endl;
           break;
       }

        case EXHAUSTED:
        {
            cout << "\tExhausted " << endl;
        }   
    
   }

   cout << "\tStamina: " << stamina << endl;
   cout << "\tPokemon Dollars: " << pokemon_dollars << endl;
   cout << "\tExperience Points: " << experience_points << endl;
   cout << endl;

}

bool Pokemon::Update()
{
    

    switch (state)
    {
        case STOPPED:
        {
            if (IsExhausted())
            {
                state = EXHAUSTED;
                return true;
            }
            else
            {
            return false;
            }
        }

        case MOVING:
        {
            if (UpdateLocation() && IsExhausted() == false)
            {
                state = STOPPED;
                return true;
            }
            else
            {
                if (IsExhausted())
                {
                    state = EXHAUSTED;
                    return true;
                }
                else
                {
                    // if (state == IN_GYM)
                    // {
                    //     current_gym->RemoveOnePokemon();
                    // }
                    
                    // if (state == IN_CENTER)
                    // {
                    //     current_center->RemoveOnePokemon();
                    // }
                    
                    state = MOVING;
                    return false;
                }
            }
        }

        case MOVING_TO_CENTER:
        {
            if (UpdateLocation() && IsExhausted() == false)
            {
                state = IN_CENTER;
                current_center->AddOnePokemon();
                return true;
            }
            else
            {
                if (IsExhausted())
                {
                    state = EXHAUSTED;
                    return true;
                }
                else
                {
                    state = MOVING_TO_CENTER;
                    return false;
                }
                
            }
        }

        case MOVING_TO_GYM:
        {
            if (UpdateLocation() && IsExhausted() == false)
            {
                state = IN_GYM;
                current_gym->AddOnePokemon();
                return true;
            }
            else
            {
                if (IsExhausted())
                {
                    state = EXHAUSTED;
                    return true;
                }
                else
                {
                    state = MOVING_TO_GYM;
                    return false;
                }
            }
            
        }

        case IN_CENTER:
        {
            if (IsExhausted())
            {
                state = EXHAUSTED;
                current_center->RemoveOnePokemon();
                return true;
            }
            else
            {
                return false;
            }
        }

        case IN_GYM:
        {
            if (IsExhausted())
            {
                state = EXHAUSTED;
                current_gym->RemoveOnePokemon();
                return true;
            }
            else
            {
                return false;
            }
        }

        case TRAINING_IN_GYM:
        {
            unsigned int experience_points_gained = current_gym->TrainPokemon(training_units_to_buy);
            unsigned int stamina_points_used = current_gym->GetStaminaCost(training_units_to_buy);

            stamina -= stamina_points_used;
            pokemon_dollars -= current_gym->GetDollarCost(training_units_to_buy);
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

            if (IsExhausted())
            {
                state = EXHAUSTED;
                return true;
            }
            else
            {
                state = IN_GYM;
                return true;     
            }
            
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

        default: 
        {
            return false;
        }

    }
}

bool Pokemon::UpdateLocation()
{
    if (IsExhausted() == true)
    {
         cout << this->display_code << this->id_num << ": is exhausted..." << endl;
        return false;
    }
    else if (fabs(this->location.x - this->destination.x) <= fabs(this->delta.x) && fabs(this->location.y - this->destination.y) <= fabs(this->delta.y))
    {
        cout << this->display_code << this->id_num << ": I'm there!" << endl;
        this->location.x = this->destination.x;
        this->location.y = this->destination.y;
        return true;
    }
    else
    {
        cout << this->display_code << this->id_num << ": step..." << endl;
        this->location.x += delta.x;
        this->location.y += delta.y;
        stamina -= 1;
        pokemon_dollars += GetRandomAmountOfPokemonDollars();
        return false;
    }
}

void Pokemon::SetupDestination(Point2D dest)
{
    destination = dest;

    if (GetDistanceBetween(this->destination, this->location) != 0)
    {
        this->delta.x = (destination.x - location.x) * (speed / GetDistanceBetween(this->destination, this->location));
        this->delta.y = (destination.y - location.y) * (speed / GetDistanceBetween(this->destination, this->location));
    }
    else
    {
        delta.x = 0;
        delta.y = 0;
    }
    
}

string Pokemon::getName()
{
    return this->name;
}

double GetRandomAmountOfPokemonDollars()
{
    return ((double) round( (  ( (double)rand() / RAND_MAX) * (2 - 0) * 100)) / 100);
}