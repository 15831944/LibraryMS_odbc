// BookIn.cpp : implementation file
//

#include "stdafx.h"
#include "librarymanage.h"
#include "BookIn.h"

#include "iostream.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CBookIn dialog


CBookIn::CBookIn(CWnd* pParent /*=NULL*/)
	: CDialog(CBookIn::IDD, pParent)
{
	//{{AFX_DATA_INIT(CBookIn)
	m_Price = _T("");
	m_Press = _T("");
	m_BookName = _T("");
	m_BookID = _T("");
	m_Category = _T("");
	m_Author = _T("");
	m_BookNum = _T("");
	m_PubYear = _T("");
	//}}AFX_DATA_INIT
}


void CBookIn::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CBookIn)
	DDX_Text(pDX, IDC_INBOOKPRICE, m_Price);
	DDX_Text(pDX, IDC_INBOOKPRESS, m_Press);
	DDX_Text(pDX, IDC_INBOOKNAME, m_BookName);
	DDX_Text(pDX, IDC_INBOOKID, m_BookID);
	DDX_Text(pDX, IDC_INBOOKCATEGORY, m_Category);
	DDX_Text(pDX, IDC_INBOOKAUTHOR, m_Author);
	DDX_Text(pDX, IDC_INBOOKNUM, m_BookNum);
	DDX_Text(pDX, IDC_INBOOKPUBYEAR, m_PubYear);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CBookIn, CDialog)
	//{{AFX_MSG_MAP(CBookIn)
	ON_BN_CLICKED(IDC_SINGLESUBMIT, OnSinglesubmit)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BOOKCLEAR, OnBookclear)
	ON_BN_CLICKED(IDC_BOOKRUSH, OnBookrush)
	ON_BN_CLICKED(IDC_BOOKINEXIT, OnBookinexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CBookIn message handlers

void CBookIn::OnSinglesubmit() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(m_BookID.IsEmpty()||m_BookNum.IsEmpty()){
		MessageBox("书号和数量不能为空!");
		return;
	}
	Book_rs.m_strFilter.Format("book_id='%s'",m_BookID);
	Book_rs.m_strSort="";
	Book_rs.Requery();
	
	if(Book_rs.IsBOF()&&Book_rs.IsEOF()){
		if(m_BookName.IsEmpty()||m_Author.IsEmpty()||m_Category.IsEmpty()||m_Press.IsEmpty()||m_Price.IsEmpty()||m_PubYear.IsEmpty())
		{
			MessageBox("信息不全，无法提交!");
			return;
		}
		Book_rs.AddNew();
		Book_rs.m_book_id=m_BookID;
		Book_rs.m_book_name=m_BookName;
		Book_rs.m_author=m_Author;
		Book_rs.m_category=m_Category;
		Book_rs.m_total_store=_ttol(m_BookNum);
		Book_rs.m_last_store=Book_rs.m_total_store;
		Book_rs.m_press=m_Press;
		Book_rs.m_price=m_Price;
		Book_rs.m_pub_year=m_PubYear;
	}
	else{
		Book_rs.Edit();
		Book_rs.m_total_store+=_ttol(m_BookNum);
		Book_rs.m_last_store+=_ttol(m_BookNum);
	}
	if(Book_rs.Update())MessageBox("入库成功!");
	else MessageBox("入库失败!");
}

BOOL CBookIn::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	if(!Book_rs.IsOpen())Book_rs.Open();
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CBookIn::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(Book_rs.IsOpen())Book_rs.Close();
	CDialog::OnClose();
}

void CBookIn::OnBookclear() 
{
	// TODO: Add your control notification handler code here
	m_BookID="";
	m_BookName="";
	m_Author="";
	m_Category="";
	m_BookNum="";
	m_Press="";
	m_Price="";
	m_PubYear="";
	UpdateData(FALSE);
}

void CBookIn::OnBookrush() 
{
	// TODO: Add your control notification handler code here
	CFileDialog FileRush(TRUE,NULL,NULL,OFN_HIDEREADONLY,"All Files(*.*)|*.*||)",AfxGetMainWnd());
	if(FileRush.DoModal()==IDOK){
		CString FilePath;
		FilePath=FileRush.GetPathName();
		CStdioFile FileObj;
		if(FileObj.Open(FilePath,CFile::typeText|CFile::modeRead)){
			MessageBox("打开文件成功!");

			CString Line;
			CString Info[8];
			while(FileObj.ReadString(Line)){
				int i;
				int l=0;
				int r=Line.Find(',',l);
				for(i=0;i<7&&r!=-1;i++){
					Info[i]=Line.Mid(l,r-l);
					l=r+1;
					r=Line.Find(',',l);
				}
				Info[7]=Line.Mid(l);
//book_no_1, Computer Science, Computer Architecture, xxx, 2004, xxx, 90.00, 2
				if(i<7||Info[7].IsEmpty()){
					MessageBox("文件格式错误!");
					continue;
				}
				Book_rs.m_strFilter.Format("book_id='%s'",Info[0]);
				Book_rs.m_strSort="";
				Book_rs.Requery();
				if(Book_rs.IsBOF()&&Book_rs.IsEOF()){
					Book_rs.AddNew();
					Book_rs.m_book_id	=Info[0];
					Book_rs.m_category	=Info[1];
					Book_rs.m_book_name	=Info[2];
					Book_rs.m_press		=Info[3];
					Book_rs.m_pub_year	=Info[4];
					Book_rs.m_author	=Info[5];
					Book_rs.m_price		=Info[6];
					Book_rs.m_total_store=_ttol(Info[7]);
					Book_rs.m_last_store=Book_rs.m_total_store;
				}
				else{
					Book_rs.Edit();
					Book_rs.m_total_store+=_ttol(Info[7]);
					Book_rs.m_last_store+=_ttol(Info[7]);
				}
				if(!Book_rs.Update())MessageBox(Info[2]+"入库失败!");
			}
			MessageBox("批量入库完毕!");
		}else MessageBox("打开文件失败!");
	}
}

void CBookIn::OnBookinexit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}
