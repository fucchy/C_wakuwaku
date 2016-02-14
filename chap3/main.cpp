#include <DxLib.h>

int WINAPI WinMain(HINSTANCE h1, HINSTANCE hp, LPSTR lpC, int nC) {
	//ウィンドウズモードにする
	ChangeWindowMode(TRUE);
	//DXライブラリ初期化
	if (DxLib_Init() == -1) return -1;
	//ボックスを描画
	DrawBox(0, 0, 120, 120, 0x00FFFF, TRUE);
	//待機
	WaitKey();
	//DXライブラリの終了処理
	DxLib_End();
	return 0;
}