// ************************************************************
// �C���X�g�[���E�A���C���X�g�[���֘A
//
// ************************************************************

BOOL MkHklmLnk(void);		// ���W�X�g���ɃV���[�g�J�b�g (HKLM, HKCU �o�[�W����)
BOOL MkHkcuLnk(void);
BOOL RmHklmLnk(void);
BOOL RmHkcuLnk(void);
void MkStartMnu(void);		// �X�^�[�g�A�b�v�ɃV���[�g�J�b�g�i/start�X�C�b�`�t��)
void RmStartMnu(void);
void MkSendtoMnu(void);		// �R���e�L�X�g���j���[�ɃV���[�g�J�b�g
void RmSendtoMnu(void);
void MkDesktopMnu(void);	// �f�X�N�g�b�v�ɃV���[�g�J�b�g
void RmDesktopMnu(void);
void MkProgramsMnu(void);	// �X�^�[�g���j���[�ɃV���[�g�J�b�g
void RmProgramsMnu(void);
void MkUninstMnu(void);		// �X�^�[�g���j���[�ɍ폜�V���[�g�J�b�g (/delete�X�C�b�`�t��)
void RmUninstMnu(void);
void MkHklmUninstMnu(void);		// ���W�X�g���i�R���p�l�j�ɍ폜�V���[�g�J�b�g (/delete�X�C�b�`�t��)
void RmHklmUninstMnu(void);
void MkHkcuUninstMnu(void);		// ���W�X�g���i�R���p�l�j�ɍ폜�V���[�g�J�b�g (/delete�X�C�b�`�t��)
void RmHkcuUninstMnu(void);
HRESULT CreateShellLink(LPCSTR pszShortcutFile,
							LPSTR pszLink, LPSTR pszDesc, LPSTR pszParam);
BOOL ChkHklmInstReg(void);
BOOL MkHklmInstReg(void);
BOOL RmHklmInstReg(void);

BOOL ChkHkcuInstReg(void);
BOOL MkHkcuInstReg(void);
BOOL RmHkcuInstReg(void);

void RmUserReg(void);

