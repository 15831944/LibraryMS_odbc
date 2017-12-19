#if !defined(AFX_ADMINRS_H__9FE7FB5D_EBBA_417E_B400_F34EB0E6A371__INCLUDED_)
#define AFX_ADMINRS_H__9FE7FB5D_EBBA_417E_B400_F34EB0E6A371__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AdminRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CAdminRS recordset

class CAdminRS : public CRecordset
{
public:
	CAdminRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CAdminRS)

// Field/Param Data
	//{{AFX_FIELD(CAdminRS, CRecordset)
	CString	m_admin_id;
	CString	m_pass_word;
	CString	m_admin_name;
	CString	m_phone_no;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAdminRS)
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

#endif // !defined(AFX_ADMINRS_H__9FE7FB5D_EBBA_417E_B400_F34EB0E6A371__INCLUDED_)
