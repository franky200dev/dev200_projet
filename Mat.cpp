#include "Mat.h"
#include "LectureFichier.h"
#include "Convertisseur.h"
#include "RectangularVectors.h"

int main(int argc, char **argv)
{
    std::vector<std::string> args;
    for(int i = 0; i < argc; ++i)
        args.push_back(argv[i]);
    algo::Mat::main(args);
   
}

namespace algo
{
//	import static Integer.min;

	void Mat::main(std::vector<std::string> &args) 
	{
		// TODO code application logic here

		

		std::vector<int> tab;

		std::string entree = "";
		std::string sortie = "";
		int largeur = -1;
		int hauteur;
		bool sensConvert = true;
		for (int i = 0;i < args.size();i++)
		{
                    std::cout <<"arg : "<<args[i]<<std::endl;
			if (args[i] == "-i")
			{
				i++;
                                std::cout <<"arg : "<<args[i]<<std::endl;
				entree = args[i];
			}
			else if (args[i] == "-o")
			{
				i++;
				sortie = args[i];
			}
			else if (args[i] == "-b2l")
			{
				sensConvert = true;
			}
			else if (args[i] == "-l2b")
			{
				sensConvert = false;

			}
			else if (args[i] == "-w")
			{
				i++;
				largeur = std::stoi(args[i]);
			}
		}
		LectureFichier *f = new LectureFichier(entree);
		LectureFichier *f1 = nullptr;
		if (sensConvert == true)
		{
			Convertisseur *convert = new Convertisseur(f->getLongueur(),f->getHauteur());
			tab = convert->blockToLine(f->getTab());
			for (int elem : tab)
			{
				std::cout << "\t" << elem;
			}
				std::cout << std::endl;
				if (largeur <= 0)
				{
					largeur = f->getLongueur();
				}
				 f1 = new LectureFichier(pack(tab,largeur));

			delete convert;
		}
		else
		{
			if (largeur <= 0)
			{
				largeur = f->getLongueur();
			}
			hauteur = (f->getLongueur() * f->getHauteur() + largeur - 1) / largeur;
			Convertisseur *convert1 = new Convertisseur(largeur,hauteur);
			 f1 = new LectureFichier(convert1->lineToBlock(toLine(f->getTab())));

			delete convert1;
		}
		f1->sauvegarder(sortie);

		delete f1;
		delete f;
	}

	std::vector<std::vector<int>> Mat::pack(std::vector<int> &tab, int largeur)
	{

		std::vector<std::vector<int>> ret = RectangularVectors::RectangularIntVectors(( tab.size() + largeur - 1) / largeur, largeur);
		for (int i = 0;i < tab.size();i++)
		{
			ret[i / largeur][i % largeur] = tab[i];
		}
		return ret;
	}

	std::vector<int> Mat::toLine(std::vector<std::vector<int>> const &tab)
	{
		std::vector<int> ret(tab.size()*tab[0].size());
		for (int i = 0;i < tab.size();i++)
		{
			for (int j = 0;j < tab[0].size();j++)
			{
				ret[j + tab[0].size()*i] = tab[i][j];
			}
		}
		return ret;
	}
}
