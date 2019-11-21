#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <iostream>
#include "Vector2D.h"
#include "Point2D.h"

using namespace std;

class GameObject
{
    protected:
        //Class variables
        Point2D location;
        int id_num;
        char display_code; 
        char state;

    public:
        //Constructors
        GameObject(char);
        GameObject(Point2D, int, char);
        virtual ~GameObject();
        void DrawSelf(char *);
        
        //Functions
        Point2D GetLocation();
        int GetId();
        char GetState();
        void ShowStatus();
        virtual bool Update() = 0;
        virtual void ShowStatus();
        virtual bool ShouldBeVisible() = 0;

};

//Will add pure virtual functions later

#endif