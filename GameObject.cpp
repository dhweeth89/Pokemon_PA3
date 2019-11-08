#include <iostream>
#include "GameObject.h"
#include "Vector2D.h"
#include "Point2D.h"

using namespace std;

GameObject::GameObject(char in_code)
{
    display_code = in_code;
    id_num = 1;
    location = Point2D();
    state = 0;
    cout << "GameObject constructed" << endl;
}

GameObject::GameObject(Point2D in_loc, int in_id, char in_code)
{
    display_code = in_code;
    id_num = in_id;
    location = in_loc;
    state = 0;

    cout << "GameObject constructed" << endl;
}
        
//Functions
Point2D GameObject::GetLocation()
{
    return location;
}

int GameObject::GetId()
{
    return id_num;
}

char GameObject::GetState()
{
    return state;
}

void GameObject::ShowStatus()
{
    cout << display_code << " status: " << id_num << " at " << location << endl;
}


//Will add pure virtual functions later