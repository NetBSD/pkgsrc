$NetBSD: patch-Source_WTF_wtf_Threading.h,v 1.1 2014/12/30 17:23:47 adam Exp $

* Add Solaris/SunOS support

--- Source/WTF/wtf/Threading.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ Source/WTF/wtf/Threading.h
@@ -112,6 +112,8 @@ using WTF::createThread;
 using WTF::currentThread;
 using WTF::detachThread;
 using WTF::waitForThreadCompletion;
+#if !OS(SOLARIS)
 using WTF::yield;
+#endif
 
 #endif // Threading_h
