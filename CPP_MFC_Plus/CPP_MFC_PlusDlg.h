
// CPP_MFC_PlusDlg.h: 头文件
//

#pragma once


//第一步
#include<HalconCpp.h>
#include<HALCONCpp/HDevThread.h>
using namespace HalconCpp;

// CCPPMFCPlusDlg 对话框
class CCPPMFCPlusDlg : public CDialogEx
{
// 构造
public:
	CCPPMFCPlusDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CPP_MFC_PLUS_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
