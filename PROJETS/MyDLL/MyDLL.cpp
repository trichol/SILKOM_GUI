/// @file MyDLL.cpp
/// @brief Définit les routines d'initialisation pour la DLL MyDLL.
///
/// Ce fichier contient les implémentations des méthodes de la classe CMyDLLApp.
///
/// @author
/// Thierry RICHOL

#include "pch.h"
#include "framework.h"
#include "MyDLL.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Construction de CMyDLLApp
CMyDLLApp::CMyDLLApp()
{
	m_Cities = { _T("Lyon"), _T("Marseille"), _T("St Etienne"), _T("Orange"), _T("Orl\u00e9ans"), _T("Strasbourg") };
}


// Implémentation de la fonction randomCity
std::vector<CString> CMyDLLApp::randomCity() 
{
    // Vérifie si la liste est vide, ce qui ne devrait pas arriver ici
    if (m_Cities.empty())
    {
        throw std::runtime_error("La liste des villes est vide. Impossible de proc\u00e9der au mélange.");
    }

    std::vector<CString> randomizedList = m_Cities; // Copie de la liste originale

    // Mélange aléatoire des éléments de la liste
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(randomizedList.begin(), randomizedList.end(), g);
    m_Cities = randomizedList;

    return m_Cities;
}
