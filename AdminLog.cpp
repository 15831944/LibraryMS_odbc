// AdminLog.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "AdminLog.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAdLogin dialog


CAdLogin::CAdLogin(CWnd* pParent /*=NULL*/)
	: CDialog(CAdLogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAdLogin)
	m_AdminID = _T("");
	m_AdminPass = _T("");
	//}}AFX_DATA_INIT
}


void CAdLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAdLogin)
	DDX_Text(pDX, IDC_ADMINID, m_AdminID);
	DDX_Text(pDX, IDC_ADMINPASWRD, m_AdminPass);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAdLogin, CDialog)
	//{{AFX_MSG_MAP(CAdLogin)
	ON_BN_CLICKED(IDOK2, OnOk2)
	ON_BN_CLICKED(IDCANCEL2, OnCancel2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAdLogin message handlers

void CAdLogin::OnOk2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(!Admin_rs.IsOpen())Admin_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select *from admin where admin_id="+m_AdminID,CRecordset::readOnly);
	Admin_rs.Close();
	if(Admin_rs.m_pass_word==m_AdminPass){
		MessageBox(_T("ÄãºÃ!"+Admin_rs.m_admin_name),_T("µÇÂ½³É¹¦"));
		Admin_rs.m_pass_word="";
		m_AdminPass="";
		UpdateData(FALSE);
		CDialog::EndDialog(TRUE);
	}
	else{
		MessageBox(_T("ID/ÃÜÂë´íÎó"));
		m_AdminPass="";
		UpdateData(FALSE);
		CDialog::EndDialog(FALSE);
	}
}

void CAdLogin::OnCancel2() 
{
	// TODO: Add your control notification handler code here
	CDialog::EndDialog(FALSE);
}
