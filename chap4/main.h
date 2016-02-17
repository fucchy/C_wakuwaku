#ifndef __MAIN_H__
#define __MAIN_H__

#include <DxLib.h>
#include "gamemain.h"
#include "loading.h"

//�O���[�o���ϐ�
//���Ԍv���p�ϐ�
extern int g_lasttime; //���O�̌v������
extern float g_frametime; //1���[�v�ɂ�����������
extern int g_timerstart; //�^�C�}�[�p�ϐ�

enum GameState //�Q�[�����
{
	GAME_TITLE,
	GAME_MAIN,
	GAME_CLEAR,
	GAME_OVER
};
extern GameState g_gamestate;

extern int g_gametitleimg; //�^�C�g���C���[�W
extern int g_heroimg; //�摜
extern float g_hx, g_hy; //���W
//�{�^��
extern BOOL g_akey_prev; //���O��A�{�^���̏��;
//�t�H���g
extern int g_middlefont; //���T�C�Y�̃t�H���g�n���h��
extern int g_largefont; //��T�C�Y�̃t�H���g�n���h��

//�֐��v���g�^�C�v�錾
void DrawGameTitle();
void DrawGameMain();
void DrawGameClear();
void DrawGameOver();
BOOL IsAKeyTrigger(int key);

#endif