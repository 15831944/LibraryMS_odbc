// LibraryManage.h : main header file for the LIBRARYMANAGE application
//

#if !defined(AFX_LIBRARYMANAGE_H__77F3B25C_0213_492F_80F0_BD1C8DEDAD66__INCLUDED_)
#define AFX_LIBRARYMANAGE_H__77F3B25C_0213_492F_80F0_BD1C8DEDAD66__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CLibraryManageApp:
// See LibraryManage.cpp for the implementation of this class
//
//CString CurAdminID;
class CLibraryManageApp : public CWinApp
{
public:
	CLibraryManageApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CLibraryManageApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CLibraryManageApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_LIBRARYMANAGE_H__77F3B25C_0213_492F_80F0_BD1C8DEDAD66__INCLUDED_)
