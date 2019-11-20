#include "Point2D.h"
#include "Vector2D.h"
#include "GameObject.h"
#include "PokemonCenter.h"
#include "PokemonGym.h"
#include "Pokemon.h"
#include "Model.h"
#include <iostream>
#include "string.h"
#include "math.h"

using namespace std;

/*

    private:

    int time;
    GameObject* object_ptrs[10];
    int num_objects;
    Pokemon* pokemon_ptrs[10];
    int num_pokemon;
    PokemonCenter* center_ptrs[10];
    int num_centers;
    PokemonGym* gym_ptrs[10];
    int num_gyms;

    public:

    Model();
    ~Model();
    Pokemon* GetPokemonPtr(int id);
    PokemonCenter* GetPokemonCenterPtr(int id);
    PokemonGym* GetPokemonGymPtr(int id);
    bool Update();
    //void Display(View& view);
    void ShowStatus();

    */

   Model::Model()
   {
       time = 0;
       
       //Pokemon::Pokemon(string in_name, int in_id, char in_code, unsigned int in_speed, Point2D in_loc)
       
       Pokemon* p1 = new Pokemon("Pikachu", 1, 'P', 5, Point2D(5,1));
       Pokemon* p2 = new Pokemon("Squirtle", 2, 'P', 7, Point2D(10,1));

       //int in_Id, Point2D in_loc
       PokemonCenter* c1 = new PokemonCenter(1, Point2D(1,20));
       PokemonCenter* c2 = new PokemonCenter(2, Point2D(10,20));
       
       /*PokemonGym::PokemonGym(unsigned int max_training_units, unsigned int stamina_cost, double dollar_cost, 
unsigned int exp_points_per_unit, int in_id, Point2D in_loc) : Building('G', in_id, in_loc)*/

       PokemonGym* g1 = new PokemonGym();
       PokemonGym* g2 = new PokemonGym(25, 3, 1.8, 4, 2, Point2D(5,5) );

       num_objects = 6;
       num_pokemon = 2;
       num_centers = 2;
       num_gyms = 2;

       object_ptrs[0] = p1;
       pokemon_ptrs[0] = p1;

       object_ptrs[1] = p2;
       pokemon_ptrs[1] = p2;
       
       object_ptrs[2] = c1;
       center_ptrs[0] = c1;

       object_ptrs[3] = c2;
       center_ptrs[1] = c2;

       object_ptrs[4] = g1;
       gym_ptrs[0] = g1;

       object_ptrs[5] = g2;
       gym_ptrs[1] = g2;

       cout << "Model default constructed" << endl;
   }

   Model::~Model()
   {
       for (int i = 0; i < 6; i++)
       {
           delete object_ptrs[i];
       }

       cout << "Model destructed." << endl;
   }

   Pokemon* Model::GetPokemonPtr(int id)
   {

   }

   PokemonCenter* Model::GetPokemonCenterPtr(int id)
   {

   }

   PokemonGym* Model::GetPokemonGymPtr(int id)
   {

   }

   bool Model::Update()
   {

   }

/*
   void Model::Display(View& view)
   {

   }
*/

   void Model::ShowStatus()
   {

   }