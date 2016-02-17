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

//数値 : 意味
//   0   何もない(草原)
//   1   障害物の岩
//   2   左右に動く敵
//   3   縦に動く敵
//   4   ドラゴン
//   7   主人公の初期位置
//   8   鍵
//   9   ゴール

void GameMain() {
	DrawMap();
	//自キャラ移動
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float mv = 80.0f * g_frametime; //移動量計算
	if (key & PAD_INPUT_UP)		g_hy -= mv;
	if (key & PAD_INPUT_DOWN)	g_hy += mv;
	if (key & PAD_INPUT_LEFT)	g_hx -= mv;
	if (key & PAD_INPUT_RIGHT)	g_hx += mv;
	DrawGraph(g_hx, g_hy, g_heroimg, TRUE);
	//Zキーをチェックして画面を切り替え
	if (IsAKeyTrigger(key) == TRUE) {
		g_gamestate = GAME_OVER;
		g_timerstart = g_lasttime; //タイマーセット
	}
}

void DrawMap() {
	for (int y = 0; y < MAP_HEIGHT; y++) {
		for (int x = 0; x < MAP_WIDTH; x++) {
			DrawGraph(x*IMG_CHIPSIZE, y*IMG_CHIPSIZE, g_imghandles.field, FALSE);
			//マップアイテム描画
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