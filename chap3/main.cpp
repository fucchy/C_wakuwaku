#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;
	//�{�b�N�X��`��
	int col = GetColor(255, 255, 0);
	DrawBox(520, 360, 640, 480, col, TRUE);
	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}