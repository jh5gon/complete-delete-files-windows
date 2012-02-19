#if !defined(AFX_DLGCONFIRM_H__8A9B6141_BC75_11D2_A7FE_004005388001__INCLUDED_)
#define AFX_DLGCONFIRM_H__8A9B6141_BC75_11D2_A7FE_004005388001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgConfirm.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CDlgConfirm �_�C�A���O

class CDlgConfirm : public CDialog
{
// �R���X�g���N�V����
public:
	CDlgConfirm(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgConfirm)
	enum { IDD = IDD_DLG_CONFF };
	CString	m_mes;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgConfirm)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgConfirm)
	virtual void OnCancel();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////
// CDlgInstall �_�C�A���O

class CDlgInstall : public CDialog
{
// �R���X�g���N�V����
public:
	CDlgInstall(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgInstall)
	enum { IDD = IDD_DLG_INSTALL };
	BOOL	m_CONTEXT;
	BOOL	m_DESKTOP;
	BOOL	m_MENU;
	int		m_UNIN;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgInstall)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgInstall)
	afx_msg void OnInsthlp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DLGCONFIRM_H__8A9B6141_BC75_11D2_A7FE_004005388001__INCLUDED_)
