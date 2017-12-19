// AdminRS.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "AdminRS.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdminRS

IMPLEMENT_DYNAMIC(CAdminRS, CRecordset)

CAdminRS::CAdminRS(CDatabase* pdb)
	: CRecordset(pdb)
{
	//{{AFX_FIELD_INIT(CAdminRS)
	m_admin_id = _T("");
	m_pass_word = _T("");
	m_admin_name = _T("");
	m_phone_no = _T("");
	m_nFields = 4;
	//}}AFX_FIELD_INIT
	m_nDefaultType = snapshot;
}


CString CAdminRS::GetDefaultConnect()
{
	return _T("ODBC;DSN=mysql");
}

CString CAdminRS::GetDefaultSQL()
{
	return _T("[admin]");
}

void CAdminRS::DoFieldExchange(CFieldExchange* pFX)
{
	//{{AFX_FIELD_MAP(CAdminRS)
	pFX->SetFieldType(CFieldExchange::outputColumn);
	RFX_Text(pFX, _T("[admin_id]"), m_admin_id);
	RFX_Text(pFX, _T("[pass_word]"), m_pass_word);
	RFX_Text(pFX, _T("[admin_name]"), m_admin_name);
	RFX_Text(pFX, _T("[phone_no]"), m_phone_no);
	//}}AFX_FIELD_MAP
}

/////////////////////////////////////////////////////////////////////////////
// CAdminRS diagnostics

#ifdef _DEBUG
void CAdminRS::AssertValid() const
{
	CRecordset::AssertValid();
}

void CAdminRS::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG
