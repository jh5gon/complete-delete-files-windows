// ************************************************************
// �C���X�g�[���E�A���C���X�g�[���֘A
//
// ************************************************************

#include "StdAfx.h"
#include "InstFunc.h"
#include <io.h>			// findfirst

// ���\�[�X�����̔ԍ������ɕK�v
#include "resource.h"		// ���C�� �V���{��


// ���W�X�g���ɐݒ肷��e��l�̃O���[�o���l���Z�b�g����B�i�d�v�j


// �������s�̃��W�X�g���ʒu
#define STR_REGKEY_RUN		"Software\\Microsoft\\Windows\\CurrentVersion\\Run"

// �R���g���[���p�l���̃A���C���X�g�[�����̊i�[�ʒu
#define STR_REGKEY_UNINST	"Software\\Microsoft\\Windows\\CurrentVersion\\Uninstall"
// �R���g���[���p�l���ɕ\������ ���O�i�A���C���X�g�[���p�j
// ���\�[�X��AFX_STR_UNINST_CPLNAME ���D�悳���
#define STR_UNINST_CPLNAME	"���S�폜"

// �X�^�[�g�A�b�v�E���j���[�̃t�H���_�������i�[����Ă��郌�W�X�g��
#define STR_REGKEY_EXPLR_FOLDER	"Software\\Microsoft\\Windows\\CurrentVersion\\Explorer\\Shell Folders"

// ���̃v���O�����̃C���X�g�[���t���O�p�Ɏg�����W�X�g���ʒu
#define STR_REGKEY_INST		"Software\\hi_soft"

// �v���O�����̃��[�U�f�[�^�iHKCU) �̈ʒu�i���[�U�f�[�^�̍폜�ɗ��p�j
// �ŉ��i (���̉��� "Settings" �L�[���폜����)
#define STR_REGKEY_USERDAT_1	"Software\\hi soft\\compdel"
// ��i (���̉��� AFX_IDS_APP_TITLE �L�[���폜����)
#define STR_REGKEY_USERDAT_2	"Software\\hi soft"


// ���̃v���O�����̐ݒ�p�Ɏg�����W�X�g���̈ʒu�i�v���O�������j
//  ���\�[�X�� AFX_IDS_APP_TITLE �ɃZ�b�g���邱��
//  ���̏ꍇ�AsTmp.
#define _ALTER_APP_TITLE "compdel"		// AFX_IDS_APP_TITLE �������Ƃ��͂�������g��

// �A���C���X�g�[���E�V���[�g�J�b�g��
// ���\�[�X��AFX_STR_LINK_UNINST ���D�悳���
#define STR_LINK_UNINST		"\\���S�폜�A���C���X�g�[��.LNK"

// �V���[�g�J�b�g�� (�X�^�[�g���j���[�̃X�^�[�g�ɓo�^����ꍇ�̖��O�j
// ���\�[�X��AFX_STR_LINK_STARTUP ���D�悳���
#define STR_LINK_STARTUP	"\\���S�폜StartUp.LNK"

// �V���[�g�J�b�g�� �i�f�X�N�g�b�v�A�R���e�L�X�g���j���[�A�X�^�[�g���j���[�̂��̑��̎��̖��O�j
// ���\�[�X��AFX_STR_LINK_PROG ���D�悳���
#define STR_LINK_PROG		"\\���S�폜.LNK"


// ************************************************************
// ���W�X�g���̋N�������s�̐ݒ�E�폜
// �uProgramName /start�v�Ƃ����R�}���h���C���ƂȂ�
// (HKLM / HKCU)
// ************************************************************

// HKLM �Ɏ������s�����N�����
BOOL MkHklmLnk(void)
{
	char szProg[MAX_PATH], tmpBuf[MAX_PATH];
	BOOL ret = FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, tmpBuf, MAX_PATH)) return ret;
	sprintf(szProg, "\"%s\" /start", tmpBuf);
	HKEY hCU;

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_RUN, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegSetValueEx( hCU, sProgName, 0, REG_SZ, (const unsigned char *)szProg, strlen(szProg)) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;
}

