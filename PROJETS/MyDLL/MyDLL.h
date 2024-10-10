/**
 * @file MyDLL.h
 * @brief Déclarations pour la DLL MyDLL.
 *
 * Ce fichier contient les déclarations de la classe CMyDLLApp et de ses méthodes.
 *
 * @author
 * Thierry RICHOL
 */

 /**
  * @class CMyDLLApp
  * @brief Classe principale pour la DLL MyDLL.
  *
  * Cette classe fournit des fonctionnalités pour générer une liste de villes aléatoires.
  */

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'pch.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"	
#include <vector>
#include <atlstr.h> 
#include <algorithm>
#include <random>
#include <stdexcept>

#ifdef MYDLL_EXPORTS
#define MYDLL_API __declspec(dllexport)
#else
#define MYDLL_API __declspec(dllimport)
#endif


class MYDLL_API CMyDLLApp 
{
public:
	/**
	 * @brief Constructeur par défaut.
	 */
	CMyDLLApp();

	/**
	 * @brief Génère une liste de villes aléatoires.
	 *
	 * @return Un vecteur de CString contenant les noms des villes.
	 */
	std::vector<CString> randomCity();

private:
	/// Liste des chaînes prédéfinies représentant les villes.
	std::vector<CString> m_Cities;
};
