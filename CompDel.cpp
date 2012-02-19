// CompDel.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
//


#include "stdafx.h"
#include "CompDel.h"
#include "Fileman.h"
#include "DlgConfig.h"
#include "DlgConfirm.h"
#include "DlgHelpDoc.h"

#include "InstFunc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CCompDelApp

BEGIN_MESSAGE_MAP(CCompDelApp, CWinApp)
	//{{AFX_MSG_MAP(CCompDelApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ}�b�s���O�p�̃}�N����ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCompDelApp �N���X�̍\�z

CCompDelApp::CCompDelApp()
{
	// TODO: ���̈ʒu�ɍ\�z�p�̃R�[�h��ǉ����Ă��������B
	// ������ InitInstance ���̏d�v�ȏ��������������ׂċL�q���Ă��������B
}

/////////////////////////////////////////////////////////////////////////////
// �B��� CCompDelApp �I�u�W�F�N�g

CCompDelApp theApp;

/////////////////////////////////////////////////////////////////////////////
// �B��� �t�@�C������t�@�C������ �I�u�W�F�N�g

CFileman MyFile;

/////////////////////////////////////////////////////////////////////////////
// CCompDelApp �N���X�̏�����

BOOL CCompDelApp::InitInstance()
{
	// �W���I�ȏ���������
	// ���������̋@�\���g�p�����A���s�t�@�C���̃T�C�Y��������������
	//  ��Έȉ��̓���̏��������[�`���̒�����s�K�v�Ȃ��̂��폜����
	//  ���������B

#ifdef _AFXDLL
	Enable3dControls();			// ���L DLL ���� MFC ���g���ꍇ�͂������R�[�����Ă��������B
#else
	Enable3dControlsStatic();	// MFC �ƐÓI�Ƀ����N����ꍇ�͂������R�[�����Ă��������B
#endif

	// ���W�X�g���̎w��
	// ���\�[�X��AFX_IDS_APP_TITLE�ɃA�v���P�[�V��������ݒ肷�邱�� 
	// m_pszAppName = "compdel" �Ƃ��Ă͂����Ȃ��I ASSERTION �G���[�ƂȂ�
	SetRegistryKey((LPCTSTR)"hi soft");

	// �R�}���h���C�������̉�͂Ə������s
	ProcessCommandline();
	// �_�C�A���O�������Ă���A�v���P�[�V�����̃��b�Z�[�W �|���v���J�n������́A
	// �A�v���P�[�V�������I�����邽�߂� FALSE ��Ԃ��Ă��������B
	return FALSE;
}

