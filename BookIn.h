#if !defined(AFX_BOOKIN_H__854AEEB8_385D_448B_8341_1D3D9FD0A98C__INCLUDED_)
#define AFX_BOOKIN_H__854AEEB8_385D_448B_8341_1D3D9FD0A98C__INCLUDED_

#include "BookRS.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookIn.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookIn dialog

class CBookIn : public CDialog
{
// Construction
public:
	CBookIn(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CBookIn)
	enum { IDD = IDD_BOOKIN };
	CString	m_Price;
	CString	m_Press;
	CString	m_BookName;
	CString	m_BookID;
	CString	m_Category;
	CString	m_Author;
	CString	m_BookNum;
	CString	m_PubYear;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookIn)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CBookIn)
	afx_msg void OnSinglesubmit();
	virtual BOOL OnInitDialog();
	afx_msg void OnClose();
	afx_msg void OnBookclear();
	afx_msg void OnBookrush();
	afx_msg void OnBookinexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	CBookRS Book_rs;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BOOKIN_H__854AEEB8_385D_448B_8341_1D3D9FD0A98C__INCLUDED_)
