$NetBSD: patch-toolkit_components_resistfingerprinting_nsRFPService.cpp,v 1.1 2017/08/10 14:46:15 ryoon Exp $

--- toolkit/components/resistfingerprinting/nsRFPService.cpp.orig	2017-07-31 16:20:51.000000000 +0000
+++ toolkit/components/resistfingerprinting/nsRFPService.cpp
@@ -152,14 +152,14 @@ nsRFPService::UpdatePref()
         PR_SetEnv(tz);
       }
     } else {
-#if defined(XP_LINUX) || defined (XP_MACOSX)
-      // For POSIX like system, we reset the TZ to the /etc/localtime, which is the
-      // system timezone.
-      PR_SetEnv("TZ=:/etc/localtime");
-#else
+#if defined(XP_WIN)
       // For Windows, we reset the TZ to an empty string. This will make Windows to use
       // its system timezone.
       PR_SetEnv("TZ=");
+#else
+      // For POSIX like system, we reset the TZ to the /etc/localtime, which is the
+      // system timezone.
+      PR_SetEnv("TZ=:/etc/localtime");
 #endif
     }
   }
