// DlgHelpDoc.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CompDel.h"
#include "DlgHelpDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgHelpDoc �_�C�A���O


CDlgHelpDoc::CDlgHelpDoc(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgHelpDoc::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgHelpDoc)
	m_edit_main = _T("");
	//}}AFX_DATA_INIT
}


void CDlgHelpDoc::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgHelpDoc)
	DDX_Text(pDX, IDC_EDIT_MAIN, m_edit_main);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgHelpDoc, CDialog)
	//{{AFX_MSG_MAP(CDlgHelpDoc)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgHelpDoc ���b�Z�[�W �n���h��
