// DlgConfig.cpp : �C���v�������e�[�V���� �t�@�C��
//

#include "stdafx.h"
#include "CompDel.h"
#include "DlgConfig.h"
#include "DlgAbout.h"
#include "DlgConfirm.h"

#include "InstFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlgPDel �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(CDlgPDel, CPropertyPage)

CDlgPDel::CDlgPDel() : CPropertyPage(CDlgPDel::IDD)
{
	//{{AFX_DATA_INIT(CDlgPDel)
	m_Date = FALSE;
	m_nOvwr = 0;
	m_rNull = -1;
	m_rZLen = -1;
	m_rRen = -1;
	//}}AFX_DATA_INIT
}

CDlgPDel::~CDlgPDel()
{
}

void CDlgPDel::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPDel)
	DDX_Check(pDX, IDC_C_DATE, m_Date);
	DDX_Text(pDX, IDC_EDIT_NTIMES, m_nOvwr);
	DDV_MinMaxInt(pDX, m_nOvwr, 1, 5);
	DDX_Radio(pDX, IDC_R1_NULL, m_rNull);
	DDX_Radio(pDX, IDC_R2_ZLEN, m_rZLen);
	DDX_Radio(pDX, IDC_R3_NNAME, m_rRen);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPDel, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPDel)
		// ����: ClassWizard �͂��̈ʒu�� DDX ����� DDV �̌Ăяo���R�[�h��ǉ����܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPDel ���b�Z�[�W �n���h��
/////////////////////////////////////////////////////////////////////////////
// CDlgPDisp �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(CDlgPDisp, CPropertyPage)

CDlgPDisp::CDlgPDisp() : CPropertyPage(CDlgPDisp::IDD)
{
	//{{AFX_DATA_INIT(CDlgPDisp)
	m_Confirm = FALSE;
	m_DispF = FALSE;
	m_NDispE = FALSE;
	m_NDispN = FALSE;
	m_Log = FALSE;
	//}}AFX_DATA_INIT
}

CDlgPDisp::~CDlgPDisp()
{
}

void CDlgPDisp::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPDisp)
	DDX_Check(pDX, IDC_C_DISPC, m_Confirm);
	DDX_Check(pDX, IDC_C_DISPF, m_DispF);
	DDX_Check(pDX, IDC_C_NDISPE, m_NDispE);
	DDX_Check(pDX, IDC_C_NDISPN, m_NDispN);
	DDX_Check(pDX, IDC_C_DISPF2, m_Log);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPDisp, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPDisp)
		// ����: ClassWizard �͂��̈ʒu�� DDX ����� DDV �̌Ăяo���R�[�h��ǉ����܂��B
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPDisp ���b�Z�[�W �n���h��
/////////////////////////////////////////////////////////////////////////////
// CDlgPOther �v���p�e�B �y�[�W

IMPLEMENT_DYNCREATE(CDlgPOther, CPropertyPage)

CDlgPOther::CDlgPOther() : CPropertyPage(CDlgPOther::IDD)
{
	//{{AFX_DATA_INIT(CDlgPOther)
	m_Dummy = FALSE;
	m_DummySkip = FALSE;
	m_nFiles = 0;
	//}}AFX_DATA_INIT
}

CDlgPOther::~CDlgPOther()
{
}

void CDlgPOther::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlgPOther)
	DDX_Control(pDX, IDC_EDIT_NFILES, m_ctrl_nFiles);
	DDX_Control(pDX, IDC_C_DMYSKIP, m_ctrl_dmyskip);
	DDX_Check(pDX, IDC_C_DMY, m_Dummy);
	DDX_Check(pDX, IDC_C_DMYSKIP, m_DummySkip);
	DDX_Text(pDX, IDC_EDIT_NFILES, m_nFiles);
	DDV_MinMaxInt(pDX, m_nFiles, 1, 99);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlgPOther, CPropertyPage)
	//{{AFX_MSG_MAP(CDlgPOther)
	ON_BN_CLICKED(IDC_UNINSTALL, OnUninstall)
	ON_BN_CLICKED(IDC_VERINFO, OnVerinfo)
	ON_BN_CLICKED(IDC_C_DMY, OnCDmy)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlgPOther ���b�Z�[�W �n���h��

void CDlgPOther::OnUninstall() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	CString sAfxMsg;
	::RmUninstMnu();
	::MkUninstMnu();	// �X�^�[�g���j���[�ɃA���C���X�g�[�����j���[��ǉ�

	sAfxMsg.LoadString(AFX_STR_DLG_MKUNIN);	// �A���C���X�g�[���p�̃V���[�g�J�b�g���쐬���܂���
	MessageBox((LPCSTR)sAfxMsg, "CompleteDelete Information", MB_ICONINFORMATION|MB_OK);
}

void CDlgPOther::OnVerinfo() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	// �o�[�W�������̕\��
	CDlgAbout dlg;
	dlg.DoModal();
}


// �R���g���[�����D�F�\���ɂ���i�����ɂ���j����
void CDlgPOther::OnCDmy() 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	if(!IsDlgButtonChecked(IDC_C_DMY))
	{
		m_ctrl_dmyskip.EnableWindow(FALSE);
		m_ctrl_nFiles.EnableWindow(FALSE);
	}
	else
	{
		m_ctrl_dmyskip.EnableWindow(TRUE);
		m_ctrl_nFiles.EnableWindow(TRUE);
	}
}

BOOL CDlgPOther::OnInitDialog() 
{
	CPropertyPage::OnInitDialog();
	
	// TODO: ���̈ʒu�ɏ������̕⑫������ǉ����Ă�������
	if(!IsDlgButtonChecked(IDC_C_DMY))
	{
		m_ctrl_dmyskip.EnableWindow(FALSE);	
		m_ctrl_nFiles.EnableWindow(FALSE);
	}
	return TRUE;  // �R���g���[���Ƀt�H�[�J�X��ݒ肵�Ȃ��Ƃ��A�߂�l�� TRUE �ƂȂ�܂�
	              // ��O: OCX �v���p�e�B �y�[�W�̖߂�l�� FALSE �ƂȂ�܂�
}
