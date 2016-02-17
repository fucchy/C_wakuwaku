#include <DxLib.h>
#include "gamemain.h"
#include "main.h"

int g_mapdata[MAP_HEIGHT][MAP_WIDTH] = {
	//0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },	//0
	{ 1, 7, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 4 },	//1
	{ 1, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 9 },	//2
	{ 1, 0, 0, 0, 0, 2, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1 },	//3
	{ 1, 0, 1, 1, 1, 1, 0, 0, 1, 0, 3, 1, 0, 0, 0, 1 },	//4
	{ 1, 0, 1, 0, 0, 1, 0, 8, 1, 0, 0, 1, 0, 1, 0, 1 },	//5
	{ 1, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1 },	//6
	{ 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1 },	//7
	{ 1, 0, 1, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1 },	//8
	{ 1, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1 },	//9
	{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 1 },	//10
	{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }	//11
};

//���l : �Ӗ�
//   0   �����Ȃ�(����)
//   1   ��Q���̊�
//   2   ���E�ɓ����G
//   3   �c�ɓ����G
//   4   �h���S��
//   7   ��l���̏����ʒu
//   8   ��
//   9   �S�[��

void GameMain() {
	DrawMap();
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

void DrawMap() {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			DrawGraph(x*IMG_CHIPSIZE, y*IMG_CHIPSIZE, g_imghandles.field, FALSE);
			//�}�b�v�A�C�e���`��
			int c = g_mapdata[y][x];
			if (c > 0) {
				DrawGraph(
					x*IMG_CHIPSIZE,
					y*IMG_CHIPSIZE,
					g_imghandles.mapitems[c],
					TRUE);
			}
		}
	}
}