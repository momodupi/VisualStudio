
// testDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CtestDlg �Ի���
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
		Output = "�����������������룡";
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


// CtestDlg ��Ϣ�������

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������ 
	m_ComboxCtrl.AddString(_T("�ڿ�����"));
	m_ComboxCtrl.AddString(_T("ר��ͼ��"));
	m_ComboxCtrl.AddString(_T("ר����������"));
	m_ComboxCtrl.AddString(_T("ѧλ����"));
	m_ComboxCtrl.AddString(_T("��������"));
	m_ComboxCtrl.AddString(_T("ר������"));
	m_ComboxCtrl.AddString(_T("��ֽ����"));
	m_ComboxCtrl.AddString(_T("���ļ�������¼"));
	m_ComboxCtrl.AddString(_T("���ʱ�׼"));

	// Ĭ��ѡ���һ��   
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
	SetDlgItemText(IDC_EDIT11, _T("����"));
	SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
	SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
	SetDlgItemText(IDC_EDIT18, NULL);
	SetDlgItemText(IDC_EDIT13, _T("�ڿ���"));
	SetDlgItemText(IDC_EDIT19, NULL);
	SetDlgItemText(IDC_EDIT14, _T("�������"));
	SetDlgItemText(IDC_EDIT20, NULL);
	SetDlgItemText(IDC_EDIT15, _T("���(�ں�)"));
	SetDlgItemText(IDC_EDIT21, NULL);
	SetDlgItemText(IDC_EDIT16, _T("��ֹҳ��"));
	SetDlgItemText(IDC_EDIT22, _T("�磺31-34"));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	//SetDlgItemText(IDC_EDIT2, fText.OutputText());
}



void CtestDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



void CtestDlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CtestDlg::OnEnChangeEdit4()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CtestDlg::OnEnChangeEdit5()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CtestDlg::OnEnChangeEdit6()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}

void CtestDlg::OnEnChangeEdit8()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CtestDlg::OnCbnSelchangeCombo1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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

	// ��ȡ��Ͽ�ؼ����б����ѡ���������   
	nSel = m_ComboxCtrl.GetCurSel();
	fText.GetType(nSel);
	switch (fText.ShowType())
	{
	case Journals:
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("�ڿ���"));
		SetDlgItemText(IDC_EDIT14, _T("�������"));
		SetDlgItemText(IDC_EDIT15, _T("���(�ں�)"));
		SetDlgItemText(IDC_EDIT16, _T("��ֹҳ��"));
		SetDlgItemText(IDC_EDIT22, _T("�磺31-34"));
		break;
	case Monographs:
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("����"));
		SetDlgItemText(IDC_EDIT13, _T("�汾"));
		SetDlgItemText(IDC_EDIT19, _T("��һ�治д"));
		SetDlgItemText(IDC_EDIT14, _T("�����"));
		SetDlgItemText(IDC_EDIT15, _T("������"));
		SetDlgItemText(IDC_EDIT16, _T("�������"));
		SetDlgItemText(IDC_EDIT23, _T("��ֹҳ��"));
		SetDlgItemText(IDC_EDIT24, _T("�磺31-34"));
		break;
	case Contributions:
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("ר������"));
		SetDlgItemText(IDC_EDIT14, _T("ר������"));
		SetDlgItemText(IDC_EDIT15, _T("�����"));
		SetDlgItemText(IDC_EDIT16, _T("������"));
		SetDlgItemText(IDC_EDIT23, _T("��ֹҳ��"));
		SetDlgItemText(IDC_EDIT24, _T("�磺31-34"));
		break;
	case Dissertations:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("�����"));
		SetDlgItemText(IDC_EDIT14, _T("���浥λ"));
		SetDlgItemText(IDC_EDIT15, _T("���"));
		break;
	case Reports:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("�����"));
		SetDlgItemText(IDC_EDIT14, _T("���쵥λ"));
		SetDlgItemText(IDC_EDIT15, _T("�������"));
		break;
	case Patents:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("ר��������"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("ר������"));
		SetDlgItemText(IDC_EDIT13, _T("�������"));
		SetDlgItemText(IDC_EDIT14, _T("ר����"));
		SetDlgItemText(IDC_EDIT15, _T("��������[��������]"));
		SetDlgItemText(IDC_EDIT21, _T("�磺2009[2012]"));
		break;
	case Newspapers:
		GetDlgItem(IDC_EDIT6)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT16)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT22)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("��ֽ��"));
		SetDlgItemText(IDC_EDIT14, _T("����ʱ��"));
		SetDlgItemText(IDC_EDIT15, _T("���"));
		break;
	case Collections:
		GetDlgItem(IDC_EDIT8)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT23)->ShowWindow(SW_HIDE);
		GetDlgItem(IDC_EDIT24)->ShowWindow(SW_HIDE);
		SetDlgItemText(IDC_EDIT11, _T("����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��Ŀ"));
		SetDlgItemText(IDC_EDIT13, _T("�����"));
		SetDlgItemText(IDC_EDIT14, _T("���浥λ"));
		SetDlgItemText(IDC_EDIT15, _T("�������"));
		SetDlgItemText(IDC_EDIT16, _T("��ֹҳ��"));
		SetDlgItemText(IDC_EDIT22, _T("�磺31-34"));
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

		SetDlgItemText(IDC_EDIT11, _T("��׼����"));
		SetDlgItemText(IDC_EDIT17, _T("�磺����, ����"));
		SetDlgItemText(IDC_EDIT12, _T("��׼���"));
		break;
	default:
		;
	}
}


void CtestDlg::OnBnClickedOk()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}



void CtestDlg::OnBnClickedButton1()
{
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
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
