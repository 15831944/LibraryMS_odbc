#if !defined(AFX_CARDMANAGE_H__93857425_62DD_4F81_A4FA_0B4587A186C5__INCLUDED_)
#define AFX_CARDMANAGE_H__93857425_62DD_4F81_A4FA_0B4587A186C5__INCLUDED_

#include "CardRS.h"	// Added by ClassView
#include "BorrowRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CardManage.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCardManage dialog

class CCardManage : public CDialog
{
// Construction
public:
	CCardManage(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCardManage)
	enum { IDD = IDD_CARDMANGER };
	CString	m_NewID;
	CString	m_IDtoDelete;
	CString	m_NewName;
	CString	m_NewType;
	CString	m_NewDept;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCardManage)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	
	// Generated message map functions
	//{{AFX_MSG(CCardManage)
	afx_msg void OnEnnewcard();
	afx_msg void OnClearcard();
	afx_msg void OnDeletecard();
	afx_msg void OnQuitcard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBorrowRS Borrow_rs;
	CCardRS Card_rs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CARDMANAGE_H__93857425_62DD_4F81_A4FA_0B4587A186C5__INCLUDED_)
