// DlgNorm.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CompDel.h"
#include "DlgNorm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgNorm �_�C�A���O


CDlgNorm::CDlgNorm(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgNorm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgNorm)
	//}}AFX_DATA_INIT
}


void CDlgNorm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgNorm)
	DDX_Control(pDX, IDC_PRGRESS, m_Progress);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgNorm, CDialog)
	//{{AFX_MSG_MAP(CDlgNorm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgNorm ���b�Z�[�W �n���h��


BOOL CDlgNorm::Create() 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	
	return CDialog::Create(IDD, NULL/*pParentWnd*/);
}


