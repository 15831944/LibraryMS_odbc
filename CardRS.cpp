// CardRS.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "CardRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardRS

IMPLEMENT_DYNAMIC(CCardRS, CRecordset)

CCardRS::CCardRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CCardRS)
	m_card_id = _T("");
	m_owner_name = _T("");
	m_owner_dept = _T("");
	m_kind = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CCardRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=mysql");
}

CString CCardRS::GetDefaultSQL()
{
	return _T("[card]");
}

void CCardRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CCardRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[card_id]"), m_card_id);
	RFX_Text(pFX, _T("[owner_name]"), m_owner_name);
	RFX_Text(pFX, _T("[owner_dept]"), m_owner_dept);
	RFX_Text(pFX, _T("[kind]"), m_kind);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CCardRS diagnostics

#ifdef _DEBUG
void CCardRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CCardRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