// HKCU �Ɏ������s�����N�����
BOOL MkHkcuLnk(void)
{
	char szProg[MAX_PATH], tmpBuf[MAX_PATH];
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, tmpBuf, MAX_PATH)) return ret;
	sprintf(szProg, "\"%s\" /start", tmpBuf);
	HKEY hCU;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_RUN, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegSetValueEx( hCU, sProgName, 0, REG_SZ, (const unsigned char *)szProg, strlen(szProg)) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;
}

// HKLM �̎��������N���폜����
BOOL RmHklmLnk(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	HKEY hCU;
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_RUN, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegDeleteValue( hCU, sProgName) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;	
}

// HKCU �̎��������N���폜����
BOOL RmHkcuLnk(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	HKEY hCU;
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_RUN, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegDeleteValue( hCU, sProgName) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;	
}

// ************************************************************
// �X�^�[�g���j���[�̋N�������s�̐ݒ�E�폜
// �uProgramName /start�v�Ƃ����R�}���h���C���ƂȂ�
// (�J�����g���[�U)
// ************************************************************
// �X�^�[�g���j���[�Ɏ������s�A�C�R�������
void MkStartMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];
	char szProg[MAX_PATH];
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sLinkStartup;	// AFX_STR_LINK_STARTUP ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sLinkStartup.LoadString(AFX_STR_LINK_STARTUP))
		sLinkStartup = STR_LINK_STARTUP;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Startup", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkStartup);
	::CreateShellLink(szProg, szLink, (LPSTR)(LPCSTR)sProgName, "/start");
		
}

// �X�^�[�g���j���[�̎������s�A�C�R�����폜����
void RmStartMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];

	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;
	CString sLinkStartup;	// AFX_STR_LINK_STARTUP ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sLinkStartup.LoadString(AFX_STR_LINK_STARTUP))
		sLinkStartup = STR_LINK_STARTUP;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Startup", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkStartup);
	::remove(szLink);
	
}

// ************************************************************
// �R���e�L�X�g���j���[�iSendTo)�̐ݒ�E�폜
// �uProgramName�v�Ƃ����R�}���h���C���ƂȂ� (�X�C�b�`�Ȃ��j
// (�J�����g���[�U)
// ************************************************************
// �R���e�L�X�g���j���[�iSendTo)�Ɏ������s�A�C�R�������
void MkSendtoMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];
	char szProg[MAX_PATH];
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************


	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "SendTo", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::CreateShellLink(szProg, szLink, (LPSTR)(LPCSTR)sProgName, "");
		
}

// �R���e�L�X�g���j���[�iSendTo)�̎������s�A�C�R�����폜����
void RmSendtoMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];

	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "SendTo", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::remove(szLink);
	
}

// ************************************************************
// �f�X�N�g�b�v�E�A�C�R���̐ݒ�E�폜
// �uProgramName�v�Ƃ����R�}���h���C���ƂȂ� (�X�C�b�`�Ȃ��j
// (�J�����g���[�U)
// ************************************************************
// �f�X�N�g�b�v�ɃA�C�R�������
void MkDesktopMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];
	char szProg[MAX_PATH];
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Desktop", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::CreateShellLink(szProg, szLink, (LPSTR)(LPCSTR)sProgName, "");
		
}

// �f�X�N�g�b�v�̃A�C�R�����폜����
void RmDesktopMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];

	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Desktop", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::remove(szLink);
	
}


// ************************************************************
// �X�^�[�g���j���[�i���̑��j�E�A�C�R���̐ݒ�E�폜
// �uProgramName�v�Ƃ����R�}���h���C���ƂȂ� (�X�C�b�`�Ȃ��j
// (�J�����g���[�U)
// ************************************************************
// �X�^�[�g���j���[�ɃA�C�R�������
void MkProgramsMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];
	char szProg[MAX_PATH];
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Programs", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::CreateShellLink(szProg, szLink, (LPSTR)(LPCSTR)sProgName, "");
		
}

