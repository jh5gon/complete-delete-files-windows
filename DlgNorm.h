#if !defined(AFX_DLGNORM_H__32F96C42_B3C2_11D2_A7FE_004005388001__INCLUDED_)
#define AFX_DLGNORM_H__32F96C42_B3C2_11D2_A7FE_004005388001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DlgNorm.h : �w�b�_�[ �t�@�C��
//

#define USER_TIMER_ID 0x315
/////////////////////////////////////////////////////////////////////////////
// CDlgNorm �_�C�A���O

class CDlgNorm : public CDialog
{
// �R���X�g���N�V����
public:
	CDlgNorm(CWnd* pParent = NULL);   // �W���̃R���X�g���N�^

// �_�C�A���O �f�[�^
	//{{AFX_DATA(CDlgNorm)
	enum { IDD = IDD_DLG_NORMAL };
	CProgressCtrl	m_Progress;
	//}}AFX_DATA


// �I�[�o�[���C�h
	// ClassWizard �͉��z�֐��̃I�[�o�[���C�h�𐶐����܂��B
	//{{AFX_VIRTUAL(CDlgNorm)
	public:
	virtual BOOL Create();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �T�|�[�g
	//}}AFX_VIRTUAL

// �C���v�������e�[�V����
protected:

	// �������ꂽ���b�Z�[�W �}�b�v�֐�
	//{{AFX_MSG(CDlgNorm)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ �͑O�s�̒��O�ɒǉ��̐錾��}�����܂��B

#endif // !defined(AFX_DLGNORM_H__32F96C42_B3C2_11D2_A7FE_004005388001__INCLUDED_)
