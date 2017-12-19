// CardManage.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "CardManage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCardManage dialog


CCardManage::CCardManage(CWnd* pParent /*=NULL*/)
	: CDialog(CCardManage::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCardManage)
	m_NewID = _T("");
	m_IDtoDelete = _T("");
	m_NewName = _T("");
	m_NewType = _T("");
	m_NewDept = _T("");
	//}}AFX_DATA_INIT
}


void CCardManage::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCardManage)
	DDX_Text(pDX, IDC_CARDID, m_NewID);
	DDV_MaxChars(pDX, m_NewID, 11);
	DDX_Text(pDX, IDC_CARDIDTODELETE, m_IDtoDelete);
	DDV_MaxChars(pDX, m_IDtoDelete, 11);
	DDX_Text(pDX, IDC_CARDNAME, m_NewName);
	DDV_MaxChars(pDX, m_NewName, 21);
	DDX_CBString(pDX, IDC_CARDTYPE, m_NewType);
	DDV_MaxChars(pDX, m_NewType, 5);
	DDX_Text(pDX, IDC_CARDDEPT, m_NewDept);
	DDV_MaxChars(pDX, m_NewDept, 21);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCardManage, CDialog)
	//{{AFX_MSG_MAP(CCardManage)
	ON_BN_CLICKED(IDC_ENNEWCARD, OnEnnewcard)
	ON_BN_CLICKED(IDC_CLEARCARD, OnClearcard)
	ON_BN_CLICKED(IDC_DELETECARD, OnDeletecard)
	ON_BN_CLICKED(IDC_QUITCARD, OnQuitcard)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCardManage message handlers
void CCardManage::OnEnnewcard() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_NewID.IsEmpty()||m_NewName.IsEmpty()||m_NewDept.IsEmpty()||m_NewType.IsEmpty()){
		MessageBox(_T("请先完善信息!"));
		return;
	}
	Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select *from card where card_id=\'"+m_NewID+"\'");
	Card_rs.Close();
	if(Card_rs.m_card_id==m_NewID)MessageBox(_T("该借书证ID已存在"));
	else{
		Card_rs.Open();
		Card_rs.AddNew();
		Card_rs.m_card_id=m_NewID;
		Card_rs.m_owner_name=m_NewName;
		Card_rs.m_owner_dept=m_NewDept;
		Card_rs.m_kind=m_NewType;
		Card_rs.Update();
		Card_rs.Close();
		MessageBox(_T("创建成功!"));
	}
}



void CCardManage::OnClearcard() 
{
	// TODO: Add your control notification handler code here
	m_NewID="";
	m_NewName="";
	m_NewDept="";
	m_NewType="";
	UpdateData(FALSE);
}

void CCardManage::OnDeletecard() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_IDtoDelete.IsEmpty()){
		MessageBox(_T("ID不能为空!"));
		return;
	}
	
	Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from card where card_id=\'"+m_IDtoDelete+"\'");
	Card_rs.Close();
	if(Card_rs.m_card_id==m_IDtoDelete){
		Borrow_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from borrow where card_id=\'"+m_IDtoDelete+"\'");
		if(!Borrow_rs.GetRecordCount())
		{
			Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from card where card_id=\'"+m_IDtoDelete+"\'");
			CRecordsetStatus status;
			Card_rs.GetStatus(status);
			Card_rs.Delete();
			if(!status.m_lCurrentRecord)Card_rs.MoveNext();
			else Card_rs.MoveFirst();
			Card_rs.Close();
			MessageBox(_T("删除成功!"));
		}
		else MessageBox(_T("此ID有书未还!"));
		Borrow_rs.Close();
	}
	else MessageBox(_T("该借书证ID不存在"));
//	UpdateData(TRUE);
//	if(m_IDtoDelete.IsEmpty()){
//		MessageBox("ID不能为空!");
//		return;
//	}
//	if(!Card_rs.IsOpen())Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from card where card_id='"+m_IDtoDelete+"'");
//	else{
////		Card_rs.m_strFilter.Format("card_id='"+m_IDtoDelete+"'");
//		Card_rs.m_strFilter.Format("card_id='%s'",m_IDtoDelete);
//		MessageBox(Card_rs.m_strFilter);
//		if(Card_rs.CanRestart())Card_rs.Requery();
//		Card_rs.m_strFilter="";
//	}
//	if(Card_rs.IsBOF()&&Card_rs.IsEOF())MessageBox("该借书证ID不存在");
//	else{
//		if(!Borrow_rs.IsOpen())Borrow_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select * from borrow where card_id='"+m_IDtoDelete+"'");
//		else{
//			CString SqlStr="borrow.card_id="+m_IDtoDelete;
////			Borrow_rs.m_strFilter.Format("card_id='"+m_IDtoDelete+"'");
//			Borrow_rs.m_strFilter=SqlStr;
//			if(Borrow_rs.CanRestart())Borrow_rs.Requery();
//			Borrow_rs.m_strFilter="";
//		}
//		if(Borrow_rs.IsBOF()&&Borrow_rs.IsEOF()){
//			CRecordsetStatus status;
//			Card_rs.GetStatus(status);
//			Card_rs.Delete();
//			if(!status.m_lCurrentRecord)Card_rs.MoveNext();
//			else Card_rs.MoveFirst();
//			MessageBox("删除成功!");
//		}
//		else MessageBox("此ID有书未还!");
//	}
//	else MessageBox("Yes");
//	if(Card_rs.GetRecordCount()<=0)MessageBox("No");
//	else MessageBox("Yes");
}

void CCardManage::OnQuitcard() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