// �X�^�[�g���j���[�̃A�C�R�����폜����
void RmProgramsMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];

	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;
	CString sLinkProg;	// AFX_STR_LINK_PROG ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sLinkProg.LoadString(AFX_STR_LINK_PROG))
		sLinkProg = STR_LINK_PROG;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Programs", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkProg);
	::remove(szLink);
	
}

// ************************************************************
// �A���C���X�g�[���E�V���[�g�J�b�g���X�^�[�g���j���[�ɍ쐬�E�폜
// �uProgramName /delete�v�Ƃ����R�}���h���C���ƂȂ�
// (�J�����g���[�U)
// ************************************************************
// �A���C���X�g�[�� �A�C�R�������
void MkUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];
	char szProg[MAX_PATH];
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sLinkUninst;	// AFX_STR_LINK_UNINST ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sLinkUninst.LoadString(AFX_STR_LINK_UNINST))
		sLinkUninst = STR_LINK_UNINST;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Programs", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkUninst);
	::CreateShellLink(szProg, szLink, (LPSTR)(LPCSTR)sProgName, "/delete");
		
}

// �A���C���X�g�[�� �A�C�R�����폜����
void RmUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szLink[MAX_PATH];

	HKEY hCU;
	DWORD lpType;
	ULONG ulSize = MAX_PATH;
	CString sLinkUninst;	// AFX_STR_LINK_UNINST ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sLinkUninst.LoadString(AFX_STR_LINK_UNINST))
		sLinkUninst = STR_LINK_UNINST;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_EXPLR_FOLDER, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegQueryValueEx( hCU, "Programs", NULL, &lpType, (unsigned char *)&szLink, &ulSize);
		RegCloseKey(hCU);
	}
	strcat(szLink, (LPCSTR)sLinkUninst);
	::remove(szLink);
	
}

// ************************************************************
// �A���C���X�g�[���E�V���[�g�J�b�g�����W�X�g���i�R���p�l�j�ɐݒ襍폜
// �uProgramName /delete�v�Ƃ����R�}���h���C���ƂȂ�
// (HKLM)
// ************************************************************
// �A���C���X�g�[�� �A�C�R�������
void MkHklmUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szProg[MAX_PATH];
	CString sRegKey;
	HKEY hCU;
	DWORD dw;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sCplName;	// AFX_STR_UNINST_CPLNAME ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sCplName.LoadString(AFX_STR_UNINST_CPLNAME))
		sCplName = STR_UNINST_CPLNAME;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************


	// �A���C���X�g�[���p�̃��W�X�g���ʒu�̌���
	sRegKey.Format("%s\\%s", STR_REGKEY_UNINST, sProgName);

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	// �p�X���ɋ󔒂������Ă���ꍇ�́A " ... " �Ƃ���
	sProgName = szProg;
	if(sProgName.Find(' ') != -1) sProgName.Format("\"%s\"", szProg);

	if (RegCreateKeyEx(HKEY_LOCAL_MACHINE, sRegKey,
		0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL,
		&hCU, &dw) == ERROR_SUCCESS)
	{
		// �R�}���h���C���̋L�q
		sProgName += " /delete";	// �X�C�b�`������
		RegSetValueEx( hCU, "UninstallString", 0, REG_SZ, (const unsigned char *)(LPCSTR)sProgName, sProgName.GetLength());
		// �\�����̋L�q
		strcpy(szProg, (LPCSTR)sCplName);
		RegSetValueEx( hCU, "DisplayName", 0, REG_SZ, (const unsigned char *)szProg, strlen(szProg));
		RegCloseKey(hCU);
	}
}

