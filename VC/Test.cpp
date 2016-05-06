// test1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "test.h"
#include "protocol.h"
#include "fpengine.h"
#include <commctrl.h>
#include <strsafe.h>


HINSTANCE	hInst;			// The current instance
BYTE		RefBuf[512];
int			RefSize=0;
BYTE		MatBuf[256];
int			MatSize=0;

int			g_count=1;


LRESULT CALLBACK	MainDlg			(HWND, UINT, WPARAM, LPARAM);

int WINAPI _tWinMain(	HINSTANCE hInstance,HINSTANCE hPrevInstance,LPTSTR    lpCmdLine,int       nCmdShow)
{
	return (int) DialogBox(hInstance, (LPCTSTR)IDD_ABOUTBOX, NULL, (DLGPROC)MainDlg);;
}

// Mesage handler for the About box.
LRESULT CALLBACK MainDlg(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
			{
				SetMsgMainHandle(hDlg);	//ʹ����Ϣģʽ
				SetDlgItemInt(hDlg,IDC_EDIT1,1,TRUE);
				SetDlgItemInt(hDlg,IDC_EDIT2,115200,TRUE);
				CheckRadioButton(hDlg,IDC_RADIO1,IDC_RADIO2,IDC_RADIO1);
				SetDispOption(FALSE,1.0,RGB(255,255,255),RGB(255,0,0),0);
			}
			return TRUE;
		case WM_NCLMESSAGE:	//ʹ����Ϣģʽ
			{
				switch(wParam)
				{
				case FPM_DEVICE:
					SetDlgItemText(hDlg,IDC_STATUS,_T("���ȴ��豸"));
					break;
				case FPM_PLACE:
					SetDlgItemText(hDlg,IDC_STATUS,_T("�밴��ָ"));
					break;
				case FPM_LIFT:
					SetDlgItemText(hDlg,IDC_STATUS,_T("��̧����ָ"));
					break;
				case FPM_TIMEOUT:
					SetDlgItemText(hDlg,IDC_STATUS,_T("�ȴ���ʱ"));
					break;
				case FPM_NEWIMAGE:
					DrawImage(GetDC(hDlg),20,50);
					break;
				case FPM_ENRFPT:
					{
						if(lParam==1)
						{
							SetDlgItemText(hDlg,IDC_STATUS,_T("�Ǽǳɹ�"));
							GetFpCharByEnl(RefBuf,&RefSize);
						}
						else
						{
							SetDlgItemText(hDlg,IDC_STATUS,_T("�Ǽ�ʧ��"));
						}
					}
					break;
				case FPM_GENCHAR:
					{
						if(lParam==1)
						{	
							SetDlgItemText(hDlg,IDC_STATUS,_T("��ȡͼ��ɹ�"));
							GetFpCharByGen(MatBuf,&MatSize);

							if(RefSize>0)
							{
								int ret=MatchTemplateOne(MatBuf,RefBuf,RefSize);
								if(ret>30)
								{
									SetDlgItemText(hDlg,IDC_STATUS,_T("�ȶԳɹ�"));
								}
								else
								{
									SetDlgItemText(hDlg,IDC_STATUS,_T("�ȶ�ʧ��"));
								}
							}
						}
						else
						{
							SetDlgItemText(hDlg,IDC_STATUS,_T("��ȡ������ʧ��"));
						}
					}
					break;
				}
			}
			return TRUE;
			break;
		case WM_COMMAND:
			if ((LOWORD(wParam) == IDOK) || (LOWORD(wParam) == IDCANCEL))
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}else
			{
				switch(LOWORD(wParam))
				{
				case IDC_BUTTON1:
					{
						CloseDevice();
						int n1,n2,n3;
						n1=GetDlgItemInt(hDlg,IDC_EDIT1,NULL,TRUE);
						n2=GetDlgItemInt(hDlg,IDC_EDIT2,NULL,TRUE);
						if(IsDlgButtonChecked(hDlg,IDC_RADIO1))
							n3=0;
						else if(IsDlgButtonChecked(hDlg,IDC_RADIO2))
							n3=1;
						else
							n3=0;						
						if(OpenDevice(n1,n2,n3)==RET_OK)
						{
							if(LinkDevice()==RET_OK)
							{
								MessageBox(hDlg,_T("���豸�ɹ�"),_T("�ɹ�"),0);
							}
							else
							{
								MessageBox(hDlg,_T("���豸ʧ��"),_T("ʧ��"),0);
							}
						}
						else
						{
							MessageBox(hDlg,_T("���豸ʧ��"),_T("ʧ��"),0);
						}
					}
					break;				
				case IDC_BUTTON4:
					EnrolFpChar();
					break;
				case IDC_BUTTON5:
					GenFpChar();
					break;
				}
			}
			break;
	}
    return FALSE;
}
