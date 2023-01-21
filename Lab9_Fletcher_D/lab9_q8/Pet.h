#ifndef PET_H
#define PET_H

#include <string>

class Pet
{
    private:
        std::string name;
        std::string species;
    public:
        Pet(std::string name, std::string species) {
            this->name = name;
            this->species = species;
        }
        std::string get_name() {
            return name;
        }
        std::string get_species() {
            return species;
        }
};
#endif