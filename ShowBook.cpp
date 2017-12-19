// ShowBook.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "ShowBook.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CShowBook dialog


CShowBook::CShowBook(CWnd* pParent /*=NULL*/)
	: CDialog(CShowBook::IDD, pParent)
{
	//{{AFX_DATA_INIT(CShowBook)
	//}}AFX_DATA_INIT
}


void CShowBook::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CShowBook)
	DDX_Control(pDX, IDC_LISTBOOK, m_ListBook);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CShowBook, CDialog)
	//{{AFX_MSG_MAP(CShowBook)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CShowBook message handlers

BOOL CShowBook::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization hereTheFlower
	CRect rect;
	m_ListBook.GetClientRect(&rect);
	m_ListBook.SetExtendedStyle(m_ListBook.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListBook.InsertColumn(0,"���",LVCFMT_CENTER,80);
	m_ListBook.InsertColumn(1,"���",LVCFMT_CENTER,60);
	m_ListBook.InsertColumn(2,"����",LVCFMT_CENTER,150);
	m_ListBook.InsertColumn(3,"������",LVCFMT_CENTER,120);
	m_ListBook.InsertColumn(4,"���",LVCFMT_CENTER,60);
	m_ListBook.InsertColumn(5,"����",LVCFMT_CENTER,100);
	m_ListBook.InsertColumn(6,"�۸�",LVCFMT_CENTER,70);
	m_ListBook.InsertColumn(7,"�ܲ�����",LVCFMT_CENTER,80);
	m_ListBook.InsertColumn(8,"���",LVCFMT_CENTER,70);
	InsertShow();

//	m_ListBook.InsertItem(0,"���");
//	m_ListBook.InsertItem(1,"���");
//	m_ListBook.InsertItem(2,"����");
//	m_ListBook.InsertItem(3,"������");
//	m_ListBook.InsertItem(4,"���");
//	m_ListBook.InsertItem(5,"����");
//	m_ListBook.InsertItem(6,"�۸�");
//	m_ListBook.InsertItem(7,"�ܲ�����");
//	m_ListBook.InsertItem(8,"���");

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CShowBook::InsertShow()
{
	for(int i=0;i<Data.num;i++)
	{
		m_ListBook.InsertItem(i,Data.str[i][0]);
		for(int j=1;j<9;j++)
			m_ListBook.SetItemText(i,j,Data.str[i][j]);
	}
}
