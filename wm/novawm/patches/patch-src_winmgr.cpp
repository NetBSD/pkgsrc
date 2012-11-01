$NetBSD: patch-src_winmgr.cpp,v 1.1 2012/11/01 19:34:15 joerg Exp $

--- src/winmgr.cpp.orig	2012-10-30 20:50:27.000000000 +0000
+++ src/winmgr.cpp
@@ -1462,7 +1462,7 @@ WinMgr::Find_UnmapIgnore (Window ignoreW
 		if ((*i) == ignoreWindow)
 		{
 #ifdef DEBUG
-			printf ("DEBUG: Found %x\n", i);
+			printf ("DEBUG: Found %x\n", *i);
 #endif
 			return 1;
 		}
