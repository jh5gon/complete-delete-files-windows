// Fileman.h: CFileman �N���X�̃C���^�[�t�F�C�X
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEMAN_H__13E1F072_ADF6_11D2_8D63_004005388001__INCLUDED_)
#define AFX_FILEMAN_H__13E1F072_ADF6_11D2_8D63_004005388001__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CFileman  
{
public:
	BOOL DeleteMain(LPCSTR buf);
	CString GetLFName();
	BOOL SetFullPath(LPCSTR buf);
	CString GetPath();
	CString GetFullPath();
	CString GetFname();
	CFileman();
	virtual ~CFileman();
	int n_nFiles;
	int n_rRen;
	int n_rZLen;
	int n_rNull;
	int n_Date;
	int n_Dummy;
	int n_NDispE;
	int n_NDispN;
	BOOL n_Confirm;
	BOOL n_DummySkip;
	int n_nOvwr;
	BOOL n_DispF;
	BOOL n_Log;
	CString *sLogStr;

private:
	BOOL PharsePath();
protected:
	BOOL DummyfileProcess();
	int nErrTrace;
	void ConfirmMsgbox(CString mes);
	CString OldPath;
	unsigned int GenerateRandom(unsigned int min, unsigned int max);
	BOOL DeleteOneFile();
	int nFiles;
	CString sFname;
	CString sPath;
	CString sFullPath;
	CString sLFName;
	BOOL isExist;
	DWORD dwFileAttr;
};

#endif // !defined(AFX_FILEMAN_H__13E1F072_ADF6_11D2_8D63_004005388001__INCLUDED_)
