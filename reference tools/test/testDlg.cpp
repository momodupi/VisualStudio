
// testDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()

CString TypeAbbr[] = { _T("[J]. "), _T("[M]. "), _T("[C]. "), _T("[D]. "), _T("[R]. "), _T("[P]. "), _T("[N]. "), _T("[C]. "), _T("[S]. ") };
CString sCommas = _T(", ");
CString sDot = _T(". ");
CString sColon = _T(":");
CString sEndl = _T("\r\n");

enum EssayType
{
	Journals = 0,
	Monographs,
	Contributions,
	Dissertations,
	Reports,
	Patents,
	Newspapers,
	Collections,
	Standards
};


// CtestDlg 对话框
class TextInput
{
private:
	int Type;

	CString Author;
	CString Title;
	CString Class;
	CString Edtion;
	CString Place;
	CString Publisher;
	CString Date;
	CString Volume;
	CString Page;	
	CString cAuthor;
	CString cTitle;
	CString pNo;
	CString sNo;
	CString Output;
	bool unComp;

public:
	TextInput()	{ Type = 0; };
	void GetType(int iType){ Type = iType; Class = TypeAbbr[iType]; };
	int ShowType(void){ return Type; };
	CString OutputText();
	void GetAuthor(CString iAuthor){Author = iAuthor; };
	void GetTitle(CString iTitle){ Title = iTitle; };
	void GetPlace(CString iPlace){ Place = iPlace; };
	void GetPublisher(CString iPublisher){  Publisher = iPublisher; };
	void GetDate(CString iDate){ Date = iDate; };
	void GetVolume(CString iVolume){ Volume = iVolume; };
	void GetPage(CString iPage){ Page = iPage; };
	void GetpNo(CString ipNo){ pNo = ipNo; };
	void GetsNo(CString isNo){ sNo = isNo; };
	void GetEdtion(CString iEdtion){ Edtion = iEdtion; };
	void GetcAuthor(CString icAuthor){ cAuthor = icAuthor; };
	void GetcTitle(CString icTitle){ cTitle = icTitle; };
	void ResetData(void);
};

void TextInput::ResetData(void)
{
	Author = '\0';
	Title = '\0';
	Class = '\0';
	Edtion = '\0';
	Place = '\0';
	Publisher = '\0';
	Date = '\0';
	Volume = '\0';
	Page = '\0';
	cAuthor = '\0';
	cTitle = '\0';
	pNo = '\0';
	sNo = '\0';
	Output = '\0';
	Type = 0;
}


CString TextInput::OutputText()
{
	switch (Type)
	{
	case Journals:
		Output = Author + Title + Class + Publisher + Date + Volume + Page;
		break;
	case Monographs:
		Output = Author + Title + Class + Edtion + Place + Publisher + Date + Page;
		break;
	case Contributions:
		Output = Author + Title + Class + cAuthor + cTitle + Place + Publisher + Page;
		break;
	case Dissertations:
		Output = Author + Title + Class + Place + Publisher + Date;
		break;
	case Reports:
		Output = Author + Title + Class + Place + Publisher + Date;
		break;
	case Patents:
		Output = Author + Title + Class + Place + pNo + Date;
		break;
	case Newspapers:
		Output = Author + Title + Class + Publisher + Date + Volume;
		break;
	case Collections:
		Output = Author + Title + Class + Place + Publisher + Date;
		break;
	case Standards:
		Output = Title + Class + sNo;
		break;
	default:
		Output = "发生错误！请重新输入！";
	}

	if (Output.IsEmpty())
	{
		return Output;
	}
	else
	{
		return (Output + sEndl);
	}

}

TextInput fText;


CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CtestDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_ComboxCtrl);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_EN_CHANGE(IDC_EDIT1, &CtestDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CtestDlg::OnEnChangeEdit2)
	ON_EN_CHANGE(IDC_EDIT3, &CtestDlg::OnEnChangeEdit3)
	ON_EN_CHANGE(IDC_EDIT4, &CtestDlg::OnEnChangeEdit4)
	ON_EN_CHANGE(IDC_EDIT5, &CtestDlg::OnEnChangeEdit5)
	ON_EN_CHANGE(IDC_EDIT6, &CtestDlg::OnEnChangeEdit6)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CtestDlg::OnCbnSelchangeCombo1)	
	ON_BN_CLICKED(IDOK, &CtestDlg::OnBnClickedOk)

	ON_EN_CHANGE(IDC_EDIT8, &CtestDlg::OnEnChangeEdit8)
	ON_BN_CLICKED(IDCANCEL, &CtestDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CtestDlg 消息处理程序

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码 
	m_ComboxCtrl.AddString(_T("期刊文献"));
	m_ComboxCtrl.AddString(_T("专著图书"));
	m_ComboxCtrl.AddString(_T("专著析出文献"));
	m_ComboxCtrl.AddString(_T("学位论文"));
	m_ComboxCtrl.AddString(_T("报告文献"));
	m_ComboxCtrl.AddString(_T("专利文献"));
	m_ComboxCtrl.AddString(_T("报纸文献"));
	m_ComboxCtrl.AddString(_T("论文集、会议录"));
	m_ComboxCtrl.AddString(_T("国际标准"));

	// 默认选择第一项   
	m_ComboxCtrl.SetCurSel(0);
	fText.GetType(m_ComboxCtrl.GetCurSel());
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT18)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT19)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT20)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT21)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
	GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
	SetDlgItemText(IDC_EDIT11, _T("作者"));
	SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
	SetDlgItemText(IDC_EDIT12, _T("题目"));
	SetDlgItemText(IDC_EDIT18, NULL);
	SetDlgItemText(IDC_EDIT13, _T("期刊名"));
	SetDlgItemText(IDC_EDIT19, NULL);
	SetDlgItemText(IDC_EDIT14, _T("出版年份"));
	SetDlgItemText(IDC_EDIT20, NULL);
	SetDlgItemText(IDC_EDIT15, _T("卷号(期号)"));
	SetDlgItemText(IDC_EDIT21, NULL);
	SetDlgItemText(IDC_EDIT16, _T("起止页码"));
	SetDlgItemText(IDC_EDIT22, _T("如：31-34"));

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	//SetDlgItemText(IDC_EDIT2, fText.OutputText());
}



void CtestDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CtestDlg::OnEnChangeEdit3()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CtestDlg::OnEnChangeEdit4()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CtestDlg::OnEnChangeEdit5()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CtestDlg::OnEnChangeEdit6()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}

void CtestDlg::OnEnChangeEdit8()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CtestDlg::OnCbnSelchangeCombo1()
{
	// TODO:  在此添加控件通知处理程序代码
	GetDlgItem(IDC_EDIT3)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT13)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT18)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT4)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT14)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT19)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT5)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT15)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT20)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT6)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT16)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT21)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT8)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT23)->ShowWindow(SW_SHOW);
	GetDlgItem(IDC_EDIT24)->ShowWindow(SW_SHOW);
	SetDlgItemText(IDC_EDIT11, NULL);
	SetDlgItemText(IDC_EDIT17, NULL);
	SetDlgItemText(IDC_EDIT12, NULL);
	SetDlgItemText(IDC_EDIT18, NULL);
	SetDlgItemText(IDC_EDIT13, NULL);
	SetDlgItemText(IDC_EDIT19, NULL);
	SetDlgItemText(IDC_EDIT14, NULL);
	SetDlgItemText(IDC_EDIT20, NULL);
	SetDlgItemText(IDC_EDIT15, NULL);
	SetDlgItemText(IDC_EDIT21, NULL);
	SetDlgItemText(IDC_EDIT16, NULL);
	SetDlgItemText(IDC_EDIT22, NULL);
	SetDlgItemText(IDC_EDIT23, NULL);
	SetDlgItemText(IDC_EDIT24, NULL);

	int nSel;

	// 获取组合框控件的列表框中选中项的索引   
	nSel = m_ComboxCtrl.GetCurSel();
	fText.GetType(nSel);
	switch (fText.ShowType())
	{
	case Journals:
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("期刊名"));
		SetDlgItemText(IDC_EDIT14, _T("出版年份"));
		SetDlgItemText(IDC_EDIT15, _T("卷号(期号)"));
		SetDlgItemText(IDC_EDIT16, _T("起止页码"));
		SetDlgItemText(IDC_EDIT22, _T("如：31-34"));
		break;
	case Monographs:
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("书名"));
		SetDlgItemText(IDC_EDIT13, _T("版本"));
		SetDlgItemText(IDC_EDIT19, _T("第一版不写"));
		SetDlgItemText(IDC_EDIT14, _T("出版地"));
		SetDlgItemText(IDC_EDIT15, _T("出版社"));
		SetDlgItemText(IDC_EDIT16, _T("出版年份"));
		SetDlgItemText(IDC_EDIT23, _T("起止页码"));
		SetDlgItemText(IDC_EDIT24, _T("如：31-34"));
		break;
	case Contributions:
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("专著作者"));
		SetDlgItemText(IDC_EDIT14, _T("专著题名"));
		SetDlgItemText(IDC_EDIT15, _T("出版地"));
		SetDlgItemText(IDC_EDIT16, _T("出版社"));
		SetDlgItemText(IDC_EDIT23, _T("起止页码"));
		SetDlgItemText(IDC_EDIT24, _T("如：31-34"));
		break;
	case Dissertations:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("保存地"));
		SetDlgItemText(IDC_EDIT14, _T("保存单位"));
		SetDlgItemText(IDC_EDIT15, _T("年份"));
		break;
	case Reports:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("报告地"));
		SetDlgItemText(IDC_EDIT14, _T("主办单位"));
		SetDlgItemText(IDC_EDIT15, _T("报告年份"));
		break;
	case Patents:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("专利申请者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("专利题名"));
		SetDlgItemText(IDC_EDIT13, _T("申请国别"));
		SetDlgItemText(IDC_EDIT14, _T("专利号"));
		SetDlgItemText(IDC_EDIT15, _T("公告日期[引用日期]"));
		SetDlgItemText(IDC_EDIT21, _T("如：2009[2012]"));
		break;
	case Newspapers:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("报纸名"));
		SetDlgItemText(IDC_EDIT14, _T("出版时间"));
		SetDlgItemText(IDC_EDIT15, _T("版次"));
		break;
	case Collections:
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("作者"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("题目"));
		SetDlgItemText(IDC_EDIT13, _T("出版地"));
		SetDlgItemText(IDC_EDIT14, _T("出版单位"));
		SetDlgItemText(IDC_EDIT15, _T("出版年份"));
		SetDlgItemText(IDC_EDIT16, _T("起止页码"));
		SetDlgItemText(IDC_EDIT22, _T("如：31-34"));
		break;
	case Standards:
		GetDlgItem(IDC_EDIT3)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT13)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT18)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT4)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT14)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT19)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT5)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT15)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT20)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);

		SetDlgItemText(IDC_EDIT11, _T("标准名称"));
		SetDlgItemText(IDC_EDIT17, _T("如：张三, 赵四"));
		SetDlgItemText(IDC_EDIT12, _T("标准编号"));
		break;
	default:
		;
	}
}


