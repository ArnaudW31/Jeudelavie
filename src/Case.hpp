#ifndef Case_HPP
#define Case_HPP

class Case{
    private:
        int nb_voisins;
        bool alive;

    public:
        Case();

        Case(bool status);

        ~Case();

        void setNbVoisins(int nb);

        void setStatus(bool state);

        int getNbVoisins();

        bool getStatus();

};

#endif