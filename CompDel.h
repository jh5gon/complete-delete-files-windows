// CompDel.h : COMPDEL �A�v���P�[�V�����̃��C�� �w�b�_�[ �t�@�C���ł��B
//

#if !defined(AFX_COMPDEL_H__13E1F064_ADF6_11D2_8D63_004005388001__INCLUDED_)
#define AFX_COMPDEL_H__13E1F064_ADF6_11D2_8D63_004005388001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// ���C�� �V���{��
#include "Fileman.h"

/////////////////////////////////////////////////////////////////////////////
// CCompDelApp:
// ���̃N���X�̓���̒�`�Ɋւ��Ă� CompDel.cpp �t�@�C�����Q�Ƃ��Ă��������B
//

class CCompDelApp : public CWinApp
{
public:
	BOOL QuickDeleteExec(CString sFileName);
	CString sLogStr;
	CCompDelApp();

// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CCompDelApp)
	public:
	virtual BOOL InitInstance();
//	virtual void WinHelp(DWORD dwData, UINT nCmd = HELP_CONTEXT);
//}}AFX_VIRTUAL

// �C���v�������e�[�V����

	//{{AFX_MSG(CCompDelApp)
		// ���� - ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ��܂��͍폜���܂��B
		//        ���̈ʒu�ɐ��������R�[�h��ҏW���Ȃ��ł��������B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
protected:
	BOOL ProcessCommandline();
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_COMPDEL_H__13E1F064_ADF6_11D2_8D63_004005388001__INCLUDED_)
