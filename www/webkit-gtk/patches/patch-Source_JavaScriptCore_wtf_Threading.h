$NetBSD: patch-Source_JavaScriptCore_wtf_Threading.h,v 1.3 2012/10/30 12:46:30 drochner Exp $

--- Source/WTF/wtf/Threading.h.orig	2012-08-27 19:05:10.000000000 +0000
+++ Source/WTF/wtf/Threading.h
@@ -112,6 +112,8 @@ using WTF::createThread;
 using WTF::currentThread;
 using WTF::detachThread;
 using WTF::waitForThreadCompletion;
+#if !OS(SOLARIS)
 using WTF::yield;
+#endif
 
 #endif // Threading_h
