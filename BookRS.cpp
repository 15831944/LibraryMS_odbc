// BookRS.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "BookRS.h"
#include "iostream.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookRS

IMPLEMENT_DYNAMIC(CBookRS, CRecordset)

CBookRS::CBookRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBookRS)
	m_book_id = _T("");
	m_category = _T("");
	m_book_name = _T("");
	m_press = _T("");
	m_pub_year = _T("");
	m_author = _T("");
	m_price = _T("");
	m_total_store = 0;
	m_last_store = 0;
	m_nFields = 9;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBookRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=mysql");
}

CString CBookRS::GetDefaultSQL()
{
	return _T("[book]");
}

void CBookRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBookRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[book_id]"), m_book_id);
	RFX_Text(pFX, _T("[category]"), m_category);
	RFX_Text(pFX, _T("[book_name]"), m_book_name);
	RFX_Text(pFX, _T("[press]"), m_press);
	RFX_Text(pFX, _T("[pub_year]"), m_pub_year);
	RFX_Text(pFX, _T("[author]"), m_author);
	RFX_Text(pFX, _T("[price]"), m_price);
	RFX_Long(pFX, _T("[total_store]"), m_total_store);
	RFX_Long(pFX, _T("[last_store]"), m_last_store);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBookRS diagnostics

#ifdef _DEBUG
void CBookRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBookRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG

