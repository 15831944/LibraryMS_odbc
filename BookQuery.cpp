// BookQuery.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "BookQuery.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookQuery dialog


CBookQuery::CBookQuery(CWnd* pParent /*=NULL*/)
	: CDialog(CBookQuery::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookQuery)
	m_Key1 = _T("");
	m_Key2 = _T("");
	m_Key3 = _T("");
	m_Word = _T("");
	m_Word1 = _T("");
	m_Word2 = _T("");
	//}}AFX_DATA_INIT
}


void CBookQuery::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookQuery)
	DDX_Text(pDX, IDC_KEY1, m_Key1);
	DDX_Text(pDX, IDC_KEY2, m_Key2);
	DDX_Text(pDX, IDC_KEY3, m_Key3);
	DDX_CBString(pDX, IDC_WORD, m_Word);
	DDX_Text(pDX, IDC_WORD1, m_Word1);
	DDX_Text(pDX, IDC_WORD2, m_Word2);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookQuery, CDialog)
	//{{AFX_MSG_MAP(CBookQuery)
	ON_BN_CLICKED(IDC_NAMEQUERY, OnNamequery)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_QUERYCLEAR, OnQueryclear)
	ON_BN_CLICKED(IDC_CANCEL, OnCancel)
	ON_BN_CLICKED(IDC_KEYQUERY, OnKeyquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookQuery message handlers

void CBookQuery::OnNamequery() 
{
	UpdateData(TRUE);
	if(!Book_rs.IsOpen())Book_rs.Open();
//	Book_rs.m_strFilter=
	if(!m_Word.Compare("类别")&&!m_Word1.IsEmpty()){
		QueryValue.Format("category='%s'",m_Word1);
		SortValue.Format("category");
	}
	else if(!m_Word.Compare("书名")&&!m_Word1.IsEmpty()){
		QueryValue.Format("book_name='%s'",m_Word1);
		SortValue.Format("book_name");
	}
	else if(!m_Word.Compare("出版社")&&!m_Word1.IsEmpty()){
		QueryValue.Format("press='%s'",m_Word1);
		SortValue.Format("press");
	}
	else if(!m_Word.Compare("年份区间")&&!m_Word1.IsEmpty()&&!m_Word2.IsEmpty())
	{
		QueryValue.Format("pub_year between '%s' and '%s'",m_Word1,m_Word2);
		SortValue.Format("pub_year");
	}
	else if(!m_Word.Compare("作者")&&!m_Word1.IsEmpty()){
		QueryValue.Format("author='%s'",m_Word1);
		SortValue.Format("author");
	}
	else if(!m_Word.Compare("价格区间")&&!m_Word1.IsEmpty()&&!m_Word2.IsEmpty()){
		QueryValue.Format("price between %s and %s",m_Word1,m_Word2);
		SortValue.Format("price");
	}else{
		MessageBox("信息不全，将显示所有书目!");
		QueryValue="";
		SortValue.Format("book_name");
	}
	QueryShow();
}

//void CBookQuery::OnEditchangeWord() 
//{
	// TODO: Add your control notification handler code here
	
//}

BOOL CBookQuery::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!Book_rs.IsOpen())Book_rs.Open();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBookQuery::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	Book_rs.Close();
	CDialog::OnClose();
}

//void CBookQuery::OnSelchangeWord() 
//{
//	// TODO: Add your control notification handler code here
//	UpdateData(TRUE);
//	CWnd *PWnd1;
//	CWnd *PWnd2;
//	PWnd1=PWnd1->GetDlgItem(IDC_WORD1);
//	PWnd2=PWnd2->GetDlgItem(IDC_WORD2);
//	PWnd1->EnableWindow(TRUE);
//	if(m_Word.Compare("类别")){
//		PWnd2->EnableWindow(FALSE);
//	}
//	else if(m_Word.Compare("书名")){
//		PWnd2->EnableWindow(FALSE);
//	}
//	else if(m_Word.Compare("出版社")){
//		PWnd2->EnableWindow(FALSE);
//	}
//	else if(m_Word.Compare("年份区间"))
//	{
//		PWnd2->EnableWindow(TRUE);
//	}
//	else if(m_Word.Compare("作者")){
//		PWnd2->EnableWindow(FALSE);
//	}
//	else if(m_Word.Compare("价格区间")){
//		PWnd2->EnableWindow(TRUE);
//	}
//}

void CBookQuery::OnQueryclear() 
{
	// TODO: Add your control notification handler code here
	m_Word="";
	m_Word1="";
	m_Word2="";
	m_Key1="";
	m_Key2="";
	m_Key3="";
	UpdateData(FALSE);
}

void CBookQuery::OnCancel() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CBookQuery::OnKeyquery() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString Key1,Key2,Key3;
	if(!m_Key1.IsEmpty())Key1.Format("book_name like '%%%s%%' or author like '%%%s%%'",m_Key1,m_Key1);
	else Key1="0";
	if(!m_Key2.IsEmpty())Key2.Format("book_name like '%%%s%%' or author like '%%%s%%'",m_Key2,m_Key2);
	else Key2="0";
	if(!m_Key3.IsEmpty())Key3.Format("book_name like '%%%s%%' or author like '%%%s%%'",m_Key3,m_Key3);
	else Key3="0";
	QueryValue.Format("%s or %s or %s",Key1,Key2,Key3);
	SortValue.Format("book_name,author");
	QueryShow();
}

void CBookQuery::QueryShow()
{
	Book_rs.m_strFilter=QueryValue;
	Book_rs.m_strSort=SortValue;
	Book_rs.Requery();
	int i=0;
	for(;!Book_rs.IsEOF();i++)
	{
		ShowBook.Data.str[i][0]=Book_rs.m_book_id;
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
	ShowBook.Data.num=i;
	ShowBook.DoModal();	
}
