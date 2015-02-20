$NetBSD: patch-wxc_src_ewxw_eljcolour.cpp,v 1.1 2015/02/20 23:39:31 joerg Exp $

--- wxc/src/ewxw/eljcolour.cpp.orig	2015-02-20 23:00:58.000000000 +0000
+++ wxc/src/ewxw/eljcolour.cpp
@@ -93,7 +93,7 @@ EWXWEXPORT(void, wxColour_SetByName)(voi
 
 EWXWEXPORT(int, wxColour_ValidName)(void* _name)
 {
-	return (int) wxTheColourDatabase->FindColour ((char*)_name);
+	return (int)(intptr_t) wxTheColourDatabase->FindColour ((char*)_name);
 }
 
 }
