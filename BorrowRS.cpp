// BorrowRS.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "BorrowRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS

IMPLEMENT_DYNAMIC(CBorrowRS, CRecordset)

CBorrowRS::CBorrowRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CBorrowRS)
	m_card_id = _T("");
	m_book_id = _T("");
	m_admin_id = _T("");
	m_nFields = 5;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CBorrowRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=mysql");
}

CString CBorrowRS::GetDefaultSQL()
{
	return _T("[borrow]");
}

void CBorrowRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CBorrowRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[card_id]"), m_card_id);
	RFX_Text(pFX, _T("[book_id]"), m_book_id);
	RFX_Text(pFX, _T("[admin_id]"), m_admin_id);
	RFX_Date(pFX, _T("[borrow_date]"), m_borrow_date);
	RFX_Date(pFX, _T("[return_date]"), m_return_date);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CBorrowRS diagnostics

#ifdef _DEBUG
void CBorrowRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CBorrowRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
