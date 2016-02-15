#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜��ǂݍ���
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	int x = 0, y = 0;

	SetDrawScreen(DX_SCREEN_BACK); //�E����ʂ�`��Ώۂɂ���
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen(); //��ʏ���
		//���L�����ړ�
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1); //�L�[�̃`�F�b�N
		if (key & PAD_INPUT_UP)		y -= 4;
		if (key & PAD_INPUT_DOWN)	y += 4;
		if (key & PAD_INPUT_LEFT)	x -= 4;
		if (key & PAD_INPUT_RIGHT)	x += 4;
		DrawGraph(x, y, ghandle, TRUE);
		ScreenFlip(); //��ʓ���ւ�
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}