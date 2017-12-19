; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CBookIn
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "librarymanage.h"
LastPage=0

ClassCount=14
Class1=CAdLogin
Class2=CAdminRS
Class3=CBookRS
Class4=CCardManage
Class5=CCardRS
Class6=CLibraryManageApp
Class7=CLibraryManageDlg
Class8=CManager

ResourceCount=9
Resource1=IDD_BOOKQUERY
Resource2=IDD_ADLOGIN
Resource3=IDD_CARDMANGER
Resource4=IDD_BOOKIN
Class9=CBorrowRS
Resource5=IDD_MANAGE
Resource6=IDD_LIBRARYMANAGE_DIALOG
Resource7=IDD_BORROW
Class10=CBookQuery
Resource8=IDD_SHOWBOOK
Class11=CShowBook
Class12=CBookIn
Class13=CBorrow
Class14=CReturn
Resource9=IDD_RETURN

[CLS:CAdLogin]
Type=0
BaseClass=CDialog
HeaderFile=AdminLog.h
ImplementationFile=AdminLog.cpp
LastObject=CAdLogin

[CLS:CAdminRS]
Type=0
HeaderFile=AdminRS.h
ImplementationFile=AdminRS.cpp

[CLS:CBookRS]
Type=0
HeaderFile=BookRS.h
ImplementationFile=BookRS.cpp

[CLS:CCardManage]
Type=0
BaseClass=CDialog
HeaderFile=CardManage.h
ImplementationFile=CardManage.cpp
LastObject=IDC_QUITCARD

[CLS:CCardRS]
Type=0
HeaderFile=CardRS.h
ImplementationFile=CardRS.cpp

[CLS:CLibraryManageApp]
Type=0
BaseClass=CWinApp
HeaderFile=LibraryManage.h
ImplementationFile=LibraryManage.cpp
Filter=N
LastObject=CLibraryManageApp

[CLS:CLibraryManageDlg]
Type=0
BaseClass=CDialog
HeaderFile=LibraryManageDlg.h
ImplementationFile=LibraryManageDlg.cpp
Filter=D
VirtualFilter=dWC

[CLS:CManager]
Type=0
BaseClass=CDialog
HeaderFile=Manager.h
ImplementationFile=Manager.cpp
Filter=D
VirtualFilter=dWC

[DB:CAdminRS]
DB=1

[DB:CBookRS]
DB=1
DBType=ODBC
ColumnCount=9
Column1=[book_id], 12, 60
Column2=[category], 12, 120
Column3=[book_name], 12, 240
Column4=[press], 12, 120
Column5=[pub_year], 1, 24
Column6=[author], 12, 120
Column7=[price], 3, 8
Column8=[total_store], 4, 4
Column9=[last_store], 4, 4

[DB:CCard]
DB=1

[DB:CCardRS]
DB=1
DBType=ODBC
ColumnCount=4
Column1=[card_id], 12, 60
Column2=[owner_name], 12, 120
Column3=[owner_dept], 12, 120
Column4=[kind], 12, 24

[DLG:IDD_ADLOGIN]
Type=1
Class=CAdLogin
ControlCount=7
Control1=IDOK2,button,1342242817
Control2=IDCANCEL2,button,1342242816
Control3=IDC_STATIC,static,1342308876
Control4=IDC_ADMINID,edit,1350631552
Control5=IDC_STATIC,static,1342308864
Control6=IDC_ADMINPASWRD,edit,1350631584
Control7=IDC_STATIC,button,1342177287

[DLG:IDD_CARDMANGER]
Type=1
Class=CCardManage
ControlCount=16
Control1=IDC_STATIC,button,1342177287
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,static,1342308865
Control4=IDC_CARDIDTODELETE,edit,1350631552
Control5=IDC_DELETECARD,button,1342242816
Control6=IDC_QUITCARD,button,1342242816
Control7=IDC_CARDID,edit,1350631552
Control8=IDC_CARDNAME,edit,1350631552
Control9=IDC_CARDDEPT,edit,1350631552
Control10=IDC_STATIC,static,1342308865
Control11=IDC_STATIC,static,1342308865
Control12=IDC_STATIC,static,1342308865
Control13=IDC_STATIC,static,1342308865
Control14=IDC_CARDTYPE,combobox,1344340227
Control15=IDC_ENNEWCARD,button,1342242816
Control16=IDC_CLEARCARD,button,1342242816

[DLG:IDD_LIBRARYMANAGE_DIALOG]
Type=1
Class=CLibraryManageDlg
ControlCount=4
Control1=IDC_LOGIN,button,1342242816
Control2=IDC_BOOKQUERY,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_QUIT,button,1342242816

