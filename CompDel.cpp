// CompDel.cpp : �A�v���P�[�V�����p�N���X�̒�`���s���܂��B
//


#include "stdafx.h"
#include "CompDel.h"
#include "Fileman.h"
#include "DlgConfig.h"
#include "DlgConfirm.h"
#include "DlgHelpDoc.h"
#include "CheckWinVer.h"

#include "InstFunc.h"

#include <HtmlHelp.h>
#include <stdlib.h>

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
				if(IsWinNT()) ::MkHkcuUninstMnu();	// WinNT �n��̂Ƃ� HKCU
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
	// ���샂�[�h�����W�X�g�����ǂݍ���
	// ************************************************************
	MyFile.n_NDispN = GetProfileInt("Settings","NDispN",0);
	MyFile.n_NDispE = GetProfileInt("Settings","NDispE",0);
	MyFile.n_Dummy = GetProfileInt("Settings","Dummy",0);
	MyFile.n_DummySkip = GetProfileInt("Settings","DummySkip",1);
	MyFile.n_Date = GetProfileInt("Settings","Date",1);
	MyFile.n_rNull = GetProfileInt("Settings","rNull",1);
	MyFile.n_rZLen = GetProfileInt("Settings","rZLen",1);
	MyFile.n_rRen = GetProfileInt("Settings","rRen",1);
	MyFile.n_nOvwr = GetProfileInt("Settings","nOvwr",5);
	MyFile.n_nFiles = GetProfileInt("Settings","nFiles",40);
	MyFile.n_Confirm = GetProfileInt("Settings","Confirm",0);
	MyFile.n_DispF = GetProfileInt("Settings","DispF",1);
	MyFile.n_Log = GetProfileInt("Settings","Log",1);

	MyFile.b_AntiCache = GetProfileInt("Settings","AddWipe",0);
	MyFile.n_UntiFolder = GetProfileInt("Settings","rAntiFolder",0);
	MyFile.n_UnticacheSize = GetProfileInt("Settings","nAnticacheSize",20);
	MyFile.n_bAntiOneShot = GetProfileInt("Settings","bAntiOneShot",1);
	MyFile.n_BufferSize = GetProfileInt("Settings","m_nBufferSize",2048);
	MyFile.n_Overrun = GetProfileInt("Settings","m_nOverrun",0);
	MyFile.n_DodChar = GetProfileInt("Settings","m_nDodChar",(int)'A');

	MyFile.b_NotRemove = GetProfileInt("Settings","bNotDel",0);


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
		CDlgPDel2 dlgPDel2;
		CDlgPDel3 dlgPDel3;
		CDlgPDisp dlgPDisp;
		CDlgPOther dlgPOther;

		m_pMainWnd = &dlg;	// ���̃_�C�A���O�����C���t���[���Ƃ���
		dlgPDisp.m_NDispN = MyFile.n_NDispN;
		dlgPDisp.m_NDispE = MyFile.n_NDispE;
		dlgPDel3.m_bDummy = MyFile.n_Dummy;
		dlgPDel3.m_bDummySkip = MyFile.n_DummySkip;
		dlgPDel3.m_nFiles = MyFile.n_nFiles;
		dlgPDel.m_Date = MyFile.n_Date;
		dlgPDel.m_rNull = MyFile.n_rNull;
		dlgPDel.m_rZLen = MyFile.n_rZLen;
		dlgPDel.m_rRen = MyFile.n_rRen;
		dlgPDel.m_nOvwr = MyFile.n_nOvwr;
		dlgPDel3.m_AntiCache = MyFile.b_AntiCache;
		dlgPDel3.m_rAntiFolder = MyFile.n_UntiFolder;
		dlgPDel3.m_nAnticacheSize = MyFile.n_UnticacheSize;
		dlgPDel3.m_bAntiOneShot = MyFile.n_bAntiOneShot;
		dlgPDel2.m_nBufferSize = MyFile.n_BufferSize;
		dlgPDel2.m_nOverrun = MyFile.n_Overrun;
		dlgPDel2.m_nDodChar = MyFile.n_DodChar;
		dlgPDisp.m_Confirm = MyFile.n_Confirm;
		dlgPDisp.m_DispF = MyFile.n_DispF;
		dlgPDisp.m_Log = MyFile.n_Log;
		dlgPDel2.m_bNotRemove = MyFile.b_NotRemove;

		// �v���p�e�B�[�y�[�W�̘A��
		dlg.AddPage(&dlgPDel);
		dlg.AddPage(&dlgPDisp);
		dlg.AddPage(&dlgPDel2);
		dlg.AddPage(&dlgPDel3);
		dlg.AddPage(&dlgPOther);
		// �v���p�e�B�[�V�[�g�̑����ύX
		dlg.m_psh.dwFlags=(dlg.m_psh.dwFlags|PSH_NOAPPLYNOW);// &(~PSH_HASHELP);
		if(dlg.DoModal() == IDOK)
		{
			if(dlgPDisp.m_NDispN != (int)GetProfileInt("Settings","NDispN",0))
				WriteProfileInt("Settings","NDispN",dlgPDisp.m_NDispN);	
			if(dlgPDisp.m_NDispE != (int)GetProfileInt("Settings","NDispE",0))
				WriteProfileInt("Settings","NDispE",dlgPDisp.m_NDispE);	
			if(dlgPDel3.m_bDummy != (int)GetProfileInt("Settings","Dummy",0))
				WriteProfileInt("Settings","Dummy",dlgPDel3.m_bDummy);	
			if(dlgPDel3.m_bDummySkip != (int)GetProfileInt("Settings","DummySkip",1))
				WriteProfileInt("Settings","DummySkip",dlgPDel3.m_bDummySkip);	
			if(dlgPDel3.m_nFiles != (int)GetProfileInt("Settings","nFiles",40))
				WriteProfileInt("Settings","nFiles",dlgPDel3.m_nFiles);	
			if(dlgPDel.m_Date != (int)GetProfileInt("Settings","Date",1))
				WriteProfileInt("Settings","Date",dlgPDel.m_Date);	
			if(dlgPDel.m_rNull != (int)GetProfileInt("Settings","rNull",1))
				WriteProfileInt("Settings","rNull",dlgPDel.m_rNull);
			if(dlgPDel.m_rZLen != (int)GetProfileInt("Settings","rZLen",1))
				WriteProfileInt("Settings","rZLen",dlgPDel.m_rZLen);
			if(dlgPDel.m_rRen != (int)GetProfileInt("Settings","rRen",1))
				WriteProfileInt("Settings","rRen",dlgPDel.m_rRen);
			if(dlgPDel.m_nOvwr != (int)GetProfileInt("Settings","nOvwr",5))
				WriteProfileInt("Settings","nOvwr",dlgPDel.m_nOvwr);
			if(dlgPDel3.m_AntiCache != (int)GetProfileInt("Settings","AddWipe",0))
				WriteProfileInt("Settings","AddWipe",dlgPDel3.m_AntiCache);
			if(dlgPDel3.m_rAntiFolder != (int)GetProfileInt("Settings","rAntiFolder",0))
				WriteProfileInt("Settings","rAntiFolder",dlgPDel3.m_rAntiFolder);
			if(dlgPDel3.m_nAnticacheSize != (int)GetProfileInt("Settings","nAnticacheSize",20))
				WriteProfileInt("Settings","nAnticacheSize",dlgPDel3.m_nAnticacheSize);
			if(dlgPDel3.m_bAntiOneShot != (int)GetProfileInt("Settings","bAntiOneShot",1))
				WriteProfileInt("Settings","bAntiOneShot",dlgPDel3.m_bAntiOneShot);
			if(dlgPDel2.m_nOverrun != (int)GetProfileInt("Settings","m_nOverrun",1024))
				WriteProfileInt("Settings","m_nOverrun",dlgPDel2.m_nOverrun);
			if(dlgPDel2.m_nDodChar != GetProfileInt("Settings","m_nDodChar",(int)'A'))
				WriteProfileInt("Settings","m_nDodChar",dlgPDel2.m_nDodChar);
			if(dlgPDel2.m_nBufferSize != (int)GetProfileInt("Settings","m_nBufferSize",2048))
				WriteProfileInt("Settings","m_nBufferSize",dlgPDel2.m_nBufferSize);
			if(dlgPDisp.m_Confirm != (int)GetProfileInt("Settings","Confirm",0))
				WriteProfileInt("Settings","Confirm",dlgPDisp.m_Confirm);
			if(dlgPDisp.m_DispF != (int)GetProfileInt("Settings","DispF",1))
				WriteProfileInt("Settings","DispF",dlgPDisp.m_DispF);
			if(dlgPDisp.m_Log != (int)GetProfileInt("Settings","Log",1))
				WriteProfileInt("Settings","Log",dlgPDisp.m_Log);
			if(dlgPDel2.m_bNotRemove != (int)GetProfileInt("Settings","bNotDel",0))
				WriteProfileInt("Settings","bNotDel",dlgPDel2.m_bNotRemove);

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


BOOL CCompDelApp::QuickDeleteExec(CString sFileName)
{
	char f_path_buffer[_MAX_PATH];

	// " ... " �ň͂܂ꂽ�t�@�C�����`���ɂ���
	sprintf(f_path_buffer, "\"%s\"", sFileName);

	// ���샂�[�h�����W�X�g�����ǂݍ���
	MyFile.n_NDispN = GetProfileInt("Settings","NDispN",0);
	MyFile.n_NDispE = GetProfileInt("Settings","NDispE",0);
	MyFile.n_Dummy = GetProfileInt("Settings","Dummy",0);
	MyFile.n_DummySkip = GetProfileInt("Settings","DummySkip",1);
	MyFile.n_Date = GetProfileInt("Settings","Date",1);
	MyFile.n_rNull = GetProfileInt("Settings","rNull",1);
	MyFile.n_rZLen = GetProfileInt("Settings","rZLen",1);
	MyFile.n_rRen = GetProfileInt("Settings","rRen",1);
	MyFile.n_nOvwr = GetProfileInt("Settings","nOvwr",5);
	MyFile.n_nFiles = GetProfileInt("Settings","nFiles",40);
	MyFile.n_Confirm = GetProfileInt("Settings","Confirm",0);
	MyFile.n_DispF = GetProfileInt("Settings","DispF",1);
	MyFile.n_Log = GetProfileInt("Settings","Log",1);

	MyFile.b_AntiCache = GetProfileInt("Settings","AddWipe",0);
	MyFile.n_UntiFolder = GetProfileInt("Settings","rAntiFolder",0);
	MyFile.n_UnticacheSize = GetProfileInt("Settings","nAnticacheSize",20);
	MyFile.n_bAntiOneShot = GetProfileInt("Settings","bAntiOneShot",1);
	MyFile.n_BufferSize = GetProfileInt("Settings","m_nBufferSize",2048);
	MyFile.n_Overrun = GetProfileInt("Settings","m_nOverrun",1024);
	MyFile.n_DodChar = GetProfileInt("Settings","m_nDodChar",(int)'A');

	// ���O�pCString�|�C���^�̈��n��
	sLogStr = "";
	MyFile.sLogStr = &sLogStr;
	// �폜���C�����[�`��
	MyFile.DeleteMain(f_path_buffer);

	// ���O�̕\��
	if(MyFile.n_Log)
	{
		CDlgHelpDoc dlgHelp;
		dlgHelp.m_edit_main = sLogStr;
		dlgHelp.DoModal();
	}
	return TRUE;
}

// ************************************************************
// �w���v�\���֐��i���z�֐����I�[�o�[���C�h�j
// HTML�w���v�ɑΉ������邽�߂ɁA�A�v���P�[�V�����̍ŏ�ʃN���X�ŃI�[�o�[���C�h
// 
// ���� dwData : ����8�r�b�g�ɁAresource.h�Œ�`���ꂽ�_�C�A���O��ID������
//      nCmd   : HELP_CONTEXT=1
// ************************************************************
void CCompDelApp::WinHelp(DWORD dwData, UINT nCmd) 
{
	// TODO: ���̈ʒu�ɌŗL�̏�����ǉ����邩�A�܂��͊�{�N���X���Ăяo���Ă�������
	
//	������ WinHelp �֐��𖳌��ɂ���
//	CWinApp::WinHelp(dwData, nCmd);


	// HELP_CONTEXT �ȊO�͉������Ȃ�
	if(nCmd != HELP_CONTEXT) return;

	// HTML�w���v��hWnd�n���h�� �i���s����NULL�j
	HWND hWnd_Help;
	// �w���v�t�@�C���ւ̐�΃p�X����邽�߂́A�p�X����p�ꎞ������
	char szChmPath[MAX_PATH], szAppPath[MAX_PATH];
	char szDrive[_MAX_DRIVE];
	char szDir[_MAX_DIR];
	char szFname[_MAX_FNAME];
	char szExt[_MAX_EXT];

	CString sTmp, sAfxMsg;

	// �A�v���P�[�V�������g�̃p�X���擾���A�g���q�� chm �ɏ���������
	// (HtmlHelp�֐��̓J�����g�t�H���_�̃w���v�t�@�C�����擾���悤�Ƃ��邽��)
	if(!::GetModuleFileName(NULL, szAppPath, MAX_PATH)) return;
	::_splitpath(szAppPath, szDrive, szDir, szFname, szExt);
	::_makepath(szChmPath, szDrive, szDir,szFname, ".chm");

	// �w���v�̕\��
	if(this->m_pMainWnd == NULL)
	{	// ���C���E�C���h�E�̃n���h������`����Ă��Ȃ��Ƃ�
		hWnd_Help = ::HtmlHelp(NULL, szChmPath, HH_HELP_CONTEXT, LOWORD(dwData));
	}
	else
	{
//		hWnd_Help = ::HtmlHelp(this->m_pMainWnd->m_hWnd, szChmPath, HH_DISPLAY_TOPIC, NULL);
		hWnd_Help = ::HtmlHelp(this->m_pMainWnd->m_hWnd, szChmPath, HH_HELP_CONTEXT, LOWORD(dwData));
	}

	if(hWnd_Help == NULL)
	{	// �w���v�t�@�C���̋N���Ɏ��s�����ꍇ
		sAfxMsg.LoadString(AFX_STR_ERR_HELP);	// �u�w���v�t�@�C���̕\�����ł��܂���\r\n �t�@�C��: %s\r\n �R���e�L�X�gID: %04X�v

		sTmp.Format(sAfxMsg, szChmPath, LOWORD(dwData));
		this->m_pMainWnd->MessageBox(sTmp, "Help File Error", MB_ICONWARNING);
	}
}
