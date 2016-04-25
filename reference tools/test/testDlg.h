
// testDlg.h : 头文件
//

#pragma once
#include "afxwin.h"


// CtestDlg 对话框
class CtestDlg : public CDialogEx
{
// 构造
public:
	CtestDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox m_ComboxCtrl;
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit4();
	afx_msg void OnEnChangeEdit5();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnEnChangeEdit6();
	afx_msg void OnCbnSelchangeCombo1();

	afx_msg void OnEnChangeEdit3();
	afx_msg void OnBnClickedOk();
	
	afx_msg void OnLbnSelchangeList3();
	afx_msg void OnEnChangeEdit7();
	afx_msg void OnEnChangeEdit11();
	afx_msg void OnEnChangeEdit15();
	afx_msg void OnEnChangeEdit8();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedCancel2();
	afx_msg void OnBnClickedButton1();
};
