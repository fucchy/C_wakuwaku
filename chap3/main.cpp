#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜��ǂݍ���
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	for (int x = 0; x < 320; x++) {
		DrawGraph(x, 224, ghandle, TRUE);
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}