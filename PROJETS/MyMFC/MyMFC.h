/// @file MyMFC.h
/// @brief Fichier d'en-tête principal de l'application SilkhomGUI.
///
/// Ce fichier contient les déclarations de la classe CMyMFCApp, qui est la classe principale de l'application MFC.
///
/// @details
/// Ce fichier inclut les symboles principaux et les déclarations nécessaires pour l'application MFC.
///
/// @note
/// Assurez-vous d'inclure 'pch.h' avant d'inclure ce fichier pour PCH.
///
/// @author
/// Thierry RICHOL

#pragma once

#ifndef __AFXWIN_H__
	#error "incluez 'pch.h' avant d'inclure ce fichier pour PCH"
#endif

#include "resource.h"		// symboles principaux


// CMyMFCApp :
// Consultez MyMFC.cpp pour l'implémentation de cette classe
//

class CMyMFCApp : public CWinApp
{
public:
	CMyMFCApp();

// Substitutions
public:
	virtual BOOL InitInstance();

// Implémentation

	DECLARE_MESSAGE_MAP()
};

extern CMyMFCApp theApp;
