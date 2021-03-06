// dxwndhost.h : DXWNDHOST Application's main header file
//

#if !defined(AFX_DXWNDHOST_H__C68B92A2_C45F_4B59_986D_5BBC6BAD3AD8__INCLUDED_)
#define AFX_DXWNDHOST_H__C68B92A2_C45F_4B59_986D_5BBC6BAD3AD8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // Main symbols

extern int MessageBoxLang(UINT, UINT, UINT);
extern int MessageBoxLangArg(UINT, UINT, UINT, ...);

// DxWnd host app private data
// fields here are associated to TARGETMAP records, but need not to be passed
// to the dxwnd hook callback, so they are left in a separate array to save 
// the (limited) IPC space and allow for more record entryes (currently 255).

#define MAX_NOTES 1024
#define MAX_REGISTRY 2048
#define MAX_TITLE 80

typedef struct PRIVATEMAP
{
	char title[MAX_TITLE+1];
	char launchpath[MAX_PATH+1];
	char startfolder[MAX_PATH+1];
	char *notes;
	char *registry;
}PRIVATEMAP;

typedef struct {
	TARGETMAP *TM;
	PRIVATEMAP *PM;
	char *ExePath;
} ThreadInfo_Type;
ThreadInfo_Type;

extern char gInitPath[MAX_PATH+1];
extern void OutTrace(const char *, ...);

/////////////////////////////////////////////////////////////////////////////
// CDxwndhostApp:
// For the definition of this class action please see the file dxwndhost.cpp.
//

class CDxwndhostApp : public CWinApp
{
public:
	CDxwndhostApp();

// Override
	// ClassWizard Generates a virtual function overrides.
	//{{AFX_VIRTUAL(CDxwndhostApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDxwndhostApp)
	afx_msg void OnAppAbout();
	afx_msg void OnViewHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ Will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DXWNDHOST_H__C68B92A2_C45F_4B59_986D_5BBC6BAD3AD8__INCLUDED_)
