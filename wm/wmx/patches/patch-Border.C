$NetBSD: patch-Border.C,v 1.1 2020/04/28 15:28:57 nikita Exp $

--- Border.C.orig	2014-11-16 19:34:19.000000000 +0000
+++ Border.C
@@ -306,7 +306,7 @@ void Border::initialiseStatics(WindowMan
                 strcpy (pixMapPath, home);
                 strcat (pixMapPath, "/");
                 strcat (pixMapPath, CONFIG_COMMAND_MENU);
-                strcat (pixMapPath, "/border.xpm");
+                strcat (pixMapPath, "/background.xpm");
                 
                 // look for background pixmap file in
                 // the users .wmx directory. It is *not*
@@ -354,9 +354,8 @@ void Border::initialiseStatics(WindowMan
                 m_backgroundPixmap = None;
                 break;
             }
-	} else
+	}
 #endif  
-            m_backgroundPixmap = None;
     }
 }
 
