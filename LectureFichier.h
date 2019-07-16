#pragma once

#include <string>
#include <vector>
#include <iostream>

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
namespace algo
{


	/**
	 *
	 * @author fkamgaing
	 */
	class LectureFichier
	{


	private:
		std::vector<std::vector<int>> m_tabFichier;
		int m_longueur = 0;
		int m_hauteur = 0;


	public:
		LectureFichier(std::vector<std::vector<int>> const &tabFichier);
		virtual int getLongueur();
		virtual int getHauteur();
		virtual std::vector<std::vector<int>> getTab();

		virtual void afficher();
		LectureFichier(const std::string &nomFichier);
	// la fonction sauvegarder me permet de sauvegarder mon resultat et d'ecrire sur un fichier de sortie
		virtual void sauvegarder(const std::string &sortie);
	};

}
