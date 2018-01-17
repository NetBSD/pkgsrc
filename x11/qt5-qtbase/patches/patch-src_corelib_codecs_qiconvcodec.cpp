$NetBSD: patch-src_corelib_codecs_qiconvcodec.cpp,v 1.2 2018/01/17 19:30:47 markd Exp $

* Add DragonFly support
* Add NetBSD support

--- src/corelib/codecs/qiconvcodec.cpp.orig	2017-01-18 14:20:58.000000000 +0000
+++ src/corelib/codecs/qiconvcodec.cpp
@@ -52,9 +52,14 @@ QT_REQUIRE_CONFIG(iconv);
 #include <stdio.h>
 #include <dlfcn.h>
 
+// for __DragonFly_version
+#if defined(__DragonFly__)
+#include <sys/param.h>
+#endif
+
 // unistd.h is needed for the _XOPEN_UNIX macro
 #include <unistd.h>
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)
+#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
 #  include <langinfo.h>
 #endif
 
@@ -71,6 +76,9 @@ QT_REQUIRE_CONFIG(iconv);
 #  else
 #    define UTF16 "UTF-16LE"
 #  endif
+#elif defined(__DragonFly__) && __DragonFly_version__ < 197700
+#  define NO_BOM
+#  define UTF16 "UTF-16"
 #else
 #  define UTF16 "UTF-16"
 #endif
@@ -444,11 +452,13 @@ iconv_t QIconvCodec::createIconv_t(const
 #endif
     const char *codeset = empty_codeset;
     cd = iconv_open(to ? to : codeset, from ? from : codeset);
+#elif defined(__NetBSD)
+    const char *codeset = 0;
 #else
     char *codeset = 0;
 #endif
 
-#if defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)
+#if (defined(_XOPEN_UNIX) && !defined(Q_OS_QNX) && !defined(Q_OS_OSF)) || defined(Q_OS_NETBSD) || defined(__DragonFly__)
     if (cd == (iconv_t) -1) {
         codeset = nl_langinfo(CODESET);
         if (codeset)
