#if !defined(AFX_BOOKQUERY_H__B18994FD_5A7C_4C07_8425_D7B75766D6DF__INCLUDED_)
#define AFX_BOOKQUERY_H__B18994FD_5A7C_4C07_8425_D7B75766D6DF__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#include "ShowBook.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookQuery.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookQuery dialog

class CBookQuery : public CDialog
{
// Construction
public:
	CBookQuery(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBookQuery)
	enum { IDD = IDD_BOOKQUERY };
	CString	m_Key1;
	CString	m_Key2;
	CString	m_Key3;
	CString	m_Word;
	CString	m_Word1;
	CString	m_Word2;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookQuery)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookQuery)
	afx_msg void OnNamequery();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnQueryclear();
	afx_msg void OnCancel();
	afx_msg void OnKeyquery();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	void QueryShow();
	CString SortValue;
	CString QueryValue;
	CShowBook ShowBook;
	CBookRS Book_rs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKQUERY_H__B18994FD_5A7C_4C07_8425_D7B75766D6DF__INCLUDED_)
