#if !defined(AFX_BORROWRS_H__90821241_5390_4D39_99D4_7561A27125A3__INCLUDED_)
#define AFX_BORROWRS_H__90821241_5390_4D39_99D4_7561A27125A3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BorrowRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS recordset

class CBorrowRS : public CRecordset
{
public:
	CBorrowRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBorrowRS)

// Field/Param Data
	//{{AFX_FIELD(CBorrowRS, CRecordset)
	CString	m_card_id;
	CString	m_book_id;
	CString	m_admin_id;
	CTime	m_borrow_date;
	CTime	m_return_date;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBorrowRS)
	public:
	virtual CString GetDefaultConnect();    // Default connection string
	virtual CString GetDefaultSQL();    // Default SQL for Recordset
	virtual void DoFieldExchange(CFieldExchange* pFX);  // RFX support
	//}}AFX_VIRTUAL

// Implementation
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_BORROWRS_H__90821241_5390_4D39_99D4_7561A27125A3__INCLUDED_)
