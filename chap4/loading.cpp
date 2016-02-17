#include "loading.h"

ImageHandles g_imghandles;

BOOL LoadGameImage() {
	g_imghandles.field = LoadGraph("media\\smp1_back.png");
	if (g_imghandles.field == -1) return FALSE;

	g_imghandles.mapitems[1] = LoadGraph("media\\smp1_rock.png");
	if (g_imghandles.mapitems[1] == -1) return FALSE;
	g_imghandles.mapitems[2] = LoadGraph("media\\smp1_chara02.png");
	if (g_imghandles.mapitems[2] == -1) return FALSE;
	g_imghandles.mapitems[3] = g_imghandles.mapitems[2];
	g_imghandles.mapitems[4] = LoadGraph("media\\smp1_chara03.png");
	if (g_imghandles.mapitems[4] == -1) return FALSE;
	g_imghandles.mapitems[5] = LoadGraph("media\\smp1_chara04.png");
	if (g_imghandles.mapitems[5] == -1) return FALSE;
	g_imghandles.mapitems[7] = LoadGraph("media\\smp1_chara01.png");
	if (g_imghandles.mapitems[7] == -1) return FALSE;
	g_imghandles.mapitems[8] = LoadGraph("media\\smp1_key.png");
	if (g_imghandles.mapitems[8] == -1) return FALSE;
	g_imghandles.mapitems[9] = LoadGraph("media\\smp1_goal.png");
	if (g_imghandles.mapitems[9] == -1) return FALSE;

	return TRUE;
}