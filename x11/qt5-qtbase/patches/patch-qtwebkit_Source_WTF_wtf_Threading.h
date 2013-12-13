$NetBSD: patch-qtwebkit_Source_WTF_wtf_Threading.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add Solaris/SunOS support

--- qtwebkit/Source/WTF/wtf/Threading.h.orig	2013-11-27 01:01:21.000000000 +0000
+++ qtwebkit/Source/WTF/wtf/Threading.h
@@ -112,6 +112,8 @@ using WTF::createThread;
 using WTF::currentThread;
 using WTF::detachThread;
 using WTF::waitForThreadCompletion;
+#if !OS(SOLARIS)
 using WTF::yield;
+#endif
 
 #endif // Threading_h
