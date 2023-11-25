#include "Case.hpp"
#include <iostream>

Case::Case()
{
    this->nb_voisins = 0;
    this->alive = false;
}

Case::Case(bool status)
{
    this->nb_voisins = 0;
    this->alive = status;
}

Case::~Case()
{

}

void Case::setNbVoisins(int nb)
{
    this->nb_voisins=nb;
}

void Case::setStatus(bool state)
{
    this->alive = state;
}

int Case::getNbVoisins()
{
    return this->nb_voisins;
}

bool Case::getStatus()
{
    return this->alive;
}

// int main()
// {
//     Case c = Case(50,false);
//     std::cout << c.getNbVoisins() << " " << c.getStatus() << std::endl;
//     return 0;
// }