// ************************************************************
// �R�}���h���C�������ɂ��U�蕪��
// (�C���X�g�[��/�A���C���X�g�[��/�ݒ�_�C�A���O/�폜���s)
// ************************************************************
BOOL CCompDelApp::ProcessCommandline()
{
	CString sAfxMsg;
	// ************************************************************
	// ����̎��s�̂݁A�C���X�g�[���_�C�A���O���o��
	// ************************************************************
	if(!ChkHkcuInstReg())
	{	// �C���X�g�[���t���O��������Ȃ�
		CDlgInstall dlgInst;
		// �C���X�g�[���_�C�A���O�̕\��
		dlgInst.m_CONTEXT = FALSE;
		dlgInst.m_DESKTOP = TRUE;
		dlgInst.m_MENU = FALSE;
		dlgInst.m_UNIN = 1;
		if(dlgInst.DoModal() == IDOK)
		{
			::MkHkcuInstReg();		// �C���X�g�[���t���O�̏�������
			if(dlgInst.m_UNIN == 0)
			{	// ���W�X�g���̃A���C���X�g�[�����j���[���쐬
				if(CheckWinNT()) ::MkHkcuUninstMnu();	// WinNT �n��̂Ƃ� HKCU
				else  ::MkHklmUninstMnu();	// Win95 �n��̂Ƃ� HKLM
			}
			else
				::MkUninstMnu();		// �X�^�[�g���j���[�ɃA���C���X�g�[����V���[�g�J�b�g���쐬
			if(dlgInst.m_CONTEXT)
				::MkSendtoMnu();		// ���郁�j���[�ɃV���[�g�J�b�g�쐬
			if(dlgInst.m_DESKTOP)
				::MkDesktopMnu();		// �f�X�N�g�b�v�ɃV���[�g�J�b�g�쐬
			if(dlgInst.m_MENU)
				::MkProgramsMnu();		// �X�^�[�g���j���[�ɃV���[�g�J�b�g�쐬
		}
		else return FALSE;	// �C���X�g�[���p��
	}
	// ************************************************************
	// �ݒ�_�C�A���O�\���B
	// ************************************************************
	if(!strlen(m_lpCmdLine))
	{	// �R�}���h���C�������Ȃ��̂Ƃ��́A�ݒ�_�C�A���O
		// ���C���_�C�A���O�̕\��
		sAfxMsg.LoadString(AFX_STR_MAINDLG);
		CPropertySheet dlg((LPCSTR)sAfxMsg);	// �_�C�A���O�̃x�[�X
		// �v���p�e�B�[�V�[�g
		CDlgPDel dlgPDel;
		CDlgPDisp dlgPDisp;
		CDlgPOther dlgPOther;

		m_pMainWnd = &dlg;	// ���̃_�C�A���O�����C���t���[���Ƃ���
		dlgPDisp.m_NDispN = GetProfileInt("Settings","NDispN",0);
		dlgPDisp.m_NDispE = GetProfileInt("Settings","NDispE",0);
		dlgPOther.m_Dummy = GetProfileInt("Settings","Dummy",0);
		dlgPOther.m_DummySkip = GetProfileInt("Settings","DummySkip",1);
		dlgPOther.m_nFiles = GetProfileInt("Settings","nFiles",40);
		dlgPDel.m_Date = GetProfileInt("Settings","Date",1);
		dlgPDel.m_rNull = GetProfileInt("Settings","rNull",1);
		dlgPDel.m_rZLen = GetProfileInt("Settings","rZLen",1);
		dlgPDel.m_rRen = GetProfileInt("Settings","rRen",1);
		dlgPDel.m_nOvwr = GetProfileInt("Settings","nOvwr",2);
		dlgPDisp.m_Confirm = GetProfileInt("Settings","Confirm",0);
		dlgPDisp.m_DispF = GetProfileInt("Settings","DispF",1);
		dlgPDisp.m_Log = GetProfileInt("Settings","Log",1);

		// �v���p�e�B�[�y�[�W�̘A��
		dlg.AddPage(&dlgPDel);
		dlg.AddPage(&dlgPDisp);
		dlg.AddPage(&dlgPOther);
		// �v���p�e�B�[�V�[�g�̑����ύX
		dlg.m_psh.dwFlags=(dlg.m_psh.dwFlags|PSH_NOAPPLYNOW);// &(~PSH_HASHELP);
		if(dlg.DoModal() == IDOK)
		{
			if(dlgPDisp.m_NDispN != (int)GetProfileInt("Settings","NDispN",0))
				WriteProfileInt("Settings","NDispN",dlgPDisp.m_NDispN);	
			if(dlgPDisp.m_NDispE != (int)GetProfileInt("Settings","NDispE",0))
				WriteProfileInt("Settings","NDispE",dlgPDisp.m_NDispE);	
			if(dlgPOther.m_Dummy != (int)GetProfileInt("Settings","Dummy",0))
				WriteProfileInt("Settings","Dummy",dlgPOther.m_Dummy);	
			if(dlgPOther.m_DummySkip != (int)GetProfileInt("Settings","DummySkip",1))
				WriteProfileInt("Settings","DummySkip",dlgPOther.m_DummySkip);	
			if(dlgPOther.m_nFiles != (int)GetProfileInt("Settings","nFiles",40))
				WriteProfileInt("Settings","nFiles",dlgPOther.m_nFiles);	
			if(dlgPDel.m_Date != (int)GetProfileInt("Settings","Date",1))
				WriteProfileInt("Settings","Date",dlgPDel.m_Date);	
			if(dlgPDel.m_rNull != (int)GetProfileInt("Settings","rNull",1))
				WriteProfileInt("Settings","rNull",dlgPDel.m_rNull);
			if(dlgPDel.m_rZLen != (int)GetProfileInt("Settings","rZLen",1))
				WriteProfileInt("Settings","rZLen",dlgPDel.m_rZLen);
			if(dlgPDel.m_rRen != (int)GetProfileInt("Settings","rRen",1))
				WriteProfileInt("Settings","rRen",dlgPDel.m_rRen);
			if(dlgPDel.m_nOvwr != (int)GetProfileInt("Settings","nOvwr",2))
				WriteProfileInt("Settings","nOvwr",dlgPDel.m_nOvwr);
			if(dlgPDisp.m_Confirm != (int)GetProfileInt("Settings","Confirm",0))
				WriteProfileInt("Settings","Confirm",dlgPDisp.m_Confirm);
			if(dlgPDisp.m_DispF != (int)GetProfileInt("Settings","DispF",1))
				WriteProfileInt("Settings","DispF",dlgPDisp.m_DispF);
			if(dlgPDisp.m_Log != (int)GetProfileInt("Settings","Log",1))
				WriteProfileInt("Settings","Log",dlgPDisp.m_Log);

		}
	}
	// ************************************************************
	// �A���C���X�g�[��
	// ************************************************************
	else if(!strcmp(m_lpCmdLine, "/delete"))
	{	// �A���C���X�g�[��
		sAfxMsg.LoadString(AFX_STR_UNIN_CONFERM);
		if(::MessageBox(NULL, (LPCSTR)sAfxMsg, "CompleteDelete Uninstaller", MB_YESNO|MB_ICONQUESTION) != IDYES)
			return FALSE;
		::RmUserReg();			// ���[�U�̈�̃��W�X�g���f�[�^�̍폜
		::RmHkcuInstReg();		// HKCU �� �C���X�g�[���t���O�̍폜
		::RmUninstMnu();		// �X�^�[�g���j���[�̃A���C���X�g�[����V���[�g�J�b�g���폜
		::RmHkcuUninstMnu();	// ���W�X�g���̃A���C���X�g�[�����j���[���폜 HKCU
		::RmHklmUninstMnu();	// ���W�X�g���̃A���C���X�g�[�����j���[���폜 HKLM
		::RmDesktopMnu();		// �f�X�N�g�b�v���폜
		::RmProgramsMnu();		// �X�^�[�g���j���[���폜
		::RmSendtoMnu();		// ���郁�j���[���폜
	}
	// ************************************************************
	// �t�@�C���̍폜 ���C���v���O�����̎��s
	// ************************************************************
	else
	{
		// ���샂�[�h�����W�X�g�����ǂݍ���
		MyFile.n_NDispN = GetProfileInt("Settings","NDispN",0);
		MyFile.n_NDispE = GetProfileInt("Settings","NDispE",0);
		MyFile.n_Dummy = GetProfileInt("Settings","Dummy",0);
		MyFile.n_DummySkip = GetProfileInt("Settings","DummySkip",1);
		MyFile.n_Date = GetProfileInt("Settings","Date",1);
		MyFile.n_rNull = GetProfileInt("Settings","rNull",1);
		MyFile.n_rZLen = GetProfileInt("Settings","rZLen",1);
		MyFile.n_rRen = GetProfileInt("Settings","rRen",1);
		MyFile.n_nOvwr = GetProfileInt("Settings","nOvwr",2);
		MyFile.n_nFiles = GetProfileInt("Settings","nFiles",40);
		MyFile.n_Confirm = GetProfileInt("Settings","Confirm",0);
		MyFile.n_DispF = GetProfileInt("Settings","DispF",1);
		MyFile.n_Log = GetProfileInt("Settings","Log",1);

		// ���O�pCString�|�C���^�̈��n��
		sLogStr = "";
		MyFile.sLogStr = &sLogStr;
		// �폜���C�����[�`��
		MyFile.DeleteMain(m_lpCmdLine);

		// ���O�̕\��
		if(MyFile.n_Log)
		{
			CDlgHelpDoc dlgHelp;
			dlgHelp.m_edit_main = sLogStr;
			dlgHelp.DoModal();
		}
	}
	return TRUE;
}

// ************************************************************
// WindowsNT �n��� Windows 95 �n��̔���
// WinNT �n��̂Ƃ� TRUE
// ************************************************************
BOOL CCompDelApp::CheckWinNT()
{
	OSVERSIONINFO ver;

	// OS�o�[�W����
	ver.dwOSVersionInfoSize = sizeof(OSVERSIONINFO);
	::GetVersionEx((LPOSVERSIONINFO)&ver);


	if(ver.dwPlatformId == VER_PLATFORM_WIN32_NT)
		return TRUE;

	return FALSE;
}
