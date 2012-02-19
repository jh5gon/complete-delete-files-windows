// DlgConfirm.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CompDel.h"
#include "DlgConfirm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgConfirm �_�C�A���O


CDlgConfirm::CDlgConfirm(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgConfirm::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgConfirm)
	m_mes = _T("");
	//}}AFX_DATA_INIT
}


void CDlgConfirm::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgConfirm)
	DDX_Text(pDX, IDC_MESSAGE, m_mes);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgConfirm, CDialog)
	//{{AFX_MSG_MAP(CDlgConfirm)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgConfirm ���b�Z�[�W �n���h��

void CDlgConfirm::OnCancel() 
{
	// TODO: ���̈ʒu�ɓ��ʂȌ㏈����ǉ����Ă��������B
	
	CDialog::OnCancel();
	EndDialog(FALSE);
}

void CDlgConfirm::OnOK() 
{
	// TODO: ���̈ʒu�ɂ��̑��̌��ؗp�̃R�[�h��ǉ����Ă�������
	
	CDialog::OnOK();
	EndDialog(TRUE);
}
/////////////////////////////////////////////////////////////////////////////
// CDlgInstall �_�C�A���O


CDlgInstall::CDlgInstall(CWnd* pParent /*=NULL*/)
	: CDialog(CDlgInstall::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlgInstall)
	m_CONTEXT = FALSE;
	m_DESKTOP = FALSE;
	m_MENU = FALSE;
	m_UNIN = -1;
	//}}AFX_DATA_INIT
}


void CDlgInstall::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgInstall)
	DDX_Check(pDX, IDC_INST_CONTEXT, m_CONTEXT);
	DDX_Check(pDX, IDC_INST_DESKTOP, m_DESKTOP);
	DDX_Check(pDX, IDC_INST_MENU, m_MENU);
	DDX_Radio(pDX, IDC_RADIO_UNIN, m_UNIN);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgInstall, CDialog)
	//{{AFX_MSG_MAP(CDlgInstall)
	ON_BN_CLICKED(IDC_INSTHLP, OnInsthlp)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgInstall ���b�Z�[�W �n���h��

// ************************************************************
// �w���v�\���֐�
// HTML�w���v�ɑΉ������邽�߂ɁA�N���X�ɑ΂��� WM_HELP ���b�Z�[�W�𑗂�
// (F1�L�[���������Ƃ��́A���̊֐��͒ʂ炸�ɒ��� this->WinHelp() �֐��֍s��
//
// �ŏI�I�ɂ� CCompDelApp �� WinHelp �֐��֓n����AHTML�w���v��\������
// ************************************************************

void CDlgInstall::OnInsthlp() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
		this->SendMessage(WM_HELP);

}

