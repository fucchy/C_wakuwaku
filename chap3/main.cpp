#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜��ǂݍ���
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	SetDrawScreen(DX_SCREEN_BACK); //�E����ʂ�`��Ώۂɂ���
	for (int x = 0; x < 320; x++) {
		ClearDrawScreen(); //��ʏ���
		DrawGraph(x, 224, ghandle, TRUE);
		ScreenFlip(); //��ʓ���ւ�
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}