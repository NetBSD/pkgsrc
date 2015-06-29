$NetBSD: patch-tools_vmmouse__iopl.c,v 1.1 2015/06/29 11:15:05 wiz Exp $

--- tools/vmmouse_iopl.c.orig	2015-04-09 06:04:46.000000000 +0000
+++ tools/vmmouse_iopl.c
@@ -44,8 +44,15 @@
 
 #if defined(VMMOUSE_OS_BSD)
 #include <sys/types.h>
-#ifdef USE_I386_IOPL
+#if defined(USE_I386_IOPL) || defined(USE_AMD64_IOPL) || defined(USE_X86_64_IOPL)
 #include <machine/sysarch.h>
+#if defined(USE_I386_IOPL)
+#define IOPL_NAME i386_iopl
+#elif defined(USE_AMD64_IOPL)
+#define IOPL_NAME amd64_iopl
+#elif defined(USE_X86_64_IOPL)
+#define IOPL_NAME x86_64_iopl
+#endif
 /***************************************************************************/
 /* I/O Permissions section                                                 */
 /***************************************************************************/
@@ -57,7 +64,7 @@ xf86EnableIO()
     if (ExtendedEnabled)
 	return true;
 
-    if (i386_iopl(1) < 0)
+    if (IOPL_NAME(1) < 0)
 	return false;
 
     ExtendedEnabled = true;
@@ -70,48 +77,13 @@ xf86DisableIO()
     if (!ExtendedEnabled)
 	return;
 
-    i386_iopl(0);
+    IOPL_NAME(0);
 
     ExtendedEnabled = false;
     return;
 }
 
-#endif /* USE_I386_IOPL */
-
-#ifdef USE_AMD64_IOPL
-#include <machine/sysarch.h>
-/***************************************************************************/
-/* I/O Permissions section                                                 */
-/***************************************************************************/
-
-static bool ExtendedEnabled = false;
-
-bool
-xf86EnableIO()
-{
-    if (ExtendedEnabled)
-	return true;
-
-    if (amd64_iopl(1) < 0)
-	return false;
-
-    ExtendedEnabled = true;
-    return true;
-}
-
-void
-xf86DisableIO()
-{
-    if (!ExtendedEnabled)
-	return;
-
-    if (amd64_iopl(0) == 0)
-	ExtendedEnabled = false;
-
-    return;
-}
-
-#endif /* USE_AMD64_IOPL */
+#endif /* defined(USE_I386_IOPL) || defined(USE_AMD64_IOPL) || defined(USE_X86_64_IOPL) */
 
 #ifdef USE_DEV_IO
 #include <sys/stat.h>
