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


	 
	/* @author fkamgaing
	 */
	class Mat
	{

		/**
		 * @param args the command line arguments
		 */
	public:
		static void main(std::vector<std::string> &args);

	public:
		static std::vector<std::vector<int>> pack(std::vector<int> &tab, int largeur);
		//
		static std::vector<int> toLine(std::vector<std::vector<int>> const &tab);

	};
}
