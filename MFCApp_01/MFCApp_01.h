
// MFCApp_01.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCApp01App:
// See MFCApp_01.cpp for the implementation of this class
//

class CMFCApp01App : public CWinApp
{
public:
	CMFCApp01App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCApp01App theApp;
