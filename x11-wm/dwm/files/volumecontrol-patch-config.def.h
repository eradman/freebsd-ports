--- config.def.h.orig	2026-11-13 19:11:22.946904000 -0500
+++ config.def.h	2026-11-13 19:20:15.814402000 -0500
@@ -60,7 +60,18 @@
 static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
 static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
 static const char *termcmd[]  = { "st", NULL };
+static const char *incrvol[] = { "mixer", "vol.volume=+0.10", NULL };
+static const char *decrvol[] = { "mixer", "vol.volume=-0.10", NULL };
+static const char *mutevol[] = { "mixer", "vol.mute=^", NULL };
+static const char *incrbright[] = { "backlight", "incr", "10", NULL };
+static const char *decrbright[] = { "backlight", "decr", "10", NULL };
 
+#define XK_XF86AudioLowerVolume 0x1008ff11
+#define XK_XF86AudioMute	0x1008ff12
+#define XK_XF86AudioRaiseVolume 0x1008ff13
+#define XK_XF86MonBrightnessUp 0x1008ff02
+#define XK_XF86MonBrightnessDown 0x1008ff03
+
 static const Key keys[] = {
 	/* modifier                     key        function        argument */
 	{ MODKEY,                       XK_p,      spawn,          {.v = dmenucmd } },
@@ -96,6 +107,11 @@
 	TAGKEYS(                        XK_8,                      7)
 	TAGKEYS(                        XK_9,                      8)
 	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
+	{ 0x0,				XK_XF86AudioRaiseVolume,	spawn,	{.v = incrvol } },
+	{ 0x0,				XK_XF86AudioLowerVolume,	spawn,	{.v = decrvol } },
+	{ 0x0,				XK_XF86AudioMute,		spawn,	{.v = mutevol } },
+	{ 0x0,				XK_XF86MonBrightnessUp,		spawn,	{.v = incrbright } },
+	{ 0x0,				XK_XF86MonBrightnessDown,	spawn,	{.v = decrbright } },
 };
 
 /* button definitions */
