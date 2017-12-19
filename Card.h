#if !defined(AFX_CARD_H__E9980A37_12E6_496A_A4A1_59210E466F4A__INCLUDED_)
#define AFX_CARD_H__E9980A37_12E6_496A_A4A1_59210E466F4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Card.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CCard recordset

class CCardRS : public CRecordset
{
public:
	CCard(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CCard)

// Field/Param Data
	//{{AFX_FIELD(CCard, CRecordset)
	CString	m_card_id;
	CString	m_owner_name;
	CString	m_owner_dept;
	CString	m_kind;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCard)
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

#endif // !defined(AFX_CARD_H__E9980A37_12E6_496A_A4A1_59210E466F4A__INCLUDED_)
