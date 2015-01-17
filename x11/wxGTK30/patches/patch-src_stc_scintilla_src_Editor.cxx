$NetBSD: patch-src_stc_scintilla_src_Editor.cxx,v 1.1 2015/01/17 11:16:59 wiedi Exp $
Avoid ambiguity on SunOS

--- src/stc/scintilla/src/Editor.cxx.orig	2014-10-06 21:33:44.000000000 +0000
+++ src/stc/scintilla/src/Editor.cxx
@@ -5841,9 +5841,9 @@ void Editor::GoToLine(int lineNo) {
 }
 
 static bool Close(Point pt1, Point pt2) {
-	if (abs(pt1.x - pt2.x) > 3)
+	if (abs((long)(pt1.x - pt2.x)) > 3)
 		return false;
-	if (abs(pt1.y - pt2.y) > 3)
+	if (abs((long)(pt1.y - pt2.y)) > 3)
 		return false;
 	return true;
 }
