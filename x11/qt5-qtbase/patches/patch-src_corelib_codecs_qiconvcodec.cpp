$NetBSD: patch-src_corelib_codecs_qiconvcodec.cpp,v 1.3 2018/06/19 07:21:23 adam Exp $

Add DragonFly support
Add NetBSD support

--- src/corelib/codecs/qiconvcodec.cpp.orig	2018-05-14 04:46:28.000000000 +0000
+++ src/corelib/codecs/qiconvcodec.cpp
@@ -51,9 +51,14 @@ QT_REQUIRE_CONFIG(iconv);
 #include <stdio.h>
 #include <dlfcn.h>
 
+// for __DragonFly_version
+#if defined(__DragonFly__)
+#include <sys/param.h>
+#endif
+
 // unistd.h is needed for the _XOPEN_UNIX macro
 #include <unistd.h>
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX)
+#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
 #  include <langinfo.h>
 #endif
 
@@ -70,6 +75,9 @@ QT_REQUIRE_CONFIG(iconv);
 #  else
 #    define UTF16 "UTF-16LE"
 #  endif
+#elif defined(__DragonFly__) && __DragonFly_version__ < 197700
+#  define NO_BOM
+#  define UTF16 "UTF-16"
 #else
 #  define UTF16 "UTF-16"
 #endif
@@ -447,7 +455,7 @@ iconv_t QIconvCodec::createIconv_t(const
     char *codeset = 0;
 #endif
 
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX)
+#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
     if (cd == (iconv_t) -1) {
         codeset = nl_langinfo(CODESET);
         if (codeset)
