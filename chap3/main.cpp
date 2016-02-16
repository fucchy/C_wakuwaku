#include <DxLib.h>

//�O���[�o���ϐ�
//���Ԍv���p�ϐ�
int g_lasttime = 0; //���O�̌v������
float g_frametime = 0; //1���[�v�ɂ�����������

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//�E�B���h�E�Y���[�h�ɂ���
	ChangeWindowMode(TRUE);
	//DX���C�u����������
	if (DxLib_Init() == -1) return -1;

	//�摜��ǂݍ���
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	float x = 0, y = 0;

	SetDrawScreen(DX_SCREEN_BACK); //�E����ʂ�`��Ώۂɂ���
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//1���[�v�ɂ����������Ԃ��v��
		int curtime = GetNowCount();
		g_frametime = (float)(curtime - g_lasttime) / 1000.0f;
		g_lasttime = curtime;

		ClearDrawScreen(); //��ʏ���
		//���L�����ړ�
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1); //�L�[�̃`�F�b�N
		float mv = 80.0f * g_frametime; //�ړ��ʌv�Z
		if (key & PAD_INPUT_UP)		y -= mv;
		if (key & PAD_INPUT_DOWN)	y += mv;
		if (key & PAD_INPUT_LEFT)	x -= mv;
		if (key & PAD_INPUT_RIGHT)	x += mv;
		DrawGraph(x, y, ghandle, TRUE);
		clsDx();
		printfDx("%d : %f : %f", g_lasttime, g_frametime, mv);
		ScreenFlip(); //��ʓ���ւ�
	}

	//�ҋ@
	WaitKey();
	//DX���C�u�����̏I������
	DxLib_End();
	return 0;
}