--- config.def.h.orig	2026-11-13 20:01:29 UTC
+++ config.def.h
@@ -5,17 +5,17 @@ static const int topbar             = 1;        /* 0 m
 static const unsigned int snap      = 32;       /* snap pixel */
 static const int showbar            = 1;        /* 0 means no bar */
 static const int topbar             = 1;        /* 0 means bottom bar */
-static const char *fonts[]          = { "monospace:size=10" };
-static const char dmenufont[]       = "monospace:size=10";
-static const char col_gray1[]       = "#222222";
-static const char col_gray2[]       = "#444444";
-static const char col_gray3[]       = "#bbbbbb";
-static const char col_gray4[]       = "#eeeeee";
-static const char col_cyan[]        = "#005577";
+static const char *fonts[]          = { "terminus:size=10" };
+static const char dmenufont[]       = "terminus:size=10";
+static const char col_gray1[]       = "#202020";
+static const char col_gray2[]       = "#404040";
+static const char col_gray3[]       = "#c0c0c0";
+static const char col_gray4[]       = "#f0f0f0";
+static const char col_cyan[]        = "#a0a0aa";
 static const char *colors[][3]      = {
 	/*               fg         bg         border   */
 	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
-	[SchemeSel]  = { col_gray4, col_cyan,  col_cyan  },
+	[SchemeSel]  = { col_gray4, col_gray2, col_cyan  },
 };
 
 /* tagging */
@@ -46,7 +46,7 @@ static const Layout layouts[] = {
 };
 
 /* key definitions */
-#define MODKEY Mod1Mask
+#define MODKEY Mod4Mask
 #define TAGKEYS(KEY,TAG) \
 	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
 	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
