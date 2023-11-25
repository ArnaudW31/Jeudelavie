#ifndef GRILLE_HPP
#define GRILLE_HPP
#include <vector>
#include <string>
#include "Case.cpp"

class Grille{

    private:
        std::vector<std::vector<Case>> grid;
        int longueur;
        int largeur;
    public:

        Grille();

        Grille(int longueur, int largeur, std::string param="");

        void changeCase(Case c, int posx,int posy);

        std::vector<std::vector<Case>> getGrid();

        void nextIteration();

        void nextIteration(int nbIte);

        void afficher();

        void afficherStats();

        std::string toString();
};

#endif