// �A���C���X�g�[�� �A�C�R�����폜����
void RmHklmUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	HKEY hCU;
	CString sRegKey;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// �A���C���X�g�[���p�̃��W�X�g���ʒu�̌���
	sRegKey.Format("%s", STR_REGKEY_UNINST);

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, sRegKey, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegDeleteKey( hCU, sProgName);
		RegCloseKey(hCU);
	}
}

// ************************************************************
// �A���C���X�g�[���E�V���[�g�J�b�g�����W�X�g���i�R���p�l�j�ɐݒ襍폜
// �uProgramName /delete�v�Ƃ����R�}���h���C���ƂȂ�
// (HKCU)
// ************************************************************
// �A���C���X�g�[�� �A�C�R�������
void MkHkcuUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	char szProg[MAX_PATH];
	CString sRegKey;
	HKEY hCU;
	DWORD dw;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���
	CString sCplName;	// AFX_STR_UNINST_CPLNAME ��ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	if(!sCplName.LoadString(AFX_STR_UNINST_CPLNAME))
		sCplName = STR_UNINST_CPLNAME;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// �A���C���X�g�[���p�̃��W�X�g���ʒu�̌���
	sRegKey.Format("%s\\%s", STR_REGKEY_UNINST, sProgName);

	// ���̂̃t���p�X��
	if(!::GetModuleFileName(NULL, szProg, MAX_PATH)) return;
	// �p�X���ɋ󔒂������Ă���ꍇ�́A " ... " �Ƃ���
	sProgName = szProg;
	if(sProgName.Find(' ') != -1) sProgName.Format("\"%s\"", szProg);

	if (RegCreateKeyEx(HKEY_CURRENT_USER, sRegKey,
		0, REG_NONE, REG_OPTION_NON_VOLATILE, KEY_WRITE|KEY_READ, NULL,
		&hCU, &dw) == ERROR_SUCCESS)
	{
		// �R�}���h���C���̋L�q
		sProgName += " /delete";	// �X�C�b�`������
		RegSetValueEx( hCU, "UninstallString", 0, REG_SZ, (const unsigned char *)(LPCSTR)sProgName, sProgName.GetLength());
		// �\�����̋L�q
		strcpy(szProg, (LPCSTR)sCplName);
		RegSetValueEx( hCU, "DisplayName", 0, REG_SZ, (const unsigned char *)szProg, strlen(szProg));
		RegCloseKey(hCU);
	}
}

// �A���C���X�g�[�� �A�C�R�����폜����
void RmHkcuUninstMnu(void) 
{
	// TODO: ���̈ʒu�ɃR���g���[���ʒm�n���h���p�̃R�[�h��ǉ����Ă�������
	HKEY hCU;
	CString sRegKey;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// �A���C���X�g�[���p�̃��W�X�g���ʒu�̌���
	sRegKey.Format("%s", STR_REGKEY_UNINST);

	if (RegOpenKeyEx(HKEY_CURRENT_USER, sRegKey, 0, KEY_QUERY_VALUE, &hCU) == ERROR_SUCCESS)
	{
		RegDeleteKey( hCU, sProgName);
		RegCloseKey(hCU);
	}
}


