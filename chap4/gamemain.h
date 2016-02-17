#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__


#include <DxLib.h>
#include "main.h"

#define IMG_CHIPSIZE 50
#define MAP_WIDTH 16
#define MAP_HEIGHT 12

extern int g_mapdata[MAP_HEIGHT][MAP_WIDTH];

enum MapItem {
	MPITEM_NO, //0:�����Ȃ�(����)
	MPITEM_ROCK, //1:��Q���̊�
	MPITEM_HMONSTER, //2:���E�ɓ����G
	MPITEM_VMONSTER, //3:�c�ɓ����G
	MPITEM_DRAGON, //4:�h���S��
	MPITEM_HEROPOS = 7, //7:��l���̏����ʒu
	MPITEM_KEY, //8:��
	MPITEM_GOAL //9:�S�[��
};

void GameMain();
void DrawMap();

#endif