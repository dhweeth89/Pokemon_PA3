#include <iostream>
#include "GameObject.h"
#include "Vector2D.h"
#include "Point2D.h"
#include "Building.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"

int main()
{
//Point Testing
    Point2D p1 = Point2D();
    Point2D p2 = Point2D(3.7, 4.5);
    Point2D p3 = Point2D(4.8, 11.3);

    cout << "p1 is " << p1 << endl;
    cout << "p2 is " << p2 << endl;
    cout << "p3 is " << p3 << endl;

    cout << "p2 + p3 is " << p2 + p3 << endl;
    cout << "p2 - p3 is " << p2 - p3 << endl;
    cout << "Distance between p2 and p3 is " << GetDistanceBetween(p2, p3) << endl;

//Vector Testing
    Vector2D v1 = Vector2D();
    Vector2D v2 = Vector2D(7.3, 8.5);
    Vector2D v3 = Vector2D(9.2, 4.7);
    
    cout << "v1 is " << v1 << endl;
    cout << "v2 is " << v2 << endl;

    cout << "v2 * 7 is " << v2 * 7 << endl;
    cout << "v2 * 3.3 is " << v2 * 3.3 << endl;

    cout << "v2 / 3.3 is " << v2 / 3.3 << endl;
    cout << "v2 / 0.5 is " << v2 / 0.5 << endl; 


//GameObject testing

    GameObject Player1 = GameObject('P');
    GameObject Player2 = GameObject(p1, 2, 'B');
    GameObject Player3 = GameObject(p2, 3, 'S');

    cout << "Player1 Id is " << Player1.GetId() << endl;
    cout << "Player1 Location is " << Player1.GetLocation() << endl;
    cout << "Player1 State is " << Player1.GetState() << endl;
    Player1.ShowStatus(); 

    cout << "Player2 Id is " << Player2.GetId() << endl;
    cout << "Player2 Location is " << Player2.GetLocation() << endl;
    cout << "Player2 State is " << Player2.GetState() << endl;
    Player2.ShowStatus(); 

    cout << "Player3 Id is " << Player3.GetId() << endl;
    cout << "Player3 Location is " << Player3.GetLocation() << endl;
    cout << "Player3 State is " << Player3.GetState() << endl;
    Player3.ShowStatus(); 





//Building testing

    Building Building1 = Building();
    Building Building2 = Building('B', 2, Point2D());
    Building Building3 = Building('B', 3, Point2D(3.3, 7.7));

    cout << "Is Building 1 visible? " << Building1.ShouldBeVisible() << endl;
    cout << "Is Building 2 visible? " << Building2.ShouldBeVisible() << endl;
    cout << "Is Building 3 visible? " << Building3.ShouldBeVisible() << endl;

    //Show Building statuses

    Building1.ShowStatus();
    Building2.ShowStatus();
    Building3.ShowStatus();

    //Adding Pokemon to buildings 1 and 2; 3 should remain 0
    Building1.AddOnePokemon();
    Building1.AddOnePokemon();

    Building2.AddOnePokemon();

    //Show building statuses again

    Building1.ShowStatus();
    Building2.ShowStatus();
    Building3.ShowStatus();

    //Remove 1 Pokemon only from Building 1

    Building1.RemoveOnePokemon();

    //Show building statuses again

    Building1.ShowStatus();
    Building2.ShowStatus();
    Building3.ShowStatus();

    //Remove 1 Pokemon from both Building 1 and Building 2

    Building1.RemoveOnePokemon();
    Building2.RemoveOnePokemon();

    //Show building statuses again

    Building1.ShowStatus();
    Building2.ShowStatus();
    Building3.ShowStatus();

    //Test for Building3 Remove a Pokemon; Should keep Building count at 0, not negative

    Building1.RemoveOnePokemon();
    Building2.RemoveOnePokemon();
    Building3.RemoveOnePokemon();

    //Show building statuses again

    Building1.ShowStatus();
    Building2.ShowStatus();
    Building3.ShowStatus();





//Testing PokemonCenter class

    PokemonCenter Center1 = PokemonCenter();
    PokemonCenter Center2 = PokemonCenter(2, Point2D());
    PokemonCenter Center3 = PokemonCenter(3, Point2D(9.85, 3.7));

    //Test PokemonCenter visibility
    cout << "Is Center 1 visible? " << Center1.ShouldBeVisible() << endl;
    cout << "Is Center 2 visible? " << Center2.ShouldBeVisible() << endl;
    cout << "Is Center 3 visible? " << Center3.ShouldBeVisible() << endl;

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();

    //Add Pokemon to Centers 1 and 2
    Center1.AddOnePokemon();
    Center2.AddOnePokemon();

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update();
    Center2.Update();
    Center3.Update();

    //Remove Pokemon from all Centers to see if it goes to negative
    Center1.RemoveOnePokemon();
    Center2.RemoveOnePokemon();
    Center3.RemoveOnePokemon();

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();

    //Tests Stamina Points
    cout << "Does Center 1 have stamina points? " << Center1.HasStaminaPoints() << endl;
    cout << "Center 1 has " << Center1.GetNumStaminaPointsRemaining() << endl;
    cout << "Does Center 2 have stamina points? " << Center2.HasStaminaPoints() << endl;
    cout << "Center 2 has " << Center2.GetNumStaminaPointsRemaining() << endl;
    cout << "Does Center 3 have stamina points? " << Center3.HasStaminaPoints() << endl;
    cout << "Center 3 has " << Center3.GetNumStaminaPointsRemaining() << endl;

    //Tests bool CanAffordStaminaPoints(unsigned int dollar_cost is 5, double budget);

    cout << "Can a user with budget 25 afford 5 stamina points at Center 1? " << Center1.CanAffordStaminaPoints(5, 25) << endl;
    cout << "Can a user with budget 25 afford 5 stamina points at Center 2? " << Center2.CanAffordStaminaPoints(5, 25) << endl;
    cout << "Can a user with budget 25 afford 5 stamina points at Center 3? " << Center3.CanAffordStaminaPoints(5, 25) << endl;

    cout << "Can a user with budget 25 afford 4 stamina points at Center 1? " << Center1.CanAffordStaminaPoints(4, 25) << endl;
    cout << "Can a user with budget 25 afford 4 stamina points at Center 2? " << Center2.CanAffordStaminaPoints(4, 25) << endl;
    cout << "Can a user with budget 25 afford 4 stamina points at Center 3? " << Center3.CanAffordStaminaPoints(4, 25) << endl;

    cout << "Can a user with budget 15 afford 5 stamina points at Center 1? " << Center1.CanAffordStaminaPoints(5, 15) << endl;
    cout << "Can a user with budget 15 afford 5 stamina points at Center 2? " << Center2.CanAffordStaminaPoints(5, 15) << endl;
    cout << "Can a user with budget 15 afford 5 stamina points at Center 3? " << Center3.CanAffordStaminaPoints(5, 15) << endl;

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();

    //Tests double GetDollarCost(unsigned int); 
    cout << "Cost at Center 1 to get 3 stamina points? " << Center1.GetDollarCost(3) << endl;
    cout << "Cost at Center 2 to get 3 stamina points? " << Center2.GetDollarCost(3) << endl;
    cout << "Cost at Center 3 to get 3 stamina points? " << Center3.GetDollarCost(3) << endl;
    
    cout << "Cost at Center 1 to get 5 stamina points? " << Center1.GetDollarCost(5) << endl;
    cout << "Cost at Center 2 to get 5 stamina points? " << Center2.GetDollarCost(5) << endl;
    cout << "Cost at Center 3 to get 5 stamina points? " << Center3.GetDollarCost(5) << endl;
    
    cout << "Cost at Center 1 to get 1 stamina point? " << Center1.GetDollarCost(1) << endl;
    cout << "Cost at Center 2 to get 1 stamina point? " << Center2.GetDollarCost(1) << endl;
    cout << "Cost at Center 3 to get 1 stamina point? " << Center3.GetDollarCost(1) << endl;
    
    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();


    //Test unsigned int DistributeStamina(unsigned int) Stamina Capacity is 100;
    cout << "Taking " << Center1.DistributeStamina(20) << " stamina out of Center 1" << endl;
    cout << "Taking " << Center2.DistributeStamina(35) << " stamina out of Center 2" << endl;
    cout << "Taking " << Center3.DistributeStamina(41) << " stamina out of Center 3" << endl;

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();
    
    //Test unsigned int DistributeStamina(unsigned int) Stamina Capacity is 100;
    cout << "Taking " << Center1.DistributeStamina(80) << " stamina out of Center 1" << endl;
    cout << "Taking " << Center2.DistributeStamina(80) << " stamina out of Center 2 even though asked for 80 because unsigned int" << endl;
    cout << "Taking " << Center3.DistributeStamina(50) << " stamina out of Center 3" << endl;

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update(); 
    Center2.Update();
    Center3.Update();

    //Test unsigned int DistributeStamina(unsigned int) Stamina Capacity is 100;
    cout << "Taking " << Center1.DistributeStamina(30) << " stamina out of Center 1 even though asked for 30 because unsigned int" << endl;
    cout << "Taking " << Center2.DistributeStamina(35) << " stamina out of Center 2 even though asked for 35 because unsigned int" << endl;
    cout << "Taking " << Center3.DistributeStamina(41) << " stamina out of Center 3 even though asked for 41 because unsigned int" << endl;

    //Shows status of Center
    Center1.ShowStatus();
    Center2.ShowStatus();
    Center3.ShowStatus();

    //Tells whether Center was updated
    Center1.Update();
    Center2.Update();
    Center3.Update();

//Testing PokemonGym
    PokemonGym gym1 = PokemonGym();
    PokemonGym gym2 = PokemonGym(20, 2, 5, 3, 2, Point2D());
    PokemonGym gym3 = PokemonGym(25, 5, 10, 5, 3, Point2D(5, 7.3));

    //Dollar cost
    
    cout << "Pokemon Gym1 dollar cost for 1 unit: " << gym1.GetDollarCost(1) << endl;
    cout << "Pokemon Gym1 dollar cost for 2 units: " << gym1.GetDollarCost(2) << endl;

    cout << endl;

    cout << "Pokemon Gym2 dollar cost for 1 unit: " << gym2.GetDollarCost(1) << endl;
    cout << "Pokemon Gym2 dollar cost for 2 units: " << gym2.GetDollarCost(2) << endl;
    

    cout << endl;

    cout << "Pokemon Gym3 dollar cost for 1 unit: " << gym3.GetDollarCost(1) << endl;
    cout << "Pokemon Gym3 dollar cost for 2 units: " << gym3.GetDollarCost(2) << endl;

    cout << endl;

    //Stamina Cost

    cout << "Pokemon Gym1 stamina cost for 1 unit: " << gym1.GetStaminaCost(1) << endl;
    cout << "Pokemon Gym1 stamina cost for 2 units: " << gym1.GetStaminaCost(2) << endl;

    cout << endl;

    cout << "Pokemon Gym2 stamina cost for 1 unit: " << gym2.GetStaminaCost(1) << endl;
    cout << "Pokemon Gym2 stamina cost for 2 units: " << gym2.GetStaminaCost(2) << endl;
    

    cout << endl;

    cout << "Pokemon Gym3 stamina cost for 1 unit: " << gym3.GetStaminaCost(1) << endl;
    cout << "Pokemon Gym3 stamina cost for 2 units: " << gym3.GetStaminaCost(2) << endl;

    cout << endl;

    //Get Remaining Training Units

    cout << "Pokemon Gym1 training units remaining: " << gym1.GetNumTrainingUnitsRemaining() << endl;
    cout << "Pokemon Gym2 training units remaining: " << gym2.GetNumTrainingUnitsRemaining() << endl;
    cout << "Pokemon Gym3 training units remaining" << gym3.GetNumTrainingUnitsRemaining() << endl;

    cout << endl;

    //Checking if Pokemon can train

    // PokemonGym gym1 = new PokemonGym();
    // PokemonGym gym2 = new PokemonGym(20, 2, 5, 3, 2, Point2D());
    // PokemonGym gym3 = new PokemonGym(25, 5, 10, 5, 3, Point2D(5, 7.3));


    cout << "Can a Pokemon with $20 and 5 stamina train for 4 units" << endl;

    cout << "At gym 1: " << gym1.IsAbleToTrain(4, 20, 5) << endl; //Stamina cost of 1, dollar cost of 1
    cout << "At gym 2: " << gym2.IsAbleToTrain(4, 20, 5) << endl; //Stamina cost of 2, dollar cost of 5
    cout << "At gym 3: " << gym3.IsAbleToTrain(4, 20, 5) << endl; //Stamina cost of 5, dollar cost of 10
    
    cout << endl;


    cout << "Can a Pokemon with $50 and 30 stamina train for 3 units" << endl;

    cout << "At gym 1: " << gym1.IsAbleToTrain(3, 50, 30) << endl; //Stamina cost of 1, dollar cost of 1
    cout << "At gym 2: " << gym2.IsAbleToTrain(3, 50, 30) << endl; //Stamina cost of 2, dollar cost of 5
    cout << "At gym 3: " << gym3.IsAbleToTrain(3, 50, 30) << endl; //Stamina cost of 5, dollar cost of 10
    
    cout << endl;

    //Update(), IsBeaten(), ShowStatus(), TrainPokemon(training_units)

    cout << "Each turn will consume 5 training points from each gym" << endl;

    gym1.ShowStatus();
    cout << endl;
    gym2.ShowStatus();
    cout << endl;
    gym3.ShowStatus();
    cout << endl;
    
    for (int i=0; i<5; i++)
    {
        cout << "Adding Pokemon to each gym" << endl;
        gym1.AddOnePokemon();
        gym2.AddOnePokemon();
        gym3.AddOnePokemon();

        gym1.TrainPokemon(5);
        gym2.TrainPokemon(5);
        gym3.TrainPokemon(5);


        cout << "Is gym 1 beaten? " << gym1.IsBeaten() << endl;
        cout << "Is gym 2 beaten? " << gym2.IsBeaten() << endl;
        cout << "Is gym 3 beaten? " << gym3.IsBeaten() << endl;

        cout << endl;
        cout << "Reiterating using Update()" << endl;

        gym1.Update();
        gym2.Update();
        gym3.Update();

        cout << endl;
        cout << "The status for each gym:" << endl;
        cout << endl;

        gym1.ShowStatus();
        cout << endl;
        gym2.ShowStatus();
        cout << endl;
        gym3.ShowStatus();
        cout << endl;
    }

    cout << "Removing one pokemon from each gym" << endl;
    gym1.RemoveOnePokemon();
    gym2.RemoveOnePokemon();
    gym3.RemoveOnePokemon();

    gym1.ShowStatus();
    cout << endl;
    gym2.ShowStatus();
    cout << endl;
    gym3.ShowStatus();
    cout << endl;    


    return 0;
}