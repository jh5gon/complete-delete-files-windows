#if !defined(AFX_DLGCONFIG_H__7BD9E5C7_BD40_11D2_A7FE_004005388001__INCLUDED_)
#define AFX_DLGCONFIG_H__7BD9E5C7_BD40_11D2_A7FE_004005388001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgConfig.h : �w�b�_�[ �t�@�C��
//

/////////////////////////////////////////////////////////////////////////////
// CDlgPDel �_�C�A���O

class CDlgPDel : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPDel)

// �R���X�g���N�V����
public:
	CDlgPDel();
	~CDlgPDel();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgPDel)
	enum { IDD = IDD_DLG_PROPDEL };
	BOOL	m_Date;
	int		m_nOvwr;
	int		m_rNull;
	int		m_rZLen;
	int		m_rRen;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDlgPDel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPDel)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CDlgPDisp �_�C�A���O

class CDlgPDisp : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPDisp)

// �R���X�g���N�V����
public:
	CDlgPDisp();
	~CDlgPDisp();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgPDisp)
	enum { IDD = IDD_DLG_PROPDISP };
	BOOL	m_Confirm;
	BOOL	m_DispF;
	BOOL	m_NDispE;
	BOOL	m_NDispN;
	BOOL	m_Log;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDlgPDisp)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPDisp)
		// ����: ClassWizard �͂��̈ʒu�Ƀ����o�֐���ǉ����܂��B
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////
// CDlgPOther �_�C�A���O

/////////////////////////////////////////////////////////////////////////////
// CDlgPOther �_�C�A���O

class CDlgPOther : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPOther)

// �R���X�g���N�V����
public:
	HRESULT CreateShellLink(LPCSTR pszShortcutFile, LPSTR pszLink, LPSTR pszDesc);
	CDlgPOther();
	~CDlgPOther();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgPOther)
	enum { IDD = IDD_DLG_PROPOTHER };
	CEdit	m_ctrl_nFiles;
	CButton	m_ctrl_dmyskip;
	BOOL	m_Dummy;
	BOOL	m_DummySkip;
	int		m_nFiles;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDlgPOther)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPOther)
	afx_msg void OnUninstall();
	afx_msg void OnVerinfo();
	afx_msg void OnCDmy();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B
#endif //(AFX_DLGCONFIG_H__7BD9E5C7_BD40_11D2_A7FE_004005388001__INCLUDED_)
