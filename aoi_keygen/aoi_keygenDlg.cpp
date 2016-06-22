
// aoi_keygenDlg.cpp : implementation file
//

#include "stdafx.h"
#include "aoi_keygen.h"
#include "aoi_keygenDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Caoi_keygenDlg dialog



unsigned int key[] =
{ 0xFB, 0xDF, 0xC8, 0xCE, 0xD9, 0xD9, 0xC4, 0xE8 };

unsigned int get_hash(char *name)
{
	unsigned int temp, anser = 1;
	int i = 0, j;
	unsigned char sum = 0;

	while (name[i]) {
		sum += name[i];
		i++;
	}
	for (j = 0; j < 8; j++) {
		sum ^= key[j];
		temp = sum % 10;
		temp++;
		anser *= temp;
	}
	anser ^= 0x0BC614E;

	return anser;
}



Caoi_keygenDlg::Caoi_keygenDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_AOI_KEYGEN_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Caoi_keygenDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(Caoi_keygenDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &Caoi_keygenDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// Caoi_keygenDlg message handlers

BOOL Caoi_keygenDlg::OnInitDialog()
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

void Caoi_keygenDlg::OnPaint()
{
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
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Caoi_keygenDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void Caoi_keygenDlg::OnBnClickedButton1()
{
	// TODO: ここにコントロール通知ハンドラー コードを追加します。
	char input[100];
	char output[100];

	this->GetDlgItemTextA(IDC_EDIT1, input, 99);

	sprintf_s(output, "%u", get_hash(input));

	this->SetDlgItemTextA(IDC_EDIT2, output);
}
