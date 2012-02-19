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
// CDlgPDel2 �_�C�A���O

class CDlgPDel2 : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPDel2)

// �R���X�g���N�V����
public:
	CDlgPDel2();
	~CDlgPDel2();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgPDel2)
	enum { IDD = IDD_DLG_PROPDEL2 };
	UINT	m_nBufferSize;
	UINT	m_nOverrun;
	UINT	m_nDodChar;
	BOOL	m_bNotRemove;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDlgPDel2)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPDel2)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

/////////////////////////////////////////////////////////////////////////////
// CDlgPDel3 �_�C�A���O

class CDlgPDel3 : public CPropertyPage
{
	DECLARE_DYNCREATE(CDlgPDel3)

// �R���X�g���N�V����
public:
	CDlgPDel3();
	~CDlgPDel3();

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgPDel3)
	enum { IDD = IDD_DLG_PROPDEL3 };
	CButton	m_ctrl_bAntiOneShot;
	CButton	m_ctrl_bDummySkip;
	CEdit	m_ctrl_nFiles;
	CEdit	m_ctrl_nAnticacheSize;
	CButton	m_ctrl_rAntiFolder2;		// �蓮�Œǉ�
	CButton	m_ctrl_rAntiFolder;
	BOOL	m_AntiCache;
	int		m_rAntiFolder;
	UINT	m_nAnticacheSize;
	BOOL	m_bDummy;
	BOOL	m_bDummySkip;
	UINT	m_nFiles;
	BOOL	m_bAntiOneShot;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B

	//{{AFX_VIRTUAL(CDlgPDel3)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:
	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgPDel3)
	afx_msg void OnCAnticache();
	virtual BOOL OnInitDialog();
	afx_msg void OnCDmy();
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
	afx_msg void OnBtnQfileBrowse();
	afx_msg void OnBtnQexec();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};
/////////////////////////////////////////////////////////////////////////////


//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B
#endif //(AFX_DLGCONFIG_H__7BD9E5C7_BD40_11D2_A7FE_004005388001__INCLUDED_)