void CtestDlg::OnBnClickedOk()
{
	// TODO:  在此添加控件通知处理程序代码
	//CDialogEx::OnOK();
	CString str;

	fText.GetType(m_ComboxCtrl.GetCurSel());

	switch (fText.ShowType())
	{
	case Journals:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetDate(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetVolume(str);
		GetDlgItemText(IDC_EDIT6, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetPage(str);
		break;
	case Monographs:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetEdtion(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT6, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetDate(str);
		GetDlgItemText(IDC_EDIT8, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetPage(str);
		break;
	case Contributions:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetcAuthor(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetcTitle(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT6, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT8, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetPage(str);
		break;
	case Dissertations:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetDate(str);
		break;
	case Reports:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetDate(str);
		break;
	case Patents:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetpNo(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetDate(str);
		break;
	case Newspapers:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += '(';
		fText.GetDate(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += ')' + sDot;
		fText.GetVolume(str);
		break;
	case Collections:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetAuthor(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT3, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPlace(str);
		GetDlgItemText(IDC_EDIT4, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sCommas;
		fText.GetPublisher(str);
		GetDlgItemText(IDC_EDIT5, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sColon;
		fText.GetDate(str);
		GetDlgItemText(IDC_EDIT6, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		str += sDot;
		fText.GetDate(str);
		break;
	case Standards:
		GetDlgItemText(IDC_EDIT1, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetTitle(str);
		GetDlgItemText(IDC_EDIT2, str);
		if (str.IsEmpty())return;
		str.Remove(' ');
		fText.GetsNo(str);
		break;
	default:
		;
	}

	GetDlgItemText(IDC_EDIT7, str);
	SetDlgItemText(IDC_EDIT7, str + fText.OutputText());
	fText.ResetData();
}




void CtestDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}



void CtestDlg::OnBnClickedButton1()
{
	// TODO:  在此添加控件通知处理程序代码
	fText.ResetData();
	SetDlgItemText(IDC_EDIT1, NULL);
	SetDlgItemText(IDC_EDIT2, NULL);
	SetDlgItemText(IDC_EDIT3, NULL);
	SetDlgItemText(IDC_EDIT4, NULL);
	SetDlgItemText(IDC_EDIT5, NULL);
	SetDlgItemText(IDC_EDIT6, NULL);
	SetDlgItemText(IDC_EDIT8, NULL);
	SetDlgItemText(IDC_EDIT7, NULL);
	fText.GetType(m_ComboxCtrl.GetCurSel());
}