// ************************************************************
// �C���X�g�[�����̏������ݥ�폜��m�F
// (HKLM)
// ************************************************************
BOOL ChkHklmInstReg(void)
{
	HKEY hCU;
	DWORD data;
	DWORD lpType;
	ULONG ulSize = sizeof(DWORD);
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// HKLM\...\Run �̌��o
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_INST, 0, KEY_READ, &hCU) == ERROR_SUCCESS)
	{
		lpType = REG_DWORD;
		if(RegQueryValueEx(hCU, (LPCSTR)sProgName, NULL, &lpType, (unsigned char *)&data, &ulSize) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;
}

BOOL MkHklmInstReg(void)
{
	HKEY hCU;
	DWORD data = 1;
	DWORD lpType;
	ULONG ulSize = sizeof(DWORD);
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************


	// HKLM\...\Run �̌��o
	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_INST, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		lpType = REG_DWORD;
		if(RegSetValueEx(hCU, (LPCSTR)sProgName, NULL, REG_DWORD, (CONST BYTE *)&data, sizeof(DWORD)) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	else
	{
		if(RegCreateKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_INST, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hCU, &lpType) == ERROR_SUCCESS)
		{		
			if(RegSetValueEx(hCU, (LPCSTR)sProgName, NULL, REG_DWORD, (CONST BYTE *)&data, sizeof(DWORD)) == ERROR_SUCCESS)
				ret = TRUE;
			RegCloseKey(hCU);
		}
	}
	return ret;
}

BOOL RmHklmInstReg(void)
{
	HKEY hCU;
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_LOCAL_MACHINE, STR_REGKEY_INST, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegDeleteValue( hCU, sProgName) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;	
}

// ************************************************************
// �C���X�g�[�����̏������ݥ�폜��m�F
// (HKCU)
// ************************************************************
BOOL ChkHkcuInstReg(void)
{
	HKEY hCU;
	DWORD data;
	DWORD lpType;
	ULONG ulSize = sizeof(DWORD);
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// HKCU\...\Run �̌��o
	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_INST, 0, KEY_READ, &hCU) == ERROR_SUCCESS)
	{
		lpType = REG_DWORD;
		if(RegQueryValueEx(hCU, (LPCSTR)sProgName, NULL, &lpType, (unsigned char *)&data, &ulSize) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;
}

BOOL MkHkcuInstReg(void)
{
	HKEY hCU;
	DWORD data = 1;
	DWORD lpType;
	ULONG ulSize = sizeof(DWORD);
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************


	// HKCU\...\Run �̌��o
	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_INST, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		lpType = REG_DWORD;
		if(RegSetValueEx(hCU, (LPCSTR)sProgName, NULL, REG_DWORD, (CONST BYTE *)&data, sizeof(DWORD)) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	else
	{
		if(RegCreateKeyEx(HKEY_CURRENT_USER, STR_REGKEY_INST, 0, NULL, REG_OPTION_NON_VOLATILE, KEY_WRITE, NULL, &hCU, &lpType) == ERROR_SUCCESS)
		{		
			if(RegSetValueEx(hCU, (LPCSTR)sProgName, NULL, REG_DWORD, (CONST BYTE *)&data, sizeof(DWORD)) == ERROR_SUCCESS)
				ret = TRUE;
			RegCloseKey(hCU);
		}
	}
	return ret;
}

BOOL RmHkcuInstReg(void)
{
	HKEY hCU;
	BOOL ret=FALSE;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_INST, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		if(RegDeleteValue( hCU, sProgName) == ERROR_SUCCESS)
			ret = TRUE;
		RegCloseKey(hCU);
	}
	return ret;	
}


// ************************************************************
// �e��ݒ背�W�X�g�����폜�i�A���C���X�g�[�����Ɏ��s�j
// (HKCU)
// ************************************************************
// ���[�U�̈�̃��W�X�g���f�[�^�𖕏�����
void RmUserReg(void)
{
	HKEY hCU;
	CString sProgName;	// AFX_IDS_APP_TITLE �� �v���O��������ǂݍ���

	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************
	if(!sProgName.LoadString(AFX_IDS_APP_TITLE))
		sProgName = _ALTER_APP_TITLE;		// ���\�[�X���Z�b�g����Ă��Ȃ����i���肦�Ȃ��j	
	// ****************** ������Ή� ���\�[�X�e�[�u���̓ǂݍ��� ******************

	// Windows NT �ł́A�T�u�L�[���������L�[�͍폜�ł��Ȃ��̂ŁA
	// 2�i�K�ō폜����
	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_USERDAT_1, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		RegDeleteKey( hCU, "Settings");
		RegCloseKey(hCU);
	}
	if (RegOpenKeyEx(HKEY_CURRENT_USER, STR_REGKEY_USERDAT_2, 0, KEY_WRITE, &hCU) == ERROR_SUCCESS)
	{
		RegDeleteKey( hCU, sProgName);
		RegCloseKey(hCU);
	}
}

