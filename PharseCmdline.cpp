// *******************************************************************
// �v���O�����ɓn���������̃p�X�����A�ЂƂ��ɕ������܂�
//
// " ... " �̂悤�Ɉ͂܂ꂽ�p�X���� �u"�v����苎���ĕ���
// �p�X���̊Ԃ́u �v�i�X�y�[�X1�j�ŋ�؂��Ă��邱��
//
// �g����
//
// 1. PharseCmdline.SetOrgStr(m_lpCmdLine); // �������Z�b�g
//
// 2. i = PharseCmdline.CountParam(); // �K�v�ł���΁A�p�X�̐������o����
//    �� �p�X�̐��� 1, 2, 3 ... �� 1����͂��܂鐔�ł���
//
// 3. while(){ sTmp1 = PharseCmdline.GetNextParam(); } // �����p�X�������o���Ă䂭
//    �� ���� �F �S�Ẵp�X�������o���I����ƁA"" (NULL �X�g�����O)���Ԃ�
//
// *******************************************************************

// PharseCmdline.cpp: CPharseCmdline �N���X�̃C���v�������e�[�V����
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "PharseCmdline.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif

//////////////////////////////////////////////////////////////////////
// �\�z/����
//////////////////////////////////////////////////////////////////////

CPharseCmdline::CPharseCmdline()
{
	m_sOrgStr = "";
	m_nCountTotal = 0;
	m_nCountCur = 0;
}

CPharseCmdline::~CPharseCmdline()
{

}

// *****************************************
// �Ώە�������N���X����CString �ϐ��Ɋi�[����
// *****************************************
BOOL CPharseCmdline::SetOrgStr(LPCSTR sBuf)
{
	if(strlen(sBuf))
	{
		m_sOrgStr = sBuf;
		m_nCountTotal = CountParam();
		return TRUE;
	}
	else
	{
		m_sOrgStr = "";
		return FALSE;
	}
}

// *****************************************
// �p�����[�^�[�������邩�Ԃ�
//
// �uAAA BBB CCC�v�� 3��
// �u"AAA BBB" CCC�v�� 2��
// *****************************************
int CPharseCmdline::CountParam()
{
	long i;	// �e���|����(������V�[�N�p�j
	long nStrLen = m_sOrgStr.GetLength();	// �R�}���h���C��������̒���
	int nCount = 0;		// �X�y�[�X�ŋ�؂����p�����[�^�̐��𐔂���
	BOOL bInsideStr = FALSE;	// �_�u���N�H�[�e�[�V�����ň͂܂ꂽ�̈�ɂ���Ƃ�

	if(nStrLen <= 0) return 0;		// ������̒����O�̂Ƃ�

	for(i=0; i<nStrLen; i++)
	{
		if(m_sOrgStr.GetAt(i) == (char)'\"')
		{	// �p�����[�^�� " ... " �̂悤�Ƀ_�u���N�H�[�e�[�V�����ň͂܂�Ă���ꍇ
			if(!bInsideStr) bInsideStr = TRUE;	// " ... " �����ɓ���
			else
			{
				if(i == nStrLen-1)
				{	// �܂��́A������I���� " �̏ꍇ
					bInsideStr = FALSE;
					i++;
					nCount++;
				}
				else if(m_sOrgStr.GetAt(i+1) == ' ')
				{	// " ... " �̍Ō�� " �͒���� �X�y�[�X��������Ō�� " �ƔF��
					// �܂��́A������I���� " �̏ꍇ
					bInsideStr = FALSE;
					i++;
					nCount++;
				}
			}
		}
		else if(!bInsideStr && m_sOrgStr.GetAt(i) == ' ')
		{	// �p�����[�^�̊Ԃ̓X�y�[�X�ŋ�؂��Ă���ꍇ
			nCount++;
		}
		else if(i == nStrLen-1)		// ������I�[�̏ꍇ
			nCount++;
	}
	return nCount;
}


// *****************************************
// ���̃p�����[�^���u�ЂƂv�Ԃ�
//
// ���o���ׂ��p�X�������Ȃ�� NULL �X�g�����O��Ԃ�
// *****************************************

