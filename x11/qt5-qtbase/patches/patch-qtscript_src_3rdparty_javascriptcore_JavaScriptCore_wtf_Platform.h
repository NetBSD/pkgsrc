$NetBSD: patch-qtscript_src_3rdparty_javascriptcore_JavaScriptCore_wtf_Platform.h,v 1.1 2013/12/13 14:38:35 ryoon Exp $

* Add NetBSD support
* Add DragonFly support

--- qtscript/src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h.orig	2013-11-27 01:00:28.000000000 +0000
+++ qtscript/src/3rdparty/javascriptcore/JavaScriptCore/wtf/Platform.h
@@ -419,7 +419,7 @@
 
 /* OS(NETBSD) - NetBSD */
 #if defined(__NetBSD__)
-#define WTF_PLATFORM_NETBSD 1
+#define WTF_OS_NETBSD 1
 #endif
 
 /* OS(OPENBSD) - OpenBSD */
@@ -427,6 +427,11 @@
 #define WTF_OS_OPENBSD 1
 #endif
 
+/* OS(DRAGONFLY) - DragonFly */
+#ifdef __DragonFly__
+#define WTF_OS_DRAGONFLY 1
+#endif
+
 /* OS(QNX) - QNX */
 #if defined(__QNXNTO__)
 #define WTF_OS_QNX 1
@@ -465,6 +470,7 @@
     || OS(LINUX)            \
     || OS(NETBSD)           \
     || OS(OPENBSD)          \
+    || OS(DRAGONFLY)        \
     || OS(QNX)              \
     || OS(SOLARIS)          \
     || OS(SYMBIAN)          \
