#include "Grille.hpp"
#include <iostream>
#include <string>
#include <random>

Grille::Grille()
{
    this->grid = {};
    this->longueur = 0;
    this->largeur = 0;
}

Grille::Grille(int longueur, int largeur,bool _tore, std::string param)
{
    this->grid= {};
    this->longueur = longueur;
    this->largeur = largeur;
    this->tore=_tore;

    //le paramètre est optionnel mais si il est définit il permet de choisir sa configuration
    if(param=="")
    {
        for (int i = 0; i < largeur; i++)
        {
            this->grid.push_back({});
            for(int j = 0; j < longueur;j++)
            {
                //case vide
                this->grid.at(i).push_back(Case());
            }
        }
    }
    else if(param=="pleine")
    {
        for (int i = 0; i < largeur; i++)
        {
            this->grid.push_back({});
            for(int j = 0; j < longueur;j++)
            {
                //case pleine
                this->grid.at(i).push_back(Case(true));
            }
        }
    }
    else if(param=="damier")
    {
        for (int i = 0; i < largeur; i++)
        {
            this->grid.push_back({});
            for(int j = 0; j < longueur;j++)
            {
                if((i+j)%2==0)
                {
                    this->grid.at(i).push_back(Case(true));
                }
                else
                {
                    this->grid.at(i).push_back(Case(false));
                }
            }
        }
    }
    else if(param=="random")
    {
        for (int i = 0; i < largeur; i++)
        {
            this->grid.push_back({});
            for(int j = 0; j < longueur;j++)
            {
                
                int random_number = rand()%2;
                if(random_number==0)
                {
                    this->grid.at(i).push_back(Case(true));
                }
                else
                {
                    this->grid.at(i).push_back(Case(false));
                }
            }
        }
    }
    
}

void Grille::changeCase(Case c, int posx, int posy)
{
    this->grid.at(posy).at(posx) = c;
}

std::vector<std::vector<Case>> &Grille::getGrid()
{
    return this->grid;
}

Case &Grille::getCase(int x,int y)
{
    return this->grid.at(y).at(x);
}

void Grille::nextIteration()
{
    //remise à 0 du nombre de voisins de toutes les cases
    for (int a = 0; a < this->largeur; a++)
    {
        for(int b = 0; b < this->longueur; b++)
        {
            Case& temp = this->grid.at(a).at(b);
            temp.setNbVoisins(0);
            
        }
    }

    //calcul du nombre de voisins de chaque case
    for (int i = 0; i < largeur; i++)
    {
        for(int j = 0; j < longueur; j++)
        {
            Case c = grid.at(i).at(j);

            if(i>0 && j>0) //en haut à gauche
            { 
                if (this->grid.at(i-1).at(j-1).getStatus()) //si la cellule en haut à gauche est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(this->largeur-1).at(this->longueur-1).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(i>0) //en haut
            { 
                if (this->grid.at(i-1).at(j).getStatus()) //si la cellule en haut est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(this->largeur-1).at(j).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(i>0 && j<longueur-1) //en haut à droite
            { 
                if (this->grid.at(i-1).at(j+1).getStatus()) //si la cellule en haut à droite est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(this->largeur-1).at(0).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(j>0) //à gauche
            { 
                if (this->grid.at(i).at(j-1).getStatus()) //si la cellule à gauche est vivante
                {

                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(i).at(this->longueur-1).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(j<longueur-1) //à droite
            { 
                if (this->grid.at(i).at(j+1).getStatus()) //si la cellule à droite est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(i).at(0).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(i<largeur-1 && j>0) //en bas à gauche
            { 
                if (this->grid.at(i+1).at(j-1).getStatus()) //si la cellule en bas à gauche est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(0).at(this->longueur-1).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(i<largeur-1) //en bas
            { 
                if (this->grid.at(i+1).at(j).getStatus()) //si la cellule en bas est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(0).at(j).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }

            if(i<largeur-1 && j<longueur-1) //en bas à droite
            { 
                if (this->grid.at(i+1).at(j+1).getStatus()) //si la cellule en bas à droite est vivante
                {
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
                
            }
            else if(this->tore)
            {
                if (this->grid.at(0).at(0).getStatus()){
                    this->grid.at(i).at(j).setNbVoisins(this->grid.at(i).at(j).getNbVoisins()+1);
                }
            }
        }
    }

    //vérification du nb de voisins pour voir si elles sont en vie
    for (int k = 0; k < largeur; k++)
    {
        for(int l = 0; l < longueur; l++)
        {
            
            Case &c = grid.at(k).at(l);

            //si une case a 3 voisins
            if(c.getNbVoisins()==3)
            {
                c.setStatus(true);
            }
            //si une case a 2 ou 3 voisins et qu'elle est vivante
            else if((c.getNbVoisins()==2 ||c.getNbVoisins()==3) && c.getStatus()==true)
            {
                c.setStatus(true);
            }
            else{
                c.setStatus(false);
            }
        }
    }
}

void Grille::nextIteration(int nbIte)
{
    for (int ite = 0;ite < nbIte;ite++)
    {
        this->nextIteration();
        this->afficher();
    }
}

void Grille::afficher()
{
    std::string result = "";
    for (int i = 0; i < largeur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            if (this->grid.at(i).at(j).getStatus())
            {
                result = result + "1 ";
            }
            else{
                result = result + "0 ";
            }  
        }
        result = result + '\n';
    }
    std::cout << result << std::endl;
}

void Grille::afficherStats()
{
    float count = 0;
    for (int i = 0; i < largeur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            if(this->grid.at(i).at(j).getStatus())
            {
                count++;
            }
        }
    }

    float percent =(count/(longueur*largeur))*100;

    std::cout<<"Nombre de cellules en vie : "<<count<<std::endl;
    std::cout<<"Pourcentage de cellules en vie : "<<std::to_string(percent)<<std::endl;
}

std::string Grille::toString()
{
    std::string result = "";
    for (int i = 0; i < largeur; i++)
    {
        for (int j = 0; j < longueur; j++)
        {
            if (this->grid.at(i).at(j).getStatus())
            {
                result = result + "1 ";
            }
            else{
                result = result + "0 ";
            }  
        }
        result = result + '\n';
    }
    return result;
}