LPCSTR CPharseCmdline::GetNextParam()
{

	if(m_nCountCur >= m_nCountTotal)
	{	// ���łɁA�S�Ẵp�����[�^���o���I����Ă���Ƃ�
		m_sOneParam = "";
		return (LPCSTR)m_sOneParam;
	}

	GetParamN(m_nCountCur + 1);		// ���ʂ� m_sOneParam �ɓ����Ă���
	m_nCountCur++;		// ���݂̃p�����[�^�ԍ����C���N�������g
	// *********
	// �擪�Ɩ����̃_�u���N�H�[�e�[�V���������
	// *********
	if(m_sOneParam.GetAt(0) == (char)'\"')
		m_sOneParam.Delete(0,1);	// 0 �����ڂ����1�������폜
	long i = m_sOneParam.GetLength();
	if(m_sOneParam.GetAt(i-1) == (char)'\"')
		m_sOneParam.Delete(i-1,1);	// �Ō�̕������폜
	return (LPCSTR)m_sOneParam;
}

// *****************************************
// n�Ԗڂ̃p�����[�^���u�ЂƂv�Ԃ�
// n �� 1 �` m_nCountTotal
// *****************************************
LPCSTR CPharseCmdline::GetParamN(int n)
{
	CString sBuf;				// ���o����������
	long nStrBegin = 0, nStrEnd = 0;	// ���o��������́A�S�̂̒��ł̎n�_�E�I�_
	long i;	// �e���|����(������V�[�N�p�j
	long nStrLen = m_sOrgStr.GetLength();	// �R�}���h���C��������̒���
	int nCount = 0;		// �X�y�[�X�ŋ�؂����p�����[�^�̐��𐔂���
	BOOL bInsideStr = FALSE;	// �_�u���N�H�[�e�[�V�����ň͂܂ꂽ�̈�ɂ���Ƃ�

	if(n > m_nCountTotal)
	{	// �g�[�^���̃p�����[�^�����z�����v���̂Ƃ�
		m_sOneParam = "";
		return (LPCSTR)m_sOneParam;
	}

	for(i=0; i<nStrLen && nCount < n; i++)		// nCount:0�`m_nCountTotal-1, n:1�`m_nCountTotal
	{
		if(m_sOrgStr.GetAt(i) == (char)'\"')
		{	// �p�����[�^�� " ... " �̂悤�Ƀ_�u���N�H�[�e�[�V�����ň͂܂�Ă���ꍇ
			if(!bInsideStr) bInsideStr = TRUE;	// " ... " �����ɓ���
			else
			{
				if(i == nStrLen-1)
				{	// ������I���� " �̏ꍇ
					bInsideStr = FALSE;
					i++;
					nCount++;
					if(i+2<nStrLen && nCount-1==n) nStrBegin = i+1;	// �w��ԍ��̕�����̊J�n�ʒu
					if(nCount==n) nStrEnd = i-1;	// �w��ԍ��̕�����̏I���ʒu
				}
				else if(m_sOrgStr.GetAt(i+1) == ' ')
				{	// " ... " �̍Ō�� " �͒���� �X�y�[�X��������Ō�� " �ƔF��
					bInsideStr = FALSE;
					i++;
					nCount++;
					if(i+2<nStrLen && nCount==n-1) nStrBegin = i+1;	// �w��ԍ��̕�����̊J�n�ʒu
					if(nCount==n) nStrEnd = i-1;	// �w��ԍ��̕�����̏I���ʒu
				}
			}
		}
		else if(!bInsideStr && m_sOrgStr.GetAt(i) == ' ')
		{	// �p�����[�^�̊Ԃ̓X�y�[�X�ŋ�؂��Ă���ꍇ
			nCount++;
			if(i+1<nStrLen && nCount==n-1) nStrBegin = i+1;	// �w��ԍ��̕�����̊J�n�ʒu
			if(nCount==n) nStrEnd = i-1;	// �w��ԍ��̕�����̏I���ʒu
		}
		else if(i == nStrLen-1)		// ������I�[�̏ꍇ
		{
			nCount++;
			if(nCount==n) nStrEnd = i;	// �w��ԍ��̕�����̏I���ʒu
		}
	}
	if(nStrEnd == 0) m_sOneParam = "";		// �w��ԍ��̕�����Ȃ� �i�G���[�j
	m_sOneParam = m_sOrgStr.Mid(nStrBegin, nStrEnd - nStrBegin + 1);

	return (LPCSTR)m_sOneParam;

}
