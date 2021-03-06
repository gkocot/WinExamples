
// MFCApp_01Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "MFCApp_01.h"
#include "MFCApp_01Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCApp01Dlg dialog



CMFCApp01Dlg::CMFCApp01Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPP_01_DIALOG, pParent), m_startIndex(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApp01Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApp01Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
//    ON_WM_LBUTTONDBLCLK()
    ON_WM_RBUTTONUP()
    ON_WM_LBUTTONUP()
END_MESSAGE_MAP()


// CMFCApp01Dlg message handlers

BOOL CMFCApp01Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApp01Dlg::OnPaint()
{
    CPaintDC dc(this);

    CBitmap bmp;
    CDC memDC;
    memDC.CreateCompatibleDC(&dc);
#if 1
    bmp.LoadBitmap(IDB_DIGIT0 + (m_startIndex % 4));
    memDC.SelectObject(&bmp);
    dc.BitBlt(0, 0, 16, 29, &memDC, 0, 0, SRCCOPY);
#else
    for (int i = m_startIndex, j = 0; i < (m_startIndex + 4); ++i, ++j)
    {
        bmp.LoadBitmap(IDB_DIGIT0 + (i % 4));
        memDC.SelectObject(&bmp);
        dc.BitBlt(j * 20, 0, 16, 29, &memDC, 0, 0, SRCCOPY);
        bmp.DeleteObject();
    }
#endif
    //CBrush brush(RGB(0, 255, 0));
    //CBrush * oldbrush = (CBrush *)dc.SelectObject(&brush);
    //
    //CPen pen(PS_SOLID, 1, RGB(255, 0, 0));
    //CPen * oldpen = (CPen*)dc.SelectObject(&pen);
    //
    //CRect rect;
    //GetClientRect(&rect);    
    //dc.Rectangle(&rect);

    //dc.SelectObject(oldbrush);
    //dc.SelectObject(oldpen);
#if 0
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	
#endif
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApp01Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



//void CMFCApp01Dlg::OnLButtonDblClk(UINT nFlags, CPoint point)
//{
//    // TODO: Add your message handler code here and/or call default
//
//    CDialogEx::OnLButtonDblClk(nFlags, point);
//}


void CMFCApp01Dlg::OnRButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    ++m_startIndex;
    RedrawWindow();
}


void CMFCApp01Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
    // TODO: Add your message handler code here and/or call default
    --m_startIndex;
    RedrawWindow();
}
