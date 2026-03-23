$NetBSD: patch-oneko.c,v 1.1 2026/03/23 11:32:52 nia Exp $

- Modern GCC no longer likes implicit int.
- Use correct pointer type for XGetGeometry.

--- oneko.c.orig	2026-03-23 11:18:59.265120401 +0000
+++ oneko.c
@@ -324,7 +324,7 @@ char	*resource;
 /*
  *	リソース・データベースからオプションを設定
  */
-
+void
 GetResources()
 {
   char	*resource;
@@ -421,7 +421,7 @@ GetResources()
 /*
  *	ねずみ型カーソルを作る
  */
-
+void
 MakeMouseCursor()
 {
     Pixmap			theCursorSource;
@@ -450,7 +450,7 @@ MakeMouseCursor()
 /*
  *	色を初期設定する
  */
-
+void
 SetupColors()
 {
     XColor	theExactColor;
@@ -499,7 +499,7 @@ InitScreen(DisplayName)
   Window			theTempRoot;
   int				WindowPointX;
   int				WindowPointY;
-  unsigned long		BorderWidth;
+  unsigned int		BorderWidth;
   int				event_base, error_base;
 
   if ((theDisplay = XOpenDisplay(DisplayName)) == NULL) {
