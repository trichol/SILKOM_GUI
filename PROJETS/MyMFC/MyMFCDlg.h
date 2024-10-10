
/// @file MyMFCDlg.h
/// @brief Fichier d'en-tête pour la boîte de dialogue principale de l'application MFC.
///
/// Ce fichier contient les déclarations de la classe CMyMFCDlg, qui gère la boîte de dialogue principale de l'application.
///
/// @details
/// La classe CMyMFCDlg hérite de CDialogEx et fournit des fonctionnalités pour l'initialisation de la boîte de dialogue,
/// la gestion des événements et l'interaction avec l'utilisateur.
///
/// @note
/// Assurez-vous d'inclure 'pch.h' avant d'inclure ce fichier pour PCH.
///
/// @see CMyMFCDlg
///
/// @author
/// Thierry RICHOL

#pragma once

#include <afxwin.h>
#include <afxcmn.h>
#include <vector>

#include "MyDLL.h"

// boîte de dialogue de CMyMFCDlg
class CMyMFCDlg : public CDialogEx
{
// Construction
public:
	CMyMFCDlg(CWnd* pParent = nullptr);	// constructeur standard

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYMFC_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// Prise en charge de DDX/DDV


// Implémentation
protected:
	HICON m_hIcon;

	// Fonctions générées de la table des messages
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	std::vector<CString> m_StringList;  // Liste des chaînes pour remplir la combo box
	CMyDLLApp myDLLApp;
public:
	CComboBox m_ComboBox;
	CEdit m_edit;
	afx_msg void OnBnClickedOk();
	afx_msg void randomization();
	afx_msg void display();
};
