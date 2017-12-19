// Borrow.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "Borrow.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBorrow dialog


CBorrow::CBorrow(CWnd* pParent /*=NULL*/)
	: CDialog(CBorrow::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBorrow)
	m_BookID = _T("");
	m_CardID = _T("");
	//}}AFX_DATA_INIT
}


void CBorrow::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBorrow)
	DDX_Text(pDX, IDC_BORROWBOOKID, m_BookID);
	DDX_Text(pDX, IDC_BORROWCARDID, m_CardID);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBorrow, CDialog)
	//{{AFX_MSG_MAP(CBorrow)
	ON_BN_CLICKED(IDC_BORROWQUERY, OnBorrowquery)
	ON_BN_CLICKED(IDC_BORROWSUBMIT, OnBorrowsubmit)
	ON_BN_CLICKED(IDC_BORROWEXIT, OnBorrowexit)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBorrow message handlers

void CBorrow::OnBorrowquery() 
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

void CBorrow::OnBorrowsubmit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(!Card_rs.IsOpen())Card_rs.Open(AFX_DB_USE_DEFAULT_TYPE,"select *from card where card_id='"+m_CardID+"'",CRecordset::readOnly);
	if(Card_rs.IsBOF()&&Card_rs.IsEOF()){
		MessageBox("借书卡号不存在!");
		return;
	}
	extern CString CurAdminID;
	if(Card_rs.IsOpen())Card_rs.Close();
	Book_rs.m_strFilter.Format("book_id='%s'",m_BookID);
	Book_rs.m_strSort="";
	Book_rs.Requery();
	if(Book_rs.IsBOF()&&Book_rs.IsEOF())
		MessageBox("所填书号不存在!");
	else{
		if(Book_rs.m_last_store>0){
			Book_rs.Edit();
			Book_rs.m_last_store--;
//			Book_rs.Update();

			Borrow_rs.m_strFilter.Format("card_id='%s' and book_id='%s'",m_CardID,m_BookID);
			Borrow_rs.m_strSort="";
			Borrow_rs.Requery();
			if(Borrow_rs.IsBOF()&&Borrow_rs.IsEOF()){
				Borrow_rs.AddNew();
				Borrow_rs.m_admin_id=CurAdminID;
				Borrow_rs.m_book_id=m_BookID;
				Borrow_rs.m_card_id=m_CardID;
				Borrow_rs.m_borrow_date=CTime::GetCurrentTime();
				Borrow_rs.m_borrow_date.Format("%Y-%m-%d");
				//Borrow_rs.m_return_date=CTime::GetCurrentTime();
				//Borrow_rs.m_return_date.Format("%Y-%m-%d");
			}
			else{
				Borrow_rs.Edit();
				Borrow_rs.m_admin_id=CurAdminID;
				Borrow_rs.m_borrow_date=Borrow_rs.m_borrow_date=CTime::GetCurrentTime();
			}
			if(Borrow_rs.Update()&&Book_rs.Update())
				MessageBox("借书成功!");
			else MessageBox("借书失败!");
		}
		else{
			Borrow_rs.m_strFilter.Format("book_id='%s'",m_BookID);
			Borrow_rs.m_strSort.Format("return_date desc");
			Borrow_rs.Requery();
			CString str;
			str.Format("图书无库存!最近归还日期%s",Borrow_rs.m_return_date.Format("%Y-%m-%d"));
			MessageBox(str);
		}
		
	}
}

void CBorrow::OnBorrowexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CBorrow::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(Book_rs.IsOpen())Book_rs.Close();
	if(Borrow_rs.IsOpen())Borrow_rs.Close();
	CDialog::OnClose();
}

BOOL CBorrow::OnInitDialog() 
{
	CDialog::OnInitDialog();

	// TODO: Add extra initialization here
	if(!Book_rs.IsOpen())Book_rs.Open();
	if(!Borrow_rs.IsOpen())Borrow_rs.Open();	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
