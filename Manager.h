#if !defined(AFX_MANAGER_H__8D3FE78C_CCD7_4233_98B1_83508D042536__INCLUDED_)
#define AFX_MANAGER_H__8D3FE78C_CCD7_4233_98B1_83508D042536__INCLUDED_

#include "CardManage.h"	// Added by ClassView
#include "BookQuery.h"	// Added by ClassView
#include "BookIn.h"	// Added by ClassView
#include "Borrow.h"	// Added by ClassView
#include "Return.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Manager.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CManager dialog

class CManager : public CDialog
{
// Construction
public:
	CManager(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CManager)
	enum { IDD = IDD_MANAGE };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CManager)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CCardManage CardMng;

	// Generated message map functions
	//{{AFX_MSG(CManager)
	afx_msg void OnExitManage();
	afx_msg void OnBookin();
	afx_msg void OnQuery();
	afx_msg void OnBorrow();
	afx_msg void OnReturn();
	afx_msg void OnCard();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CReturn Return;
	CBorrow Borrow;
	CBookIn BookIn;
	CBookQuery BookQ;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MANAGER_H__8D3FE78C_CCD7_4233_98B1_83508D042536__INCLUDED_)
