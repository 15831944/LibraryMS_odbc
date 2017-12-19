#if !defined(AFX_BOOKRS_H__BEB7EDBD_98C3_457E_B988_1ED684FEC64D__INCLUDED_)
#define AFX_BOOKRS_H__BEB7EDBD_98C3_457E_B988_1ED684FEC64D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// BookRS.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CBookRS recordset

class CBookRS : public CRecordset
{
public:
	CBookRS(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(CBookRS)

// Field/Param Data
	//{{AFX_FIELD(CBookRS, CRecordset)
	CString	m_book_id;
	CString	m_category;
	CString	m_book_name;
	CString	m_press;
	CString	m_pub_year;
	CString	m_author;
	CString	m_price;
	long	m_total_store;
	long	m_last_store;
	//}}AFX_FIELD


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CBookRS)
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
CString Interpreter(CString statement);
//??????
CString read_input();
//??create??????
CString create_clause(CString SQL,int start);
//??create table??????
CString create_table(CString SQL,int start);
//????
CString get_attribute(CString temp,CString sql);
//??create index??????
CString create_index(CString SQL,int start);
//??create index on??????
CString create_index_on(CString SQL,int start,CString sql);
//??drop??????
CString drop_clause(CString SQL,int start);
//??drop table??????
CString drop_table(CString SQl,int start);
//??drop index??????
CString drop_index(CString SQL,int start);
//??select ??????
CString select_clause(CString SQL,int start);
//??insert ??????
CString insert_clause(CString SQL,int start);
//??delete??????
CString delete_clause(CString SQL,int start);
//??quit??????
CString quit_clause(CString SQL,int start);

#endif // !defined(AFX_BOOKRS_H__BEB7EDBD_98C3_457E_B988_1ED684FEC64D__INCLUDED_)
