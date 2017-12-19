#if !defined(AFX_ADMINLOG_H__FC867957_47E0_40BC_AD64_4EF0503B9926__INCLUDED_)
#define AFX_ADMINLOG_H__FC867957_47E0_40BC_AD64_4EF0503B9926__INCLUDED_

#include "AdminRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdminLog.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdLogin dialog

class CAdLogin : public CDialog
{
// Construction
public:
	CAdLogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CAdLogin)
	enum { IDD = IDD_ADLOGIN };
	CString	m_AdminID;
	CString	m_AdminPass;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdLogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	CAdminRS Admin_rs;

	// Generated message map functions
	//{{AFX_MSG(CAdLogin)
	afx_msg void OnOk2();
	afx_msg void OnCancel2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADMINLOG_H__FC867957_47E0_40BC_AD64_4EF0503B9926__INCLUDED_)
