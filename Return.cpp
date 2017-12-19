// Return.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "Return.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CReturn dialog


CReturn::CReturn(CWnd* pParent /*=NULL*/)
	: CDialog(CReturn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CReturn)
	m_BookID = _T("");
	m_CardID = _T("");
	//}}AFX_DATA_INIT
}


void CReturn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CReturn)
	DDX_Text(pDX, IDC_RETURNBOOKID, m_BookID);
	DDX_Text(pDX, IDC_RETURNCARDID, m_CardID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CReturn, CDialog)
	//{{AFX_MSG_MAP(CReturn)
	ON_BN_CLICKED(IDC_RETURNQUERY, OnReturnquery)
	ON_BN_CLICKED(IDC_RETURNSUBMIT, OnReturnsubmit)
	ON_BN_CLICKED(IDC_RETURNEXIT, OnReturnexit)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CReturn message handlers

void CReturn::OnReturnquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(!Card_rs.IsOpen())Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select *from card where card_id='"+m_CardID+"'",CRecordset::readOnly);
	if(Card_rs.IsBOF()&&Card_rs.IsEOF()){
		MessageBox("借书卡号不存在!");
		return;
	}
	if(Card_rs.IsOpen())Card_rs.Close();
	
	Borrow_rs.m_strFilter.Format("card_id='%s'",m_CardID);
	Borrow_rs.m_strSort="";
	Borrow_rs.Requery();
	
	int i=0;
	while(!Borrow_rs.IsEOF()){
		Book_rs.m_strFilter.Format("book_id='%s'",Borrow_rs.m_book_id);
		Book_rs.m_strSort="";
		Book_rs.Requery();
		for(;!Book_rs.IsEOF();i++)
		{
			CString Mark;
			if(Borrow_rs.m_borrow_date>Borrow_rs.m_return_date)
				Mark="*";
			else Mark="";
			ShowBook.Data.str[i][0]=Mark+Book_rs.m_book_id;
			ShowBook.Data.str[i][1]=Book_rs.m_category;
			ShowBook.Data.str[i][2]=Book_rs.m_book_name;
			ShowBook.Data.str[i][3]=Book_rs.m_press;
			ShowBook.Data.str[i][4]=Book_rs.m_pub_year;
			ShowBook.Data.str[i][5]=Book_rs.m_author;
			ShowBook.Data.str[i][6]=Book_rs.m_price;
			ShowBook.Data.str[i][7].Format("%d",Book_rs.m_total_store);
			ShowBook.Data.str[i][8].Format("%d",Book_rs.m_last_store);
			Book_rs.MoveNext();
		}
		Borrow_rs.MoveNext();
	}
	if(!i)MessageBox("此借书卡号未借书!");
	else{
		ShowBook.Data.num=i;
		ShowBook.DoModal();
	}
}

void CReturn::OnReturnsubmit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(!Card_rs.IsOpen())Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select *from card where card_id='"+m_CardID+"'",CRecordset::readOnly);
	if(Card_rs.IsBOF()&&Card_rs.IsEOF()){
		MessageBox("借书卡号不存在!");
		return;
	}
	if(Card_rs.IsOpen())Card_rs.Close();

	Book_rs.m_strFilter.Format("book_id='%s'",m_BookID);
	Book_rs.m_strSort="";
	Book_rs.Requery();
	Borrow_rs.m_strFilter.Format("card_id='%s' and book_id='%s'",m_CardID,m_BookID);
	Borrow_rs.m_strSort="";
	Borrow_rs.Requery();
	if(Book_rs.IsBOF()&&Book_rs.IsEOF())
		MessageBox("所填书号不存在!");
	else if(Borrow_rs.IsBOF()&&Borrow_rs.IsEOF())
			MessageBox("此借书卡未借此书!");
	else{
		if(Borrow_rs.m_return_date<Borrow_rs.m_borrow_date){
			Book_rs.Edit();
			Book_rs.m_last_store++;
			
		
			Borrow_rs.Edit();
			Borrow_rs.m_return_date=CTime::GetCurrentTime();
			Borrow_rs.m_return_date.Format("%Y-%m-%d");
			if(Book_rs.Update()&&Borrow_rs.Update())
				MessageBox("还书成功!");
			else MessageBox("还书失败!");
		}
		else MessageBox("此借书卡未借此书!");
	}
}

void CReturn::OnReturnexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

BOOL CReturn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!Book_rs.IsOpen())Book_rs.Open();
	if(!Borrow_rs.IsOpen())Borrow_rs.Open();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CReturn::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(Book_rs.IsOpen())Book_rs.Close();
	if(Borrow_rs.IsOpen())Borrow_rs.Close();
	CDialog::OnClose();
}
