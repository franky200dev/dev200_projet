#include "LectureFichier.h"
#include "RectangularVectors.h"
#include <sstream>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
namespace algo
{

	LectureFichier::LectureFichier(vector<vector<int>> const &tabFichier)
	{
	      	m_tabFichier = tabFichier;
	        m_hauteur =  tabFichier.size();
		m_longueur =  tabFichier[0].size();



	}

	int LectureFichier::getLongueur()
	{
		return m_longueur;
	}

	int LectureFichier::getHauteur()
	{
		return m_hauteur;
	}

	vector<vector<int>> LectureFichier::getTab()
	{
		return m_tabFichier;
	}
 // cette fonction permet d'afficher le contenu de m_tabFichier
	void LectureFichier::afficher()
	{
		for (auto tab : m_tabFichier)
		{
			for (auto elem : tab)
			{
				cout << "\t" << elem;
			}
			cout << std::endl;
		}
                
                
	}
        //const string &nomFichier

	LectureFichier::LectureFichier(const string &nomFichier) {
              cout<<"path : " <<nomFichier<<endl;
                vector<vector<int>> stockLigne;
               ifstream monFlux(nomFichier);
                if(monFlux){
                   
                string ligne;
                printf("ligne par ligne\n");
                while(getline(monFlux,ligne))
                {
                    istringstream tmp(ligne);
                    vector<int> row;
                    while(getline(tmp,ligne, ';'))
                    {
                        istringstream iss(ligne);
                        int val = 0;
                        iss >> val;
                        row.push_back(val);
                    }
                    stockLigne.push_back(row);
                }

     }
                 else
                     cout<<"impossible d'ouvrir le fichier" <<endl;
//               stockLigne.push_back(monFlux);
                m_longueur = stockLigne[0].size(); // la je me place sur la largeur de la matrice car elle est de dimension
		m_hauteur = stockLigne.size(); // ici j'ai hauteur de la matrice qui represente la taille de la matrice
		m_tabFichier = RectangularVectors::RectangularIntVectors(m_hauteur, m_longueur); //c'est le tableau qui contient tous mes fichiers
		for (int i = 0;i < m_hauteur;i++)
		{
			for (int j = 0;j < m_longueur;j++)
			{
				m_tabFichier[i][j] = stockLigne[i][j]; // ici je stock toute les de mon  fichier dans getLigne
			}          
        }  
        }
        
		

		
        void LectureFichier::sauvegarder(const string &sortie)
	{
            ofstream monFlux(sortie);
            if(monFlux)
            {
                for(int i = 0; i < m_hauteur; ++i)
                {
                    monFlux << m_tabFichier[i][0];
                    for(int j = 1; j < m_longueur; ++j)
                        monFlux << "; " << m_tabFichier[i][j];
                    monFlux << std::endl;
                }
            }
             else
                cout << "Impossible d'ouvrir le fichier." << endl;   
            
        }

//Convertir un entier en string
string convertInt(int nombre)
{
   stringstream ss; ss << nombre;return ss.str();
}


		
		
	}
