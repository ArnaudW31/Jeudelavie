#ifndef GRILLE_HPP
#define GRILLE_HPP
#include <vector>
#include <string>
#include "Case.hpp"

class Grille{

    private:
        std::vector<std::vector<Case>> grid;
        int longueur;
        int largeur;
        bool tore;
    public:

        Grille();

        Grille(int longueur, int largeur, bool _tore, std::string param="");

        void changeCase(Case c, int posx,int posy);

        std::vector<std::vector<Case>> &getGrid();

        Case &getCase(int x, int y);

        void nextIteration();

        void nextIteration(int nbIte);

        void afficher();

        void afficherStats();

        std::string toString();
};

#endif