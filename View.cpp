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

 static const int view_maxsize = 20;

    private:

    int size;
    double scale;
    Point2D origin;
    char grid[view_maxsize][view_maxsize][2];
    
    
    bool GetSubscripts(int&, int&, Point2D);

    public:

    View();
    void Clear();
    void Plot(GameObject * ptr);

    void Draw();

*/

View::View()
{
    size = 11;
    scale = 2;
    origin = Point2D();
}

bool View::GetSubscripts(int& out_x, int& out_y, Point2D location)
{
    
    
    out_x = (int) ((location.x - origin.x) / scale);
    out_y = (int) ((location.y - origin.y) / scale);

    if (out_x <= view_maxsize || out_y <= view_maxsize)
    {
        return true;
    }
    else
    {
        cout << "An object is outside the display" << endl;
        return false;
    }
    
}

void View::Clear()
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << ". ";
        }
        cout << endl;
        cout << endl;
    }
}

void View::Plot(GameObject *ptr)
{
    int point_x = ptr->GetLocation().x;
    int point_y = ptr->GetLocation().y; 
}

