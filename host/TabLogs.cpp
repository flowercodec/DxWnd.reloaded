// TabLogs.cpp : implementation file
//

#include "stdafx.h"
#include "TargetDlg.h"
#include "TabLogs.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTabLogs dialog

CTabLogs::CTabLogs(CWnd* pParent /*=NULL*/)
	: CDialog(CTabLogs::IDD, pParent)
{
	//{{AFX_DATA_INIT(CTabLogs)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

BOOL CTabLogs::OnInitDialog()
{
	extern BOOL gbDebug;
	CDialog::OnInitDialog();
	(CButton *)(this->GetDlgItem(IDC_DXPROXED))->EnableWindow(gbDebug ? TRUE : FALSE);
	(CButton *)(this->GetDlgItem(IDC_ASSERT))->EnableWindow(gbDebug ? TRUE : FALSE);
	return TRUE;
}

void CTabLogs::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	CTargetDlg *cTarget = ((CTargetDlg *)(this->GetParent()->GetParent()));
	extern BOOL gbDebug;
	DDX_Check(pDX, IDC_OUTTRACE, cTarget->m_OutTrace);
	DDX_Check(pDX, IDC_OUTDEBUG, cTarget->m_OutDebug);
	DDX_Check(pDX, IDC_CURSORTRACE, cTarget->m_CursorTrace);
	DDX_Check(pDX, IDC_LOGENABLED, cTarget->m_LogEnabled);
	DDX_Check(pDX, IDC_OUTWINMESSAGES, cTarget->m_OutWinMessages);
	DDX_Check(pDX, IDC_OUTDXTRACE, cTarget->m_OutDXTrace);
	DDX_Check(pDX, IDC_IMPORTTABLE, cTarget->m_ImportTable);
	DDX_Check(pDX, IDC_OUTREGISTRY, cTarget->m_RegistryOp);
	DDX_Check(pDX, IDC_TRACEHOOKS, cTarget->m_TraceHooks);
	if(gbDebug){
		DDX_Check(pDX, IDC_DXPROXED, cTarget->m_DXProxed);
		DDX_Check(pDX, IDC_ASSERT, cTarget->m_AssertDialog);
	}
}

BEGIN_MESSAGE_MAP(CTabLogs, CDialog)
	//{{AFX_MSG_MAP(CTabLogs)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTabLogs message handlers
