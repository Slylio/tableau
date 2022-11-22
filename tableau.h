#ifndef TABLEAU
#define TABLEAU
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
            std::cout<< "Construction d'un tableau vide de "<< tableSize <<" elements a l'adresse "<< &tableau <<"\n";
            size=tableSize;
            for (int i=0;i<size;i++){
                add(0);
            }
        }


        //Constructeur avec une liste
        Tableau(std::initializer_list<T> l){
            std::cout<< "Construction d'un tableau de " << l.size() << " elements a l'adresse "<< &tableau <<"\n";
            this->size=l.size();
             for (const auto& e : l){
                add(e);
             }
            //std::lock_guard(m);
        }

        
        template<class ... U>
        Tableau(U ... args):Tableau({args...}){}

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

        T& operator[](int i) const{
            return tableau[i];
        }

        T& operator()(int i) const{
            try {
                return tableau[i];
            } catch (const std::out_of_range& oor){
                std::cerr<<"Out of range error\n";
            }
        }
        private :
            T* tableau;
            int size;

};


#endif