// Manager.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "Manager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CManager dialog


CManager::CManager(CWnd* pParent /*=NULL*/)
	: CDialog(CManager::IDD, pParent)
{
	//{{AFX_DATA_INIT(CManager)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CManager::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CManager)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CManager, CDialog)
	//{{AFX_MSG_MAP(CManager)
	ON_BN_CLICKED(IDC_EXIT_MANAGE, OnExitManage)
	ON_BN_CLICKED(IDC_BOOKIN, OnBookin)
	ON_BN_CLICKED(IDC_QUERY, OnQuery)
	ON_BN_CLICKED(IDC_BORROW, OnBorrow)
	ON_BN_CLICKED(IDC_RETURN, OnReturn)
	ON_BN_CLICKED(IDC_CARD, OnCard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CManager message handlers

void CManager::OnExitManage() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CManager::OnBookin() 
{
	// TODO: Add your control notification handler code here
	BookIn.DoModal();
}

void CManager::OnQuery() 
{
	// TODO: Add your control notification handler code here
	BookQ.DoModal();
}

void CManager::OnBorrow() 
{
	// TODO: Add your control notification handler code here
	Borrow.DoModal();
}

void CManager::OnReturn() 
{
	// TODO: Add your control notification handler code here
	Return.DoModal();
}

void CManager::OnCard() 
{
	// TODO: Add your control notification handler code here
	CardMng.DoModal();
}

