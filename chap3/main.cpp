#include <DxLib.h>

//グローバル変数
//時間計測用変数
int g_lasttime = 0; //直前の計測時間
float g_frametime = 0; //1ループにかかった時間

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//ウィンドウズモードにする
	ChangeWindowMode(TRUE);
	//DXライブラリ初期化
	if (DxLib_Init() == -1) return -1;

	//画像を読み込み
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	float x = 0, y = 0;

	SetDrawScreen(DX_SCREEN_BACK); //ウラ画面を描画対象にする
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		//1ループにかかった時間を計測
		int curtime = GetNowCount();
		g_frametime = (float)(curtime - g_lasttime) / 1000.0f;
		g_lasttime = curtime;

		ClearDrawScreen(); //画面消去
		//自キャラ移動
		int key = GetJoypadInputState(DX_INPUT_KEY_PAD1); //キーのチェック
		float mv = 80.0f * g_frametime; //移動量計算
		if (key & PAD_INPUT_UP)		y -= mv;
		if (key & PAD_INPUT_DOWN)	y += mv;
		if (key & PAD_INPUT_LEFT)	x -= mv;
		if (key & PAD_INPUT_RIGHT)	x += mv;
		DrawGraph(x, y, ghandle, TRUE);
		clsDx();
		printfDx("%d : %f : %f", g_lasttime, g_frametime, mv);
		ScreenFlip(); //画面入れ替え
	}

	//待機
	WaitKey();
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}