// ************************************************************
// �V���[�g�J�b�g�̍쐬
// ************************************************************
// �t�@�C���ւ̃V���[�g�J�b�g�E�A�C�R�����쐬����B
// SDK �ł� Shell Links �ƌ����B
// pszShortcutFile : ���̃t�@�C���̃t���p�X���iC:\WINDOWS\NOTEPAD.EXE�j
// pszLink : �V���[�g�J�b�g�t�@�C���̃t���p�X���i C:\WINDOWS\�c.lnk�j
// pszDesc : �\����
// pszParam : �X�C�b�`�i�w�肵�Ȃ��Ƃ��� "" ���Z�b�g)
// ���̍��ڂɊւ��ẮA MSDN���C�u��������"Using Shell Links"�̃^�C�g������������
// �֐��̐����Ȃǂ� "The IShellLink Interface"�ɂ���
HRESULT CreateShellLink(LPCSTR pszShortcutFile,
							LPSTR pszLink, LPSTR pszDesc, LPSTR pszParam)
{
    HRESULT hres;
    IShellLink *psl;

	CoInitialize(NULL);	// MSDN�T���v���t�@�C���ł͂����������Ă���̂Œ��ӂ���

	// IShellLink �I�u�W�F�N�g��(psl��)����
    hres = CoCreateInstance(CLSID_ShellLink, NULL, CLSCTX_INPROC_SERVER,
                            IID_IShellLink, (void **)&psl);
    if (SUCCEEDED(hres))
    {
       IPersistFile *ppf;
       
	   // Query IShellLink for the IPersistFile interface for
	   // saving the shortcut in persistent storage.
       hres = psl->QueryInterface(IID_IPersistFile, (void **)&ppf);
	   if (SUCCEEDED(hres))
	   {   
	        WORD wsz[MAX_PATH];   // buffer for Unicode string

	   		// ���̃t�@�C���i�^�[�Q�b�g�j�̃p�X��ݒ�
          	hres = psl->SetPath(pszShortcutFile);
/*
			if (!SUCCEEDED(hres))
				if(!n_NDispE)
					AfxMessageBox("�V���[�g�J�b�g�쐬���ɃG���[���N�����܂���",
						MB_OK|MB_ICONINFORMATION|MB_TOPMOST);
*/
	   		// �p�����[�^�̐ݒ��ݒ�
			if(strlen(pszParam))
          		hres = psl->SetArguments(pszParam);

            // �V���[�g�J�b�g�̐�����(Description)���Z�b�g
			// ���̂��߂Ɏg������������A�s���H
          	hres = psl->SetDescription(pszDesc);
/*
			if (!SUCCEEDED(hres))
				if(!n_NDispE)
					AfxMessageBox("�V���[�g�J�b�g�쐬���ɃG���[���N�����܂���",
						MB_OK|MB_ICONINFORMATION|MB_TOPMOST);
*/
	     	// �V���[�g�J�b�g�t�@�C������MBCS �� ���C�h�L�����N�^�������
	     	MultiByteToWideChar(CP_ACP, 0, pszLink, -1, wsz, MAX_PATH);

          	// �V���[�g�J�b�g�t�@�C�����f�B�X�N�ɏ�������
			// Save the shortcut via the IPersistFile::Save member function.
          	hres = ppf->Save(wsz, TRUE);
/*
			if (!SUCCEEDED(hres))
				if(!n_NDispE)
					AfxMessageBox("�V���[�g�J�b�g�쐬���ɃG���[���N�����܂���",
						MB_OK|MB_ICONINFORMATION|MB_TOPMOST);
*/
            // Release the pointer to IPersistFile.
          	ppf->Release();
       }
       // Release the pointer to IShellLink.
       psl->Release();
    }
	CoUninitialize();
    return hres;

}

// ************************************************************
// EOF
// ************************************************************
