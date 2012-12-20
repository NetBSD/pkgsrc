$NetBSD: patch-polsys.c,v 1.1 2012/12/20 21:36:03 joerg Exp $

--- polsys.c.orig	2012-12-20 16:08:50.000000000 +0000
+++ polsys.c
@@ -1079,7 +1079,7 @@ unsigned long GetPixelByRGB(Color cl, in
 	}
     }
 
-    return ;
+    return 0;
 }
 
 /* SetupWindow() で生成したウィンドウを破棄する
