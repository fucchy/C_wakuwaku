#include <DxLib.h>
#include "gamemain.h"
#include "main.h"

void GameMain() {
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