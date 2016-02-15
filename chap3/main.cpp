#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//ウィンドウズモードにする
	ChangeWindowMode(TRUE);
	//DXライブラリ初期化
	if (DxLib_Init() == -1) return -1;

	//画像を読み込み
	int ghandle = LoadGraph("media\\smp1_chara01.png");
	int x = 0;

	SetDrawScreen(DX_SCREEN_BACK); //ウラ画面を描画対象にする
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0) {
		ClearDrawScreen(); //画面消去
		if (x <= 320) x += 1;
		DrawGraph(x, 224, ghandle, TRUE);
		ScreenFlip(); //画面入れ替え
	}

	//待機
	WaitKey();
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}