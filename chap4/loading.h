#ifndef __LOADING_H__
#define __LOADING_H__

#include <DxLib.h>

struct ImageHandles
{
	int field; //�w�i�̑���
	int mapitems[10]; //�}�b�v��̃A�C�e��
};
extern ImageHandles g_imghandles;

BOOL LoadGameImage();

#endif
