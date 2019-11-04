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

    cout << "Is Building 1 visible?" << Building1.ShouldBeVisible() << endl;
    cout << "Is Building 2 visible?" << Building2.ShouldBeVisible() << endl;
    cout << "Is Building 3 visible?" << Building3.ShouldBeVisible() << endl;

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

    return 0;
}