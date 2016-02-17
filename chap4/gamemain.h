#ifndef __GAMEMAIN_H__
#define __GAMEMAIN_H__


#include <DxLib.h>
#include "main.h"

#define IMG_CHIPSIZE 50
#define MAP_WIDTH 16
#define MAP_HEIGHT 12

extern int g_mapdata[MAP_HEIGHT][MAP_WIDTH];

enum MapItem {
	MPITEM_NO, //0:何もない(草原)
	MPITEM_ROCK, //1:障害物の岩
	MPITEM_HMONSTER, //2:左右に動く敵
	MPITEM_VMONSTER, //3:縦に動く敵
	MPITEM_DRAGON, //4:ドラゴン
	MPITEM_HEROPOS = 7, //7:主人公の初期位置
	MPITEM_KEY, //8:鍵
	MPITEM_GOAL //9:ゴール
};

void GameMain();
void DrawMap();

#endif