#if !defined(AFX_SHOWBOOK_H__7778879D_9DC3_404E_A8E0_4E82C90BD1D0__INCLUDED_)
#define AFX_SHOWBOOK_H__7778879D_9DC3_404E_A8E0_4E82C90BD1D0__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ShowBook.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CShowBook dialog

class CShowBook : public CDialog
{
// Construction
public:
	struct DataStore{
		CString str[100][9];
		int num;
	}Data;
	CShowBook(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CShowBook)
	enum { IDD = IDD_SHOWBOOK };
	CListCtrl	m_ListBook;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CShowBook)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CShowBook)
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	
	void InsertShow();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SHOWBOOK_H__7778879D_9DC3_404E_A8E0_4E82C90BD1D0__INCLUDED_)