[DLG:IDD_MANAGE]
Type=1
Class=CManager
ControlCount=6
Control1=IDC_BOOKIN,button,1342242816
Control2=IDC_QUERY,button,1342242816
Control3=IDC_BORROW,button,1342242816
Control4=IDC_RETURN,button,1342242816
Control5=IDC_EXIT_MANAGE,button,1342242816
Control6=IDC_CARD,button,1342242816

[CLS:CBorrowRS]
Type=0
HeaderFile=BorrowRS.h
ImplementationFile=BorrowRS.cpp
BaseClass=CRecordset
Filter=N
VirtualFilter=r
LastObject=CBorrowRS

[DB:CBorrowRS]
DB=1
DBType=ODBC
ColumnCount=5
Column1=[card_id], 12, 60
Column2=[book_id], 12, 60
Column3=[admin_id], 12, 30
Column4=[borrow_date], 11, 16
Column5=[return_date], 11, 16

[DLG:IDD_BOOKQUERY]
Type=1
Class=CBookQuery
ControlCount=15
Control1=IDC_NAMEQUERY,button,1342242817
Control2=IDC_WORD1,edit,1350631552
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,button,1342177287
Control5=IDC_STATIC,static,1342308865
Control6=IDC_STATIC,static,1342308865
Control7=IDC_STATIC,static,1342308865
Control8=IDC_KEY1,edit,1350631552
Control9=IDC_KEY2,edit,1350631552
Control10=IDC_KEY3,edit,1350631552
Control11=IDC_KEYQUERY,button,1342242816
Control12=IDC_QUERYCLEAR,button,1342242816
Control13=IDC_CANCEL,button,1342242816
Control14=IDC_WORD,combobox,1344340227
Control15=IDC_WORD2,edit,1350631552

[DLG:IDD_BOOKIN]
Type=1
Class=CBookIn
ControlCount=21
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_STATIC,static,1342308866
Control4=IDC_STATIC,static,1342308865
Control5=IDC_INBOOKCATEGORY,edit,1350631552
Control6=IDC_INBOOKNAME,edit,1350631552
Control7=IDC_INBOOKPUBYEAR,edit,1350631552
Control8=IDC_INBOOKPRICE,edit,1350631552
Control9=IDC_STATIC,static,1342308865
Control10=IDC_STATIC,static,1342308866
Control11=IDC_STATIC,static,1342308866
Control12=IDC_INBOOKPRESS,edit,1350631552
Control13=IDC_INBOOKID,edit,1350631552
Control14=IDC_INBOOKAUTHOR,edit,1350631552
Control15=IDC_STATIC,static,1342308866
Control16=IDC_INBOOKNUM,edit,1350631552
Control17=IDC_SINGLESUBMIT,button,1342242816
Control18=IDC_BOOKINEXIT,button,1342242816
Control19=IDC_BOOKCLEAR,button,1342242816
Control20=IDC_STATIC,button,1342177287
Control21=IDC_BOOKRUSH,button,1342242816

[DLG:IDD_BORROW]
Type=1
Class=CBorrow
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_BORROWCARDID,edit,1350631552
Control4=IDC_BORROWBOOKID,edit,1350631552
Control5=IDC_BORROWQUERY,button,1342242816
Control6=IDC_BORROWSUBMIT,button,1342242816
Control7=IDC_BORROWEXIT,button,1342242816

[CLS:CBookQuery]
Type=0
HeaderFile=BookQuery.h
ImplementationFile=BookQuery.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBookQuery

[DLG:IDD_SHOWBOOK]
Type=1
Class=CShowBook
ControlCount=1
Control1=IDC_LISTBOOK,SysListView32,1350664193

[CLS:CShowBook]
Type=0
HeaderFile=ShowBook.h
ImplementationFile=ShowBook.cpp
BaseClass=CDialog
Filter=D
LastObject=IDC_LISTBOOK
VirtualFilter=dWC

[CLS:CBookIn]
Type=0
HeaderFile=BookIn.h
ImplementationFile=BookIn.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CBookIn

[CLS:CBorrow]
Type=0
HeaderFile=Borrow.h
ImplementationFile=Borrow.cpp
BaseClass=CDialog
Filter=D
LastObject=CBorrow
VirtualFilter=dWC

[DLG:IDD_RETURN]
Type=1
Class=CReturn
ControlCount=7
Control1=IDC_STATIC,static,1342308865
Control2=IDC_STATIC,static,1342308865
Control3=IDC_RETURNCARDID,edit,1350631552
Control4=IDC_RETURNBOOKID,edit,1350631552
Control5=IDC_RETURNQUERY,button,1342242816
Control6=IDC_RETURNSUBMIT,button,1342242816
Control7=IDC_RETURNEXIT,button,1342242816

[CLS:CReturn]
Type=0
HeaderFile=Return.h
ImplementationFile=Return.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CReturn

