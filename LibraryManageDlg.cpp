// LibraryManageDlg.cpp : implementation file
//

#include "stdafx.h"
#include "LibraryManage.h"
#include "LibraryManageDlg.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CLibraryManageDlg dialog

CLibraryManageDlg::CLibraryManageDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CLibraryManageDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CLibraryManageDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLibraryManageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CLibraryManageDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CLibraryManageDlg, CDialog)
	//{{AFX_MSG_MAP(CLibraryManageDlg)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_LOGIN, OnLogin)
	ON_BN_CLICKED(IDC_QUIT, OnQuit)
	ON_BN_CLICKED(IDC_BOOKQUERY, OnBookquery)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CLibraryManageDlg message handlers

BOOL CLibraryManageDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CLibraryManageDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CLibraryManageDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
CString CurAdminID;
void CLibraryManageDlg::OnLogin() 
{
	// TODO: Add your control notification handler code here
//	login.Admin_rs.Open();
	/*CString a("123");
	char ab[10];
	strcpy(ab,a);
	FILE *fp;
	fp=fopen(ab,"wt");
	fwrite((const void *)ab,1,4,fp);
	fclose(fp);*/
	if(login.DoModal()){
//		Admin_rs.m_admin_id=login.m_AdminID;
		CurAdminID=login.m_AdminID;
//		CDialog::OnOK();
		Manage.DoModal();
	}
}

void CLibraryManageDlg::OnQuit() 
{
	// TODO: Add your control notification handler code here
	CDialog::OnCancel();
}

void CLibraryManageDlg::OnBookquery() 
{
	// TODO: Add your control notification handler code here
	BookQ.DoModal();
}
