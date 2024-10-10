/// @file MyMFCDlg.cpp
/// @brief Implémentation de la boîte de dialogue principale de l'application MFC.
///
/// Ce fichier contient les implémentations des méthodes de la classe CMyMFCDlg, qui gère la boîte de dialogue principale de l'application.
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

#include "pch.h"
#include "framework.h"
#include "MyMFC.h"
#include "MyMFCDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// boîte de dialogue CAboutDlg utilisée pour la boîte de dialogue 'À propos de' pour votre application
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Données de boîte de dialogue
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // Prise en charge de DDX/DDV

// Implémentation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// boîte de dialogue de CMyMFCDlg



CMyMFCDlg::CMyMFCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MYMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO3, m_ComboBox);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}

BEGIN_MESSAGE_MAP(CMyMFCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMyMFCDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// gestionnaires de messages de CMyMFCDlg
BOOL CMyMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// IDM_ABOUTBOX doit se trouver dans la plage des commandes système.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Définir l'icône de cette boîte de dialogue.  L'infrastructure effectue cela automatiquement
	//  lorsque la fenêtre principale de l'application n'est pas une boîte de dialogue
	SetIcon(m_hIcon, TRUE);			// Définir une grande icône
	SetIcon(m_hIcon, FALSE);		// Définir une petite icône

	// TODO: ajoutez ici une initialisation supplémentaire



	// Remplir la ComboBox avec la liste de chaînes
	m_edit.SetWindowTextW(_T(""));
	randomization();

	return TRUE;  // retourne TRUE, sauf si vous avez défini le focus sur un contrôle
}

void CMyMFCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// Si vous ajoutez un bouton Réduire à votre boîte de dialogue, vous devez utiliser le code ci-dessous
//  pour dessiner l'icône.  Pour les applications MFC utilisant le modèle Document/Vue,
//  cela est fait automatiquement par l'infrastructure.

void CMyMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // contexte de périphérique pour la peinture

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Centrer l'icône dans le rectangle client
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Dessiner l'icône
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// Le système appelle cette fonction pour obtenir le curseur à afficher lorsque l'utilisateur fait glisser
//  la fenêtre réduite.
HCURSOR CMyMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyMFCDlg::OnBnClickedOk()
{
	// Obtenir l'index de l'élément sélectionné dans la ComboBox
	int nSel = m_ComboBox.GetCurSel();
	if (nSel != CB_ERR) // Vérifier si un élément est sélectionné
	{
		CString strSelectedText;
		// Obtenir le texte de l'élément sélectionné
		m_ComboBox.GetLBText(nSel, strSelectedText);
		// Re randomisation de la liste
		randomization();

		
		// Définir le texte dans le contrôle d'édition
        strSelectedText = (CString("Vous avez choisi : ") + strSelectedText + CString(". La combo va etre de nouveau randomis\u00e9e!"));
		m_edit.SetWindowTextW(strSelectedText);

		
	}
	else
	{
		// Aucun élément n'est sélectionné, vous pouvez gérer ce cas ici
		m_edit.SetWindowTextW(_T("Aucun \u00e9l\u00e9ment s\u00e9lectionn\u00e9"));
	}
}



void CMyMFCDlg::randomization()
{
	m_ComboBox.ResetContent();  // Clear the combo box
	m_StringList = myDLLApp.randomCity();
	for (const auto& str : m_StringList)
	{
		m_ComboBox.AddString(str);  // Add each string to the combo box
	}
	m_ComboBox.Invalidate();
	m_ComboBox.UpdateWindow();
}

void CMyMFCDlg::display()
{
	int count = m_ComboBox.GetCount();
	// Afficher le nombre d'éléments dans la console de débogage
	TRACE(_T("\n---------------------------------------------------------"));
	TRACE(_T("\nrandomization()"));
	TRACE(_T("Nombre d'éléments dans la ComboBox : %d\n"), count);// Afficher le texte de chaque élément dans la console de débogage
	for (int i = 0; i < count; ++i)
	{
		CString strText;
		m_ComboBox.GetLBText(i, strText);
		TRACE(_T("Élément %d : %s\n"), i, strText);
	}
}
