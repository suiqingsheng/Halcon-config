
// CPP_MFC_PlusDlg.cpp: 实现文件
//

#include "stdafx.h"
#include "CPP_MFC_Plus.h"
#include "CPP_MFC_PlusDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCPPMFCPlusDlg 对话框



CCPPMFCPlusDlg::CCPPMFCPlusDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_CPP_MFC_PLUS_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCPPMFCPlusDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCPPMFCPlusDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCPPMFCPlusDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CCPPMFCPlusDlg 消息处理程序

BOOL CCPPMFCPlusDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CCPPMFCPlusDlg::OnPaint()
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
HCURSOR CCPPMFCPlusDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



////
//HWND hwnd1 = GetDlgItem(IDC_STATIC)->m_hWnd;
//Hlong MainWndID = (Hlong)hwnd1;



void CCPPMFCPlusDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	


	
	//第二步
	// Local iconic variables
	HObject  ho_Image;

	// Local control variables
	HTuple  hv_Width, hv_Height, hv_WindowHandle;

	//第三步
	/*if (HDevWindowStack::IsOpen())
		CloseWindow(HDevWindowStack::Pop());*/

	ReadImage(&ho_Image, "D:/Visual studio 2017/Projects/Halcon-Config/res/2.jpg");
	GetImageSize(ho_Image, &hv_Width, &hv_Height);
	
	//第四步，其中IDC_STATIC为Picture Control的ID
	HWND hImgWnd = GetDlgItem(IDC_STATIC)->m_hWnd;
	


	SetWindowAttr("background_color", "black");

	//第五步
	//修改后的语句，将原来的0改成(LONG)hImgWnd
	OpenWindow(0, 0, hv_Width, hv_Height, (LONG)hImgWnd, "visible", "", &hv_WindowHandle);
	//原来的语句
	//OpenWindow(0, 0, hv_Width, hv_Height, 0, "visible", "", &hv_WindowHandle);

	
	HDevWindowStack::Push(hv_WindowHandle);
	if (HDevWindowStack::IsOpen())
		SetPart(HDevWindowStack::GetActive(), 0, 0, hv_Height - 1, hv_Width - 1);
	if (HDevWindowStack::IsOpen())
		DispObj(ho_Image, HDevWindowStack::GetActive());



}
