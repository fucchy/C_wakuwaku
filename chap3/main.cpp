#include <DxLib.h>

//グローバル変数
//時間計測用変数
int g_lasttime = 0; //直前の計測時間
float g_frametime = 0; //1ループにかかった時間
enum GameState //ゲーム状態
{
	GAME_TITLE, GAME_MAIN, GAME_CLEAR, GAME_OVER
};

GameState g_gamestate = GAME_TITLE; //ゲーム状態を記録する変数
int g_gametitleimg; //タイトルイメージ
int g_heroimg; //画像
float g_hx = 0, g_hy = 0; //座標

//関数プロトタイプ宣言
void DrawGameTitle();
void DrawGameMain();
void DrawGameClear();
void DrawGameOver();

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//ウィンドウズモードにする
	ChangeWindowMode(TRUE);
	//ウィンドウサイズを変更する
	SetGraphMode(800, 600, 32);
	//DXライブラリ初期化
	if (DxLib_Init() == -1) return -1;

	//画像を読み込み
	g_gametitleimg = LoadGraph("media\\smp1_title.png");
	g_heroimg = LoadGraph("media\\smp1_chara01.png");

	SetDrawScreen(DX_SCREEN_BACK); //ウラ画面を描画対象にする
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//1ループにかかった時間を計測
		int curtime = GetNowCount();
		g_frametime = (float)(curtime - g_lasttime) / 1000.0f;
		g_lasttime = curtime;

		ClearDrawScreen(); //画面消去
		//画面描画関数に切り替え
		switch (g_gamestate)
		{
		case GAME_TITLE:
			DrawGameTitle();
			break;
		case GAME_MAIN:
			DrawGameMain();
			break;
		case GAME_CLEAR:
			DrawGameClear();
			break;
		case GAME_OVER:
			DrawGameOver();
			break;
		default:
			break;
		}
		ScreenFlip(); //画面入れ替え
	}

	//待機
	WaitKey();
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}

//タイトル画面描画
void DrawGameTitle() {
	DrawBox(0, 0, 800, 600, GetColor(255, 255, 255), TRUE);
	DrawGraph(0, 0, g_gametitleimg, TRUE);
}

//ゲーム本編描画
void DrawGameMain() {
	//自キャラ移動
	int key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
	float mv = 80.0f * g_frametime; //移動量計算
	if (key & PAD_INPUT_UP)		g_hy -= mv;
	if (key & PAD_INPUT_DOWN)	g_hy += mv;
	if (key & PAD_INPUT_LEFT)	g_hx -= mv;
	if (key & PAD_INPUT_RIGHT)	g_hx += mv;
	DrawGraph(g_hx, g_hy, g_heroimg, TRUE);
}

//ゲームクリア画面描画
void DrawGameClear() {

}

//ゲームオーバー画面描画
void DrawGameOver() {

}