#include "loading.h"

ImageHandles g_imghandles;

BOOL LoadGameImage() {
	g_imghandles.field = LoadGraph("media\\smp1_back.png");
	if (g_imghandles.field == -1) return FALSE;

	return TRUE;
}