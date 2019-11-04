#ifndef POKEMONGYM_H
#define POKEMONGYM_H

    class PokemonGym : public Building
    {

        enum PokemonGymStates{
            NOT_BEATEN = 0,
            BEATEN = 1
        };

        private:

        double num_training_units_remaining;
        unsigned int max_number_of_training_units;
        unsigned int stamina_cost_per_training_unit;
        unsigned int dollar_cost_per_training_unit;
        unsigned int experience_points_per_training_unit;

        public:

        PokemonGym();
        PokemonGym(unsigned int, unsigned int, double, unsigned int, int, Point2D);


        double GetDollarCost(unsigned int);
        unsigned int GetStaminaCost(unsigned int);
        unsigned int GetNumTrainingUnitsRemaining();
        bool IsAbleToTrain(unsigned int, double, unsigned int);
        unsigned int TrainPokemon(unsigned int);
        bool Update();
        bool IsBeaten();
        void ShowStatus();        
    };
    
#endif