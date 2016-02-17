#ifndef __LOADING_H__
#define __LOADING_H__

#include <DxLib.h>

struct ImageHandles
{
	int field; //背景の草原
	int mapitems[10]; //マップ上のアイテム
};
extern ImageHandles g_imghandles;

BOOL LoadGameImage();

#endif
