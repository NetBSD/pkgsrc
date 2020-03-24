$NetBSD: patch-kinit_kinit.cpp,v 1.1 2020/03/24 20:34:31 joerg Exp $

--- kinit/kinit.cpp.orig	2020-03-23 21:41:19.609926369 +0000
+++ kinit/kinit.cpp
@@ -1478,7 +1478,7 @@ static void kdeinit_library_path()
    if (display.isEmpty())
    {
 #if defined(Q_WS_X11) || defined(Q_WS_QWS)
-     fprintf(stderr, "kdeinit4: Aborting. $"DISPLAY" is not set.\n");
+     fprintf(stderr, "kdeinit4: Aborting. $" DISPLAY " is not set.\n");
      exit(255);
 #endif
    }
