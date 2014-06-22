$NetBSD: patch-mozilla_ipc_glue_ScopedXREEmbed.cpp,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/glue/ScopedXREEmbed.cpp.orig	2014-06-13 00:45:31.000000000 +0000
+++ mozilla/ipc/glue/ScopedXREEmbed.cpp
@@ -66,7 +66,7 @@ ScopedXREEmbed::Start()
   localFile = do_QueryInterface(parent);
   NS_ENSURE_TRUE_VOID(localFile);
 
-#ifdef OS_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (XRE_GetProcessType() == GeckoProcessType_Content) {
     // We're an XPCOM-using subprocess.  Walk out of
     // [subprocess].app/Contents/MacOS to the real GRE dir.
