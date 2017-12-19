#if !defined(AFX_BORROW_H__016E6AB3_30D4_4104_93E7_DA1A0E0767E1__INCLUDED_)
#define AFX_BORROW_H__016E6AB3_30D4_4104_93E7_DA1A0E0767E1__INCLUDED_

#include "ShowBook.h"	// Added by ClassView
#include "BorrowRS.h"	// Added by ClassView
#include "BookRS.h"	// Added by ClassView
#include "CardRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Borrow.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrow dialog

class CBorrow : public CDialog
{
// Construction
public:
	CBorrow(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBorrow)
	enum { IDD = IDD_BORROW };
	CString	m_BookID;
	CString	m_CardID;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrow)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBorrow)
	afx_msg void OnBorrowquery();
	afx_msg void OnBorrowsubmit();
	afx_msg void OnBorrowexit();
	afx_msg void OnClose();
	virtual BOOL OnInitDialog();
	
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CCardRS Card_rs;
	CShowBook ShowBook;
	CBorrowRS Borrow_rs;
	CBookRS Book_rs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROW_H__016E6AB3_30D4_4104_93E7_DA1A0E0767E1__INCLUDED_)
