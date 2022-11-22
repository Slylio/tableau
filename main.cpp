#include <tableau.h>
int main(){
    Tableau<double> t0; //Création d’un tableau vide
    Tableau<int> t1(3); //Création d’un tableau de 3 éléments
    //Création d’un tableau de 5 éléments initialisés à 2,3,4,6,6
    Tableau<double> t2 = {2, 3, 4, 6, 6};
    t2[3]=5;
    std::cout<<t2[3]<<std::endl;
    //Création d’un tableau de 3 éléments initialisés à 7,8,9
    const Tableau<int>* t3=new Tableau<int>(7,8,9);

    //Tableau<float> extr(2.,5.5,6.3,8.,9.9);

}