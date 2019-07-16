#pragma once

#include <vector>

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
	class Convertisseur
	{ // la class convertisseur me converrti un tableau de tableau en un tableau et eccfectue aussi le parcours de la matrice zig-zag

	private:
		int m_longueur = 0; //represente la largeur de tableau
		int m_hauteur = 0; // c'est la hauteur comme son nom l'indice
	public:
		std::vector<std::vector<int>> m_depart; // ici j'ai la matrice de depart
		std::vector<std::vector<int>> m_direction; // direction de parcous de la matrice car elle s'effectue sur le demiu perimetre soit la longueur et la hauteur
		std::vector<int> m_taille; // taille  de la matrice a parcourir

		Convertisseur(int longueur, int hauteur);



	private:
		int demiperim();

	public:
		virtual std::vector<int> blockToLine(std::vector<std::vector<int>> const &tab);

		virtual std::vector<std::vector<int>> lineToBlock(std::vector<int> const &tab);




	};


}
