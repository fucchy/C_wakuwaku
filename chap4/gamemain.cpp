#include <DxLib.h>
#include "gamemain.h"
#include "main.h"

void GameMain() {
	//���L�����ړ�
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float mv = 80.0f * g_frametime; //�ړ��ʌv�Z
	if (key & PAD_INPUT_UP)		g_hy -= mv;
	if (key & PAD_INPUT_DOWN)	g_hy += mv;
	if (key & PAD_INPUT_LEFT)	g_hx -= mv;
	if (key & PAD_INPUT_RIGHT)	g_hx += mv;
	DrawGraph(g_hx, g_hy, g_heroimg, TRUE);
	//Z�L�[���`�F�b�N���ĉ�ʂ�؂�ւ�
	if (IsAKeyTrigger(key) == TRUE) {
		g_gamestate = GAME_OVER;
		g_timerstart = g_lasttime; //�^�C�}�[�Z�b�g
	}
}