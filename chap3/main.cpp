#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜��ǂݍ���
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	int x = 0;

	SetDrawScreen(DX_SCREEN_BACK); //�E����ʂ�`��Ώۂɂ���
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen(); //��ʏ���
		if (x <= 320) x += 1;
		DrawGraph(x, 224, ghandle, TRUE);
		ScreenFlip(); //��ʓ���ւ�
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}