#include <mutex>
#include <iostream>
#include <vector>
#include <initializer_list>
#include <list>

template <typename T=int>
class Tableau{
    //std::mutex m;
    public:
        //Constructeur par défaut
        Tableau(int tableSize=0){
            std::cout<< "Construction d'un tableau vide de "<< tableSize <<"a l'adresse "<< &tableau <<"\n";
            size=tableSize;
            for (int i=0;i<tableSize;i++){
                add(0);
            }
        }
        
        template<class ... U>
        Tableau(U ... args):Tableau({args...}){}

        //Constructeur avec une liste
        Tableau(std::initializer_list<T> l){
            std::cout<< "Construction de " << l.size() << " elements a l'adresse "<< &tableau <<"\n";
            this->size=l.size();
             for (const auto& e : l){
                add(e);
             }
            //std::lock_guard(m);
        }

        

        ~Tableau(){delete[] tableau;}

        void add(T e){
            tableau[size]=e;
        }

        const int taille(){
            return this->size;
        }

            
        void afficher(){
            for (int i=0; i<size;i++){
                std::cout<<tableau[i];
            }
            std::cout<<'\n';
        }

        private :
            T* tableau;
            int size;

};

int main(){
    Tableau<double> t0; //Création d’un tableau vide
    Tableau<int> t1(3); //Création d’un tableau de 3 éléments
    //Création d’un tableau de 5 éléments initialisés à 2,3,4,6,6
    Tableau<double> t2 = {2, 3, 4, 6, 6};
    //Création d’un tableau de 3 éléments initialisés à 7,8,9
    const Tableau<int>* t3=new Tableau<int>{7,8,9};
    //Tableau<float> extr(2.,5.5,6.3,8.,9.9);
}