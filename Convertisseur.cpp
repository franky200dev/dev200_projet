#include "Convertisseur.h"
#include "RectangularVectors.h"

namespace algo
{
//	import static Integer.min;

	Convertisseur::Convertisseur(int longueur, int hauteur)
	{ // ici dans le contructeur j'initialise les attribut a utiliser
		m_longueur= longueur;
		m_hauteur = hauteur;

		m_depart = RectangularVectors::RectangularIntVectors(2, demiperim()); // 2 represente la largeur et demiperim c'est la distance qu'on parcours  donc longueur + hauteur cdans notre algorithme
		m_direction = RectangularVectors::RectangularIntVectors(2, demiperim());
		m_taille = std::vector<int>(demiperim());
		for (int i = 0;i < demiperim();i++)
		{
			m_taille[i] = std::min(std::min(i + 1,longueur),std::min(hauteur,demiperim() - i)); // la taille c'est minimum entre min(i+1,longueur) et min(hauteur,demiperim()-i)
			if (i % 2 == 0)
			{ // ici j'effectu le parcours  dans un sens ou dans l'autre
				m_direction[0][i] = -1;
				m_direction[1][i] = 1;

				if (i < longueur)
				{
					m_depart[0][i] = i;
					m_depart[1][i] = 0;
				}
				else
				{
					m_depart[0][i] = longueur - 1;
					m_depart[1][i] = i - (longueur - 1);
				}
			}
			else
			{
				m_direction[0][i] = 1;
				m_direction[1][i] = -1;
				if (i < hauteur)
				{
					m_depart[0][i] = 0;
					m_depart[1][i] = i;
				}
				else
				{
					m_depart[0][i] = i - (hauteur - 1);
					m_depart[1][i] = hauteur - 1;
				}
			}
		}

	}

	int Convertisseur::demiperim()
	{ // demi perim est juste la hauteur de parcours de la matrice
		return m_longueur + m_hauteur - 1;
	}

	std::vector<int> Convertisseur::blockToLine(std::vector<std::vector<int>> const &tab)
	{ // block to line est une fonction qui me permet de prendre traité qui est a deux dimension et de l'ecrirze a une seule diension
		std::vector<int> tableauRetour(m_longueur * m_hauteur);
		int index = 0;
		for (int i = 0;i < demiperim();i++)
		{
			for (int j = 0;j < m_taille[i];j++)
			{
				int x = m_depart[0][i] + j * m_direction[0][i];
				int y = m_depart[1][i] + j * m_direction[1][i];
				tableauRetour[index] = tab[y][x];
				index++;
			}
		}
		return tableauRetour;
	}

	std::vector<std::vector<int>> Convertisseur::lineToBlock(std::vector<int> const &tab)
	{ // prend un tableau d'une dimension et renvoi un tableau de tableau
		std::vector<std::vector<int>> tableauRetour = RectangularVectors::RectangularIntVectors(m_hauteur, m_longueur);
		int index = 0;
		for (int i = 0;i < demiperim();i++)
		{
			for (int j = 0;j < m_taille[i];j++)
			{
				int x = m_depart[0][i] + j * m_direction[0][i];
				int y = m_depart[1][i] + j * m_direction[1][i];
				tableauRetour[y][x] = tab[index];
				index++;
			}
		}
		return tableauRetour;
	}
}
